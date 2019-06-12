int distance;
int triggerPin = 4;
int echoPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  distance = (pulseIn(echoPin, HIGH) / 58);
  Serial.print("Distance(cm) = ");
  Serial.println(distance);
  delay(1000);
  
} 
