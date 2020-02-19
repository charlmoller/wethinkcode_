
function parseCookies(cstr) {
	var list = {};
	var rc = cstr;
	rc && rc.split(';').forEach(function(cookie) {
		var parts = cookie.split('=');
		list[parts.shift().trim()] = decodeURI(parts.join('='));
	});
	return list;
}

function getLoggedInUserName() {
	var logged = decodeURIComponent(parseCookies(document.cookie).login);
	return logged;
}

function log_out() {
	$.post('/api/logout');
	document.cookie = 'login=';
	location.href = '/';
}

function setAttributes(elem, vals) {
	for (var k in vals) {
		elem.setAttribute(k, vals[k]);
	}
}
