
// 
// This requires only an ESP32 and download cable. No other hardware is reuired.
// A wifi SSID and password is required.
// Written by: Subhan Iqbal  12/03/25
//
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "homepage.h"
#include <ESP32Servo.h>   //  ESP32 Servo library

const char* ssid = "Subhan's S24 Ultra";
const char* password = "12345678";
Servo Waist;       // Declare variable to control Waist Servo
Servo Shoulder;    // Declare variable to control Shoulder Servo
Servo Elbow;       // Declare variable to control Elbow Servo
Servo Grippers;    // Declare variable to control Grippers Servo

int WAIST_DEGREES = 90;    // Initial position of waist servo = 90 degrees
int SHOULDER_DEGREES = 20; // Initial position of shoulder servo = 20 degrees
int ELBOW_DEGREES = 50;    // Initial position of elbow servo = 50 degrees
int GRIPPERS_DEGREES = 0;  // Initial position of grippers servo = 0 degrees

#define VRY_2 34       // Assign Joystick 2 Y-axis input to GPIO 34 (analog input)
#define VRX_2 35       // Assign Joystick 2 X-axis input to GPIO 35 (analog input)
#define VRY_1 32       // Assign Joystick 1 Y-axis input to GPIO 32 (analog input)
#define VRX_1 33       // Assign Joystick 1 X-axis input to GPIO 33 (analog input)

WebServer server(80);

//temp function to simulate temp sensor
String getAngle() {
  return "25.4";
}


void handleRoot() {
  String message = homePagePart1 + getAngle();
  server.send(200, "text/html", message);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);     
}     
     
void setup(void) {

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
     Waist.attach(18);    // Assign GPIO 18 for controlling the Waist servo
  Shoulder.attach(19); // Assign GPIO 19 for controlling the Shoulder servo
  Elbow.attach(21);    // Assign GPIO 21 for controlling the Elbow servo
  Grippers.attach(22); // Assign GPIO 22 for controlling the Grippers servo
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks

  int LVRY_1 = analogRead(VRY_1);    // Read Y-axis from Joystick 1
  int LVRX_1 = analogRead(VRX_1);    // Read X-axis from Joystick 1
  int LVRY_2 = analogRead(VRY_2);    // Read Y-axis from Joystick 2
  int LVRX_2 = analogRead(VRX_2);    // Read X-axis from Joystick 2

  // Scale the 12-bit ADC reading (0-4095) to match the 10-bit range (0-1023)
  LVRY_1 = map(LVRY_1, 0, 4095, 0, 1023);
  LVRX_1 = map(LVRX_1, 0, 4095, 0, 1023);
  LVRY_2 = map(LVRY_2, 0, 4095, 0, 1023);
  LVRX_2 = map(LVRX_2, 0, 4095, 0, 1023);

  // Control Waist
  if (LVRY_1 < 340) WAIST_DEGREES -= 1;                // If Joystick 1 Y reading is less than 340, decrease Waist servo by 1 degree
  else if (LVRY_1 > 680) WAIST_DEGREES += 1;           // If Joystick 1 Y reading is greater than 680, increase Waist servo by 1 degree
  WAIST_DEGREES = min(175, max(0, WAIST_DEGREES));     // Waist servo moves between 0 degrees (min) and 175 degrees (max)

  // Control Shoulder
  if (LVRX_1 < 340) SHOULDER_DEGREES += 2;             // If Joystick 1 X reading is less than 340, increase Shoulder servo by 2 degrees
  else if (LVRX_1 > 680) SHOULDER_DEGREES -= 2;        // If Joystick 1 X reading is greater than 680, decrease Shoulder servo by 2 degrees
  SHOULDER_DEGREES = min(110, max(10, SHOULDER_DEGREES)); // Shoulder servo moves between 10 degrees (min) and 110 degrees (max)

  // Control Elbow
  if (LVRX_2 < 340) ELBOW_DEGREES -= 1;                // If Joystick 2 X reading is less than 340, decrease Elbow servo by 1 degree
  else if (LVRX_2 > 680) ELBOW_DEGREES += 1;           // If Joystick 2 X reading is greater than 680, increase Elbow servo by 1 degree
  ELBOW_DEGREES = min(80, max(0, ELBOW_DEGREES));      // Elbow servo moves between 0 degrees (min) and 80 degrees (max)

  // Control Grippers
  if (LVRY_2 < 340) GRIPPERS_DEGREES -= 3;             // If Joystick 2 Y reading is less than 340, decrease Grippers servo by 3 degrees
  else if (LVRY_2 > 680) GRIPPERS_DEGREES += 2;        // If Joystick 2 Y reading is greater than 680, increase Grippers servo by 2 degrees
  GRIPPERS_DEGREES = min(58, max(0, GRIPPERS_DEGREES)); // Grippers servo moves between 0 degrees (min) and 58 degrees (max)

  // Write the values to the servos
  Waist.write(WAIST_DEGREES);     // Assign the value of WAIST_DEGREES to the Waist servo
  Shoulder.write(SHOULDER_DEGREES); // Assign the value of SHOULDER_DEGREES to the Shoulder servo
  Elbow.write(ELBOW_DEGREES);     // Assign the value of ELBOW_DEGREES to the Elbow servo
  Grippers.write(GRIPPERS_DEGREES);// Assign the value of GRIPPERS_DEGREES to the Grippers servo

  delay(40);                       // 40 millisecond delay
}



