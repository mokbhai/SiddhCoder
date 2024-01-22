# Hooks

#### What is a hook in react?

    In React, a "hook" refers to a special kind of function that allows you to use state and other React features in functional components. Hooks were introduced in React version 16.8 to provide a way to use stateful logic in functional components, which were previously limited to using only props and could not manage local component state.

In this we saw some basic uses of hook `useState` and `useRef`

### `useState` example `./src/InputComponent.js`

    This hook allows functional components to have local state. It returns an array with two elements: the current state value and a function that lets you update it.

### `useRef` example `./src/TextInputWithFocusButton.js`

    This React Hook that provides a way to create mutable objects that persist across renders. It's commonly used to access and interact with the DOM directly, manage focus, and store mutable values that don't trigger a re-render when they change.

### `useEffect` example `./src/ShowDate`

    This hook is used for side effects in functional components. It allows you to perform actions in your component, such as data fetching, subscriptions, or manually changing the DOM, after the component has been rendered.

### `useContext` example `./src/MyComponent.js`

    This is used to subscribe to React context without introducing a nesting component. It allows a functional component to consume values from a context provider.

### `useReducer` example `./src/Counter.js`

    useReducer is an alternative to useState that is more suitable for managing complex state logic. It is often preferable when the next state depends on the previous one.

### `useCallback`

    useCallback is used to memoize functions, preventing them from being recreated on each render. This can be useful to optimize performance in scenarios where functions are passed down as props to child components.

    `
    import React, { useCallback } from 'react';

    function MyComponent({ onClick }) {
    const handleClick = useCallback(() => {
        // do something
        onClick();
    }, [onClick]);

    return <button onClick={handleClick}>Click me</button>;
    }
    `

### `useMemo`

    useMemo is used to memoize the result of a computation, preventing it from being recomputed on every render. It is useful for performance optimization when dealing with expensive calculations.
    `
    import React, { useMemo } from 'react';

    function ExpensiveComponent({ data }) {
    const result = useMemo(() => {
        // Some expensive computation based on data
        return data.map(item => item * 2);
    }, [data]);

    return <div>{result}</div>;
    }
    `

### `useImperativeHandle`

    useImperativeHandle customizes the instance value that is exposed when using React.forwardRef. It is often used to hide certain properties or methods of a component when it is used as a forward ref.

    `
    import React, { useRef, useImperativeHandle } from 'react';

    const MyInput = React.forwardRef((props, ref) => {
    const inputRef = useRef();

    useImperativeHandle(ref, () => ({
        focus: () => {
        inputRef.current.focus();
        },
        // Other methods or properties to expose
    }));

    return <input ref={inputRef} />;
    });
    `

These are some of the commonly used React hooks. There are additional hooks like useLayoutEffect, useDebugValue, and custom hooks that you can create to encapsulate and reuse stateful logic in your components. Understanding these hooks and when to use them can greatly enhance your ability to build functional and efficient React components.
