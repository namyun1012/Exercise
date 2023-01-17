const quotes = [
    {
        quote: "Hello World!",
        author: "me",
    },

    {
        quote: "Knowledge is power.",
        author: "Sir Francis Bacon",
    },

    {
        quote: "Life is like a box of chocolates. You never know what you're gonna get.",
        author: "Forrest Gump (character)",
    },
    
    {
        quote: "걍 살자",
        author: "나",
    },

];

const quote = document.querySelector("#quote span:first-child");
const author = document.querySelector("#quote span:last-child");

const todaysQuote = quotes[Math.floor(Math.random() * quotes.length)];

quote.innerText = todaysQuote.quote;
author.innerText = todaysQuote.author;