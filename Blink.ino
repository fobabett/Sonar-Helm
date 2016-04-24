#define TRIG 5
#define ECHO 6
#define LED_RED 13
#define LED_YEL 12
#define LED_BLU 11
#define LED_GRN 10
// threshold, in cm
#define DST_RED 20
#define DST_YEL 40
#define DST_BLU 70
#define DST_GRN 110
#define MAX_DISTANCE 400
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YEL, OUTPUT);
  pinMode(LED_BLU, OUTPUT);
  pinMode(LED_GRN, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YEL, LOW);
  digitalWrite(LED_BLU, LOW);
  digitalWrite(LED_GRN, LOW);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(0.1);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < DST_RED) {
    digitalWrite(LED_RED, HIGH);
  } else if (distance < DST_YEL) {
    digitalWrite(LED_YEL, HIGH);
  } else if (distance < DST_BLU) {
    digitalWrite(LED_BLU, HIGH);
  } else if (distance < DST_GRN) {
    digitalWrite(LED_GRN, HIGH);
  }
  if(distance <=0) {
    delay(200);
  }
  else if (distance >= MAX_DISTANCE) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(200);
}
