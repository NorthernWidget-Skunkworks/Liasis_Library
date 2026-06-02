# Liasis

**Arduino library for the NorthernWidget longwave pyrgeometer**

*Liasis* is a genus of Australian water and olive pythons. Like all pythons, they possess labial pit organs — heat-sensing cavities along the lips that detect thermal infrared radiation in the ~5–30 µm range, the same window in which warm objects near ambient temperature emit most strongly. It is the same physical phenomenon this library measures.

This library interfaces with the NorthernWidget longwave pyrgeometer module, which measures atmospheric downwelling thermal infrared radiation via a ZTP-135SR thermopile, along with housing temperature for reference compensation.

The shortwave (solar) sensor that was formerly bundled with this library's predecessor is maintained separately as **[Libelle](https://github.com/NorthernWidget-Skunkworks/Libelle_Library)** — named after the German word for dragonfly, whose compound eyes span UV to near-infrared.

## Channels

| Column (`getHeader()`) | Method | Description |
|------------------------|--------|-------------|
| `IR_Long [mV]` | `getThermo()` | Thermopile raw output voltage (mV) |
| `IR_Long [C]` | `getThermoC()` | Longwave-derived temperature (°C) |
| `PyrgT [C]` | `getTemp()` | Housing temperature from thermistor (°C) |

The thermopile measures the net radiation exchange between the sensor and the sky above, which is dominated by atmospheric thermal emission in the 8–14 µm window. Housing temperature is required for reference junction compensation to obtain calibrated irradiance.

## Hardware

The longwave module reads the ZTP-135SR thermopile and its integrated thermistor through a Texas Instruments ADS1115 16-bit ADC at I2C address 0x4A. Signal conditioning is handled by a pair of LTC2054 zero-drift op-amps.

**Key ICs:** Amphenol ZTP-135SR (thermopile + thermistor), ADS1115 (ADC), LTC2054 (op-amp)

## Basic usage

```cpp
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
```

## API

| Method | Returns | Description |
|--------|---------|-------------|
| `begin()` | `uint8_t` | Initialize sensor and I2C bus |
| `getHeader()` | `String` | Comma-separated column names with units |
| `getString()` | `String` | Comma-separated measurement values |
| `getThermo()` | `float` | Thermopile raw output voltage (mV) |
| `getThermoC(accuracy)` | `float` | Longwave-derived temperature (°C); accuracy 0 = low (default), 1 = high |
| `getTemp()` | `float` | Housing temperature from thermistor (°C) |

## Name history

This library was split from the combined **Monarch** library (formerly **Dyson**), which housed both the shortwave and longwave sensors in a single codebase. On the split, the longwave sensor became *Liasis* and the shortwave sensor became *[Libelle](https://github.com/NorthernWidget-Skunkworks/Libelle_Library)*. The combined archive is preserved at [NorthernWidget-Skunkworks/Monarch-Dyson_Library__Archive](https://github.com/NorthernWidget-Skunkworks/Monarch-Dyson_Library__Archive).

*Liasis* continues the NorthernWidget tradition of naming instruments after organisms with exceptional sensory capabilities.

The hardware project lives at [NorthernWidget-Skunkworks/Project-Monarch](https://github.com/NorthernWidget-Skunkworks/Project-Monarch).

## License

[GNU General Public License v3](LICENSE)
