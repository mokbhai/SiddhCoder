import Card from "./Card";
import "./App.css";

function App() {
  return (
    <div className="app">
      <h1>Task: Add three Card elements</h1>
      <Card h2="First card's h2" h3="First card's h3" />
      <Card h2="Second card's h2" h3="Second card's h3" />
      <Card h2="Third card's h2" h3="Third card's h3" />
    </div>
  );
}

export default App;
