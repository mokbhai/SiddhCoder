const express = require("express");
const router = express.Router();
const workoutController = require("../controllers/workoutController");

//#region Routes

// Route to get all workouts
router.get("/", workoutController.getAllWorkouts);

// Route to get a specific workout by ID
router.get("/:id", workoutController.getWorkoutById);

// Route to create a new workout
router.post("/", workoutController.createWorkout);

// Route to delete a workout by ID
router.delete("/:id", workoutController.deleteWorkoutById);

// Route to update a workout by ID
router.patch("/:id", workoutController.updateWorkoutById);

//#endregion

module.exports = router;
