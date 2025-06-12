//-/-/-/-/-/-/-/-/-/-/-/-/-/--/-/-/-/-/-/-/-/-/-/robô inseto\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\\

#define PIN_TRIG 52
#define PIN_ECHO 53
int relay = 12;

void setup(){

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  Serial.begin(9600);
}

void loop(){
  //-------------------------------calculates the distance in cm-----------------------------------------------
 //Start a new measurement:
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  int duration = pulseIn(PIN_ECHO, HIGH);
  Serial.print("Distância em CM: ");
  float distance = duration / 58;
  Serial.println(distance);
  if (distance <= 10 ) {
    digitalWrite(relay, HIGH);
    delay(5000); 
    digitalWrite(relay, LOW);
  } else {
    digitalWrite(relay, LOW);
  }
  delay(3000);
 //-------------------------------------------------------------------------------------------------------------
}
