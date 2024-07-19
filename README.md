# ESP32 and ESP8266 Neopixel and Ultrasonic Sensor Project

This project involves two microcontrollers, the ESP32 and ESP8266, working together to create an interactive light display using a Neopixel strip and ultrasonic sensors. The ultrasonic sensors measure distances and send this information to the ESP32, which then adjusts the Neopixel strip's colors accordingly. Additionally, the distances are sent as OSC (Open Sound Control) messages to control the cutoff filter of three different synthesizers in Ableton Live.

## Components

- **ESP32**
  - Neopixel strip (59 pixels)
- **ESP8266**
  - 3 HC-SR04 ultrasonic sensors
- **WiFi Network**


## ESP32 Code

The ESP32 code controls the Neopixel strip based on commands received from the ESP8266.

## ESP8266 Code

The ESP8266 code reads the distance from three ultrasonic sensors and sends this data to the ESP32. It also sends OSC messages to control the synthesizers.


### Parte 3:

```markdown
## How It Works

1. **ESP8266:**
   - Measures distance using three HC-SR04 ultrasonic sensors.
   - Sends distance data and commands to the ESP32.
   - Sends OSC messages to control the synthesizers' cutoff filters in Ableton Live.

2. **ESP32:**
   - Receives data from the ESP8266 via Serial2.
   - Adjusts the Neopixel strip colors based on the received distances.

## Setup

1. **Connect the ESP8266** to the HC-SR04 sensors:
   - TRIG_PIN1 -> D1
   - ECHO_PIN1 -> D4
   - TRIG_PIN2 -> D2
   - ECHO_PIN2 -> D5
   - TRIG_PIN3 -> D3
   - ECHO_PIN3 -> D7

2. **Connect the ESP32** to the Neopixel strip:
   - Data pin of the Neopixel strip -> GPIO 25

3. **Set up WiFi:**
   - Ensure both ESP32 and ESP8266 are connected to the same network.

## Usage

1. Upload the respective codes to the ESP32 and ESP8266.
2. Power on both microcontrollers.
3. Observe how the Neopixel strip reacts to changes in distance measured by the ultrasonic sensors.
4. Use the OSC messages to control the cutoff filters in Ableton Live.

## Dependencies

- Adafruit NeoPixel library for controlling the Neopixel strip.
- ESP8266WiFi and WiFiUdp libraries for WiFi connectivity.
- OSCMessage library for sending OSC messages.

## Future Improvements

- Enhance the smoothing algorithm for distance measurements.
- Add more Neopixel strips or sensors for a more complex display.
- Integrate more OSC controls for additional synthesizer parameters.

Feel free to contribute to this project by submitting pull requests or opening issues. Enjoy experimenting with interactive light and sound!


