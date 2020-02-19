var images = {};
var tags = [];
var possibleTags;
document.getElementById('image1').addEventListener('change', loadImage);
document.getElementById('image2').addEventListener('change', loadImage);
document.getElementById('image3').addEventListener('change', loadImage);
document.getElementById('image4').addEventListener('change', loadImage);
document.getElementById('image5').addEventListener('change', loadImage);

function loadImage(e) {
  var files = e.target.files;
  if (FileReader && files && files.length) {
    var fr = new FileReader();
    fr.onload = function() {
				 images[e.target.id] = fr.result;
    };
    fr.readAsDataURL(files[0]);
	 }
}



window.addEventListener('load', function() {
  xhr = new XMLHttpRequest();
  xhr.open('GET', 'api/getTags', true);
  xhr.setRequestHeader('Content-Type', 'application/json');
  xhr.onload = function() {
    possibleTags = JSON.parse(this.responseText);
    possibleTags.forEach(function(item) {
      var option = document.createElement('option');
      option.value = item;
      document.getElementById('tags').appendChild(option);
    });
  };
  xhr.send();
});

function remove_elem(event) {
  var par = document.getElementById('tag_container');
  tags.splice(tags.indexOf(event.target.id, 1));
  par.removeChild(event.currentTarget);
}

function add_tag() {
  var cont = document.getElementById('tag_container');
  var val = document.getElementById('taglist').value;
  var opts = document.getElementById('tags').childNodes;
  for (var i = 0; i < opts.length; i++) {
    if (opts[i].value === val) {
      if (val != '' && !tags.includes(val)) {
        tags.push(val);
        var wrap = document.createElement('div');
        wrap.className = 'wrap';
        wrap.id = val;
        wrap.innerHTML = '<span>#' + val + '</span>';
        wrap.addEventListener('click', remove_elem);
        cont.appendChild(wrap);
      }
      document.forms['register']['tags'].value = '';
    }
  }
}

function register_submit() {
  xhr = new XMLHttpRequest();
  xhr.open('POST', 'api/updateSettings', true);
  xhr.setRequestHeader('Content-Type', 'application/json');
  xhr.onload = register_response;
  xhr.send(JSON.stringify({
    gender: document.forms['register']['gender'].value.split(' '),
    interest: document.forms['register']['interest'].value.split(' '),
    age: document.forms['register']['age'].value,
    bio: document.forms['register']['bio'].value,
    tags: tags,
    file1: images['image1'],
    file2: images['image2'],
    file3: images['image3'],
    file4: images['image4'],
    file5: images['image5'],
  }));
}

function register_response() {
  var msg = document.getElementById('regmsg');
  var data = JSON.parse(this.responseText);
  if (data['message'] == 'OK') {
    location.href = '/';
  } else {
    msg.innerHTML = '*' + data['errmsg'];
  }
}
