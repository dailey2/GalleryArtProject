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

// Adds an event listener for the sign up button
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

// Adds an event listener for the log in button
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

// Adds an event listener for the submit response button
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

// Adds an event listener for the Sign Up link in the navbar
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

// Adds an event listener for the Log In link in the navbar
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

// Reports errors in registering users or returns success status
function completeRegistration(results) {
    var status = results['status'];
    if (status != "success") {
        var errorMessage = "Registration failed:\n";
        if (results['username_error']) errorMessage += results['username_error'] + "\n";
        if (results['email_error']) errorMessage += results['email_error'] + "\n";
        if (results['password_error']) errorMessage += results['password_error'] + "\n";
        alert(errorMessage.trim());
        return;
    } else {
        alert("Registration Successful! Please log in!");
    }
    var user = results['status'];
    console.log("Registered:" + user);
}


// Called when the user presses the log in button
function logIn() {
	console.log("logging in user")
	
	username = document.getElementById('logIn-username').value;
	password = document.getElementById('logIn-password').value;
	fetch(baseUrl+'/artProject/logIn/'+username+'/'+password, {
        method: 'get'
    })
    .then (response => response.json() )
    .then (data =>completeLogIn(data, username))
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

// Reports errors in logging in users or returns success status
function completeLogIn(results, username) {
	var status = results['status'];
	if (status != "success") {
		alert("Login failed. Please ensure you have an account and that your username and password are correct.");
		return;
	}else{
		alert("Log in Successful!");
	}
	var user = results['status'];
	console.log("Logged in:"+ username);
	
	localStorage.setItem('loggedIn', true);
    localStorage.setItem('username', username);
    
	loggedIn(username);
}

// Changes navbar layout when user logs in 
function loggedIn(username) {
    document.querySelector('.navbar-brand').innerText = 'Gallery Art Project - Welcome ' + username;
    
    document.getElementById('navbar-signUp').style.display = 'none';
    document.getElementById('navbar-logIn').style.display = 'none';
    
    var logoutButton = document.createElement('a');
    logoutButton.href = "#";
    logoutButton.className = "nav-link";
    logoutButton.id = "navbar-logout";
    logoutButton.innerText = "Logout";
    logoutButton.onclick = function() {
        logOut();
    };
    
    document.querySelector('.navbar-nav').appendChild(logoutButton);
}

// Function to keep the navbar updated when logged in
function updateNavbar() {
    if (localStorage.getItem('loggedIn') === 'true') {
        const username = localStorage.getItem('username');
        loggedIn(username);
    }
}

// Logs out user
function logOut() {
    localStorage.removeItem('loggedIn');
    localStorage.removeItem('username');
    location.reload();
}

// Call updateNavbar() on page load
document.addEventListener('DOMContentLoaded', updateNavbar);


// Called when a user presses the submit response button
function submitResponse() {
	
	if (localStorage.getItem('loggedIn') !== 'true') {
        alert("Please log in to submit a response.");
        return;
    }
    
	console.log("Submitting response");

  	artwork = document.getElementById('artwork').getAttribute('data-value');
  	emotion = document.querySelector('input[name="emotion"]:checked').value;

  	fetch(baseUrl+'/artProject/submit/'+artwork+'/'+emotion, {
    	method: 'get'
  	})
    .then (response => response.json() )
    .then (data => completeResponse(data))
    .catch(error => {
        {alert("Error: Something went wrong:"+error);}
    })
}

// Returns success message if response is submitted
function completeResponse(results) {
	alert("Response successfully submitted!");
}


