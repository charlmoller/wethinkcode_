
const bcrypt = require('bcrypt');
const User = require('../models/userModel');
const mailer = require('../modules/mailer');
const notifications = require('../modules/notifications');
const debug = require('debug')('matcha:usercontroller');
const util = require('util')
const fs = require('fs');
const https = require('https');
const geoip = require('geoip-lite');

let setSessionVars = (req, user) => {
	req.session.login = user._id;
	req.session.isFullyRegistered = user.isFullyRegistered;
	req.session.emailConfirmed = user.emailConfirmed;
};

exports.register = (req, res) => {
	if (req.body.pass != req.body.cpass) {
		res.json({message: 'Passwords don\'t match.'});
	} else {
		let user = new User();
		user.name = req.body.name;
		user.surname = req.body.surname;
		user.email = req.body.email;
		user.isFullyRegistered = 0;
		user.emailConfirmed = 0;
		user.emailConfirmationCode = mailer.createConfirmationCode(user.email);
		bcrypt.hash(req.body.pass, 10, (err, hash) => {
			if (err) {
				res.send(err);
			} else {
				user.pass = hash;
				user.save((err) => {
					if (err) {
						res.json({message: 'User already exists!'});
					} else {
						setSessionVars(req, user);
						mailer.send(user.email, "Please click <a href=\"http://127.0.0.1:8080/validate/" + user.emailConfirmationCode + " \">here</a> to complete your registration.");
						res.json({message: 'OK'});
					}
				});
			}
		});
	}
};

exports.updateSettings = (req, res) => {
	debug(req.body.tags);
	let tags = [...new Set(req.body.tags)];
	debug(tags);
	let user = {_id: req.session.login};
	let values = { $set:{
		isFullyRegistered: 1,
		age: req.body.age,
		interest: req.body.interest,
		gender: req.body.gender,
		bio: req.body.bio,
		tags: tags,
		fame: 0,
		file1: req.body.file1,
		file2: req.body.file2,
		file3: req.body.file3,
		file4: req.body.file4,
		file5: req.body.file5
	}};
	User.findOneAndUpdate(user, values, { overwrite: true }, (err, success) => {
		if (err || !success) {
			res.json({message: 'Error updating values.'});
		} else {
			req.session.isFullyRegistered = 1;
			req.session.emailConfirmed = 1;
			debug("sesh: ", req.session);
			res.json({message: 'OK'});
		}
	});
};

exports.updateLocation = (req, res) => {
	let user = {_id: req.session.login};
	if (req.body.lat && req.body.lon) {
		let values = { $set:{
			location: {type:"Point", coordinates: [req.body.lon, req.body.lat]},
		}};
		User.findOneAndUpdate(user, values, { overwrite: true }, (err, success) => {
			if (err || !success) {
				debug("Error updating location.");
				return res.json({message: 'Error updating values.'});
			} else {
				debug("Successfully updated location.");
				return res.json({message: 'OK'});
			}
		});
	} else {
		var ip = req.connection.remoteAddress;
		// TODO REMOVE
		ip = "102.65.47.35";
		var geo = geoip.lookup(ip);
		if (geo != null) {
			let values = { $set:{
				location: {type:"Point", coordinates: [geo.ll[1], geo.ll[0]]},
			}};
			User.findOneAndUpdate(user, values, { overwrite: true }, (err, success) => {
				if (err || !success) {
					return res.json({message: 'Error updating values.'});
				} else {
					return res.json({message: 'OK'});
				}
			});
		} else {
			return res.json({message: 'Error updating values.'});

		}
	}
};

exports.login = async (req, res) => {
	let query = {'email': req.body.email};
	try {
		let user  = await User.findOne(query).select('+pass').exec();
		let match = await bcrypt.compare(req.body.pass, user.pass);
		if (match) {
			setSessionVars(req, user);
			return res.json({message: 'OK', data: user});
		} else {
			return res.json({message: 'Incorrect password.'});
		}
	} catch(e) {
		return res.json({message: 'Mail not found.'});
	}
};

exports.logout = (req, res) => {
	req.session.login = "";
	req.session.isFullyRegistered = 0;
	req.session.emailConfirmed = 0;
	res.redirect('/');
};

exports.getById = (req, res) => {
	var query = {'_id': req.query.id};
	User.findOne(query, (err, user) => {
		if (err) {
			return res.json({message: 'Mail not found.'});
		} else if (user) {
			return res.json({message: 'OK', data: user});
		} else {
			return res.json({message: 'Mail not found.'});
		}
	});
};

exports.deleteAll = (req, res) => {
	User.remove({}, (err, user) => {
		if (err) {
			res.send(err);
		} else {
			res.json({
				status: "OK",
				message: "Deleted all users."
			});
		}
	});
};

exports.getMatches = (req, res) => {
	debug("age", req.body.age);
	debug("fame", req.body.fame);
	debug("tags", req.body.tags);
	debug("dis", req.body.dis);
	debug("sort", req.body.sort);
	let query = {'_id': req.body.user};
	User.findOne(query, (err, user) => {
		if (err) {
			return res.json({message: 'Mail not found.'});
		} else if (user) {
			var date = new Date(user.age);
			var age_min = new Date(user.age);
			age_min.setFullYear(age_min.getFullYear() - (req.body.age));
			debug("location", user.location);
			query = {
				gender: {$in: user.interest},
				interest: {$in: user.gender},
				email: { $ne: user.email},
				_id: { $nin: user.blocked},
				fame: { $gte: req.body.fame },
				age: { $gte: new Date(age_min)},
			};
			var sort = null;
			if (req.body.sort != "location" && req.body.sort != "tags") {
				sort = {sort: req.body.sort};
			}
			if (sort == "fame")
				sort = {sort: "-fame"};
		  	User.find(query, null, sort).lean().exec((err, users) => {
			  	if (err){
			  		debug(err);
			  		res.json({
			  			message: "err",
			  			data: err.message
			  		});
			  	} else {
			  		users.forEach( function(el, i, arr1) {
			  			var a = el.location.coordinates[0] - user.location.coordinates[0];
			  			var b = el.location.coordinates[1] - user.location.coordinates[1];
			  			arr1[i].distance = Math.sqrt( a*a + b*b ) * 110.574;
			  			arr1[i].ctags = (el.tags.filter(value => -1 !== user.tags.indexOf(value))).length;
			  			debug(el.distance, el.ctags, arr1[i].ctags);
			  		});
			  		debug(user.tags);
			  		if (req.body.sort == "location") {
			  			users.sort((a, b) => (a.distance > b.distance) ? 1 : -1);
			  		} else if (req.body.sort == "tags") {
			  			users.sort((a, b) => (a.ctags < b.ctags) ? 1 : -1);
			  		} 
			  		res.json({
			  			message: "OK",
			  			data: users,
			  			user: user
			  		});
				 }
			 });
		} else {
			return res.json({message: 'Mail not found.'});
		}
	});
};

exports.userLike = (req,res) => {

	debug(req.body);
	debug(req.session);

	let liked = req.body.id;
	let logged = {'_id': req.session.login };

	User.findOne(logged)
	.then((login) => {

		let status = "";
		if (!(login.likes)) {
			login.likes = [];
		}

		var index = login.likes.indexOf(liked);
		if (index === -1) {
			login.likes.push(liked);
			status = "liked";
			notifications.send(req.body.id, "<a href='#' onclick='display_profile(\""+login._id+"\");'>"
				+ login.name + " " + login.surname + "</a> liked you.");
			// flip
			User.updateOne({'_id': req.body.id}, {
				$addToSet:{liked_by: req.session.login},
				$inc: {fame: 1}
			}).then(() => {
				debug('OK');

				User.findOne({"_id": req.body.id})
				.then((user) => {
					if (login.liked_by.includes(req.body.id)) {
						User.updateOne({'_id': req.body.id}, {
							$addToSet:{connected: req.session.login}
						}).then(()=>{
							debug('OK connected');
							notifications.send(req.body.id, "<a href='#' onclick='display_profile(\""+req.session.login+"\");'>"
								+ login.name + " " + login.surname + "</a> is now connected to you.");
						})
						.catch((err) => {debug(err);});
						User.updateOne({'_id': req.session.login}, {
							$addToSet:{connected: req.body.id}
						}).then(()=>{
							debug('OK connected');
							notifications.send(req.session.login, "<a href='#' onclick='display_profile(\""+req.body.id+"\");'>"
								+ user.name + " " + user.surname + "</a> is now connected to you.");
						})
						.catch((err) => {debug(err);});
					}
				})
				.catch((err) => {
					debug(err);
				});
				debug('OK');
			}).catch((err) => {
				debug('Error updating liked_by!');
			});
		} else {
			login.likes.splice(index, 1);
			status = "unliked";
			notifications.send(req.body.id, "<a href='#' onclick='display_profile(\""+login._id+"\");'>"
				+ login.name + " " + login.surname + "</a> unliked you.");
			User.findOne({"_id": req.body.id})
			.then((user) => {
				if (login.connected.includes(req.body.id)) {
					User.updateOne({'_id': req.body.id}, {
						$pull:{connected: req.session.login}
					}).then(()=>{
						debug('OK not connected');
						notifications.send(req.body.id, "<a href='#' onclick='display_profile(\""+req.session.login+"\");'>"
									+ login.name + " " + login.surname + "</a> is no longer connected to you.");
					})
					.catch((err) => {debug(err);});
					User.updateOne({'_id': req.session.login}, {
						$pull:{connected: req.body.id}
					}).then(()=>{
						debug('OK not connected');
						notifications.send(req.session.login, "<a href='#' onclick='display_profile(\""+req.body.id+"\");'>"
									+ user.name + " " + user.surname + "</a> is no longer connected to you.");
					})
					.catch((err) => {debug(err);});
				}
			})
			.catch((err) => {
				debug(err);
			});
		}

		//connect

		let values = { $set:{likes: login.likes} };
		User.updateOne(logged, values)
		.then(() => {
			return res.json({message: 'OK', status: status});
		}).catch((err) => {
			return res.json({message: 'Error saving like!'});
		});

	}).catch((err) => {
		return res.json({message: 'Error saving like!'});
	});
};

exports.getNotifications = (req,res) => {
	let query = {'_id': req.body.user};
	User.findOne(query, (err, user) => {
		if (err) {
			return res.json({message: 'Mail not found.'});
		} else if (user) {
			if (!user.notifications)
				user.notifications = [];
			return res.json({message: 'OK', notifs: user.notifications});
		}
	});
};

exports.readNotif = async (req,res) => {
	debug(req.body);
	notifications.read(req.body.user, req.body.message_id);
	return res.json({message: 'OK'});
};

exports.sendVisitNotif = (req,res) => {
	debug(req.body);
	// todo change
	notifications.send(req.body.id, "<a href='#' onclick='display_profile(\""+req.session.login+"\");'>"
		+ req.body.name + "</a> visited your profile.");
	User.updateOne({'_id': req.body.id}, { $addToSet:{visited_by: req.session.login} })
	.then(() => {
		debug('OK');
	}).catch((err) => {
		debug('Error updating visited_by!');
	});
	return res.json({message: 'OK'});
};


exports.block = async (req, res) => {
	
	User.findOne({'_id': req.body.user})
	.then((user) => {
		if (!user.blocked)
			user.blocked = [];
		user.blocked.push(req.body.id);
		let values = { $set:{blocked: user.blocked} };
		User.updateOne({'_id': req.body.user}, values)
		.then(() => {
			return res.json({message: 'OK'});
		}).catch((err) => {
			return res.json({message: 'Error blocking user!'});
		});

	}).catch((err) => {
		return res.json({message: 'Error finding user!'});
	});
};


exports.report = async (req, res) => {
	
	User.findOne({'_id': req.body.id})
	.then((user) => {
		if (!user.reports)
			user.reports = [];
		user.reports.push(req.body.user);
		let values = { $set:{reports: user.reports} };
		User.updateOne({'_id': req.body.id}, values)
		.then(() => {
			return res.json({message: 'OK'});
		}).catch((err) => {
			return res.json({message: 'Error reporting user!'});
		});

	}).catch((err) => {
		return res.json({message: 'Error finding user!'});
	});
};

exports.sendResetPassword = async (req,res) => {
	
	try {
		let user   = await User.findOne({'email': req.body.email}).select('+pass').exec();
		let url    = 'http://127.0.0.1:8080/resetpw?';
		let urlstr = "u=" + user._id + "&p=" + user.pass;
		mailer.send(user.email, "Hi " + user.name + ", click here " + url + urlstr);
		res.json({message: 'OK'});
	} catch(e) {
		res.json({message: 'Error sending reset email.'});
	}

};


exports.resetPassword = async (req, res) => {

	debug("req.body", req.body);

	try {
		let samepw  = await (() => {return req.body.pass === req.body.cpass});
		let user    = await User.findOne({'_id': req.body.id}).select('+pass').exec();
		let matches = req.body.oldpass === user.pass;
		if (matches != true)
			throw new Error("Error");
		let	newhash = await bcrypt.hash(req.body.pass, 10);
		let success	= await User.updateOne(user, { $set: {pass: newhash}});
		setSessionVars(req, user);
		return res.json({message: 'OK'});
	} catch(e) {
		return res.json({message: "Error: " + e});
	}
};

exports.validateEmail = (req, res) => {
	debug("Validating: email confirmation code: ", req.params.confirmationCode );
	let decoded = mailer.decodeConfirmationCode( req.params.confirmationCode );
	debug("decoded", decoded, "email", decoded.email);
	let user = { 'email': decoded.email };
	let values =
	{ $set:
		{
			emailConfirmed: 1,
		}
	};
	User.findOneAndUpdate(user, values, (err, success) => {
		debug("err", err, "success", success);
		if (err) {
			res.render('landing', { title: 'Not a valid confirmation code!' });
		} else {
			debug("Cookie currently in form: ", decoded.email);
			req.session.login = decoded.email;
			req.session.emailConfirmed = 1;
			res.render('landing', { title: 'Please log in.' });
		}
	});
};

exports.getTags = async (req, res) => {
	debug("test");
	try {
		let tagFile = await fs.promises.readFile('tags.json');
		res.json(JSON.parse(tagFile));
	} catch(e) {
		res.json({});
	}
};