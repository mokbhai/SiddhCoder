import fizzbuzz from "./fizzbuzz";
import "./App.css";

function App() {
  const result = fizzbuzz(30);
  return <div className="App">{result}</div>;
}

export default App;
