import React, { useState } from "react";
import api from "../api";
import styled from "styled-components";

const Title = styled.h1`
  font-size: 1.5em;
  text-align: center;
`;

const Wrapper = styled.div`
  margin: 0 30px;
`;

const Label = styled.label`
  margin: 5px;
`;

const InputText = styled.input`
  margin: 5px;
`;

const Button = styled.button`
  margin: 15px 15px 15px 5px;
`;

const CancelButton = styled.a`
  margin: 15px 15px 15px 5px;
`;

const MoviesInsert = () => {
  const [name, setName] = useState("");
  const [rating, setRating] = useState("");
  const [time, setTime] = useState("");

  const handleChangeInputName = (event) => {
    setName(event.target.value);
  };

  const handleChangeInputRating = (event) => {
    setRating(event.target.value);
  };

  const handleChangeInputTime = (event) => {
    setTime(event.target.value);
  };

  const handleIncludeMovie = async () => {
    const arrayTime = time.split("/");
    const payload = { name, rating, time: arrayTime };

    try {
      await api.insertMovie(payload);
      window.alert(`Movie inserted successfully`);
      setName("");
      setRating("");
      setTime("");
    } catch (error) {
      console.error("Error inserting movie:", error);
      window.alert("Error inserting movie");
    }
  };

  return (
    <Wrapper>
      <Title>Create Movie</Title>

      <Label>Name: </Label>
      <InputText type="text" value={name} onChange={handleChangeInputName} />

      <Label>Rating: </Label>
      <InputText
        type="number"
        step="0.1"
        min="0"
        max="10"
        value={rating}
        onChange={handleChangeInputRating}
      />

      <Label>Time: </Label>
      <InputText type="text" value={time} onChange={handleChangeInputTime} />

      <Button onClick={handleIncludeMovie}>Add Movie</Button>
      <CancelButton href={"/movies/list"}>Cancel</CancelButton>
    </Wrapper>
  );
};

export default MoviesInsert;
