import React, { useEffect, useState } from "react";
import axios from "axios";

function GetData({ date }) {
  // At the beginning, posts is an empty array
  const [posts, setPosts] = useState([]);

  // Define the function that fetches the data from API
  const fetchData = async () => {
    const { data } = await axios.get(
      `https://form-check-hixwog3m7q-uc.a.run.app/${date}`
    );
    setPosts(data);
  };

  // Trigger the fetchData after the initial render by using the useEffect hook
  useEffect(() => {
    fetchData();
  }, []);

  let response = {
    totalPushUps: 4,
    totalGoodPushUps: 2,
    totalGoodPushUpsData: {
      Angle: 4,
    },
    totalBadPushUps: 2,
    totalBadPushUpsData: {
      Angle: 4,
    },
  };
  return (
    <div className="wrapper">
      {posts.length > 0 ? (
        console.log(posts)
      ) : (
        <p className="loading">Loading... </p>
      )}
    </div>
  );
}

export default GetData;
