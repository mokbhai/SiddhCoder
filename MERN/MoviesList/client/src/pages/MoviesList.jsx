import React, { useState, useEffect } from "react";
import api from "../api";
import styled from "styled-components";
import ReactTable from "react-table-6";
import "react-table-6/react-table.css";

const Wrapper = styled.div`
  padding: 0 40px 40px 40px;
`;

const Update = styled.div`
  color: #ef9b0f;
  cursor: pointer;
`;

const Delete = styled.div`
  color: #ff0000;
  cursor: pointer;
`;

const UpdateMovie = ({ id }) => {
  const updateUser = () => {
    window.location.href = `/movies/update/${id}`;
  };

  return <Update onClick={updateUser}>Update</Update>;
};

const DeleteMovie = ({ id }) => {
  const deleteUser = () => {
    if (window.confirm(`Do you want to delete the movie ${id} permanently?`)) {
      api.deleteMovieById(id);
      window.location.reload();
    }
  };

  return <Delete onClick={deleteUser}>Delete</Delete>;
};

const MoviesList = () => {
  const [movies, setMovies] = useState([]);
  const [isLoading, setIsLoading] = useState(false);

  useEffect(() => {
    const fetchMovies = async () => {
      setIsLoading(true);
      try {
        const response = await api.getAllMovies();
        setMovies(response.data.data);
        setIsLoading(false);
      } catch (error) {
        console.error("Error fetching movies:", error);
        setIsLoading(false);
      }
    };

    fetchMovies();
  }, []);

  const columns = [
    {
      Header: "ID",
      accessor: "_id",
      filterable: true,
    },
    {
      Header: "Name",
      accessor: "name",
      filterable: true,
    },
    {
      Header: "Rating",
      accessor: "rating",
      filterable: true,
    },
    {
      Header: "Time",
      accessor: "time",
      Cell: (props) => <span>{props.value.join(" / ")}</span>,
    },
    {
      Header: "",
      accessor: "",
      Cell: (props) => (
        <span>
          <DeleteMovie id={props.original._id} />
        </span>
      ),
    },
    {
      Header: "",
      accessor: "",
      Cell: (props) => (
        <span>
          <UpdateMovie id={props.original._id} />
        </span>
      ),
    },
  ];

  const showTable = movies.length > 0;

  return (
    <Wrapper>
      {showTable && (
        <ReactTable
          data={movies}
          columns={columns}
          loading={isLoading}
          defaultPageSize={10}
          showPageSizeOptions={true}
          minRows={0}
        />
      )}
    </Wrapper>
  );
};

export default MoviesList;
