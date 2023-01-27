import {
    BrowserRouter as Router,
    Route,
    Routes,
    Link,
} from "react-router-dom";
import Coin from "./routes/Coin";
import Detail from "./routes/Detail";
import Home from "./routes/Home";


function App() {
    return (
        <Router>
            <Routes>
                <Route path="/hello" element={
                    <h1>hello</h1>
                }/>
                <Route path="/movie/:id" element = {<Detail />}/>
                <Route path="/" element= {<Home />}/>
                <Route path="/coin" element = {<Coin />}/>
            </Routes>
        </Router>
    );
}

export default App;