const debug           = require('debug')('matcha:app');
const createError     = require('http-errors');
const express         = require('express');
const path            = require('path');
const cookieParser    = require('cookie-parser');
const session         = require('express-session');
const MemoryStore     = require('memorystore')(session)
const logger          = require('morgan');
const fs              = require('fs')

const sessionManager = require("./modules/sessionManager");
const indexRouter = require('./routes/index');
const apiRouter   = require('./routes/api');
const chatRouter  = require('./routes/chat');


var logStream = fs.createWriteStream(path.join(__dirname, 'log.log'), { flags: 'a' });
// APP SETUP
const app = express();
app.use(logger('dev'));
//app.use(logger('dev', { stream: logStream }));
// express.json() replaces body-parser
app.use(express.json({ limit: '50mb' }));
app.use(express.urlencoded({ extended: true, limit: '50mb' }));
app.use(session({
	store: new MemoryStore({
      checkPeriod: 86400000 // prune expired entries every 24h
    }),
	resave: true,
	saveUninitialized: true,
	cookie: { secure: true },
	secret: 'keyboard cat',
	cookie: { maxAge: 30000000 }
}));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use(sessionManager.handle);

// VIEW ENGINE SETUP
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

app.use(indexRouter);
app.use('/chat', chatRouter);
app.use('/api', apiRouter);

// this will send favicon requests etc.. to root, don't do this.
// app.get('*', (req, res) => res.redirect('/'));

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
