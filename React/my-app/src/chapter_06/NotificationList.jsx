import React from "react";
import Notification from "./Notification";

const reservedNotifications = [
    {
        id : 1,
        message: "안녕하세요 오늘 일정을 알려드립니다.",
    },

    {
        id : 2,
        message: "점심 식사 시간 입니다.",

    },

    {
        id : 3,
        message : "이제 곧 미팅이 시작됩니다.",
    },
    
];

var timer;

class NotificationList extends React.Component {
    constructor(props) {
        super(props);
    
        
        // 초기 생성될 때 state는 비어있음
        this.state = {
            notifications : [],
        };

    }

    componentDidMount() {
        const {notifications} = this.state;
        timer = setInterval(() => {
            if(notifications.length < reservedNotifications.length) {
                const index = notifications.length;
                notifications.push(reservedNotifications[index]);
                // state 변경
                this.setState({
                    notifications : notifications,
                });
            } else {
                // 반복 중단
                // notifications 를 비움
                this.setState({
                    notifications : [],
                });
                clearInterval(timer);
            }
        }, 1000);
    }

    componentWillUnmount() {
        if(timer) {
            clearInterval(timer);
        }
    }
    // 웹에 나타낼 때
    render() {
        return (
            <div>
                {this.state.notifications.map((notification) => {
                    return <Notification 
                    key = {notification.id}
                    id = {notification.id}    
                    message = {notification.message} />;
                })}
            </div>
        );
    }
}


export default NotificationList