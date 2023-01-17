const images = [
    "img1.jpeg",
    "img2.jpeg",
    "img3.jpeg",
    "img4.jpeg",
];


const chosenImage = images[Math.floor(Math.random() * images.length)];

const bgImage = document.createElement("img");

bgImage.src = `img/${chosenImage}`;

document.body.appendChild(bgImage);