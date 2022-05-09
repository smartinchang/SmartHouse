#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "TEKY OFFICE";
const char* password = "Teky@2018";
WiFiClient client;

// ThingSpeak Settings
unsigned long ChannelNumber = 1673641;
const char * ReadAPIKey = "X96PCNXEHWISWVKL";
int statusCode;

void setup() {
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  Serial.begin(9600);
  Serial.print("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("\r\nWiFi connected");
  ThingSpeak.begin(client);
}

void loop() {
  long data = ThingSpeak.readFloatField(ChannelNumber, 1, ReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200) {
    Serial.println("Led 1 Data read from ThingSpeak: " + String(data, 9));
    if (data == 0) {
      digitalWrite(D5, LOW);
    } else {
      digitalWrite(D5, HIGH);
    }
  } else {
    Serial.println("Unable to read channel/No internet connection");
  }
  data = ThingSpeak.readFloatField(ChannelNumber, 2, ReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200) {
    Serial.println("Led 2 Data read from ThingSpeak: " + String(data, 9));
    if (data == 0) {
      digitalWrite(D6, LOW);
    } else {
      digitalWrite(D6, HIGH);
    }
  } else {
    Serial.println("Unable to read channel/No internet connection");
  }
  data = ThingSpeak.readFloatField(ChannelNumber, 3, ReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200) {
    Serial.println("Led 3 Data read from ThingSpeak: " + String(data, 9));
    if (data == 0) {
      digitalWrite(D7, LOW);
    } else {
      digitalWrite(D7, HIGH);
    }
  } else {
    Serial.println("Unable to read channel/No internet connection");
  }
  data = ThingSpeak.readFloatField(ChannelNumber, 4, ReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200) {
    Serial.println("Led 4 Data read from ThingSpeak: " + String(data, 9));
    if (data == 0) {
      digitalWrite(D8, LOW);
    } else {
      digitalWrite(D8, HIGH);
    }
  } else {
    Serial.println("Unable to read channel/No internet connection");
  }
  delay(1000);
}
