const Movie = require("../models/movie-model");

const createMovie = (req, res) => {
  const body = req.body;

  if (!body) {
    return res.status(400).json({
      success: false,
      error: "You must provide a movie",
    });
  }

  const movie = new Movie(body);

  if (!movie) {
    return res
      .status(400)
      .json({ success: false, error: "Invalid movie data" });
  }

  movie
    .save()
    .then(() => {
      return res.status(201).json({
        success: true,
        id: movie._id,
        message: "Movie created!",
      });
    })
    .catch((error) => {
      return res.status(400).json({
        error,
        message: "Movie not created!",
      });
    });
};

const updateMovie = async (req, res) => {
  const body = req.body;

  if (!body) {
    return res.status(400).json({
      success: false,
      error: "You must provide a body to update",
    });
  }

  try {
    const movie = await Movie.findOne({ _id: req.params.id });

    if (!movie) {
      return res.status(404).json({
        success: false,
        message: "Movie not found!",
      });
    }

    movie.name = body.name;
    movie.time = body.time;
    movie.rating = body.rating;

    await movie.save();

    return res.status(200).json({
      success: true,
      id: movie._id,
      message: "Movie updated!",
    });
  } catch (error) {
    return res.status(500).json({
      success: false,
      error: "Server Error",
    });
  }
};

const deleteMovie = async (req, res) => {
  try {
    const movie = await Movie.findOneAndDelete({ _id: req.params.id });

    if (!movie) {
      return res.status(404).json({ success: false, error: `Movie not found` });
    }

    return res.status(200).json({ success: true, data: movie });
  } catch (err) {
    console.log(err);
    return res.status(400).json({ success: false, error: err });
  }
};

const getMovieById = async (req, res) => {
  try {
    const movie = await Movie.findOne({ _id: req.params.id });

    if (!movie) {
      return res.status(404).json({ success: false, error: `Movie not found` });
    }
    return res.status(200).json({ success: true, data: movie });
  } catch (err) {
    console.log(err);
    return res.status(400).json({ success: false, error: err });
  }
};

const getMovies = async (req, res) => {
  try {
    const movies = await Movie.find({});

    if (!movies || movies.length === 0) {
      return res
        .status(404)
        .json({ success: false, error: `Movies not found` });
    }

    return res.status(200).json({ success: true, data: movies });
  } catch (error) {
    return res.status(500).json({ success: false, error: error.message });
  }
};

module.exports = {
  createMovie,
  updateMovie,
  deleteMovie,
  getMovies,
  getMovieById,
};
