const int AirValue = 121;   //replace the value with value when placed in air using calibration code 
const int WaterValue = 480; //replace the value with value when placed in water using calibration code 
int soilMoistureValue = 0;
int soilmoisturepercent=0;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void loop() {
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil

  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    Serial.println("100 %");
  }
  else if(soilmoisturepercent <=0)
  {
    Serial.println("0 %");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print("Soil Moisture Percent = ");
    Serial.print(soilmoisturepercent);
    Serial.println("%");
    
  }  

  delay(250);
}
