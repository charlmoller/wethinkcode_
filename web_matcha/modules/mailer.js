
const debug = require('debug')('matcha:mailer');
const nodemailer = require('nodemailer');

require('dotenv').config();

let transport = nodemailer.createTransport({
	host: 'smtp.gmail.com',
	port: 465,
	auth: {
	   user: process.env.GMAIL_USERNAME,
	   pass: process.env.GMAIL_PASS
	}
});

exports.send = (address, message) => {
  	const options = {
		from: 'cwmoller1@gmail.com',
		to: address,
		subject: 'Matcha',
		html: message
	};
	transport.sendMail(options, function(err, info) {
		if (err) {
		  debug(err)
		} else {
		  debug(info);
		}
	});
};

// Formula = base64_encode(email) + 20 random characters
exports.createConfirmationCode = (email) => {
	
	let get_random_chars = () => { 
		let length = 20;
		let result = '';
		let characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
		let charactersLength = characters.length;
		for ( let i = 0; i < length; i++ ) {
    		result += characters.charAt(Math.floor(Math.random() * charactersLength));
		}
		return result;
	};
	
	// append base64 encoded user email in front
	let buff = new Buffer(email);
	let base64data = buff.toString('base64');

	return base64data + get_random_chars();
};

exports.decodeConfirmationCode = (cc) => {
	
	let code = cc.slice(-20);

	let buff = new Buffer(cc.slice(0, -20), 'base64');
	let email = buff.toString('ascii');
	
	return {code: code, email: email};
};