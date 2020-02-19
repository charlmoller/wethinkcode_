
const User = require('../models/userModel');
const debug = require('debug')('matcha:sessionManager');

exports.handle = (req, res, next) => {
	// TODO:REMOVE:::
	req.session.login = "5df8e720d4d4d60057c0ed16";
	req.session.emailConfirmed = 1;
	req.session.isFullyRegistered = 1;

	// TODO:REMOVE^^^
	let sesh = req.session;
	//debug("req.sessionID", req.sessionID);
	//debug(req.session);
	if(sesh.login == undefined) req.session.login = "";
	if(sesh.emailConfirmed == undefined) req.session.emailConfirmed = 0;
	if(sesh.isFullyRegistered == undefined) req.session.isFullyRegistered = 0;
	if (sesh.login && sesh.emailConfirmed == 1 && sesh.isFullyRegistered == 1) {
		req.session.fullyLogged = 1;
		let user = {'_id': req.session.login};
		let values = { $set:{last_online: Date.now()} };
		//User.updateMany({}, {
		//	$set: {
		//		file1: "data:image/gif;base64,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"
		//	}
		//}).then(() => {
		//	debug('OK UPDATE ALL');
		//}).catch((err) => {
		//	debug('Error updating', err);
		//});
		//User.find({}).lean().exec((err, users) => {
        //	users.forEach( function(element, index, arr1) {
        //		arr1[index].location = {type : "Point",
        //			coordinates:[18.406406399999998 + (Math.random()*0.02), -33.9414132 + (Math.random()*0.02)]};
        //		User.updateOne({'_id': arr1[index]._id}, arr1[index])
        //		.then(() => {
		//			debug('OK update each document');
		//		}).catch((err) => {
		//			debug('Error updating last_online');
		//		});
        //	});
    	//});

		User.updateOne(user, values)
		.then(() => {
			debug('OK');
		}).catch((err) => {
			debug('Error updating last_online');
		});
		req.session.save(function(err) {
  			// session saved
		});
		res.cookie('login', sesh.login, { maxAge: 60000000 });
	} else {
		req.session.fullyLogged = 0;
	}
	next();
}