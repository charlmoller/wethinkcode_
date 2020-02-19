
$(document).ready(function(){
	getLocation();
	search();
});
$(document).ready(list_chats);
$(document).ready(getNotifications);
$(document).ready(getChats);

$(document).ready(function(){
	$("#profile-button").click(function(){
		display_profile(getLoggedInUserName());
	});
});

setInterval(getNotifications, 50000);
setInterval(getChats, 50000);

var g_user;
var g_users;
var g_chats = null;

function getChats() {
	log_dev(getLoggedInUserName());
	$.post({
		url: 'chat/getChats',
		data: {
			user: getLoggedInUserName(),
		},
		success: function(res){
			$("#msg_loader").hide();
			g_chats = res;
		},
	});
}

function showListChats(){
	var res = g_chats;
	if (res.message == "OK") {
		console.log(res.users);
		var mod_users = res.users;
		var content = "";
		mod_users.forEach( function(el, i, arr1) {
			content += `<a href="#" onclick="view_chat('${el._id}');">
				<p id="chat-${el.id}"style='border:1px solid #dee2e6; border-radius:3px;
   			padding: 8px; margin-bottom:2px;'>${el.name} ${el.surname}</p></a>`;
		});
		$("#chat-content").html(content);
	} else {
		$("#chat-content").html("No chats available.");
	}
}

function chat_send_click(){
	var idd = $(this).attr('data-id');
	var chatid = $(this).attr('data-chatid');
	var name = $(this).attr('data-name');
	var input = "#chat-input-" + idd;
	var message = name + ": " + $(input).val();
	if ($(input).val() != ""){
		$.post({
				url: 'chat/sendChat',
				data: {
					chatid: chatid,
					message: message,
				},
				success: function(res){
					var divv = "#chat-body-" + chatid;
					$(divv).html( $(divv).html() + message + "<br>" );
					console.log(res);
				}
		});
	}
	$(input).val("");
}

function view_chat(idd){
	$("#chat-content").html("Loading");
		$.post({
			url: 'chat/getChat',
			data: {
				user: getLoggedInUserName(),
				id: idd,
			},
			success: function(res){
				console.log(res);
				if (res.message == "OK") {
					var uuu = res.users.find(o => o._id === idd);
					var content = "";
					// TODO ADD MESSAGES HERE

					content += `<p id="chat-body-${res.chat._id}">`;
					res.chat.messages.forEach( function(el, index) {
						content += `${el}</br>`;
					});
					content += `</p>`;
					content+= 
						`<br>
						<div class="input-group mb-3">
						  <input autocomplete="off" id="chat-input-${idd}" type="text" class="form-control" placeholder="" aria-label="" aria-describedby="basic-addon1">
						  <div class="input-group-prepend">
						    <button id="chat-send-${idd}" class="btn btn-outline-secondary"
						    	data-id="${idd}"
						    	data-chatid="${res.chat._id}"
						    	data-name="${uuu.name}"
						    	type="button">Send</button>
						  </div>
						</div>`;
					$("#chat-content").html(content);
					$("[id^=chat-send]").click(chat_send_click);
				} else {
					$("#chat-content").html("Chat not available.");
				}
			}
		});
}


function getNotifications() {
	log_dev(getLoggedInUserName());
	$.post({
		url: 'api/getNotifications',
		data: {
			user: getLoggedInUserName(),
		},
		success: handleGetNotifications,
	});
}

function handleGetNotifications(data) {
	$('#notif-badge').show();
	if (data.message == 'OK') {
		log_dev('succes', data.notifs);
    	var counter = 0;
    	if (!data.notifs)
    		data.notifs = [];
    	var notif_body = "";
    	data.notifs = data.notifs.reverse();
    	data.notifs.forEach(function(v, i) {
    		if (v.read == false) counter++;
    		notif_body += `
    			<p id="notif-${v.id}"style='border-bottom:1px solid #dee2e6; 
    			padding: 5px; margin-bottom:0px;'>
    			${v.message}
    			<a type='button' class='float-right' onclick="read_notif(${v.id})">Mark as Read</a></p>`;
    	});
    	$("#notif-badge").html(counter);
    	if (counter == 0) {
    		$("#notif-body").html("<p style='padding: 5px;'>No new notifications</p>");
    	} else {
    		$("#notif-body").html(notif_body);
    	}
    }
}

function read_notif(id) {
	var notif = $("#notif-"+id).remove();
	$.post({
		url: 'api/readNotif',
		data: {
			user: getLoggedInUserName(),
			message_id: id,
		},
		success: function(data){ log_dev(data.message)},
	});
}

function getLocation() {
  if (navigator.geolocation) {
  	console.log("Getting location from chrome");
    navigator.geolocation.getCurrentPosition(function(position) {
  		$.post({
			url: 'api/updateLocation',
			data: {
				user: getLoggedInUserName(),
				lat: position.coords.latitude,
				lon: position.coords.longitude,
			},
			success: function() {
				log_dev('Updated location callback');
			},
		});
    }, function (error) {
    	// Get location through other means
    console.log("Getting location through other means");
		$.post({
			url: 'api/updateLocation',
			data: {
				user: getLoggedInUserName(),
			},
			success: function() {
				log_dev('Updated location callback');
			},
		});
    });
  } else {
    alert("Geolocation is not supported by this browser.");
  }
}

function search() {
	log_dev(getLoggedInUserName());
	$.post({
		url: 'api/getMatches',
		data: {
			user: getLoggedInUserName(),
			age: document.forms["register"]["age"].value,
			fame: document.forms["register"]["fame"].value,
			tags: document.forms["register"]["tags"].value,
			dis: document.forms["register"]["dist"].value,
			sort: $("input[name=gridRadios]:checked").val(),
		},
		success: search_populate,
	});
}

function perform_search() {
	$('#accordion').toggleClass("show");
	$('#load_status').attr("style", "display: inline-block !important");
	$('#search_content').html("");
	search();
}

function reset_search() {
	$("#inage").val(80);
	$("#indis").val(100);
	$("#ingap").val(0);
	$("#intag").val(0);
	$("#gridRadios1").checked = true;
	$('#accordion').toggleClass("show");
	$('#load_status').attr("style", "display: inline-block !important");
	$('#search_content').html("");
	search();
}

function like_button_click(event) {
	$(this).blur();
	var btn = $(this);
	var idd = btn.attr('id');
	var ii = $(this).children("i");
	var ll = $(this).children("span");
    event.preventDefault();
    ll.show();
    ii.hide();
	log_dev(btn.attr('email'));
	var _uid = idd.substring(12);

	$.post("/api/userLike", {'id': _uid}, function(res){
		
		log_dev(res);
		
		if (res.message == "OK") {
		} else {

		}
		btn.toggleClass("btn-outline-danger");
		btn.toggleClass("btn-outline-dark");
		ii.toggleClass("fas");
		ii.toggleClass("far");
		if (btn.prop('title') == "Like")
			btn.prop('title', 'Unlike');
		else
			btn.prop('title', 'Like');
    ll.hide();
    ii.show();
	});
	log_dev(_uid);
}

function build_user_html(user, i) {
	var notLiked = g_user.likes.indexOf(user._id) === -1;
	return `
	<div class='card col-md-4'>
		<img src='${user.file1}' class='card-img-top mx-auto' alt='...'
		style='max-width:300px; display:${(user.file1 && g_user.file1 ? "inline-block" : "none")}'>
		<div class='card-body'>
			<h5 class='card-title'>
				${user.name} ${user.surname}
			</h5>
			<p class='card-text'>
				${get_age(user.age)},
				${(user.gender+"").replace(/^\w/, c => c.toUpperCase())}<br>
				Interested in: ${user.interest}<br>
				Distance: ${Math.round(user.distance*100)/100} km<br>
				Tags: ${user.tags.join(", ")} 
			</p>
		</div>
		<div>
			<button id='like-button-${user._id}' type='button'
				title='${(notLiked ? "Like" : "Unlike")}'
				class='btn btn-outline-${(notLiked ? "danger" : "dark")}'
				style='display:${(user.file1 ? "inline-block" : "none")}'>
				<i id="like-heart" class='${(notLiked ? "fas" : "far")} fa-heart'></i>
          <span id="like-loader" class="spinner-border spinner-border-sm"
            role="status" style="display:none"></span>
			</button>&nbsp;
			<button onclick="display_profile('${user._id}');" id='view-button-${user._id}'
				type='button' class='btn btn-outline-primary'>
				View
			</button>
		</div>
		<br>
	</div>`;
}

function search_populate(data) {
	g_user = null;
    g_users = null;
	if (data.message == 'OK') {
        g_user = data.user;
        g_users = data.data;
        console.log(g_user);
        console.log(g_users);
        console.log("g_user.likes");
        console.log(g_user.likes);        
        $('#profile-button').show();
        $('#chat-button').show();
        $('#notif-button').show();
	}
	display_profiles();
}

function display_profiles() {
	$('#load_status').attr("style", "display: none !important");

	var div = $('#search_content');
	if (g_user && g_users) {
		$('#search-dropdown').show();
		if (!g_user.likes) g_user.likes = [];
		var str = "<br><div class='row'>";
		for (var i = 0; i < g_users.length; i++) {
			var user = g_users[i];
			str += build_user_html(user, i);
		}		
		div.html(str + "</div>");
	} else {
		div.html("No matches found! Try updating your settings.");
		log_dev(data.message);
	}
	$("[id^=like-button]").click(like_button_click);
	$("[id^=like-button]").mousedown(function(e){ e.preventDefault(); $(this).blur(); });
	$("[id^=like-button]").mouseup(function(e) { e.preventDefault(); $(this).blur(); });
}

function send_chat() {
    $.post(
        '/chat/send',
        { id: "5df8e71fd4d4d60057c0ed14", message: $("#message-self").val() },
        function(res) {
            log_dev(res);
        }
    );
    $("#message-self").val("test");
}

function get_age(date) {
	var age = new Date(Date.now() - new Date(date));
	return Math.abs(age.getUTCFullYear() - 1970);
}

function display_profile(i) {
	view_profile(i);
	if (i != getLoggedInUserName()) {
		$.post(
			"/api/sendVisitNotif",
			{
				'id': i,
				'name': g_user.name + " " + g_user.surname,
			}, 
			function(res){}
		);
	}
}

function view_profile(id) {
	$('#search_content').hide();
	$('#search-dropdown').hide();
	$('#load_status').show(); 
	$.get({
		url: 'api/getById',
		data: { id: id },
		success: function(data) {
			$('#load_status').attr("style", "display: none !important");
			var profile_page = `<a href="/" type='button'
				class='btn btn-outline-danger'>
				<i id="like-heart" class='fas fa-arrow-left'></i>
				</a><br><br>`;
			profile_page += build_profile_card(data.data);
			$('#search_content').html(profile_page);
			$('#search_content').show();
			var c_user = data.data;
			c_user.liked_by.forEach( function(element, index) {
				$.get({
					url: 'api/getById',
					data: { id: element },
					success: function(userr) {
						var uu = userr.data;
						$('#liked_by').append(`<a href="#" onclick="display_profile('${uu._id}')">
							${uu.name} ${uu.surname}<a><br>`);
					}
				});
			});
			c_user.visited_by.forEach( function(element, index) {
				$.get({
					url: 'api/getById',
					data: { id: element },
					success: function(userr) {
						var uu = userr.data;
						$('#visited_by').append(`<a href="#" onclick="display_profile('${uu._id}')">
							${uu.name} ${uu.surname}<a><br>`);
					}
				});
			});
			$("[id^=like-button]").click(like_button_click);
			$("[id^=like-button]").mousedown(function(e){ e.preventDefault(); $(this).blur(); });
			$("[id^=like-button]").mouseup(function(e) { e.preventDefault(); $(this).blur(); });
		},
	});
}

function handle_report(id) {
	log_dev(id);
	$.post({url: 'api/report', 
		data: {
			user: getLoggedInUserName(),
			id: id,
		},
		success: function(res) {
			log_dev(res);
			location.href = '/';
		}, 
	});
}

function handle_block(id) {
	log_dev(id);
	$.post({url: 'api/block', 
		data: {
			user: getLoggedInUserName(),
			id: id,
		},
		success: function(res) {
			log_dev(res);
			location.href = '/';
		}
	});
}

function build_profile_card(uuu) {
	var notLiked = g_user.likes.indexOf(uuu._id) === -1;
	var date1;
	var date2;
	var online_string;
	if (!uuu.last_online) {
		online_string = new Date(uuu.create_date).toUTCString();
	} else {
		date1 = new Date(uuu.last_online).getTime();
		date2 = new Date().getTime();
		var diff = (date2 - date1) / (1000 * 3600 * 24);
		console.log(diff);
		if (diff < 0.00001)
			online_string = "Now Online";
		else 
			online_string = new Date(uuu.last_online).toUTCString();
	}
	var logged = (getLoggedInUserName() == uuu._id);
	var loggedStr = "";
	if (logged) {
		loggedStr = `
			<div class='card col-md-6'>
				<div class='card-body'>
					<h3 class='card-title'>History</h5>
					<p class='card-text'>
						<h5>Recent Likes:</h5>
						<p id="liked_by"></p>
						<h5>Recent Profile Vists:</h5>
						<p id="visited_by"></p>
					</p>
			</div>
		`;
	}
	return `
	<div class='card col-md-6'>
		<img src='${uuu.file1}' class='card-img-top mx-auto' alt='...'
		style='display:${(uuu.file1 ? "inline-block" : "none")}'>
		<div class='card-body'>
			<h5 class='card-title'>
				${logged ? "My Profile" : (uuu.name + " " + uuu.surname)}
			</h5>
			<p class='card-text'>
				<b>${get_age(uuu.age)},
				${(uuu.gender+"").replace(/^\w/, c => c.toUpperCase())}</b><br>
				Last online: <b>${online_string}</b><br>
				Interested in: <b>${uuu.interest}</b><br>
				Tags: <b>${uuu.tags.join(", ")}</b><br>
				Fame Rating: <b>${uuu.fame}</b><br>
				<p>Bio:<br><b>${uuu.bio}</b></p> 
			</p>
		</div>
		<div style="display:${logged ? "none" : "block"};">
			<button id='like-button-${uuu._id}' type='button'
				title='${(notLiked ? "Like" : "Unlike")}'
				class='btn btn-outline-${(notLiked ? "danger" : "dark")}'
				style='display:${((uuu.file1 && g_user.file1) ? "inline-block" : "none")}'>
				<i id="like-heart" class='${(notLiked ? "fas" : "far")} fa-heart'></i>
          <span id="like-loader" class="spinner-border spinner-border-sm"
            role="status" style="display:none"></span>
			</button>
			<br><br>
			<button onclick='handle_report("${uuu._id}");' type='button'
				title='report' class='btn btn-outline-danger'>
				Report
			</button>&nbsp;
			<button onclick='handle_block("${uuu._id}");' type='button'
				title='report' class='btn btn-outline-danger'>
				Block
			</button>&nbsp;
		</div>
		<br>
	</div>` + loggedStr;
}

function handle_list_chats(res) {
    log_dev(res);
    $('#msg_loader').html("");
    $("#modal-content").html("");
    if (res.message == "OK") {
        //var strc = "";
        //res.data.forEach(function(item) {
        //    strc += "<div style='border: 1px solid #dee2e6; margin:0 auto;'>" + item + "</div><br>";
        //});
        //$("#modal-content").html(strc);
    }
}

function list_chats() {
    //$.get(
    //    '/chat/listChats',
    //    handle_list_chats
    //);
}

function get_chats() {
    //$.get(
    //    '/chat/getChats',
    //    function(res) {
    //    	log_dev(res);
    //    }
    //);
}

function log_dev() {
	var i;
	for (i = 0; i < arguments.length; i++) {
		//arguments[i];
	}
}