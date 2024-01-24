import React, { useContext } from "react";
import MyContext from "./context/MyContext";

export default function MyComponent() {
  const contextValue = useContext(MyContext);

  return (
    <div>
      <h3>useContext</h3>
      {contextValue}
    </div>
  );
}
