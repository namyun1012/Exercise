import React, {useState, useEffect} from "react";

function Counter(props) {
    const [count, setCount] = useState(0);
    // 화살표 함수 함수의 약식이라고 보면 될 듯 function을 대체함
    useEffect(() => {
        document.title = `총 ${count}번 클릭했습니다.`;
    });

    return (
        <div>
            <p>총 {count}번 클릭했습니다.</p>
            
            <button onClick={()=> setCount(count + 1)}>
                클릭
            </button>
        </div>
    );
}

export default Counter;