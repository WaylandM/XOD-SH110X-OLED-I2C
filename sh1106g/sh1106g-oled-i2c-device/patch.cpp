// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_SH110x"
#pragma XOD require "https://github.com/adafruit/Adafruit-GFX-Library"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

node {
    meta {
        using Type = Adafruit_SH1106G*;
    }

    uint8_t mem[sizeof(Adafruit_SH1106G)];

    void evaluate(Context ctx) {
        if (!isSettingUp())
            return;
        auto wire = getValue<input_I2C>(ctx);
        auto width = getValue<input_WIDTH>(ctx);
        auto height = getValue<input_HEIGHT>(ctx);
        auto reset_pin = getValue<input_RESET_PIN>(ctx);
        Type display = new (mem) Adafruit_SH1106G(width, height, wire, reset_pin);
        emitValue<output_DEV>(ctx, display);
    }
}




