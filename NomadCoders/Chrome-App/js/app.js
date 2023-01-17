const loginForm = document.querySelector("#login-form");
const loginInput = loginForm.querySelector("input");
const loginButton = loginForm.querySelector("button");
const greeting = document.querySelector("#greeting");

const link = document.querySelector("a");
const HIDDEN_CLASS = "hidden";
const USERNAME_KEY = "username";

const savedUsername = localStorage.getItem(USERNAME_KEY);


function onLoginSubmit(tomato) {
    
    // submit 할 때의 기본으로 작동되는 것을 막음
    tomato.preventDefault();
    const userName = loginInput.value;
    localStorage.setItem(USERNAME_KEY, userName);
    loginForm.classList.add(HIDDEN_CLASS);
    paintGreetings(userName);
}

function handleLinkClick(event) {
    event.preventDefault();
    console.dir(event)
    alert("clicked!");
}

function paintGreetings(username) {
    greeting.innerText = `Hello ${username}`;
    greeting.classList.remove(HIDDEN_CLASS);
}

if(savedUsername == null) {
    loginForm.classList.remove(HIDDEN_CLASS);
    loginForm.addEventListener("submit", onLoginSubmit);
} else {
    paintGreetings(savedUsername);
}