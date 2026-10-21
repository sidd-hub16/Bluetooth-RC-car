// Motor A connections
const int enA = 9; // ENA pin on L298N (PWM capable)
const int in1 = 10; // IN1 pin on L298N
const int in2 = 11; // IN2 pin on L298N

// Motor B connections
const int enB = 6; // ENB pin on L298N (PWM capable)
const int in3 = 3; // IN3 pin on L298N
const int in4 = 5;// IN4 pin on L298N

// Motor speed (0-255)
const int motorSpeed = 70; // Adjust as needed

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Set the motor speed (PWM)
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
}

void loop() {
  if (Serial.available()) {
    char key = Serial.read();
    key = toupper(key); // Read the incoming character

    switch (key) {
      case 'F': // Both motors forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        Serial.println("Moving Forward");
        break;

      case 'B': // Both motors backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        Serial.println("Moving Backward");
        break;

      case 'L': // Motor A backward, Motor B forward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        Serial.println("Turning Left (Motor A backward, Motor B forward)");
        break;

      case 'R': // Motor A forward, Motor B backward (typo in request, assuming 'D' for the opposite direction of 'A')
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        Serial.println("Turning Right (Motor A forward, Motor B backward)");
        break;

      case 'S': // Stop motors
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        Serial.println("Stopping Motors");
        break;

      default:
        // Do nothing for other key presses
        break;
    }
  }
}