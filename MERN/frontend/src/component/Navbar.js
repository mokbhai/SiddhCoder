import { Link } from "react-router-dom";
const Navbar = () => {
  return (
    <header>
      <div className="container">
        <Link to="/">
          <h1>WorkoutBuddy</h1>
        </Link>
        <Link to="/signup">
          <h1>Signup</h1>
        </Link>
        <Link to="/login">
          <h1>Login</h1>
        </Link>
      </div>
    </header>
  );
};

export default Navbar;
