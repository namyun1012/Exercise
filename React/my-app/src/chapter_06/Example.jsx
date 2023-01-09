// state는 React Componnet의 변경 가능한 데이터를 의미함

class LikeButton extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            liked : false
        };
    }
}