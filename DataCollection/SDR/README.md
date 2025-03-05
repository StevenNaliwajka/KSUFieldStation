#include <OneWire.h>
#include <DallasTemperature.h>

// Soil moisture sensor pin
const int moisturePin = A0;

// DS18B20 data wire is connected to digital pin 2 on the Arduino
#define ONE_WIRE_BUS 13

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature
DallasTemperature sensors(&oneWire);

// Calibration values for soil moisture sensor
int dryValue = 1023; // Adjust based on calibration (dry condition)
int wetValue = 242;    // Adjust based on calibration (wet condition)

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Start the DS18B20 sensor
  sensors.begin();
}

void loop() {
  // Read the soil moisture value
  int moistureValue = analogRead(moisturePin);
  
  // Map the soil moisture value to a percentage
  int moisturePercent = map(moistureValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);
  
  // Request temperature from the DS18B20 sensor
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  
  // Print the results to the Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.print(moistureValue);
  Serial.print(" | Soil Moisture (%): ");
  Serial.print(moisturePercent);
  Serial.print("% | Soil Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  // Wait 1 second before the next reading
  delay(1000);
}