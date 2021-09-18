import { Route } from "react-router-dom";
import Header from "./components/Header";
import Home from "./components/Home";
import Journey from "./components/Journey";
import Exercises from "./components/Exercises";
import "./App.css";
import NavigationBar from "./components/NavBar";

const App = () => {
  return (
    <>
      <NavigationBar />
      <div className="App-intro">
        <Route path="/" component={Home} />
        <Route path="/journey" component={Journey} />
        <Route path="/exercises" component={Exercises} />
      </div>
    </>
  );
};

export default App;
