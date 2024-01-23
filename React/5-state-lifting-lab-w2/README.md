# 5-state-lifting-lab-w2

- This is a lab exercise of coursera link - https://www.coursera.org/learn/react-basics/ungradedLab/cSfrS/managing-state-in-react

### Ques. What is State Lifting?

- passing of state from child to parent
- Note: state can only be passed from parent to child
- so we used state in parent clas itself
- bard ->

  State lifting is a common technique in React development for managing the state of UI components. It involves moving state data from child components up to their nearest common ancestor component. This makes the state data accessible to all the child components that need it, and ensures that it stays consistent across the component hierarchy.

  Here's an analogy to help understand state lifting: Imagine you have a family of three people living in a house. Each person (component) has their own set of keys (state) to unlock different doors (functions) in the house. This can be inefficient and lead to confusion, as someone might lock a door that others need to use.

  State lifting is like moving the house keys to a central location, like a key holder on the wall. Now, everyone has access to the same set of keys, and they can easily unlock any door they need. This makes things more organized and efficient.
