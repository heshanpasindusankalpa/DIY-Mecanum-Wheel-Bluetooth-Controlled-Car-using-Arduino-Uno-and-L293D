#include <AFMotor.h>
#include <SoftwareSerial.h>

// Define motors connected to Adafruit Motor Shield
AF_DCMotor motor1(1); // Front-left motor
AF_DCMotor motor2(2); // Front-right motor
AF_DCMotor motor3(3); // Back-left motor
AF_DCMotor motor4(4); // Back-right motor

// Define SoftwareSerial pins for HC-06
SoftwareSerial Bluetooth(10, 9); // RX, TX (connect HC-06 TX to pin 10, RX to pin 9)

char command; // Variable to store received command

void setup() {
  // Set up motor speeds
  motor1.setSpeed(200); // Set speed between 0 to 255
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  // Start serial communication
  Serial.begin(9600);
  Bluetooth.begin(9600); // Initialize HC-06 at 9600 baud rate
  Serial.println("Mecanum Wheel Robot Bluetooth Control");
}

void loop() {
  // Check if data is available from HC-06
  if (Bluetooth.available()) {
    command = Bluetooth.read(); // Read the command

    switch (command) {
      case 'F': // Forward
        Serial.println("Forward");
        moveForward();
        break;

      case 'B': // Backward
        Serial.println("Backward");
        moveBackward();
        break;

      case 'L': // Left
        Serial.println("Left");
        moveLeft();
        break;

      case 'R': // Right
        Serial.println("Right");
        moveRight();
        break;

      case 'G': // Diagonal Forward-Left
        Serial.println("Diagonal Forward-Left");
        moveDiagonalForwardLeft();
        break;

      case 'I': // Diagonal Forward-Right
        Serial.println("Diagonal Forward-Right");
        moveDiagonalForwardRight();
        break;

      case 'H': // Diagonal Backward-Left
        Serial.println("Diagonal Backward-Left");
        moveDiagonalBackwardLeft();
        break;

      case 'J': // Diagonal Backward-Right
        Serial.println("Diagonal Backward-Right");
        moveDiagonalBackwardRight();
        break;

      case 'T': // Rotate Clockwise
        Serial.println("Rotate Clockwise");
        rotateClockwise();
        break;

      case 'Y': // Rotate Counter-Clockwise
        Serial.println("Rotate Counter-Clockwise");
        rotateCounterClockwise();
        break;

      case 'S': // Stop
        Serial.println("Stop");
        stopMotors();
        break;

      default:
        Serial.println("Invalid Command");
        stopMotors();
        break;
    }
  }
}

// Function to move forward
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// Function to move backward
void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

// Function to strafe left
void moveLeft() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

// Function to strafe right
void moveRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

// Function to move diagonally forward-left
void moveDiagonalForwardLeft() {
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
}

// Function to move diagonally forward-right
void moveDiagonalForwardRight() {
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
}

// Function to move diagonally backward-left
void moveDiagonalBackwardRight() {
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
}

// Function to move diagonally backward-right
void moveDiagonalBackwardLeft() {
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);
}

// Function to rotate clockwise
void rotateClockwise() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

// Function to rotate counter-clockwise
void rotateCounterClockwise() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

// Function to stop all motors
void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

