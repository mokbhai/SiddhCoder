const Workout = require("../models/workoutModel");

const workoutController = {};

// Get all workouts
workoutController.getAllWorkouts = async (req, res) => {
  try {
    const workouts = await Workout.find().sort({ createAt: -1 });
    res.status(200).json(workouts);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
};

// Get a specific workout by ID
workoutController.getWorkoutById = async (req, res) => {
  const { id } = req.params;

  try {
    const workout = await Workout.findById(id);
    if (!workout) {
      return res.status(404).json({ message: "Workout not found" });
    }
    res.status(200).json(workout);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
};

// Create a new workout
workoutController.createWorkout = async (req, res) => {
  const { title, load, reps } = req.body;

  try {
    const workout = await Workout.create({ title, load, reps });
    res.status(201).json(workout);
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
};

// Create multiple new workouts
workoutController.createWorkouts = async (req, res) => {
  const workouts = req.body;
  try {
    for (const workout of workouts) {
      const { title, load, reps } = workout;
      await Workout.create({ title, load, reps });
    }
    res.status(201).json({ message: "Workouts created successfully" });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
};

// Delete a workout by ID
workoutController.deleteWorkoutById = async (req, res) => {
  const { id } = req.params;

  try {
    const workout = await Workout.findByIdAndDelete(id);
    if (!workout) {
      return res.status(404).json({ message: "Workout not found" });
    }
    res.status(200).json(workout);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
};

// Update a workout by ID
workoutController.updateWorkoutById = async (req, res) => {
  const { id } = req.params;
  const updateFields = req.body;

  try {
    const workout = await Workout.findByIdAndUpdate(id, updateFields, {
      new: true,
    });
    if (!workout) {
      return res.status(404).json({ message: "Workout not found" });
    }
    res.status(200).json(workout);
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
};

module.exports = workoutController;
