# sensor-visualization
Project to visualize data from various sensors (temperature, moisture, etc)

## Arduino Information
### Board
- Arduino Uno WiFi Rev2

### Setup
- *Install the Arduino IDE to your environment
- In the IDE go to board manager and install the `Arduino megaAVR Boards`. Once installed, select the `Arduino Uno WiFi Rev2` as your board.
- For now I have included the library directory in the repository. There is a todo to add a build script of some sort but I don't want to get distracted. For now let's focus on transmitting data.
- Open the Config.h file and add your own WiFi SSID and password here.

* This only covers local development, if you are using the web editor you are on your own.

## API Information
The _current_ API is written in NodeJS using express. Although I would like to use something else to create the API this will do for getting started.

### Setup
- Install NodeJS 17.4.0 on your machine
- Install npm
- Navigate to the api directory in this project
- Run npm install

## To Run
Once installation is complete you should be able to run `npm start` to start the server.
