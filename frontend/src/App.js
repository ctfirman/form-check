import { Route } from "react-router-dom";
import Home from "./components/Home";
import Journey from "./components/Journey";
import Exercises from "./components/Exercises";
import "./css/App.css";
import NavigationBar from "./components/NavBar";
import Pushups from "./components/Pushups";

const App = () => {
  return (
    <>
      <NavigationBar />
      <div className="App-intro">
        <Route path="/home" component={Home} />
        <Route path="/journey" component={Journey} />
        <Route path="/exercises" component={Exercises} />
        <Route path="/demo" component={Pushups} />

      </div>
    </>
  );
};

export default App;
