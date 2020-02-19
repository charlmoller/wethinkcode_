const debug = require('debug')('matcha:chat');
const express = require('express')
const router = require('express').Router();
const fs = require('fs');
const path = require('path');

const User = require('../models/userModel');
const Chat = require('../models/chatModel');

router.route('/getChat').post(async (req, res) => {
	debug(req.body);
	User.find({'_id': [req.body.user, req.body.id]})
	.then((users) => {
		Chat.findOne({
			users: { $all: [req.body.user, req.body.id] }
		})
		.then((chat) => {
			if (chat) {
				return res.json({message: 'OK', chat: chat, users: users});
			} else {
				let chat = new Chat();
				chat.users = [req.body.user, req.body.id];
				chat.messages = [];
				chat.save((err) => {
					if (err) {
						return res.json({message: 'Error saving chat!'});						
					} else {
						return res.json({message: 'OK', chat: chat, users: users});
					}
				});
			}
		}).catch((err) => {
			return res.json({message: 'Error finding chat!'});
		});
	}).catch((err) => {
		return res.json({message: 'Error finding user for chat!'});
	});
});

router.route('/sendChat').post(async (req, res) => {
	debug(req.body.chatid);
	Chat.findOneAndUpdate(
		{ '_id': req.body.chatid },
		{ $push: { messages: req.body.message }}
	).then((chat) => {
		if (chat)
			return res.json({message: 'OK'});
		else
			return res.json({message: 'Chat not found.'});
	}).catch((err) => {
		return res.json({message: 'Error finding chat!'});
	});
});

router.route('/getChats').post(async (req, res) => {
	debug(req.body);
	User.findOne({'_id': req.body.user}, (err, user) => {
		if (err) {
			debug(err);
			return res.json({message: 'Error finding users!'});
		} else if (user) {
			if (!user.connected)
				user.connected = [];
			User.find({'_id': user.connected})
			.then((users) => {
				return res.json({message: 'OK', users: users, user: user});
			}).catch((err) => {
				return res.json({message: 'Error finding users!'});
			});
		} else {
			debug("No entry found in chat.");
			return res.json({message: 'Error finding users!'});
		}
	});
});

module.exports = router;
