import React, { useState, useEffect } from "react";

export default function ShowDate() {
  const [date, setDate] = useState(new Date());

  useEffect(() => {
    // Set up an interval to update the date every second (adjust as needed)
    const intervalId = setInterval(() => {
      setDate(new Date());
    }, 1000);

    // Clean up the interval when the component is unmounted
    return () => clearInterval(intervalId);
  }, []); // Empty dependency array ensures the effect runs only once on mount

  return (
    <>
      <h3 className="App-link">Current DateTime: {date.toLocaleString()} </h3>
    </>
  );
}
