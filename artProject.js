var baseUrl = 'http://3.15.139.27:5005';
var state="off";
var inthandle;

var first;
var last;
var email;
var username;
var password;

var artwork;
var emotion;


// Action if the user presses the sign up button
document.addEventListener("DOMContentLoaded", () => {
  document.getElementById('signUp-btn').addEventListener("click", (e) => {
    registerUser();
  });
});

// Action if the user presses the log in button
document.addEventListener("DOMContentLoaded", () => {
  document.getElementById('logIn-btn').addEventListener("click", (e) => {
    logIn();
  });
});

// Action if the user presses the submit response button
document.addEventListener("DOMContentLoaded", () => {
  document.getElementById('submitResponse-btn').addEventListener("click", (e) => {
    submitResponse();
  });
});


// Called when the user presses the sign up button
function registerUser() {
	console.log("registering user");

  	first = encodeURIComponent(document.getElementById('signUp-first').value);
  	last = encodeURIComponent(document.getElementById('signUp-last').value);
  	email = encodeURIComponent(document.getElementById('signUp-email').value);
  	username = encodeURIComponent(document.getElementById('signUp-username').value);
  	password = encodeURIComponent(document.getElementById('signUp-password').value);
  	fetch(baseUrl+'/artProject/register/'+first+'/'+last+'/'+email+'/'+username+'/'+password, {
    	method: 'get'
  	})
    .then (response => response.json() )
    .then (data =>completeRegistration(data))
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

function completeRegistration(results) {
	var status = results['status'];
	if (status != "success") {
		alert("Registration failed!");
		return;
	}else{
		alert("Registration Successful!");
	}
	var user = results['status'];
	console.log("Registered:"+user);
}


// Called when the user presses the sign up button
function logIn() {
	console.log("logging in user")
	
	username = document.getElementById('usernameLogIn').value;
	password = document.getElementById('passwordLogIn').value;
	fetch(baseUrl+'/artProject/logIn/'+username+'/'+password, {
        method: 'get'
    })
    .then (response => response.json() )
    .then (data =>completeLogIn(data))
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

function completeLogIn(results) {
	var status = results['status'];
	if (status != "success") {
		alert("Log in failed!");
		return;
	}else{
		alert("Log in Successful!");
	}
	var user = results['status'];
	console.log("Logged in:"+user);
}


// Called when a user presses the submit response button
function submitResponse() {
	console.log("Submitting response");

  	artwork = encodeURIComponent(document.getElementById('artwork').value);
  	emotion = encodeURIComponent(document.getElementById('response').value);

  	fetch(baseUrl+'/artProject/submit/'+artwork+'/'+emotion, {
    	method: 'get'
  	})
    .then (response => response.json() )
    .then (data =>completeResponse(data))
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

function completeResponse(results) {
	var status = results['status'];
	if (status != "success") {
		alert("Response failed to submit!");
		return;
	}else{
		alert("Response successfully submitted!");
	}
}






