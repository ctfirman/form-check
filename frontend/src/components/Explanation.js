import React from "react";

function Explanation() {
  return (
    <div>
      We used an ESP 32 microcontroller to transmit three dimensional
      coordinates to a live Flask app hosted by the Google Cloud Platform. The
      Flask appication can POST data to the Firebase real time database, where
      data is stored in a collection of exercises. Then this React application
      queries the realtime database and retrieves the data in order to present
      streamlined analytics so that you can achieve your fitness goals!
    </div>
  );
}

export default Explanation;
