#include <OneWire.h>
#include <DallasTemperature.h>

// Soil moisture sensor pin
const int moisturePin = A0;
const int moisturePin2 = A1;

// DS18B20 data wire is connected to digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2
#define ONE_WIRE_BUS2 3

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
OneWire2 oneWire2(ONE_WIRE_BUS2);

// Pass our oneWire reference to Dallas Temperature
DallasTemperature sensors(&oneWire);
DallasTemperature sensors2(&oneWire2);

// Calibration values for soil moisture sensor
int dryValue = 1023; // Adjust based on calibration (dry condition)
int wetValue = 242;    // Adjust based on calibration (wet condition)

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Start the DS18B20 sensor
  sensors.begin();
  sensors2.begin();
}

void loop() {
  // Read the soil moisture value
  int moistureValue = analogRead(moisturePin);
  int moistureValue2 = analogRead(moisturePin2);

  // Map the soil moisture value to a percentage
  int moisturePercent = map(moistureValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);
  int moisturePercent2 = map(moistureValue2, dryValue, wetValue, 0, 100);
  moisturePercent2 = constrain(moisturePercent2, 0, 100);

  // Request temperature from the DS18B20 sensor
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  sensors2.requestTemperatures();
  float temperatureC2 = sensors2.getTempCByIndex(0);

  // Print the results to the Serial Monitor
  Serial.print("Set1: Soil Moisture: ");
  Serial.print(moistureValue);
  Serial.print(" | Soil Moisture (%): ");
  Serial.print(moisturePercent);
  Serial.print("% | Soil Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  Serial.print("Set2: Soil Moisture: ");
  Serial.print(moistureValue2);
  Serial.print(" | Soil Moisture (%): ");
  Serial.print(moisturePercent2);
  Serial.print("% | Soil Temperature: ");
  Serial.print(temperatureC2);
  Serial.println(" °C");

  // Wait 1 second before the next reading
  delay(1000);
}