import React from "react";

const WorkoutDetails = ({ workout, onDelete }) => {
  const handleDelete = () => {
    if (typeof onDelete === "function") {
      onDelete(workout._id);
    }
  };

  return (
    <div className="workout-details">
      <div className="details">
        <h4>{workout.title}</h4>
        <p>
          <strong>Load (kg): </strong>
          {workout.load}
        </p>
        <p>
          <strong>Reps: </strong>
          {workout.reps}
        </p>
        <p>{workout.createdAt}</p>
      </div>
      <button className="delete-button" onClick={handleDelete}>
        <img
          src="https://img.freepik.com/free-photo/trash-bin-front-side-white-background_187299-40223.jpg?w=1800&t=st=1706931771~exp=1706932371~hmac=30cbb4340b60c359083c2f4984541b61efcf3a946c029fe081b28a80f4443e86"
          alt="Delete Workout"
          style={{ width: "24px", height: "24px" }}
        />
      </button>
    </div>
  );
};

export default WorkoutDetails;
