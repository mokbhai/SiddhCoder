import React, { useState, useEffect } from "react";
import { useParams } from "react-router-dom";
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

const MoviesUpdate = () => {
  const { id } = useParams();
  const [name, setName] = useState("");
  const [rating, setRating] = useState("");
  const [time, setTime] = useState("");

  useEffect(() => {
    const fetchMovie = async () => {
      try {
        const response = await api.getMovieById(id);
        const movieData = response.data.data;
        setName(movieData.name);
        setRating(movieData.rating);
        setTime(movieData.time.join("/"));
      } catch (error) {
        console.error("Error fetching movie:", error);
      }
    };
    fetchMovie();
  }, [id]);

  const handleChangeInputName = (event) => {
    setName(event.target.value);
  };

  const handleChangeInputRating = (event) => {
    setRating(event.target.value);
  };

  const handleChangeInputTime = (event) => {
    setTime(event.target.value);
  };

  const handleUpdateMovie = async () => {
    const arrayTime = time.split("/");
    const payload = { name, rating, time: arrayTime };

    try {
      await api.updateMovieById(id, payload);
      window.alert(`Movie updated successfully`);
      setName("");
      setRating("");
      setTime("");
    } catch (error) {
      console.error("Error updating movie:", error);
      window.alert("Error updating movie");
    }
  };

  return (
    <Wrapper>
      <Title>Update Movie</Title>

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

      <Button onClick={handleUpdateMovie}>Update Movie</Button>
      <CancelButton href={"/movies/list"}>Cancel</CancelButton>
    </Wrapper>
  );
};

export default MoviesUpdate;
