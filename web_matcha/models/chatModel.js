var mongoose = require('mongoose');

// Setup schema
var chatSchema = mongoose.Schema({
  users: [],
  messages: [],
});

// Export User model
var Chat = module.exports = mongoose.model('chat', chatSchema);

module.exports.get = function(callback, limit) {
  Chat.find(callback).limit(limit);
};
