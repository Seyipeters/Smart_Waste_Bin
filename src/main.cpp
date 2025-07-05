#include <Servo.h>

// Servo pulse widths
#define SERVO_STOP_US     1475   // This prevents servo from jiltering when not getting signals
#define SERVO_OPEN_US     1300   // Rotate in one direction
#define SERVO_CLOSE_US    1700   // Rotate in the other direction
#define SERVO_ROTATE_DURATION 500  // ms: duration for half-lid movement

Servo servo;

// Pin assignments
const int trigPin = 5;
const int echoPin = 6;
const int servoPin = 7;

long duration, distance;
long distanceArray[3]; // For averaging

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(servoPin);
  stopServo();  // Prevent idle movement
}

void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000); // Timeout to avoid blocking
  if (duration == 0) {
    distance = 999; // No object detected
  } else {
    distance = duration * 0.034 / 2; // Convert to cm
  }
}

void openLid() {
  servo.writeMicroseconds(SERVO_OPEN_US);  // Rotate open
  delay(SERVO_ROTATE_DURATION);
  stopServo();
}

void closeLid() {
  servo.writeMicroseconds(SERVO_CLOSE_US); // Rotate close
  delay(SERVO_ROTATE_DURATION);
  stopServo();
}

void stopServo() {
  servo.writeMicroseconds(SERVO_STOP_US);  // Fine-tuned stop signal
}

void loop() {
  long sum = 0;
  for (int i = 0; i < 3; i++) {
    measureDistance();
    distanceArray[i] = distance;
    sum += distance;
    delay(50);
  }

  distance = sum / 3;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Trigger when hand is very close (<10cm)
  if (distance > 1 && distance < 15) {
    openLid();
    delay(3000);   // Wait while open
    closeLid();
  }

  delay(100);  // Small delay before next check
}
