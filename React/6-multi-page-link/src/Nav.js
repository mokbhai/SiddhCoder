import { Link } from "react-router-dom";

function Nav(props) {
    return (
        <div>
        <nav>
            <Link to="/" className="nav-item">Homepage</Link>
            <Link to="/about" className="nav-item">About Little Lemon</Link>
            <Link to="/contact" className="nav-item">Contact</Link>
            </nav>
        </div>
    );
}

export default Nav;