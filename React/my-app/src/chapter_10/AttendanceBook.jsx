import React from "react";

const stuents = [
    {
        id : 1,
        name : "Inje",
    },

    {
        id : 2,
        name : "Steve",
    },

    {
        id : 3,
        name : "Bill",
    },

    {
        id : 4,
        name : "Jeft",
    },

];

function AttendanceBook(props) {
    return (
        <ul>
            {stuents.map((stuent) => {
                return <li key={stuent.id}>{stuent.name}</li>;
            })}
            
        </ul>
    );
}

export default AttendanceBook;