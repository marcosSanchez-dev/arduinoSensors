#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

#define TRIG_PIN1 D1
#define ECHO_PIN1 D4
#define TRIG_PIN2 D2
#define ECHO_PIN2 D5
#define TRIG_PIN3 D3
#define ECHO_PIN3 D7

const char* ssid = "oceguedas";
const char* password = "amoryeppi";

const char* host = "192.168.68.104";
const int port = 8888;

WiFiUDP udp;

void sendOSC(const char* address, float value) {
  OSCMessage msg(address);
  msg.add(value);
  udp.beginPacket(host, port);
  msg.send(udp);
  udp.endPacket();
  msg.empty();
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  long duration1, distance1, duration2, distance2, duration3, distance3;
  byte command = 0;

  // Sensor 1
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Sensor 2
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Sensor 3
  digitalWrite(TRIG_PIN3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);
  duration3 = pulseIn(ECHO_PIN3, HIGH);
  distance3 = duration3 * 0.034 / 2;

  // Set bits for each sensor
  if (distance1 < 45) {
    command |= 0b001;
  }
  if (distance2 < 45) {
    command |= 0b010;
  }
  if (distance3 < 45) {
    command |= 0b100;
  }

  // Send OSC messages
  if (distance1 < 45) {
    float value1 = map(distance1, 5, 45, 0, 100) / 100.0;
    sendOSC("/OSC/uno", value1);
  }
  if (distance2 < 45) {
    float value2 = map(distance2, 5, 45, 0, 100) / 100.0;
    sendOSC("/OSC/dos", value2);
  }
  if (distance3 < 45) {
    float value3 = map(distance3, 5, 45, 0, 100) / 100.0;
    sendOSC("/OSC/tres", value3);
  }

  Serial.write(command);
  Serial.write(distance1);
  Serial.write(distance2);
  Serial.write(distance3);

  delay(100);
}
