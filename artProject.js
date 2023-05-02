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


document.addEventListener("DOMContentLoaded", () => {
  const signUpButton = document.getElementById('signUp-btn');
  if (signUpButton) {
    signUpButton.addEventListener("click", (e) => {
      registerUser();
    });
  } else {
    console.warn("signUp-btn element not found in the DOM");
  }
});

document.addEventListener("DOMContentLoaded", () => {
  const logInButton = document.getElementById('logIn-btn');
  if (logInButton) {
    logInButton.addEventListener("click", (e) => {
      logIn();
    });
  } else {
    console.warn("logIn-btn element not found in the DOM");
  }
});


// Action if the user presses the submit response button
document.addEventListener("DOMContentLoaded", () => {
  const submitResponseButton = document.getElementById('submitResponse-btn');
  if (submitResponseButton) {
    submitResponseButton.addEventListener("click", (e) => {
      submitResponse();
    });
  } else {
    console.warn("submitResponse-btn element not found in the DOM");
  }
});

// Action if the user clicks the Sign Up link in the navbar
document.addEventListener("DOMContentLoaded", () => {
  const navbarSignUpLink = document.getElementById('navbar-signUp');
  if (navbarSignUpLink) {
    navbarSignUpLink.addEventListener("click", (e) => {
      e.preventDefault();
      const signUpModal = new bootstrap.Modal(document.getElementById('signUp'));
      signUpModal.show();
    });
  } else {
    console.warn("navbar-signUp element not found in the DOM");
  }
});

// Action if the user clicks the Log In link in the navbar
document.addEventListener("DOMContentLoaded", () => {
  const navbarLogInLink = document.getElementById('navbar-logIn');
  if (navbarLogInLink) {
    navbarLogInLink.addEventListener("click", (e) => {
      e.preventDefault();
      const logInModal = new bootstrap.Modal(document.getElementById('logIn'));
      logInModal.show();
    });
  } else {
    console.warn("navbar-logIn element not found in the DOM");
  }
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

  	artwork = document.getElementById('artwork').getAttribute('data-value');
  	emotion = document.querySelector('input[name="emotion"]:checked').value;

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






