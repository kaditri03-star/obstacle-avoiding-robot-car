int FR1 = 5;
int FR2 = 6;
int FL1 = 9;
int FL2 = 10;

int speed = 125;

const int trigPin = 2;
const int echoPin = 3;

// Move forward
void moveForward() {
  analogWrite(FR1, speed - 20);
  analogWrite(FR2, 0);
  analogWrite(FL1, speed + 3);
  analogWrite(FL2, 0);
}

// Turn left
void turnLeft() {
  analogWrite(FR1, speed + 50);
  analogWrite(FR2, 0);
  analogWrite(FL1, 0);
  analogWrite(FL2, 0);
}

// Stop motors
void stop() {
  analogWrite(FR1, 0);
  analogWrite(FR2, 0);
  analogWrite(FL1, 0);
  analogWrite(FL2, 0);
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(FR1, OUTPUT);
  pinMode(FR2, OUTPUT);
  pinMode(FL1, OUTPUT);
  pinMode(FL2, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");

  if (duration == 0) {
    Serial.println("No echo");
    moveForward();
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 50) {
      stop();
      delay(1000);

      turnLeft();
      delay(500);
    }
    else {
      moveForward();
    }
  }

  delay(100);
}
