
int percent = 0;
int prevPercent = 0;

int lightPin = 22;

void setup() {

  Serial.begin(9600);
  pinMode(lightPin,OUTPUT);

}

void loop() {
  //experiment 1, reading potentialometer
  percent = round(analogRead(0)/1024.00 * 100);
  if(percent != prevPercent){
    Serial.println(percent);
    prevPercent = percent;
  }
  
  //experiment 2, sending voltage to LED
   if (Serial.available() > 0) {
    String receivedString = "";
    while (Serial.available() > 0) {
      receivedString += char(Serial.read ());
    }
    Serial.println(receivedString);
    if(receivedString == "1")
      digitalWrite(lightPin,HIGH);  
    else
      digitalWrite(lightPin,LOW);
  }
  //delay for 100ms
  delay(100);
}
