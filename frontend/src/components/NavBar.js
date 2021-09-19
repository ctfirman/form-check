import React from "react";
import { makeStyles } from "@material-ui/core/styles";
import AppBar from "@material-ui/core/AppBar";
import Toolbar from "@material-ui/core/Toolbar";
import Typography from "@mui/material/Typography";
import { Button } from "@material-ui/core";
import TimelineIcon from "@mui/icons-material/Timeline";
import FitnessCenterRoundedIcon from "@mui/icons-material/FitnessCenterRounded";
import HomeRoundedIcon from "@mui/icons-material/HomeRounded";
import navBarPic from "../img/JTN-HTNLogo.png";
import { Link, useLocation } from "react-router-dom";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";

const useStyles = makeStyles((theme) => ({
  root: {
    flexGrow: 1,
  },
  menuButton: {
    marginRight: theme.spacing(2),
  },
  profile: {
    flexGrow: 1,
  },
  text: {
    display: "flex",
    flexDirection: "column",
    flexGrow: 1,
    fontWeight: 300,
    justifyContent: "center",
    textDecoration: "none",
    variant: "h1",
  },
  image: {
    marginRight: "10px",
    height: "80px",
  },
  appBar: {
    backgroundColor: "#000",
    alignContent: "center",
  },
  button: {
    margin: theme.spacing(1),
    fontSize: 50,
    color: "white",
    backgroundColor: "transparent",
  },
}));

function NavigationBar() {
  const classes = useStyles();
  const location = useLocation();

  return (
    <div className={classes.root}>
      <AppBar position="static" className={classes.appBar}>
        <Toolbar>
          <img src={navBarPic} alt="JTN" className={classes.image} />
          {location.pathname === "/" && (
            <>
              <Typography variant="h6" className={classes.text} color="inherit">
                Home
              </Typography>
              <Button
                component={Link}
                to="/journey"
                color="inherit"
                startIcon={<TimelineIcon />}
              >
                My Journey
              </Button>
              <Button
                component={Link}
                to="/exercises"
                color="inherit"
                startIcon={<FitnessCenterRoundedIcon />}
              >
                Exercises
              </Button>
            </>
          )}
          {location.pathname === "/home" && (
            <>
              <Typography variant="h6" className={classes.text} color="inherit">
                Home
              </Typography>
              <Button
                component={Link}
                to="/journey"
                color="inherit"
                startIcon={<TimelineIcon />}
              >
                My Journey
              </Button>
              <Button
                component={Link}
                to="/exercises"
                color="inherit"
                startIcon={<FitnessCenterRoundedIcon />}
              >
                Exercises
              </Button>
            </>
          )}
          {location.pathname === "/journey" && (
            <>
              <Typography variant="h6" className={classes.text} color="inherit">
                My Journey
              </Typography>
              <Button
                component={Link}
                to="/home"
                color="inherit"
                startIcon={<HomeRoundedIcon />}
              >
                Home
              </Button>
              <Button
                component={Link}
                to="/exercises"
                color="inherit"
                startIcon={<FitnessCenterRoundedIcon />}
              >
                Exercises
              </Button>
            </>
          )}
          {location.pathname === "/exercises" && (
            <>
              <Typography variant="h6" className={classes.text} color="inherit">
                Exercises
              </Typography>
              <Button
                component={Link}
                to="/home"
                color="inherit"
                startIcon={<HomeRoundedIcon />}
              >
                Home
              </Button>
              <Button
                component={Link}
                to="/journey"
                color="inherit"
                startIcon={<TimelineIcon />}
              >
                My Journey
              </Button>
            </>
          )}
        </Toolbar>
      </AppBar>
    </div>
  );
}

export default NavigationBar;
