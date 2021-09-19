import Button from "@mui/material/Button";
import React from "react";
import "../css/Home.css";
import Explanation from "./Explanation";
import Overview from "./Overview";

function Home() {
  return (
    <>
      <div className="Home__title">
        <p>
          Welcome to our 2021 Hack the North Project, it's called Jacked the
          North!
        </p>
      </div>
      <div className="Home__explanation">
        <Overview />
      </div>
      <div className="Home__title">
        <p>How does the Form Checker work?</p>
      </div>
      <div className="Home__explanation">
        <Explanation />
      </div>
      <br />
      <Button
        href="https://photos.app.goo.gl/D3dHuqg68hv6GRoA9"
        size="large"
        color="primary"
        variant="outline"
        target="_blank"
      >
        demo
      </Button>
    </>
  );
}
export default Home;
