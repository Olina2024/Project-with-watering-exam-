#define BLYNK_TEMPLATE_ID "TMPL4VQ2tDL3T"
#define BLYNK_TEMPLATE_NAME "Esp32"
#define BLYNK_AUTH_TOKEN "jXpx3L5GRNQe48L_8S8BaRx-ajNrDQ9G"
#include <Temperature_LM75_Derived.h>
#include "secret.h"
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include "Wire.h"
#include "gpio.h"
#include <BlynkSimpleEsp32.h>


float readLM75Temperature() {
/*
  Wire.beginTransmission(LM75_ADDR);
  Wire.write(0x00);           // Temperature register
  Wire.endTransmission();

  Wire.requestFrom(LM75_ADDR, 2);  // LM75 gives 2 bytes

  if (Wire.available() == 2) {
    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();

    int16_t temp = (msb << 8) | lsb;
    temp >>= 5;                // LM75 uses 11-bit temperature
    return temp * 0.125f;      // each bit = 0.125 °C
  }

  return NAN;
  */
  return random(0,40);
}

float readH33PHumidity(){
  
  return map(analogRead(Anlog_Pin), 0, 1023, 0, 100);;
}
void connectBlynk() {
  // Set WiFi to station mode (client me:\Ouyangjing\IOT24\examarbet\esp32s3\GPIO.hode, not access point)
 // WiFi.mode(WIFI_STA);
  //WiFi.begin(ssid, password);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  Serial.println("Connecting to Wi-Fi");
  // Optional: Print local IP
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  // Wait until WiFi connection is established
  /*
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
*/
  }
void setup() {
  pinMode(Anlog_Pin,INPUT_PULLUP);
  Serial.begin(115200);  // Initialize serial communication for debugging
  delay(2000);            // Wait for serial monitor to connect
  Wire.begin(SDA,SCL);
  connectBlynk();
}

// Arduino main loop - runs continuously
void loop() {
  // Use static variable to track last send time (initialized to allow immediate first send)
   Blynk.run();
  temperature= readLM75Temperature();
  humidity=readH33PHumidity();
  Serial.print("temperature is:");
  Serial.println(temperature);
  Serial.print("humidity is:");
  Serial.println(humidity);

   Blynk.virtualWrite(V1, temperature);
   Blynk.virtualWrite(V2, humidity);
   
   Blynk.virtualWrite(V0){
     if( param.asInt() == 1 && digitalread(DC)==LOW)
       digitalwrite(DC,HIGH);
     } else  if( param.asInt() == 1 && digitalread(DC)== High) {
       Serail.println("DC has already watering");
   }else digtalwrite(DC,LOW);
  
   delay(1000);
  // Check if it's time to send telemetry data
  /*
  if (millis() - previousMillis >= sendInterval) {
    // Update the last send time
    previousMillis = millis();

    // Publish simulated sensor data (temperature and humidity) as JSON
  //   bool sendResult = publishTelemetry("{\"temperature\":" + String(temperature, 2) + ",\"humidity\":" + String(humidity,2) + "}");
    // Restart ESP32 if publish failed (indicates connection issue)
 
  }
 */
  // Process incoming MQTT messages and maintain connection

}
