
var express = require('express')
let router = require('express').Router();

var usrCtl = require('../controllers/userController');

router.route('/deleteAll').get(usrCtl.deleteAll);
router.route('/getById').get(usrCtl.getById);
router.route('/register').post(usrCtl.register);
router.route('/updateSettings').post(usrCtl.updateSettings);
router.route('/getNotifications').post(usrCtl.getNotifications);
router.route('/readNotif').post(usrCtl.readNotif);
router.route('/sendVisitNotif').post(usrCtl.sendVisitNotif);
router.route('/userLike').post(usrCtl.userLike);
router.route('/login').post(usrCtl.login);
router.route('/report').post(usrCtl.report);
router.route('/block').post(usrCtl.block);
router.route('/sendResetPassword').post(usrCtl.sendResetPassword);
router.route('/resetPassword').post(usrCtl.resetPassword);
router.route('/logout').post(usrCtl.logout);
router.route('/getMatches').post(usrCtl.getMatches);
router.route('/updateLocation').post(usrCtl.updateLocation);
router.route('/getTags').get(usrCtl.getTags);


module.exports = router;
