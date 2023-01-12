import { useState } from "react";

function Mailbox(props) {
    const unreadMessage = props.unreadMessage;

    // unreadMessage.length의 값에 따라 아래의 부분이 렌더링이 되거나 혹은 안됨
    return (
        <div>
            <h1>안녕하세요!</h1>
            {unreadMessage.length > 0 &&
                <h2>
                    현재 {unreadMessage.length} 개의 읽지 않은 메시지가 있습니다.    
                </h2>
            }
        </div>

    );

}

function Counter (props) {
    const count = 0;

    return (
        <div>
            {count && <h1> 현재 카운트 : {count}</h1>}
        </div>
    )
}

function WaringBanner(props) {
    if(!props.warning) {
        return null;
    }

    return (
        <div>경고!</div>
    );
}

function MainPage(props) {
    const [showWarning, setShowwarning] = useState(false);

    const handleToggleClick = () => {
        setShowwarning(prevShowWarning => !prevShowWarning);
    }

    return (
        <div>
            <WaringBanner waring = {showWarning} />
            <button onClick={handleToggleClick}>
                {showWarning ? '감추기' : '보이기'}
            </button>
        </div>
    )
}


