const toDoForm = document.getElementById("todo-form");
const toDoList = document.getElementById("todo-list");
const toDoInput = toDoForm.querySelector("input");

const TODOS_KEY = "toDos"

const savedToDos = localStorage.getItem(TODOS_KEY);

let toDos = [];

function saveToDos() {
    localStorage.setItem("toDos", JSON.stringify(toDos));
}


function deleteToDo(event) {
    const li = event.target.parentElement;
    toDos = toDos.filter(toDo => toDo.id !== parseInt(li.id));
    li.remove();
    saveToDos();
}


function paintTodo(newTodoObj) {
    const li = document.createElement("li");
    const span = document.createElement("span");
    const button = document.createElement("button");
    
    button.innerText ="❌";
    button.addEventListener("click", deleteToDo);
    
    li.appendChild(span);
    li.appendChild(button);
    toDoList.appendChild(li);

    li.id = newTodoObj.id;
    span.innerText = newTodoObj.text;
    
    
}

function handleToDoSubmit(event) {
    event.preventDefault();
    const newTodo = toDoInput.value;
    toDoInput.value = "";
    
    const newTodoObj = {
        text:newTodo,
        id : Date.now(),
    };

    toDos.push(newTodoObj);
    paintTodo(newTodoObj);
    saveToDos();
}

toDoForm.addEventListener("submit", handleToDoSubmit);

function sayHello(item) {
    console.log(item);
}


if(savedToDos != null) {
    const parsedToDos = JSON.parse(savedToDos);
    toDos = parsedToDos;
    parsedToDos.forEach(paintTodo);

}

// delete  할 때 사용
function Filter() {

}

[1,2,3,4].filter(Filter)