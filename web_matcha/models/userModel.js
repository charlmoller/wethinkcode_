var mongoose = require('mongoose');

/*
◦ The gender.
◦ Sexual preferences.
◦ A biography.
◦ A list of interests with tags (ex: #vegan, #geek, #piercing etc...). These tags
must be reusable.
◦ Pictures, max 5, including 1 as profile picture.
*/

// Setup schema
var userSchema = mongoose.Schema({
  name: {type: String, required: true},
  surname: {type: String, required: true},
  email: {type: String, required: true, unique: true},
  pass: {type: String, required: true, select: false},
  isFullyRegistered: {type: Number, required: true},
  emailConfirmed: {type: Number, required: true},
  emailConfirmationCode: {type: String, required: true},
  fame: {type: Number, default: 0, max:10}, // between 0 and 10, like stars
  age: Date,
  gender: [], // 0, 1, 2 = male female other
  interest: [],
  preferences: {}, // {0,1} or {0, 2} etc
  tags: [], // {'dogs'}
  likes: {}, // id's of users that this user likes
  liked_by: [],
  visited_by: [],
  connected: [], // id's of users that are connected to this
  notification: Number,
  notifications: {}, // notifications???
  messages: {},
  location: {
   type: { type: String },
   coordinates: []
  }, // [longitude,latitude] probably
  blocked: {}, // blocked user id's
  reports: {},
  bio: String,
  phone: String,
  last_online: Date,
  create_date: Date,
  file1: String,
  file2: String,
  file3: String,
  file4: String,
  file5: String,
});

userSchema.index({ location: "2dsphere" });

// Export User model
var User = module.exports = mongoose.model('user', userSchema);

module.exports.get = function(callback, limit) {
  User.find(callback).limit(limit);
};
