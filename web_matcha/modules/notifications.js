
const User = require('../models/userModel');
const debug = require('debug')('matcha:notifications');

exports.send = (id, message) => {
	User.findOne({'_id': id}).then((user) => {
		if (!(user.notifications)) {
			user.notifications = [];
		}
		if (!(user.notification)) {
			user.notification = 0;
		}
		user.notifications.push({
			message: message,
			date: new Date(),
			read: false,
			id: user.notification,
		});
		let values = {$set:{
			notifications: user.notifications,
			notification: user.notification + 1
		}};
		User.updateOne({'_id': id}, values)
		.then(() => {
			debug("worked");
		}).catch((err) => {
			debug("error update");
		});
	}).catch((err) => {
		debug("error find", err);
	});
};

exports.read = async (id, message_id) => {
	debug(id, message_id);
	User.updateOne(
		{ _id: id },
		{ $pull: { notifications: {id: parseInt(message_id) }}}
	).then(() => {
		debug("worked");
	}).catch((err) => {
		debug("error update");
	});
};