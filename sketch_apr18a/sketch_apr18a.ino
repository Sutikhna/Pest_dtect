#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define MOISTURE_PIN 34
#define MQ2_PIN 35
#define IR_PIN 13
#define PIR_PIN 14
#define VIBRATION_PIN 27

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(IR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(VIBRATION_PIN, INPUT);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int moistureValue = analogRead(MOISTURE_PIN);
  int gasValue = analogRead(MQ2_PIN);
  int irValue = digitalRead(IR_PIN);
  int pirValue = digitalRead(PIR_PIN);
  int vibrationValue = digitalRead(VIBRATION_PIN);

  Serial.println("===== Sensor Readings =====");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Soil Moisture (0-4095): ");
  Serial.println(moistureValue);

  Serial.print("Gas Level (MQ2, 0-4095): ");
  Serial.println(gasValue);

  Serial.print("IR Sensor: ");
  Serial.println(irValue == LOW ? "Object Detected" : "No Object");

  Serial.print("PIR Motion Sensor: ");
  Serial.println(pirValue == HIGH ? "Motion Detected" : "No Motion");

  Serial.print("Vibration Sensor: ");
  Serial.println(vibrationValue == HIGH ? "Vibration Detected" : "No Vibration");

  Serial.println("===========================\n");

  delay(2000);
}
