//--------------------------------------------------------------------------------------------------------DEFINE------------------------------------------------------------------------------//

#include <U8g2lib.h>
#include <AsyncDelay.h>
#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

AsyncDelay tick;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R2, SCL, SDA, U8X8_PIN_NONE);

//------------------------------------------------------------------------------------------------------------IMAGES----------------------------------------------------------------------------//

static const unsigned char bg[] U8X8_PROGMEM = {
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff };


static const unsigned char happy_frog_a[] U8X8_PROGMEM = {
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xe7,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0x7f,0xfe,0xff,0xff,0x87,0x7f,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xf8,0xff,0xff,0x3f,0xff,0xff,0xff,0x3f,0xff,0xff,0xff,0xff,0xff,
 0x07,0xf0,0x1f,0xe0,0xff,0xff,0xcf,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0x3f,
 0xf8,0x01,0x80,0x0f,0xc0,0xff,0xff,0xe7,0xff,0xff,0xff,0xff,0xf9,0xff,0xff,
 0x0f,0x40,0xe0,0x03,0x80,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0x87,0x03,0xfc,0x1f,0xe0,0x9f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xe3,0x0f,0xfe,0xff,0xf1,0x1c,0xff,0xff,0xff,0xef,0xff,0xff,0xff,
 0xff,0xff,0xff,0xe3,0x38,0xff,0xff,0x73,0x1b,0x0f,0xff,0xff,0xf0,0xff,0xff,
 0xff,0xff,0x0f,0xff,0x73,0xfb,0xff,0xff,0x7f,0x3b,0x67,0xf8,0x3f,0xff,0xff,
 0xff,0xff,0xff,0x6f,0xfc,0x73,0xfb,0xff,0xff,0x7f,0x1b,0x67,0xfa,0xff,0xff,
 0xff,0xff,0xff,0xff,0xe1,0xf1,0x73,0xfb,0xbf,0xfe,0xff,0x1f,0xe7,0xfb,0xff,
 0xff,0xff,0xff,0xff,0xff,0xed,0x87,0xe3,0xff,0xbf,0xfe,0xff,0x8f,0xe7,0xe1,
 0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1f,0xc3,0xff,0xff,0xff,0xff,0xc3,0xf7,
 0xef,0xff,0xff,0xff,0xff,0xff,0x7f,0xfe,0x1f,0x86,0xdb,0xff,0xff,0xbb,0xe3,
 0xf3,0xe7,0xff,0xff,0xff,0xff,0xff,0x3f,0xfc,0x3f,0x8c,0xdd,0x3f,0xfe,0xdb,
 0xe3,0xf3,0x07,0xff,0xff,0xff,0xff,0xff,0x9f,0xff,0xff,0xc0,0xee,0x9f,0xfc,
 0xed,0xe7,0xfb,0x3f,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xe0,0xf6,0xcf,
 0xf9,0xed,0xc7,0xf9,0x9f,0xff,0xff,0xff,0xff,0xff,0x9f,0xff,0xff,0xe1,0xff,
 0xe7,0xfb,0xff,0x4f,0xf8,0x9f,0xff,0xff,0xff,0xff,0xff,0xbf,0xff,0xff,0xf1,
 0xff,0xe7,0xf8,0xff,0x4f,0xfc,0x3f,0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0xff,
 0xe3,0xff,0x0f,0xfe,0xff,0x0f,0xfc,0x7f,0xff,0xff,0xff,0xff,0xff,0x7f,0xfe,
 0xff,0xe3,0xff,0xff,0xff,0xff,0x1f,0xfe,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,
 0xc8,0xff,0xc7,0xff,0xff,0xff,0xff,0x0f,0xff,0x1f,0xff,0xff,0xff,0xff,0xff,
 0xff,0xc3,0xff,0x87,0xff,0x7f,0xf8,0xff,0x8f,0xff,0x0f,0xff,0xff,0xff,0xff,
 0xff,0xff,0x8f,0xff,0x8f,0xff,0x07,0xc7,0xff,0x87,0xff,0x8f,0xff,0xff,0xff,
 0xff,0xff,0xff,0x9f,0xff,0x1f,0xff,0xf1,0x1f,0xff,0x83,0xff,0x87,0xff,0xff,
 0xff,0xff,0xff,0xff,0x1f,0xff,0x1f,0xfe,0xfc,0x7f,0xfe,0xc3,0xff,0xc3,0xff,
 0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0x3f,0x7e,0xfe,0xff,0xfc,0xe1,0xff,0xc3,
 0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xfe,0x7f,0x3c,0xff,0xff,0xf9,0xf1,0xff,
 0xc3,0xdf,0xff,0xff,0xff,0xff,0xff,0x7f,0xfe,0x7f,0xbc,0xff,0xff,0xfb,0xf0,
 0xff,0xf1,0x1f,0xfc,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0x98,0xff,0xff,0x73,
 0xf8,0xff,0xf8,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xd1,0xff,0xff,
 0x77,0xfc,0x7f,0xfc,0xff,0xf7,0xff,0xff,0xff,0x3f,0xff,0xf8,0xff,0xc1,0xff,
 0xff,0x37,0xfe,0x3f,0xfe,0xff,0xff,0xff,0xff,0xff,0x01,0xff,0xf1,0xff,0xc3,
 0xff,0xff,0x37,0xfe,0x3f,0xfe,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,
 0xc7,0xff,0xff,0x0f,0xfe,0x1f,0xff,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,
 0xff,0xc7,0xff,0xff,0x0f,0xff,0x1f,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,
 0xe7,0xff,0x8f,0xff,0xff,0x8f,0xff,0x8f,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,
 0xf3,0xc7,0xff,0x8f,0xff,0xff,0x8f,0xff,0xcf,0xff,0x9f,0xff,0xff,0xff,0xff,
 0xff,0xfb,0xc7,0xff,0x1f,0xff,0xff,0x87,0xff,0xc7,0xff,0x3f,0xff,0xff,0xff,
 0xff,0xff,0xf9,0x8f,0xff,0x3f,0xfe,0xff,0xc7,0xff,0xe3,0xff,0x7f,0xff,0xff,
 0xff,0xff,0xff,0xfd,0x9f,0xff,0x3f,0xfe,0xff,0xe3,0xff,0xe3,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xfe,0x1f,0xff,0x7f,0xfc,0x7f,0xe0,0xff,0xf1,0xff,0xff,
 0xff,0xff,0xff,0xff,0x7f,0xfe,0x1f,0xff,0x7f,0xf0,0x07,0xf0,0xff,0xf0,0xff,
 0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0x3f,0xfe,0xff,0x0f,0x00,0xff,0xff,0xf8,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfe,0xff,0x0f,0xfc,0xff,0xff,
 0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0xff,0xff,0xff,
 0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0xff,0xff,
 0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0x03,
 0xe0,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,
 0x00,0xc0,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,
 0x3f,0x00,0x00,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xf9,0x1f,0x00,0x00,0xfe,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xf9,0x0f,0x00,0x00,0xfc,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xf9,0x07,0x00,0x00,0xfc,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xf9,0x07,0x00,0x00,0xf8,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xf9,0x07,0x00,0x00,0xf8,0xff,0xfc,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xf9,0x03,0x00,0x00,0xf8,0xff,0xfc,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x03,0x00,0x00,0xf0,0xff,0xf8,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x03,0x00,0x00,0xf0,0xff,0xf8,0xff,
 0xff,0xff,0xff,0xff };

static const unsigned char happy_frog_b[] U8X8_PROGMEM = {
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xfd,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0x9f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0x3f,0xfe,0xff,0xff,0xf3,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0x9f,0xff,0xff,0xff,0xcf,0xbf,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xf8,0xff,0xff,0xcf,0xff,0xff,0xff,0x3f,0xff,0xff,0xff,0xff,0xff,
 0x07,0xf0,0x1f,0xe0,0xff,0xff,0xe7,0xff,0xff,0xff,0xff,0xfc,0x1f,0xfe,0x3f,
 0xf8,0x01,0x80,0x0f,0xc0,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xf9,0xdf,0xfe,
 0x0f,0x40,0xe0,0x03,0x80,0x8f,0x7f,0x32,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,
 0xfc,0x87,0x03,0xfc,0x1f,0xe0,0x9f,0x3f,0x07,0xfe,0xff,0xff,0xff,0xff,0xff,
 0x9c,0xf9,0xe3,0x0f,0xfe,0xff,0xf1,0x1c,0xbf,0xe7,0xfe,0x81,0xff,0xff,0xff,
 0xff,0xfc,0xf1,0xe3,0x38,0xff,0xff,0x73,0x1b,0x9f,0xff,0x7e,0xfc,0xff,0xff,
 0xff,0x3f,0xf8,0xe1,0x73,0xfb,0xff,0xff,0x7f,0x3b,0x8f,0xff,0xf8,0xff,0xff,
 0xff,0xff,0x9f,0xff,0xc3,0x73,0xfb,0xff,0xff,0x7f,0x1b,0x8f,0xff,0xf0,0xff,
 0xff,0xff,0xff,0xdf,0xff,0xc7,0x73,0xfb,0xbf,0xfe,0xff,0x1f,0xc7,0xff,0xe7,
 0xff,0xff,0xff,0xff,0xdf,0xff,0x8f,0xe3,0xff,0xbf,0xfe,0xff,0x8f,0xc7,0xff,
 0xef,0xff,0xff,0xff,0xff,0x9f,0xff,0x0f,0xc3,0xff,0xff,0xff,0xff,0xc3,0xe3,
 0xff,0xe7,0xff,0xff,0xff,0xff,0x3f,0xff,0x1f,0x86,0xdb,0xff,0xff,0xbb,0xe3,
 0xe3,0xff,0xf3,0xff,0xff,0xff,0xff,0x3f,0xfe,0x3f,0x8c,0xdd,0x3f,0xfe,0xdb,
 0xe3,0xf1,0xff,0xf1,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0xc0,0xee,0x9f,0xf9,
 0xed,0xe7,0xf9,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xe0,0xf6,0xcf,
 0xf3,0xed,0xc7,0xf8,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xe1,0xff,
 0xe7,0xf7,0xff,0x4f,0xf8,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xf1,
 0xff,0xc7,0xf8,0xff,0x4f,0xfc,0x7f,0xfc,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,
 0xe3,0xff,0x1f,0xfe,0xff,0x0f,0xfc,0x3f,0xfe,0xff,0xff,0xff,0xff,0xff,0xe7,
 0xff,0xe3,0xff,0xff,0xff,0xff,0x1f,0xfe,0x3f,0xfe,0xff,0xff,0xff,0xff,0xff,
 0xc7,0xff,0xc7,0xff,0xff,0xff,0xff,0x0f,0xff,0x1f,0xff,0xff,0xff,0xff,0xff,
 0xff,0xc7,0xff,0x87,0xff,0x7f,0xf8,0xff,0x8f,0xff,0x1f,0xff,0xff,0xff,0xff,
 0xff,0xff,0x8f,0xff,0x8f,0xff,0x07,0xc7,0xff,0x87,0xff,0x9f,0xff,0xff,0xff,
 0xff,0xff,0xff,0x9f,0xff,0x1f,0xff,0xf1,0x1f,0xff,0x83,0xff,0x8f,0xff,0xff,
 0xff,0xff,0xff,0xff,0x1f,0xff,0x1f,0xfe,0xfc,0x7f,0xfe,0xc3,0xff,0xc7,0xff,
 0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0x3f,0x7e,0xfe,0xff,0xfc,0xe1,0xff,0xc3,
 0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xfe,0x7f,0x3c,0xff,0xff,0xf9,0xf1,0xff,
 0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfe,0x7f,0xbc,0xff,0xff,0xfb,0xf0,
 0xff,0xf1,0x1f,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0x98,0xff,0xff,0x73,
 0xf8,0xff,0xf8,0x7f,0xf8,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xd1,0xff,0xff,
 0x77,0xfc,0x7f,0xfc,0xff,0xe3,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xc1,0xff,
 0xff,0x37,0xfe,0x3f,0xfe,0xff,0xff,0xff,0xff,0xff,0x0f,0xfe,0xf1,0xff,0xc3,
 0xff,0xff,0x37,0xfe,0x3f,0xfe,0xfb,0xff,0xff,0xff,0xff,0xf1,0xff,0xf1,0xff,
 0xc7,0xff,0xff,0x0f,0xfe,0x1f,0xff,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,
 0xff,0xc7,0xff,0xff,0x0f,0xff,0x1f,0xff,0xe7,0xff,0xff,0xff,0xff,0xff,0xf3,
 0xe7,0xff,0x8f,0xff,0xff,0x8f,0xff,0x8f,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,
 0xf9,0xc7,0xff,0x8f,0xff,0xff,0x8f,0xff,0xcf,0xff,0x9f,0xff,0xff,0xff,0xff,
 0xff,0xfd,0xc7,0xff,0x1f,0xff,0xff,0x87,0xff,0xc7,0xff,0x3f,0xff,0xff,0xff,
 0xff,0xff,0xfc,0x8f,0xff,0x3f,0xfe,0xff,0xc7,0xff,0xe3,0xff,0x7f,0xff,0xff,
 0xff,0xff,0x7f,0xfe,0x9f,0xff,0x3f,0xfe,0xff,0xe3,0xff,0xe3,0xff,0xff,0xff,
 0xff,0xff,0xff,0x3f,0xff,0x1f,0xff,0x7f,0xfc,0x7f,0xe0,0xff,0xf1,0xff,0xff,
 0xff,0xff,0xff,0xff,0xbf,0xff,0x1f,0xff,0x7f,0xf0,0x07,0xf0,0xff,0xf0,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xfe,0xff,0x0f,0x00,0xff,0xff,0xf8,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfe,0xff,0x0f,0xfc,0xff,0xff,
 0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0xff,0xff,0xff,
 0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0xff,0xff,
 0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0x03,
 0xe0,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,
 0x00,0xc0,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,
 0x3f,0x00,0x00,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xf9,0x1f,0x00,0x00,0xfe,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xf9,0x0f,0x00,0x00,0xfc,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xf9,0x07,0x00,0x00,0xfc,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xf9,0x07,0x00,0x00,0xf8,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xf9,0x07,0x00,0x00,0xf8,0xff,0xfc,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xf9,0x03,0x00,0x00,0xf8,0xff,0xfc,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x03,0x00,0x00,0xf0,0xff,0xf8,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x03,0x00,0x00,0xf0,0xff,0xf8,0xff,
 0xff,0xff,0xff,0xff };

static const unsigned char buttonFrog[] U8X8_PROGMEM = {
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0x1f,0x98,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xf9,0x0f,0x00,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xe0,
 0x1f,0x00,0x3f,0xe0,0x8f,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,
 0xc0,0x07,0x00,0x0e,0xc7,0x8f,0x43,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0x07,0x00,0xe3,0x1f,0xc4,0x8f,0xcf,0xe3,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0x83,0x0f,0xf8,0xff,0xe0,0x9f,0xcf,0xf3,0xfc,0xff,0xff,0xff,0xff,0xff,
 0xe0,0xff,0xc3,0x3f,0xfc,0xff,0xf3,0x39,0xcf,0x7f,0xfc,0xff,0xff,0xff,0xff,
 0xff,0xc0,0xff,0xe1,0x7f,0xfe,0xff,0xf3,0x38,0xcf,0x3f,0xfe,0xff,0xff,0xff,
 0xff,0x83,0xc4,0xff,0x71,0xf8,0xff,0xff,0xff,0x38,0x8f,0x1f,0xff,0xff,0xff,
 0xff,0xff,0x03,0xce,0xff,0x79,0xf8,0xff,0xff,0xff,0x38,0x8f,0x87,0xff,0xff,
 0xff,0xff,0xff,0x03,0xce,0xff,0x79,0xf0,0xbf,0xfe,0xff,0x3f,0x0f,0xc3,0xff,
 0xff,0xff,0xff,0xff,0x33,0xce,0xff,0xf9,0xf8,0xbf,0xfc,0xff,0x1f,0x0f,0xe1,
 0xff,0xff,0xff,0xff,0xff,0x73,0xce,0xff,0xf1,0xff,0xbf,0xff,0xef,0x8f,0x1f,
 0xf0,0xff,0xff,0xff,0xff,0xff,0x73,0xce,0xff,0xf3,0x5b,0xfe,0xff,0x64,0xc3,
 0x3f,0xf8,0xff,0xff,0xff,0xff,0xff,0xe7,0xcf,0xff,0xe3,0x59,0xff,0xff,0x36,
 0xc3,0x3f,0xfe,0xff,0xff,0xff,0xff,0xff,0xc7,0xc7,0xff,0xe3,0x4d,0xf7,0xf7,
 0xb6,0x8f,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0xc6,0xff,0xe3,0x2d,0xe7,
 0xf3,0xf3,0x8f,0xff,0xff,0x07,0x81,0xff,0xff,0xff,0x7f,0xe0,0xff,0xf3,0xfd,
 0x8f,0xf8,0xff,0x9f,0xff,0xff,0x07,0x88,0xff,0xff,0xff,0xff,0xe3,0xff,0xf1,
 0xff,0x3f,0xfe,0xff,0x1f,0xff,0xff,0xe7,0x9c,0xff,0xff,0xff,0xff,0xff,0xff,
 0xf1,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0x67,0x9e,0xff,0xff,0xff,0xff,0xff,
 0xff,0xf1,0xff,0xff,0xff,0xff,0x3f,0xff,0xff,0xc7,0x8f,0xff,0xff,0xff,0xff,
 0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0x3f,0xff,0xff,0xc7,0xcf,0xff,0xff,0xff,
 0xff,0xff,0xff,0xf8,0xff,0xc7,0xff,0xff,0x3f,0xff,0xff,0xc7,0xc7,0xff,0xff,
 0xff,0xff,0xff,0xff,0xf8,0xff,0xb9,0xff,0xff,0x3f,0xff,0xff,0x87,0xe3,0xff,
 0xff,0xff,0xff,0xff,0xff,0xf0,0x1f,0xbc,0xff,0xff,0x3f,0xff,0xff,0x8f,0xf1,
 0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xcf,0xbc,0xff,0xff,0x3f,0xff,0xff,0x0f,
 0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xef,0x91,0xff,0xff,0xbf,0xff,0xff,
 0x1f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xef,0x00,0xfe,0xff,0xbf,0xff,
 0xff,0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0x6f,0xe0,0xfe,0xff,0x9f,
 0xff,0xff,0x7f,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0x1f,0xe0,0xfc,0xff,
 0x9f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0x1f,0xe0,0xfd,
 0xff,0xdf,0xff,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xdf,0xc0,
 0xfc,0xff,0xcf,0xff,0x07,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0f,0xdf,
 0x1b,0xfe,0xff,0xc7,0x1f,0x26,0xfe,0xff,0xff,0xff,0xff,0xff,0x70,0xf0,0x07,
 0xde,0xb9,0xff,0xff,0x87,0x0f,0x70,0xfe,0xff,0xff,0xff,0xff,0xff,0xa0,0xf1,
 0x07,0xdc,0x39,0xff,0xff,0x81,0x8f,0x70,0xfe,0xff,0xff,0xff,0xff,0xff,0xcc,
 0xf1,0x63,0x18,0x30,0xff,0xff,0x18,0x8f,0x79,0xff,0xff,0xff,0xff,0xff,0xff,
 0xdc,0xf1,0xf1,0xe0,0x91,0xff,0x7f,0x1c,0x1e,0x3b,0xff,0xff,0xff,0xff,0xff,
 0xff,0xfc,0xfd,0xf1,0x81,0xc1,0xff,0x1f,0x3e,0x1e,0x3f,0xff,0xff,0xff,0xff,
 0xff,0xff,0xfd,0xfc,0xf9,0x0f,0xf0,0xff,0x83,0x7f,0x3c,0x9c,0xff,0xff,0xff,
 0xff,0xff,0xff,0xf9,0xfe,0xfc,0x7f,0x00,0x00,0xe0,0x7f,0xfc,0x98,0xff,0xff,
 0xff,0xff,0xff,0xff,0x73,0xfe,0xfc,0xff,0xf1,0xff,0xff,0x7f,0xf8,0xc1,0xff,
 0xff,0xff,0xff,0xff,0xff,0x33,0x7f,0xfc,0xff,0xf1,0xff,0xff,0xff,0xf8,0xe7,
 0xff,0xff,0xff,0xff,0xff,0xff,0x87,0x7f,0xfe,0xe1,0xf1,0xff,0xff,0xff,0xf8,
 0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0x7f,0x7e,0x00,0xf1,0xff,0x01,0xfc,
 0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x7e,0x0e,0xf0,0xff,0x00,
 0xfc,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xfe,0x1f,0xf0,0xff,
 0x78,0xfe,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0x7f,0xf0,
 0x7f,0xfe,0x7f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xff,0x7f,
 0xf8,0x7f,0xfe,0x7f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xfe,
 0x3f,0xf8,0x7f,0xfe,0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,
 0xfe,0x1f,0xfc,0x7f,0xfe,0x1f,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0x7f,0xfe,0x0f,0x1e,0x7c,0xfe,0x0f,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xfe,0x03,0xc3,0x73,0xfc,0x03,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xfc,0xc0,0xfb,0xe7,0x40,0x20,0xfe,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0x01,0xf0,0xfd,0xcf,0x01,0x30,0xfe,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0x0f,0xfc,0xfc,0xdf,0x03,0x1c,0xfe,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0x7f,0xfe,0x9f,0x8f,0x1f,0xfe,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0x7f,0xff,0xbf,0xff,0x1f,0xfe,0xff,
 0xff,0xff,0xff,0xff };

static const unsigned char coldFrog1[] U8X8_PROGMEM = {
 0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xcf,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0x9f,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0x09,0xa0,0xff,0xc3,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xf9,0xff,0x3f,0xfc,0xe0,0x0f,0xff,0x19,
 0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0x67,0xfc,0xff,0x87,0x78,0xfe,0x3f,0xfe,
 0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0xfe,0xff,0xd3,0x3b,0xfe,0xff,
 0xfc,0xff,0xf0,0x7f,0xf8,0xff,0xff,0xff,0xff,0x0f,0xff,0xff,0xf8,0x9f,0xff,
 0xff,0xfc,0xf8,0xf3,0x7f,0xe0,0xff,0xff,0xff,0xff,0x7f,0xfe,0xff,0xfe,0x9f,
 0x07,0x70,0x1c,0xe0,0xfb,0x7f,0xf0,0xff,0xfe,0xff,0xff,0x7f,0xfc,0xff,0x3e,
 0xb8,0x01,0x00,0x0c,0xc0,0xfb,0x7f,0xfb,0x9f,0xfe,0xff,0xff,0x7f,0xfd,0xff,
 0x0f,0x00,0xe0,0x03,0x80,0x8f,0xf3,0xff,0xe1,0x3f,0xf8,0xff,0xff,0x7f,0xff,
 0xff,0x87,0x03,0xfc,0x1f,0xe0,0x9f,0xf7,0xff,0xed,0x1f,0xfe,0xff,0xff,0xff,
 0xff,0xff,0xe3,0x0f,0xfe,0xff,0xf1,0x1c,0xe7,0xff,0xff,0x7f,0xfc,0xff,0xff,
 0xff,0xff,0xff,0xe3,0x38,0xff,0xff,0x73,0x18,0xe7,0xff,0xff,0xff,0xfd,0xff,
 0xff,0xff,0xff,0xff,0x73,0xf8,0xff,0xff,0x7f,0x38,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0x73,0xf8,0xff,0xff,0x7f,0x18,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x73,0xf8,0xbf,0xfe,0xff,0x1f,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xbf,0xfe,0xff,0x8f,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xc3,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x87,0xdb,0xef,0xff,0xbb,0xe3,
 0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xdd,0x03,0xf8,0xdb,
 0xe3,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0xee,0x03,0xf0,
 0xed,0xe7,0xff,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xf6,0x3b,
 0xf6,0xed,0xc7,0xff,0xef,0xff,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xff,
 0xff,0xff,0xff,0xcf,0xff,0xff,0xff,0xf8,0xff,0xff,0x3f,0xff,0xff,0xff,0xf0,
 0xff,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,0xc1,0xff,0xff,0x3f,0xff,0xff,0xeb,
 0xf0,0xff,0xff,0xff,0xff,0x8f,0xff,0xff,0xff,0xf3,0xff,0xff,0x1f,0xfe,0x7f,
 0xe2,0xf8,0xff,0xff,0xff,0xff,0x9f,0xff,0xff,0x0f,0xe0,0xff,0xff,0xff,0xff,
 0xff,0xf1,0xfc,0xff,0xff,0xff,0xff,0x8f,0xff,0xff,0x7f,0xca,0xff,0xff,0xff,
 0xff,0xff,0xe3,0xfc,0xff,0x7f,0xf8,0xff,0x9f,0xff,0xff,0xff,0xdb,0xff,0xff,
 0xff,0xff,0x7f,0xe0,0xf8,0xff,0x07,0xc7,0xff,0x9f,0xff,0xff,0xff,0xfb,0xff,
 0xff,0xff,0xff,0xff,0xeb,0xf9,0xff,0xf1,0x1f,0xff,0x9f,0xff,0xff,0xff,0xfd,
 0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xff,0xfc,0x7f,0xfe,0x8f,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0x7f,0xfe,0xff,0xfc,0xcf,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0x3f,0xff,0xff,0xf9,0xcf,0xfb,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xbf,0xff,0xff,0xfb,0xcf,
 0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0x9f,0xff,0xff,0xf3,
 0xc7,0xf1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xdf,0xff,0xff,
 0xf7,0xe7,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xcf,0xff,
 0xff,0xf7,0xc3,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xcf,
 0xff,0xff,0xf7,0x83,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,
 0xcf,0xff,0xff,0xcf,0x01,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0x1f,0xcf,0xff,0xff,0xcf,0x11,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0x3f,0x9e,0xff,0xff,0xcf,0x38,0x9e,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,
 0xff,0xff,0x1f,0x9c,0xff,0xff,0x4f,0x30,0xfe,0x7f,0xff,0xff,0xff,0xff,0xff,
 0xe5,0xff,0xff,0x1f,0x10,0xff,0xff,0x07,0x72,0xfc,0x7f,0xcc,0xff,0xff,0xff,
 0x9f,0xe1,0xff,0xff,0x8f,0x21,0xfe,0xff,0x07,0x73,0xfc,0xff,0xe4,0xff,0xff,
 0xff,0x7f,0xf8,0xff,0xff,0x8f,0x03,0xfe,0xff,0x03,0xe3,0xfc,0x3f,0xf0,0xff,
 0xf7,0xff,0x3f,0xe1,0xff,0xff,0xc7,0x0f,0xf0,0x7f,0xc0,0xe7,0xfc,0xff,0xf1,
 0xff,0x27,0xff,0xff,0xcd,0xff,0xff,0xe7,0x1f,0xf0,0x07,0xe0,0xc7,0xfc,0xff,
 0xf5,0xff,0x8f,0xff,0xff,0xfd,0xff,0xff,0xe3,0xff,0x0f,0x00,0xc7,0xc7,0xf8,
 0xff,0xff,0xff,0x9f,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0x0f,0xfc,0xc7,0x4f,
 0xf8,0xff,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xcf,
 0x0f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,
 0xcf,0x0f,0xf1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xe1,0xff,0xff,
 0xff,0x8f,0x8f,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xc0,0xff,
 0xff,0xff,0x8f,0x9f,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0x05,
 0xff,0xff,0xff,0x87,0x9f,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,
 0x1d,0xf0,0xff,0x7f,0x80,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xe0,0x7c,0x00,0x00,0x00,0x80,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xeb,0xfc,0x03,0x00,0x00,0x9f,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xe7,0xfc,0xff,0xff,0xff,0x9f,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xe7,0xfc,0xff,0xff,0xff,0x1f,0x9f,0xe7,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xef,0xfc,0xff,0xff,0xff,0x1f,0x9f,0xe7,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xef,0xfc,0xff,0xff,0xff,0x3f,0x9f,0xe7,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xfc,0xff,0xff,0xff,0x3f,0x9f,0xe7,0xff,
 0xff,0xff,0xff,0xff };

static const unsigned char coldFrog2[] U8X8_PROGMEM = {
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xe3,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xcf,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xf9,0x9f,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0xff,0xff,0x00,0x00,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0xfd,0xff,0xff,0xff,0xf8,0x7f,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0xfc,0xff,0xff,0x3f,0xfe,0x7f,
 0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x5f,0xfe,0xff,0xf1,0x9f,0xff,
 0xff,0x3e,0xe0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0x7f,0xec,0x9f,
 0xff,0xff,0x0e,0x80,0xff,0x2f,0xf9,0xff,0xff,0xff,0xff,0x7f,0xff,0x7f,0x3f,
 0x98,0x03,0x00,0x84,0x8f,0xff,0x0f,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,
 0x0f,0x80,0x00,0x00,0xe0,0x1f,0xff,0x3f,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,
 0xbf,0x87,0x03,0xf8,0x7f,0xe0,0x1f,0xff,0x0f,0xf1,0x9f,0xff,0xff,0xff,0xff,
 0xff,0xbf,0xc7,0x1f,0xff,0xff,0xff,0x38,0xff,0xff,0xff,0x1f,0xfe,0xff,0xff,
 0xff,0xff,0x9f,0xe3,0xfc,0xff,0xff,0x7f,0x30,0xfe,0xff,0xff,0x07,0xff,0xff,
 0xff,0xff,0xff,0xdf,0x63,0xf8,0xff,0xff,0x7f,0x70,0xfe,0xff,0xff,0xbf,0xfc,
 0xff,0xff,0xff,0xff,0xdf,0x73,0xf8,0xff,0xff,0x7f,0x38,0xfe,0xff,0xff,0x9f,
 0xff,0xff,0xff,0xff,0xff,0x9f,0x73,0xf8,0xdf,0xfe,0xff,0x3f,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x9f,0xe3,0xff,0xdf,0xfe,0xff,0x1f,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xc7,0xff,0xff,0xff,0xf7,0x07,0xff,
 0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x87,0xdd,0xf7,0xf0,0xb3,0x87,
 0xff,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xdd,0x17,0xf0,0xb9,
 0xc7,0xfd,0xd7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xdd,0x03,0xe0,
 0x9d,0xc7,0xfc,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xde,0xab,
 0xe0,0xdd,0xcf,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xf3,0xdf,
 0xaf,0xff,0xff,0xcf,0xfb,0xff,0xff,0xff,0xff,0xff,0x1f,0xfc,0xff,0xf3,0xf3,
 0xff,0xff,0xff,0xff,0x8f,0xfb,0xff,0xff,0xfd,0xff,0xff,0x7f,0xfe,0x7f,0xf0,
 0xf3,0xff,0xff,0xff,0xff,0x9f,0xfb,0xff,0x7f,0xfd,0xff,0xff,0x7f,0xfe,0xff,
 0xe0,0xf3,0xff,0xff,0xff,0xff,0x9f,0xf9,0xff,0x7f,0xec,0xff,0xff,0xff,0xff,
 0x7f,0xf0,0xf3,0xff,0xff,0xff,0xff,0x1f,0xfd,0xff,0x7f,0xe0,0xff,0xff,0xff,
 0xff,0x7f,0xf2,0xf3,0xff,0xff,0xff,0xff,0x1f,0xf9,0xff,0x1f,0xe0,0xff,0xff,
 0xff,0xff,0xff,0xff,0xf3,0xff,0x1f,0x00,0xff,0x3f,0xfb,0xff,0xdf,0xf8,0xff,
 0xff,0xff,0xff,0xff,0xff,0xf3,0xff,0xc7,0x7f,0xfc,0x1f,0xff,0xff,0x7f,0xf2,
 0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xff,0xf3,0xff,0xf9,0x9f,0xff,0xff,0x7f,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xff,0xf9,0xff,0xf3,0x9f,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xff,0xfc,0xff,0xf7,0x9f,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0x7f,0xfe,0xff,0xe7,0x8f,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0x7f,0xff,0xff,0xef,
 0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0x3f,0xff,0xff,
 0xef,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,0xbf,0xff,
 0xff,0xef,0x07,0xfe,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xcf,0xbf,
 0xff,0xff,0xef,0x23,0xfe,0xff,0xe9,0xff,0xff,0xff,0xff,0xfb,0xff,0xef,0x8f,
 0xbf,0xff,0xff,0xef,0x63,0xfc,0xff,0xeb,0xff,0xff,0xff,0xff,0xf1,0xff,0x0f,
 0x1f,0xbf,0xff,0xff,0xef,0xf1,0xf8,0xff,0x00,0xff,0xff,0xff,0xff,0x65,0xff,
 0x3f,0x1f,0xbe,0xff,0xff,0x6f,0xe0,0xf9,0xff,0x06,0xff,0xcf,0xff,0xff,0x01,
 0xff,0xbf,0x3f,0xbc,0xff,0xff,0x37,0xc4,0xf1,0xff,0xe7,0xff,0x1f,0xfe,0xff,
 0xcb,0xff,0x3f,0x1f,0x30,0xff,0xff,0x0f,0xc6,0xf1,0xff,0xc1,0xff,0x07,0xfe,
 0xff,0x93,0xff,0x7f,0x1f,0x01,0xff,0xff,0x83,0x8f,0xf1,0xff,0xfb,0xff,0x3f,
 0xff,0xff,0xff,0xff,0x7f,0x9f,0x03,0xfc,0xff,0xc0,0x1f,0xf1,0xff,0xff,0xff,
 0x9f,0xff,0xff,0xff,0xff,0x3f,0x8f,0x3f,0xe0,0x1f,0xc0,0x1f,0x70,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x9f,0xcf,0xff,0x01,0x00,0xc6,0x3f,0x90,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xc7,0xff,0x0f,0xc0,0xcf,0x3f,0x82,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,0xcf,0x3f,
 0x22,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,0xcf,
 0x7f,0x26,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xff,0xff,
 0x8f,0x7f,0x26,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xff,
 0xff,0x80,0x7f,0x66,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0xff,
 0xff,0x01,0x80,0x7f,0x24,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
 0x10,0x00,0x00,0x9c,0xff,0x24,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0x18,0x00,0x00,0xfc,0x9f,0xff,0xe4,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xfc,0xc7,0xff,0xff,0x9f,0xff,0xe4,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xfc,0xff,0xff,0xff,0x1f,0xff,0xe4,0xfe,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0x3f,0xff,0xe4,0xff,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0x3f,0xff,0xe4,0xff,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0x3f,0xff,0xe4,0xff,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0x3f,0xff,0xe4,0xff,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfc,0xff,0xff,0xff,0x3f,0xff,0xe4,0xff,
 0xff,0xff,0xff,0xff };

//---------------------------------------------------------------------------------------------------------CONSTANTS--------------------------------------------------------------------//

#define hfrog_width 128
#define hfrog_height 64
const int fps = 0; //3-4 ish fps
const int display_width = 164;
const int crit_temp = 20;
int animate_frame = 0;
int current_pos = -display_width;
int move_int = 3; //movement interval
int delayTime = 2000; //for flower
float temp_hum[2] = {0};

char button = 6;
char led = 4;
char rotary = A0;
char sound = A2;
//char tempsensor = 3;
//-----------------------------------------------------------------------------------------------------CODING--------------------------------------------------------------//

void setup(void) {

  u8g2.begin();
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  tick.start(fps, AsyncDelay::MILLIS);
}

void loop() {
  if (tick.isExpired()) {
  current_pos += move_int;
    if(current_pos > 2*display_width)
    {
      current_pos = .9*display_width;
    }
    if (digitalRead(button) == HIGH)
    {
      buttonPress();
    }
    if (analogRead(sound) > 380)
    {
      coldAnimate();
      //loudFrog();
    }
    else
    {
       drawFrogAnimate();
    }

    //temp and hum sensor is very slow :(
    
    /*if (!dht.readTempAndHumidity(temp_hum))
    {
      if (temp_hum[1] < crit_temp)
      {
        coldAnimate();
      } 
      else
      {
        drawFrogAnimate();
      } 
      if (animate_frame == 0)
      {
         animate_frame++;
      }
      else if (animate_frame == 1)
      {
        animate_frame--;
      }
    }*/
    if (animate_frame == 0)
      {
         animate_frame++;
      }
      else if (animate_frame == 1)
      {
        animate_frame--;
      }
    tick.repeat();
  }

} 


void drawFrogAnimate() {
  u8g2.firstPage();
  do {
    u8g2.drawXBMP(0,0, hfrog_width, hfrog_height, bg); //the background of white
    switch (animate_frame) {
      case 0:
        u8g2.drawXBMP(current_pos,0, hfrog_width, hfrog_height, happy_frog_a);
        break;
      case 1: 
        u8g2.drawXBMP(current_pos,0, hfrog_width, hfrog_height, happy_frog_b);
        break;
    }
  }
  while(u8g2.nextPage());
}

void coldAnimate() {
//cold!
u8g2.firstPage();
do {
  u8g2.drawXBMP(0,0, hfrog_width, hfrog_height, bg); //the background of white
  switch (animate_frame) {
    case 0:
      u8g2.drawXBMP(current_pos,0, hfrog_width, hfrog_height, coldFrog1);
      break;
    case 1: 
      u8g2.drawXBMP(current_pos,0, hfrog_width, hfrog_height, coldFrog2);
      break;
      }
    }
    while(u8g2.nextPage());
}

void buttonPress() {
  u8g2.firstPage();
  do {
    u8g2.drawXBMP(0,0, hfrog_width, hfrog_height, buttonFrog);
    digitalWrite(led,HIGH);
  }
  while(u8g2.nextPage());
    delay(delayTime);
    digitalWrite(led,LOW);

}
