const toDoForm = document.getElementById("todo-form");
const toDoList = document.getElementById("todo-list");
const toDoInput = toDoForm.querySelector("input");

const TODOS_KEY = "toDos"

const savedToDos = localStorage.getItem(TODOS_KEY);

const toDos = [];

function saveToDos() {
    localStorage.setItem("toDos", JSON.stringify(toDos));
}


function deleteToDo(event) {
    const li = event.target.parentElement;
    li.remove();    
}


function paintTodo(newTodo) {
    const li = document.createElement("li");
    const span = document.createElement("span");
    const button = document.createElement("button");
    button.innerText ="❌";
    button.addEventListener("click", deleteToDo);
    li.appendChild(span);
    li.appendChild(button);
    span.innerText = newTodo;
    toDoList.appendChild(li);
}

function handleToDoSubmit(event) {
    event.preventDefault();
    const newTodo = toDoInput.value;
    toDoInput.value = "";
    toDos.push(newTodo);
    paintTodo(newTodo);
    saveToDos();
}

toDoForm.addEventListener("submit", handleToDoSubmit);

function sayHello(item) {
    console.log(item);
}

if(saveToDos != null) {
    const parsedToDos = JSON.parse(savedToDos);
    parsedToDos.forEach(sayHello);

}