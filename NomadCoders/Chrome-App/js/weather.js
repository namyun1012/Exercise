const API_KEY = "Git 에 올릴 때";


function onGeoOk(position) {
    const lat = position.coords.latitude;
    const lon = position.coords.longitude;
    console.log("You live in", lat, lon);
    const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${API_KEY}&units=metric`;
    //JavaScript가 url를 부름
    fetch(url)
    .then(response => response.json())
    .then(data => {
        const weatherContainer = document.getElementById("weather");
        const city = document.querySelector("#weather span:first-child");
        const weather = document.querySelector("#weather span:last-child");
        const name = data.name;
        city.innerText = `오늘의 날씨 : ${name}`;
        weather.innerText = `${data.weather[0].main} / ${data.main.temp}`;
    });

}

function onGeoError() {
    alert("Can't find you.")
}

// 성공시 onGeoOk 를 실행
navigator.geolocation.getCurrentPosition(onGeoOk, onGeoError);


