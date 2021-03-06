import React, { useState } from "react";
import Calendar from "react-calendar";
import "../css/Journey.css";
import GetData from "./GetData";

function Journey() {
  const [date, setDate] = useState(new Date());
  const [check, setCheck] = useState([]);

  const updateSetCheck = (value) => {
    if (!check.includes(value)) {
      console.log(!check.includes(value));
      setCheck([...check, value]);
    }
    console.log(check[check.length - 1]);
  };
  // yyyy-mm-dd
  return (
    <>
      <div className="Journey">
        <h1 className="text-center">Your Journey</h1>
        <div className="calendar-container">
          <Calendar
            onChange={setDate}
            value={date}
            onClickDay={updateSetCheck(date.toISOString().split("T")[0])}
          />
        </div>
        <div className="Journey__Motivation">
          <p>Day {check.length} of your journey! Keep going!</p>
        </div>
      </div>
      <div className="Journey__Progress">
        <p>Your Progress</p>
      </div>
      <div className="Journey__getRequest">
        <GetData date={check[check.length - 1]} />
      </div>
    </>
  );
}

export default Journey;
