/*
 ******************************************************************************

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, see <http://www.gnu.org/licenses/>.

 Adafruit library to control WS2811/WS2812 based RGB
 LED devices such as Adafruit NeoPixel strips.
 Currently handles 800 KHz and 400kHz bitstream on IntoRobot Board,
 WS2812, WS2812B and WS2811.

 Also supports:
 - Radio Shack Tri-Color Strip with TM1803 controller 400kHz bitstream.
 - TM1829 pixels

 Written by Phil Burgess / Paint Your Dragon for Adafruit Industries.
 Modified to work with Spark Core by Technobly.
 Contributions by PJRC and other members of the open source community.

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing products
 from Adafruit!
 ******************************************************************************
 */
#ifndef ADAFRUIT_NEOPIXEL_H_
#define ADAFRUIT_NEOPIXEL_H_

#include "Arduino.h"

// 'type' flags for LED pixels (third parameter to constructor):
#define WS2812   0x02 // 800 KHz datastream (NeoPixel)
#define WS2812B  0x02 // 800 KHz datastream (NeoPixel)
#define WS2811   0x00 // 400 KHz datastream (NeoPixel)
#define TM1803   0x03 // 400 KHz datastream (Radio Shack Tri-Color Strip)
#define TM1829   0x04 // 800 KHz datastream ()

class Adafruit_NeoPixel
{
    public:

        // Constructor: number of LEDs, pin number, LED type
        Adafruit_NeoPixel(uint16_t n, uint8_t p=2, uint8_t t=WS2812B);
        ~Adafruit_NeoPixel();

        void
            begin(void),
            show(void) __attribute__((optimize("Ofast"))),
            setPin(uint8_t p),
            setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
            setPixelColor(uint16_t n, uint32_t c),
            setBrightness(uint8_t);
        uint8_t *getPixels() const;
        uint16_t numPixels(void) const;
        static uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
        uint32_t getPixelColor(uint16_t n) const;

    private:
        const uint16_t
            numLEDs,       // Number of RGB LEDs in strip
            numBytes;      // Size of 'pixels' buffer below
        const uint8_t
            type;          // Pixel type flag (400 vs 800 KHz)
        uint8_t
            pin,           // Output pin number
            brightness,
            *pixels;        // Holds LED color values (3 bytes each)
        uint32_t
            endTime;       // Latch timing reference
};

#endif // NEOPIXEL_H
