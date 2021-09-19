# Form-Check
Hack the North 2021

https://devpost.com/software/jacked-the-north
http://jackedthenorth.tech
https://form-check-326415.web.app/home

## Inspiration
We are trying to GET JACKED!
## What it does
Form Checker collects and sends balance, form, and technique data from the user while doing pushups to our web app that generates a report on the properness of the form.
## How we built it
We integrated a gyroscope/accelerometer with an ESP-32 to measure changes in relative position and angular velocity in order to create the user's Form information. That information is then sent to a FLASK backend hosted on the cloud. The information is then stored on FireStore and can be retrieved; later displayed on our REACT web app.
## Challenges we ran into
We ran into issues with Full Stack integration, and hardware quality & calibration.
## Accomplishments that we're proud of
We are proud of being able to parallelize data acquisition and data pushing using the ESP-32's dual cores.
## What we learned
We learned how to integrate the various aspects of software development with hardware.
## What's next for Jacked the North
Incorporate more exercises so that more people can get jacked.
