

function WelCome(props) {
    return <h1>안녕 {props.name}</h1>;
}

class Welcome extends React.Component {
    render() {
        return <h1>안녕 {this.props.name}</h1>;
    }
}