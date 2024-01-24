# 6-multi-pages-lank

in this exapmle I have seen how to link multiple pages in react.
Yes, react is still a SPA (single page application).

In this exaple I have used `react-route-dom` packagefor linking multiple pages.

Notice in App.js you will de `Routes` and `Route` they work as a link to url extentions.
Also in Nav.js I have used `Link` tage which has same work as `<a>` in html

### Overview

This example illustrates how to implement multi-page navigation in a React application using the react-router-dom package. Despite React often being associated with Single Page Applications (SPAs), this guide demonstrates how to create a multi-page experience.

### Implementation

1. App.js:
   In the App.js file, use the Routes and Route components to define navigation paths for different pages within your application.

```
import { Routes, Route } from 'react-router-dom';

function App() {
  return (
    <div>
      <Routes>
        <Route path="/" element={<HomePage />} />
        <Route path="/about" element={<AboutPage />} />
        {/* Add more Route components for additional pages */}
      </Routes>
    </div>
  );
}
```

2. Nav.js:
   In the Nav.js file, utilize the Link component to create navigation links, similar to the <a> tag in HTML.

```
import { Link } from 'react-router-dom';

function Nav() {
  return (
    <nav>
      <ul>
        <li>
          <Link to="/">Home</Link>
        </li>
        <li>
          <Link to="/about">About</Link>
        </li>
        {/* Add more Link components for additional pages */}
      </ul>
    </nav>
  );
}
```

### Usage:

#### Install react-router-dom:

`npm install react-router-dom`

Integrate the Routes and Route components in your `App.js` file.

Use the `Link` component in your navigation components (e.g., Nav.js) to create links between different pages.

Customize the routes and links based on your application's structure.
