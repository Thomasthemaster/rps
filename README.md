# Rock Paper Scissors

A portable and fun Rock Paper Scissors Game using **a Servo and an Ultrasonic Sensor**.

---

## 🚀 How It Works

The buzzer beeps and the Ultrasonic Sensor waits for a hand. When the hand is detected, the Servo will randomly spin around and then quickly rotate to it's selected position. The Arduino randomly chooses a number between 0 and 2 to select which position to move to. Then the Arduino will wait for the hand to move away, and sound the buzzer again. Once the buzzer sounds again, the Ultrasonic Sensor waits for a hand.

### Hardware
- **Development Board:** Arduino Nano
- **Main Components:** Servo + Ultrasonic Sensor
- **Software:** Arduino IDE

### Cool Features
- Servo turning to random positions to represent Rock/Paper/Scissors
- Portability
- Servo turning only when hand is detected near the Ultrasonic Sensor
- Sound (buzzer)

---

## 📊 Circuit Layouts

### Wiring Diagram

Below is the wiring diagram for the project:

![Wiring Diagram](COMPAKT_Reaction_Time_Game_Wiring_Diagram.png)

**Note: This wiring diagram was made in Wokwi. Since Wokwi doesn't have a Power MB V2 and the cube on top of the Servo in the actual build, the wiring diagram is an approximation of the physical build but retains the correct wiring and functionality.**

### Schematic

Below is the schematic generated in Tinkercad:

[![Schematic](Schematic.png)](Schematic.png)

*Schematic coming soon*

## 🔗 Wokwi Simulation
Try the interactive simulation of the project here:

[Open in Wokwi](https://wokwi.com/projects/474481508287527937)

---
## 🖼️ Project Photo

See the project (may have some issues viewing it on desktop):

[Click here](Reaction_Time_Game_Image.png)

## 🎥 Video Demonstration

Watch the project in action + an explanation of the build:

[▶ Watch the Video](https://www.youtube.com/watch?v=UvWVi3E_Qpk)

---

## 📁 Repository Contents

- `Rock_Paper_Scissors_Game.ino` — Arduino source code
- `README.md` — Project documentation
- `LICENSE` — Apache License 2.0
- `Reaction_Time_Game_Image.png` — Project photo
- `COMPAKT_Reaction_Time_Game_Wiring_Diagram.png` — Wiring Diagram 
- `Schematic.png` — Coming Soon!

---

## 🛠️ Components Used

- Arduino Nano Board
- Passive Buzzer
- Ultrasonic Sensor
- Servo
- Pushbutton
- Power MB V2 + 9V Battery
- Jumper wires

---

## 💡 What I Learned

I learned to add other things to my projects. Since I added a cube with 3 sides showing Rock, Paper, and Scissors, I think this project has really disputed my ability to add other things to my projects rather than just the pure components. 

---

## 📜 License

This project is licensed under the Apache License 2.0.
