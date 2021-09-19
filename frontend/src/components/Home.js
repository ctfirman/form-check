import React from "react";
import "../css/Home.css";
import Overview from "./Overview";
import ReactPlayer from "react-player";
import Title from "./Title";

const title1 =
  "Welcome to our 2021 Hack the North Project, it's called Jacked the North!";
const title2 = "How does the Form Checker work?";
const title3 = "What's next?";
const msg1 =
  "We wanted to make sure you could achieve your fitness goals, and GET JACKED, so we created a tool to let you know that you're doing any exercise properly as well as activating the right muscle group.";
const msg2 =
  "We used an ESP 32 microcontroller to transmit three dimensional coordinates to a live Flask app hosted by the Google Cloud Platform. The Flask appication can POST data to the Firebase real time database, where data is stored in a collection of exercises. Then this React application queries the realtime database and retrieves the data in order to present streamlined analytics so that you can achieve your fitness goals!";
const msg3 = `Check out the My Journey page to start your fitness journey!`;

function Home() {
  return (
    <>
      <div className="Home__title">
        <Title title={title1} />
      </div>
      <div className="Home__explanation">
        <Overview message={msg1} />
      </div>
      <div className="Home__title">
        <Title title={title2} />
      </div>
      <div className="Home__explanation">
        <Overview message={msg2} />
      </div>
      <div className="Home__video">
        <ReactPlayer url="https://www.youtube.com/watch?v=ukamStnRXHc" />
      </div>
      <div className="Home__title">
        <Title title={title3} />
      </div>
      <div className="Home__explanation">
        <Overview message={msg3} />
      </div>
    </>
  );
}
export default Home;
