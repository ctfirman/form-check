import React from "react";
import Pullups from "./Pullups";
import Pushups from "./Pushups";
import Squats from "./Squats";
import "../css/Exercises.css";
import { Button } from "@material-ui/core";
import { Link } from "react-router-dom";

function Exercises() {
  return (
    <>
      <div className="Exercises__Background">
        <div className="Exercises__Names">
          <Pushups />
        </div>
        <div className="Exercises__Names">More Coming soon...</div>
      </div>
    </>
  );
}

export default Exercises;
