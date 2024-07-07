const int motorPin = 9; // Motor control pin

void setup() {
  pinMode(motorPin, OUTPUT); // Set motor pin as output
}

void loop() {
  // Increase motor speed
  for (int dutyCycle = 5; dutyCycle <= 150; dutyCycle++) {
    analogWrite(motorPin, dutyCycle); // Set PWM duty cycle
    delay(100); // Adjust delay for smooth speed change
  }

  // Decrease motor speed
  for (int dutyCycle = 150; dutyCycle >= 5; dutyCycle--) {
    analogWrite(motorPin, dutyCycle); // Set PWM duty cycle
    delay(100); // Adjust delay for smooth speed change
  }
}
