//#region import

import InputComponent from "./InputComponent";
import "./App.css";
import TextInputWithFocusButton from "./TextInputWithFocusButton";
import MyComponent from "./MyComponent";
import Counter from "./Counter";
import ShowDate from "./ShowDate";

//#endregion

//#region App

function App() {
  return (
    <div className="App">
      <div className="App-header">
        <h1>Hooks</h1>
      </div>
      <ShowDate />
      <div className="cards-container">
        <div className="card">
          <InputComponent />
        </div>
        <div className="card">
          <Counter />
        </div>
        <div className="card">
          <TextInputWithFocusButton />
        </div>
        <div className="card">
          <MyComponent />
        </div>
      </div>
    </div>
  );
}

//#endregion

export default App;
