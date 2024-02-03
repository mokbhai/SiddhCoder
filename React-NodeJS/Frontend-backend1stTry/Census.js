import React, { Component } from "react";

class Census extends Component {
  constructor(props) {
    super(props);
    this.state = {
      error: null,
      isLoaded: false,
      words: [],
    };
  }
  componentDidMount() {
    fetch("URL")
      .then((res) => res.json())
      .then(
        (data) => {
          this.setState({
            isLoaded: true,
            words: data,
          });
        },

        (error) => {
          this.setState({
            isLoaded: true,
            error,
          });
        }
      );
  }

  render() {
    const { error, isLoaded, words } = this.state;
    if (error) {
      return <div>Error: {error.message}</div>;
    } else if (!isLoaded) {
      return <div>Loading...</div>;
    } else {
      return (
        <ul>
          {words.map((s) => (
            <li></li>
          ))}
        </ul>
      );
    }
  }
}
export default Census;
