import { useEffect } from "react";
import WorkoutDetails from "../component/workoutDetails";
import WorkoutForm from "../component/workoutForm";
import { useWorkoutContext } from "../hooks/useWorkoutContext";

const Home = () => {
  const { workouts, dispatch } = useWorkoutContext();

  useEffect(() => {
    const fetchWorkouts = async () => {
      const response = await fetch("/api/workouts");

      if (response.ok) {
        const data = await response.json();

        const sortedWorkouts = data.sort((a, b) => {
          return new Date(b.createdAt) - new Date(a.createdAt);
        });

        dispatch({ type: "SET_WORKOUTS", payload: sortedWorkouts });
      }
      if (!response.ok) {
        throw new Error("Failed to fetch workouts");
      }
    };
    fetchWorkouts();
  }, [dispatch]);

  const handleDeleteWorkout = async (id) => {
    const response = await fetch(`/api/workouts/${id}`, {
      method: "DELETE",
    });

    if (response.ok) {
      // Refresh workout list after deletion
    } else {
      console.error("Failed to delete workout");
    }
  };

  return (
    <div className="home">
      <div className="workouts">
        {workouts &&
          workouts.map((workout) => (
            <WorkoutDetails
              key={workout._id}
              workout={workout}
              onDelete={() => handleDeleteWorkout(workout._id)}
            />
          ))}
      </div>
      <WorkoutForm />
    </div>
  );
};

export default Home;
