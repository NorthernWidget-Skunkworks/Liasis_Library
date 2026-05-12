// LiasisDemo.ino
#include <Liasis.h>

Liasis pyrgeo;

void setup() {
	Serial.begin(38400);
	pyrgeo.begin();
	Serial.println(pyrgeo.getHeader());
}

void loop() {
	Serial.println(pyrgeo.getString());
	delay(1000);
}
