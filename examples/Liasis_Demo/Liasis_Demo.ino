#include <Liasis.h>

Liasis pyrgeo;

void setup() {
    Serial.begin(9600);
    Serial.println("Liasis longwave pyrgeometer");
    Serial.println("Reads thermopile voltage [mV], longwave temperature [C], and housing temperature [C] once per second.");

    if (!pyrgeo.begin()) {
        Serial.println("Liasis not found. Check wiring.");
        while (1);
    }

    Serial.println(pyrgeo.getHeader());
}

void loop() {
    Serial.println(pyrgeo.getString());
    delay(1000);
}
