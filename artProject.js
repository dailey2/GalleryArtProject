var baseUrl = 'http://3.15.139.27:5005';
var state="off";
var inthandle;

var first;
var last;
var email;
var username;
var password;


// Action if the user presses the sign up button
document.getElementById('signUp-btn').addEventListener("click", (e) => {
	register();
})

// Action if the user presses the log in button
document.getElementById('logIn-btn').addEventListener("click", (e) => {
	logIn();
})


// Called when the user presses the sign up button
function register() {
	console.log("registering user")
	
	first = document.getElementById('orangeForm-first').value;
	last = document.getElementById('orangeForm-last').value;
	email = document.getElementById('orangeForm-email').value;
	username = document.getElementById('orangeForm-username').value;
	password = document.getElementById('orangeForm-password').value;
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
function register() {
	console.log("logging in user")
	
	username = document.getElementById('orangeForm-usernameLogIn').value;
	password = document.getElementById('orangeForm-passwordLogIn').value;
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

