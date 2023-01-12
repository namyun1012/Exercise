import React from "react";

const numbers = [1,2,3,4,5];

const doubled = numbers.map((number) => number  * 2);

const listItems = numbers.map((number) => 
    <li>{number}</li>
    );


function NumberList(props) {
    const {numbers} = props;

    const listItems = numbers.map((number) =>
        <li>{number}</li>
    );

    return (
        <ul>{listItems}</ul>
    );
}
