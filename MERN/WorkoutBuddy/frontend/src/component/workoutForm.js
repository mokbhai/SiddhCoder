import React, { useState } from "react";
import { useWorkoutContext } from "../hooks/useWorkoutContext";

const WorkoutForm = () => {
  const { dispatch } = useWorkoutContext();
  const [formData, setFormData] = useState({
    title: "",
    reps: "",
    load: "",
  });
  const [error, setError] = useState(null);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData({
      ...formData,
      [name]: value,
    });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    const response = await fetch("/api/workouts", {
      method: "POST",
      body: JSON.stringify(formData),
      headers: {
        "Content-Type": "application/json",
      },
    });

    if (response.ok) {
      const data = await response.json();
      setError(null);
      // console.log("Workout added: ", data);
      dispatch({ type: "CREATE_WORKOUT", payload: data });
      setFormData({ title: "", reps: "", load: "" });
    } else {
      const errorData = await response.json();
      setError(errorData.error);
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <div>
        <label htmlFor="title">Title:</label>
        <input
          type="text"
          id="title"
          name="title"
          value={formData.title}
          onChange={handleChange}
          required
        />
      </div>
      <div>
        <label htmlFor="reps">Reps:</label>
        <input
          type="number"
          id="reps"
          name="reps"
          value={formData.reps}
          onChange={handleChange}
          required
        />
      </div>
      <div>
        <label htmlFor="load">Load:</label>
        <input
          type="number"
          id="load"
          name="load"
          value={formData.load}
          onChange={handleChange}
          required
        />
      </div>
      {error && <div className="error">{error}</div>}
      <button type="submit">Submit</button>
    </form>
  );
};

export default WorkoutForm;
