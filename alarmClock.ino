#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
#define buz 11
const int buzzer = 11;

void setup () {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  pinMode(buzzer, OUTPUT);

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // used to set RTC, use once then comment out first line
    //RTC.adjust(DateTime(__DATE__, __TIME__));
    RTC.adjust(DateTime(2019, 03, 11, 11, 10, 0)); // Set time manually once
  }
}

void loop () {
  DateTime now = RTC.now();
  if (now.hour() == 10 && now.minute() == 53) {
    Buzz();
  }

}
void Buzz() {
  tone(buzzer, 1000); // Sends a 1KHz sound signal
  delay(500);        // 1 sec play
  noTone(buzzer);
  delay(500);
}

}
