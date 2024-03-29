//#region require

require("dotenv").config();

const express = require("express");
const app = express();
const mongoose = require("mongoose");
const workoutsRoutes = require("./routes/workouts");
const userRoute = require("./routes/userRoutes");

//#endregion

const PORT = process.env.PORT || 4001;

//#region middlewares

app.use(express.json()); // used for requesting body

app.use((req, res, next) => {
  console.log(req.path, req.method);
  next();
});

// app.use((req, res, next) => {
//   res.header("Access-Control-Allow-Origin", "http://localhost:3000");
//   res.header(
//     "Access-Control-Allow-Header",
//     "Origin, X-Requested-With Content-Type, Accept"
//   );
//   next();
// });

//#endregion

//#region Connection Mongoose

mongoose
  .connect(process.env.MONGO_URI)
  .then(() => {
    //#region listen

    app.listen(4000, () => {
      console.log("DB Connected & Backend App working on " + PORT);
    });

    //#endregion
  })
  .catch((error) => {
    console.log(error);
  });

//#endregion

//#region routes

app.use("/api/workouts", workoutsRoutes);
app.use("/api/user", userRoute);

//#endregion

// //#region listen

// app.listen(4000, () => {
//   console.log("Backend App working on " + PORT);
// });

// //#endregion
