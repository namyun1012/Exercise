import React from "react";
import { useState } from "react";

function Reservation(props) {
    const [haveBreakfast, setHaveBreakfast] = useState(true);
    const [numberOfGuest, setNumberOfGuest] = useState(2);

    const handleSubmit = (event) => {
        alert(`아침 식사 여부 : ${haveBreakfast}, 방문 객 수: ${numberOfGuest}`);
        event.preventDefault();
    }

    return (
        <form onSubmit={handleSubmit}>
            <label>
                아침 식사 여부:
                <input 
                    type="checkbox"
                    checked = {haveBreakfast}
                    onChange = {(event) => {
                        setHaveBreakfast(event.target.checked);
                    }} />
            </label>
            <br />
            <label>
                방문 객 수:
                <input 
                    type="number"
                    value = {numberOfGuest}
                    onChange = {(event) => {
                        setNumberOfGuest(event.target.value);
                    }}
                />
            </label>
            <button type="submit">제출</button>
        </form>
    );

}

export default Reservation;