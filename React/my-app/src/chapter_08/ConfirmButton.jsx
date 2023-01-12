import React, {useState} from "react";

function ConfirmButton(props) {
    // useState 를 사용하기 위해서
    const [isConfirmed, setIsConfirmed] = useState(false);

    const handleConfirm = () => {
        setIsConfirmed((prevIsconfirmed) => !prevIsconfirmed);
    };

    return (
        <button onClick={handleConfirm} disabled={isConfirmed}>
            {isConfirmed ? "확인됨" : "확인하기"}
        </button>
    )
}

export default ConfirmButton;