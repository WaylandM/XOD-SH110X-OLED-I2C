// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_SH110x"
#pragma XOD require "https://github.com/adafruit/Adafruit-GFX-Library"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

node {
    meta {
        using Type = Adafruit_SH1107*;
    }

    uint8_t mem[sizeof(Adafruit_SH1107)];

    void evaluate(Context ctx) {
        if (!isSettingUp())
            return;
        auto wire = getValue<input_I2C>(ctx);
        auto width = getValue<input_WIDTH>(ctx);
        auto height = getValue<input_HEIGHT>(ctx);
        auto reset_pin = getValue<input_RESET_PIN>(ctx);
        Type display = new (mem) Adafruit_SSD1306(width, height, wire, reset_pin);
        
        // Attempt to initialize display module; if attempt fails raise error
        auto address = getValue<input_ADDRESS>(ctx);
        if (!display->begin(SSD1306_SWITCHCAPVCC, address)) {
            raiseError(ctx);
            return;
        }
        emitValue<output_DEV>(ctx, display);
    }
}




