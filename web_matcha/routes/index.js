const debug = require('debug')('matcha:index');
const express = require('express')
const router = require('express').Router();

const User = require('../models/userModel');
const users = require('../controllers/userController');

// ROUTING SETUP
router.route('/').get((req, res) => {
	debug("req.session       ", req.session);
	debug("req.cookies.login ", req.cookies.login);
	if (req.session.fullyLogged) {
		res.render('app', {title: 'Matcha'});
	} else {
		res.render('landing', {title: 'Matcha'});
	}
});

router.route('/registration').get((req, res) => {
	if (req.session.login == "") {
		res.redirect("/");		
	} else if (req.session.emailConfirmed == 0) {
		res.render('landing', { title: 'Please confirm your email!' });
	} else if (req.session.isFullyRegistered){
		res.redirect("/settings");
	} else {
		User.findOne({'_id': req.session.login})
		.then((user) => {
			res.render('settings', { title: 'Complete Registration', user: JSON.stringify(user) });
		}).catch((err) => {
			res.render('landing', { title: 'Please log in.' });
		});
	}
});

router.route('/settings').get((req, res) => {
	debug("login: ", req.session.login);
	if (!req.session.isFullyRegistered) {
		res.redirect("/registration");
	} else {
		User.findOne({'_id': req.session.login})
		.then((user) => {
			debug(user);
			res.render('settings', { title: 'Modify Profile', user: JSON.stringify(user) });
		}).catch((err) => {
			res.render('landing', { title: 'Please log in.' });
		});
	}
});

router.route('/validate/:confirmationCode').get((req, res) => {
	debug("login: ", req.params.confirmationCode);
	users.validateEmail(req, res);
});

router.route('/resetpw').get((req, res) => {
	//debug("login: ", req.params.confirmationCode);
	res.render('resetpw', { title: 'Please log in.' });
});

router.route('/changePassword/:login').get(async (req, res) => {
	debug(req.session.login, req.params.login);
	try {
		let user = await User.findOne({'_id': req.params.login}).select('+pass').exec();
		if (req.session.login !== req.params.login)
			throw new Error("Error");
		let urlstr = "u=" + user._id + "&p=" + user.pass;
		res.redirect("/resetpw?" + urlstr);
	} catch(e) {
		res.render('landing', { title: 'Can not change password for this user!' });
	}
});

module.exports = router;