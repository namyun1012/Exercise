import React, {useState} from "react";

function Toggle(props) {
    const [isToggleon, setIsToggleOn] = useState(true);

    // 함수 안에 함수로 정의
    function handleClick() {
        setIsToggleOn((isToggleon) => !isToggleon);
    }

    /*  화살표 함수를 이용해서 정의
    const handleClick = () => {
        setIsToggleOn((isToggleon) => !isToggleon);
    }
    */
    return (
        <button onClick={handleClick}>
            {isToggleon ? "켜짐" : "꺼짐"};
        </button>
    );
}

export default Toggle