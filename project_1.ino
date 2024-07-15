#include <DHT11.h>
#define DHTPIN 2  // DHT11 data pin connected to digital pin 2
#define DHTTYPE DHT11  // DHT11 sensor type

#define LDRPIN A0 // LDR analog pin connected to analog pin A0
#define FANPIN 3  // Fan relay control pin connected to digital pin 3
#define LIGHTPIN 4 // Light relay control pin connected to digital pin 4

DHT11 dht11(2);

void setup() {
  pinMode(FANPIN, OUTPUT);
  pinMode(LIGHTPIN, OUTPUT);
//  digitalWrite(FANPIN, LOW);  // initially turn off fan
  digitalWrite(LIGHTPIN, LOW); // initially turn off light
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  float humidity = dht11.readHumidity();  // Read humidity value from DHT11 sensor
  float temperature = dht11.readTemperature(); // Read temperature value from DHT11 sensor
  int lightLevel = analogRead(LDRPIN); // Read light level from LDR sensor
  delay(2000);

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Check if temperature is too high, turn on fan
  if (temperature > 35) { // Adjust this threshold as needed
    digitalWrite(FANPIN, LOW); // Turn on fan
    Serial.println("Temperature is high. Fan turned on.");
    Serial.println("Temperature: "); 
    Serial.println(temperature);
    
    
  }  else if (lightLevel < 100){
    digitalWrite(FANPIN, LOW);
    Serial.println("Temperature is high due to higher light intensity.");
    Serial.println("Light level: ");
    Serial.println(lightLevel);
    
    
  } else {
    digitalWrite(FANPIN, HIGH);
    Serial.println("Both Temperature and Light level is low so fan turned off .");
    Serial.println("Temperature: "); 
    Serial.println(temperature);
    Serial.println("Light level: ");
    Serial.println(lightLevel);
    
  }

//  // Check if light level is low, turn on light
//  if (lightLevel > 100) { // Adjust this threshold as needed
//    digitalWrite(LIGHTPIN, LOW); // Turn on light
//    Serial.println("Low light detected. Light turned on.");
//    Serial.println(lightLevel);
//  } else {
//    digitalWrite(LIGHTPIN, HIGH); // Turn off light
//    Serial.println("Sufficient light detected. Light turned off.");
//    Serial.println(lightLevel);
//
//  }

  delay(5000); // Adjust delay time as needed
}
