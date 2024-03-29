// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Roboto_Mono_Bold_24Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0xFF,0x77,0x77,0x77,0x77,0x70,0x06,0xFF,0x60, // '!'
	0xE7,0xE7,0xE6,0xE6,0xC6,0xC6, // '"'
	0x06,0x30,0x18,0xC0,0x66,0x01,0x98,0x06,0x61,0xFF,0xF7,0xFF,0xC3,0x38,0x0C,0xC0,0x33,0x0F,0xFF,0xBF,0xFE,0x18,0xC0,0x66,0x01,0x98,0x06,0x60,0x31,0x80, // '#'
	0x03,0x00,0x30,0x03,0x01,0xFC,0x3F,0xE7,0x8F,0x70,0x77,0x07,0x78,0x03,0xE0,0x1F,0x80,0xFE,0x01,0xF0,0x07,0xF0,0x77,0x07,0x78,0xF7,0xFF,0x3F,0xE0,0x70,0x03,0x00,0x30, // '$'
	0x3C,0x01,0xF8,0x0E,0x62,0x39,0x98,0xE6,0xC1,0xFB,0x03,0xD8,0x00,0x60,0x03,0x00,0x0D,0xC0,0x6F,0x83,0x73,0x0D,0xCC,0x67,0x30,0x1C,0xC0,0x3F,0x00,0x78, // '%'
	0x0F,0x01,0xFC,0x0F,0xF0,0x73,0x87,0x1C,0x1C,0xE0,0xFE,0x07,0xE0,0x1E,0x03,0xF1,0xDD,0xCF,0xCF,0x7E,0x3F,0x70,0xFB,0xFF,0xCF,0xFE,0x3F,0x78, // '&'
	0xFF,0xFF,0xC0, // '''
	0x04,0x1C,0x71,0xC3,0x0E,0x1C,0x30,0xE1,0xC3,0x87,0x0E,0x1C,0x38,0x70,0xE0,0xC1,0xC1,0x83,0x83,0x07,0x82, // '('
	0x83,0x0E,0x1C,0x38,0xE1,0x87,0x1C,0x71,0xC7,0x1C,0x71,0xC7,0x1C,0x73,0x8E,0x71,0xCE,0x30, // ')'
	0x06,0x00,0x60,0x06,0x08,0x62,0xF6,0xEF,0xFF,0x0F,0x00,0xF0,0x1B,0x83,0x98,0x71,0xC1,0x08, // '*'
	0x0F,0x00,0xF0,0x0F,0x00,0xF0,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0xF0,0x0F,0x00,0xF0,0x0F,0x00, // '+'
	0x77,0x77,0x77,0xE4, // ','
	0xFF,0xFF,0xFF,0xFC, // '-'
	0x7F,0xF7, // '.'
	0x03,0x83,0x81,0xC0,0xE0,0xE0,0x70,0x38,0x38,0x1C,0x0E,0x0E,0x07,0x03,0x83,0x81,0xC0,0xE0,0xE0,0x70,0x00, // '/'
	0x1F,0x0F,0xF1,0xFF,0x78,0xEE,0x1F,0xC3,0xF8,0x7F,0x3F,0xEF,0xFF,0x3F,0xC7,0xF0,0xFE,0x1F,0xE3,0x9F,0xF3,0xFC,0x1F,0x00, // '0'
	0x03,0x1F,0xFF,0xFF,0xCF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F, // '1'
	0x1F,0x03,0xFC,0x7F,0xEF,0x0E,0xE0,0xE0,0x0E,0x00,0xE0,0x1C,0x03,0xC0,0x78,0x0F,0x01,0xE0,0x3C,0x07,0x80,0xFF,0xFF,0xFF,0xFF,0xF0, // '2'
	0x1F,0x83,0xFC,0x7F,0xEF,0x0E,0xF0,0xF0,0x0E,0x01,0xE0,0xFC,0x0F,0xC0,0xFE,0x00,0xF0,0x07,0xE0,0x7F,0x0F,0x7F,0xE7,0xFC,0x1F,0x80, // '3'
	0x01,0xC0,0x3C,0x07,0xC0,0x7C,0x0F,0xC1,0xDC,0x19,0xC3,0x9C,0x71,0xC6,0x1C,0xFF,0xFF,0xFF,0xFF,0xF0,0x1C,0x01,0xC0,0x1C,0x01,0xC0, // '4'
	0x3F,0xE3,0xFE,0x7F,0xE7,0x00,0x70,0x07,0x20,0x7F,0xC7,0xFE,0x71,0xE0,0x0F,0x00,0x70,0x07,0xF0,0xF7,0x0E,0x7F,0xE3,0xFC,0x0F,0x80, // '5'
	0x03,0x80,0xF8,0x1F,0x83,0xC0,0x78,0x07,0x30,0xFF,0xCF,0xFE,0xF8,0xEF,0x0F,0xF0,0x7F,0x07,0xF0,0xF7,0x0E,0x7F,0xE3,0xFC,0x0F,0x80, // '6'
	0xFF,0xFF,0xFF,0xFF,0xF0,0x0E,0x00,0xE0,0x1C,0x01,0xC0,0x38,0x03,0x80,0x70,0x07,0x00,0xF0,0x0E,0x01,0xE0,0x1C,0x03,0xC0,0x38,0x00, // '7'
	0x1F,0x83,0xFC,0x7F,0xE7,0x0E,0x70,0xE7,0x0E,0x7F,0xE1,0xF8,0x3F,0xC7,0x0E,0xF0,0xFF,0x0F,0xF0,0xFF,0x0F,0x7F,0xE3,0xFC,0x1F,0x80, // '8'
	0x1F,0x03,0xFC,0x7F,0xC7,0x0E,0xF0,0xEE,0x0E,0xE0,0xFF,0x0F,0x71,0xF7,0xFE,0x3F,0xE0,0xCE,0x00,0xE0,0x3C,0x1F,0x81,0xF0,0x1C,0x00, // '9'
	0x7F,0xF7,0x00,0x00,0x00,0x7F,0xF7, // ':'
	0x3B,0xDE,0x70,0x00,0x00,0x00,0x00,0xE7,0x39,0xCE,0x77,0x10, // ';'
	0x00,0x40,0x70,0xFC,0xFE,0xFE,0x3C,0x0F,0x81,0xFC,0x1F,0xC0,0xF0,0x0C, // '<'
	0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x01,0xFF,0xFF,0xFF,0xFF, // '='
	0x80,0x38,0x0F,0xC1,0xFC,0x0F,0xC0,0x70,0x7C,0xFE,0xFE,0x3C,0x0C,0x00, // '>'
	0x1F,0x0F,0xFB,0xFF,0xF0,0xFE,0x0E,0x03,0xC0,0x70,0x1C,0x0F,0x01,0xC0,0x38,0x00,0x00,0x00,0x1C,0x07,0x80,0xF0,0x0E,0x00, // '?'
	0x07,0xC0,0x3F,0xC1,0x83,0x8C,0x06,0x73,0xC9,0x9F,0x36,0xEC,0xDB,0x33,0xCC,0xCF,0x33,0x24,0xCD,0x9B,0xFE,0x67,0x71,0x80,0x03,0x04,0x07,0xF0,0x0F,0xC0, // '@'
	0x03,0x80,0x1E,0x00,0x7C,0x01,0xF0,0x0F,0xC0,0x3B,0x80,0xEE,0x07,0xB8,0x1C,0xF0,0x71,0xC3,0xC7,0x0F,0xFE,0x3F,0xF9,0xFF,0xE7,0x83,0xDC,0x0F,0xF0,0x1C, // 'A'
	0xFF,0x0F,0xFC,0xFF,0xEE,0x0E,0xE0,0xEE,0x0E,0xE1,0xEF,0xFC,0xFF,0xCF,0xFE,0xE0,0xFE,0x0F,0xE0,0xFE,0x0F,0xFF,0xEF,0xFC,0xFF,0x80, // 'B'
	0x0F,0x83,0xFE,0x7F,0xE7,0x0F,0xF0,0x7E,0x07,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xF0,0x77,0x0F,0x7F,0xE3,0xFE,0x0F,0x80, // 'C'
	0xFF,0x0F,0xFC,0xFF,0xEF,0x1E,0xF0,0xFF,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0xFF,0x1E,0xFF,0xEF,0xFC,0xFF,0x00, // 'D'
	0xFF,0xFF,0xFF,0xFF,0xF0,0x0E,0x01,0xC0,0x38,0x07,0xFE,0xFF,0xDF,0xFB,0x80,0x70,0x0E,0x01,0xC0,0x3F,0xFF,0xFF,0xFF,0xE0, // 'E'
	0xFF,0xFF,0xFF,0xFF,0xF0,0x0E,0x01,0xC0,0x38,0x07,0xFE,0xFF,0xDF,0xFB,0x80,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x00, // 'F'
	0x0F,0x83,0xFE,0x7F,0xE7,0x8F,0xF0,0x7F,0x00,0xE0,0x0E,0x00,0xE3,0xFE,0x3F,0xE3,0xFE,0x07,0xF0,0x77,0x07,0x7F,0xF3,0xFE,0x0F,0xC0, // 'G'
	0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x70, // 'H'
	0xFF,0xFF,0xFF,0xFC,0x38,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x03,0x80,0xE0,0x38,0x0E,0x03,0x8F,0xFF,0xFF,0xFF,0xC0, // 'I'
	0x00,0x70,0x07,0x00,0x70,0x07,0x00,0x70,0x07,0x00,0x70,0x07,0x00,0x70,0x07,0x00,0x70,0x07,0xF0,0xF7,0x0F,0x7F,0xE3,0xFC,0x1F,0x80, // 'J'
	0xE0,0xFF,0x0F,0x38,0x79,0xC7,0x8E,0x78,0x73,0x83,0xBC,0x1F,0xC0,0xFE,0x07,0xF8,0x3D,0xE1,0xC7,0x0E,0x3C,0x70,0xF3,0x87,0x9C,0x1E,0xE0,0x78, // 'K'
	0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x3F,0xFF,0xFF,0xFF,0xE0, // 'L'
	0xF8,0xFF,0x8F,0xF9,0xFF,0x9F,0xFD,0xFE,0xFF,0xEF,0xFE,0xF7,0xE7,0x7E,0x77,0xE6,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x70, // 'M'
	0xF0,0xFF,0x0F,0xF8,0xFF,0x8F,0xFC,0xFF,0xCF,0xFE,0xFF,0xEF,0xF6,0xFF,0x7F,0xF3,0xFF,0x3F,0xF1,0xFF,0x1F,0xF1,0xFF,0x0F,0xF0,0xF0, // 'N'
	0x0F,0x83,0xFC,0x7F,0xE7,0x0F,0xF0,0x7E,0x07,0xE0,0x7E,0x07,0xE0,0x7E,0x07,0xE0,0x7E,0x07,0xF0,0x77,0x0F,0x7F,0xE3,0xFC,0x0F,0x80, // 'O'
	0xFF,0x0F,0xFC,0xFF,0xEE,0x0E,0xE0,0xFE,0x0F,0xE0,0xFE,0x1E,0xFF,0xEF,0xFC,0xFE,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x00, // 'P'
	0x0F,0x81,0xFE,0x1F,0xF8,0xE1,0xEF,0x07,0x70,0x3B,0x81,0xFC,0x0F,0xE0,0x7F,0x03,0xF8,0x1F,0xC0,0xEF,0x07,0x38,0x79,0xFF,0x87,0xFC,0x0F,0xF0,0x03,0xC0,0x0E,0x00,0x20, // 'Q'
	0xFF,0x0F,0xFC,0xFF,0xEE,0x0E,0xE0,0xEE,0x0E,0xE0,0xEE,0x1E,0xFF,0xCF,0xF8,0xFF,0x8E,0x38,0xE3,0xCE,0x1C,0xE1,0xEE,0x0E,0xE0,0xF0, // 'R'
	0x0F,0x81,0xFF,0x1F,0xFC,0xE0,0xE7,0x07,0xB8,0x01,0xE0,0x07,0xE0,0x1F,0xC0,0x3F,0x00,0x3C,0x00,0xFE,0x07,0xF8,0x3D,0xFF,0xC7,0xFC,0x0F,0xC0, // 'S'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80, // 'T'
	0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0xF0,0x7F,0x07,0x70,0xF7,0x0F,0x7F,0xE3,0xFC,0x0F,0x80, // 'U'
	0xF0,0x3D,0xC0,0xF7,0x83,0x9E,0x1E,0x38,0x78,0xE1,0xC3,0xC7,0x07,0x3C,0x1C,0xE0,0x73,0x80,0xEE,0x03,0xF8,0x0F,0xC0,0x3F,0x00,0x7C,0x01,0xE0,0x07,0x80, // 'V'
	0xE3,0x1D,0x8E,0x77,0x39,0xDD,0xE7,0x77,0x9D,0xDE,0xE7,0x7B,0x9D,0xEE,0x77,0xF8,0xDB,0xE3,0xEF,0x8F,0x3E,0x3C,0xF0,0xF3,0xC3,0xCF,0x0F,0x1C,0x1C,0x70, // 'W'
	0xF8,0x3D,0xE0,0xE3,0xC7,0x8F,0x1C,0x1E,0xF0,0x3B,0x80,0xFE,0x01,0xF0,0x07,0x80,0x1F,0x00,0xFE,0x03,0xB8,0x1E,0xF0,0xF1,0xC3,0xC7,0x9E,0x0E,0xF8,0x3C, // 'X'
	0xF0,0x3D,0xE0,0xF3,0x83,0x8F,0x1E,0x1C,0x70,0x73,0xC0,0xEE,0x03,0xB8,0x0F,0xC0,0x1F,0x00,0x78,0x00,0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80, // 'Y'
	0xFF,0xF7,0xFF,0xBF,0xFC,0x01,0xC0,0x1E,0x01,0xE0,0x0E,0x00,0xF0,0x0F,0x00,0x70,0x07,0x80,0x78,0x03,0x80,0x3C,0x03,0xFF,0xFF,0xFF,0xFF,0xF8, // 'Z'
	0xFF,0xFF,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0x7F,0xFF, // '['
	0xE0,0x70,0x1C,0x0E,0x07,0x01,0xC0,0xE0,0x70,0x1C,0x0E,0x07,0x01,0xC0,0xE0,0x78,0x1C,0x0E,0x03,0x81,0xC0, // '\'
	0xFF,0xFE,0x73,0x9C,0xE7,0x39,0xCE,0x73,0x9C,0xE7,0x39,0xCE,0x73,0xFF,0xFF, // ']'
	0x1C,0x0E,0x0F,0x86,0xC7,0x63,0x39,0x8D,0xC7,0xC1,0x80, // '^'
	0xFF,0xFF,0xFF,0xFC, // '_'
	0xF3,0x8E, // '`'
	0x1F,0x83,0xFC,0x7F,0xE7,0x0E,0x00,0xE1,0xFE,0x7F,0xE7,0x0E,0xF0,0xEF,0x0E,0x7F,0xE7,0xFE,0x3E,0xF0, // 'a'
	0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xDE,0x3F,0xF7,0xFE,0xE1,0xFC,0x1F,0x83,0xF0,0x7E,0x0F,0xC1,0xF8,0x7F,0xFE,0xFF,0xDD,0xE0, // 'b'
	0x0F,0x83,0xFC,0x7F,0xE7,0x0F,0x70,0x7F,0x00,0xF0,0x0F,0x00,0x70,0x77,0x0F,0x7F,0xE3,0xFC,0x0F,0x80, // 'c'
	0x00,0xF0,0x0F,0x00,0xF0,0x0F,0x00,0xF1,0xEF,0x3F,0xF7,0xFF,0x70,0xFF,0x0F,0xF0,0xFF,0x0F,0xF0,0xFF,0x0F,0x70,0xF7,0xFF,0x3F,0xF1,0xE7, // 'd'
	0x0F,0x83,0xFC,0x7F,0xE7,0x07,0x70,0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0x07,0x82,0x7F,0xF3,0xFE,0x0F,0x80, // 'e'
	0x00,0xE8,0x1F,0x81,0xFC,0x1E,0x00,0xE0,0x07,0x03,0xFF,0xDF,0xFE,0xFF,0xF0,0x70,0x03,0x80,0x1C,0x00,0xE0,0x07,0x00,0x38,0x01,0xC0,0x0E,0x00,0x70,0x03,0x80, // 'f'
	0x1F,0x73,0xFF,0x7F,0xF7,0x0F,0x70,0x7F,0x07,0xF0,0x7F,0x07,0x70,0x77,0x0F,0x7F,0xF3,0xFF,0x1E,0x70,0x0F,0x20,0xF7,0xFE,0x3F,0xC1,0xF8, // 'g'
	0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xCF,0x3F,0xF7,0xFF,0xE1,0xFC,0x1F,0x83,0xF0,0x7E,0x0F,0xC1,0xF8,0x3F,0x07,0xE0,0xFC,0x1C, // 'h'
	0x1C,0x07,0x81,0xC0,0x00,0x00,0x3F,0x0F,0xC3,0xF0,0x1C,0x07,0x01,0xC0,0x70,0x1C,0x07,0x01,0xC3,0xFF,0xFF,0xFF,0xF0, // 'i'
	0x0E,0x1C,0x38,0x00,0x0F,0xDF,0xBF,0x0E,0x1C,0x38,0x70,0xE1,0xC3,0x87,0x0E,0x1C,0x38,0xFF,0xFF,0xBE,0x00, // 'j'
	0xE0,0x0E,0x00,0xE0,0x0E,0x00,0xE0,0x0E,0x1E,0xE3,0xCE,0x78,0xEF,0x0F,0xE0,0xFE,0x0F,0xE0,0xFF,0x0F,0x78,0xE3,0x8E,0x3C,0xE1,0xEE,0x0F, // 'k'
	0xFE,0x1F,0xC3,0xF8,0x07,0x00,0xE0,0x1C,0x03,0x80,0x70,0x0E,0x01,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x03,0x87,0xFF,0xFF,0xFF,0xFC, // 'l'
	0xEE,0xEF,0xFF,0xFF,0xFE,0x77,0xE7,0x7E,0x77,0xE7,0x7E,0x77,0xE7,0x7E,0x77,0xE7,0x7E,0x77,0xE7,0x70, // 'm'
	0xEF,0x9F,0xFB,0xFF,0xF0,0xFE,0x0F,0xC1,0xF8,0x3F,0x07,0xE0,0xFC,0x1F,0x83,0xF0,0x7E,0x0E, // 'n'
	0x0F,0x83,0xFC,0x7F,0xE7,0x0F,0xF0,0x7F,0x07,0xE0,0x7F,0x07,0xF0,0x77,0x0F,0x7F,0xE3,0xFC,0x0F,0x80, // 'o'
	0xEF,0x1F,0xFB,0xFF,0x70,0xFE,0x0F,0xC1,0xF8,0x3F,0x07,0xE1,0xFC,0x3F,0xFF,0x7F,0xEE,0xF1,0xC0,0x38,0x07,0x00,0xE0,0x1C,0x00, // 'p'
	0x1E,0x73,0xFF,0x7F,0xF7,0x0F,0xF0,0xFF,0x0F,0xF0,0xFF,0x0F,0x70,0xF7,0x0F,0x7F,0xF3,0xFF,0x1E,0xF0,0x0F,0x00,0xF0,0x0F,0x00,0xF0,0x0F, // 'q'
	0xE3,0xFF,0xFF,0xFF,0xE0,0xF0,0x3C,0x0F,0x03,0xC0,0xF0,0x3C,0x0F,0x03,0xC0,0xF0,0x00, // 'r'
	0x1F,0x83,0xFE,0x7F,0xF7,0x0F,0x70,0x07,0xE0,0x1F,0xC0,0x3E,0x80,0x77,0x07,0x7F,0xF3,0xFE,0x0F,0x80, // 's'
	0x1E,0x01,0xE0,0x1E,0x0F,0xFE,0xFF,0xEF,0xFE,0x1E,0x01,0xE0,0x1E,0x01,0xE0,0x1E,0x01,0xE0,0x1E,0x00,0xFF,0x0F,0xF0,0x3E, // 't'
	0xE0,0xFC,0x1F,0x83,0xF0,0x7E,0x0F,0xC1,0xF8,0x3F,0x07,0xE0,0xFC,0x3F,0xFF,0xBF,0xF3,0xCE, // 'u'
	0xE0,0x7F,0x83,0x9C,0x3C,0xE1,0xC3,0x8E,0x1C,0xF0,0xE7,0x03,0xB8,0x1D,0x80,0xFC,0x03,0xE0,0x1E,0x00,0xF0,0x00, // 'v'
	0xE3,0x1D,0x8C,0x77,0x39,0x9D,0xEE,0x77,0xB9,0xDE,0xE7,0x7B,0x8D,0xBE,0x3C,0xF0,0xF3,0xC3,0xCF,0x0F,0x3C,0x3C,0x70, // 'w'
	0xF0,0x7B,0xC7,0x8E,0x78,0x3B,0x81,0xFC,0x07,0xC0,0x3E,0x01,0xF0,0x1F,0xC1,0xEF,0x0E,0x38,0xF1,0xEF,0x07,0x80, // 'x'
	0xE0,0x3F,0x83,0xDC,0x1C,0xF1,0xE3,0x8E,0x1C,0x70,0xF7,0x83,0xB8,0x1D,0xC0,0x7C,0x03,0xE0,0x0E,0x00,0x70,0x07,0x80,0x38,0x0F,0xC0,0x7C,0x03,0xC0,0x00, // 'y'
	0x7F,0xF7,0xFF,0x7F,0xF0,0x1E,0x03,0xC0,0x78,0x0F,0x01,0xE0,0x3C,0x03,0xC0,0x7F,0xFF,0xFF,0xFF,0xF0, // 'z'
	0x06,0x1C,0x70,0xE1,0xC3,0x87,0x0E,0x38,0x73,0xC7,0x0F,0x07,0x0E,0x0E,0x1C,0x38,0x70,0xE1,0xC1,0xC1,0x80, // '{'
	0xFF,0xFF,0xFF,0xFF,0xFF,0xF0, // '|'
	0xC0,0xF0,0x70,0x38,0x38,0x38,0x38,0x38,0x38,0x3C,0x1F,0x0F,0x1F,0x38,0x38,0x38,0x38,0x38,0x38,0x30,0x70,0xE0,0xC0 // '}'
};
const GFXglyph Roboto_Mono_Bold_24Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,  15,    0,    0 }, // ' '
	  {     1,   4,  17,  15,    5,  -17 }, // '!'
	  {    10,   8,   6,  15,    3,  -18 }, // '"'
	  {    16,  14,  17,  15,    0,  -17 }, // '#'
	  {    46,  12,  22,  15,    1,  -20 }, // '$'
	  {    79,  14,  17,  15,    0,  -17 }, // '%'
	  {   109,  13,  17,  15,    1,  -17 }, // '&'
	  {   137,   3,   6,  15,    5,  -18 }, // '''
	  {   140,   7,  24,  15,    4,  -19 }, // '('
	  {   161,   6,  24,  15,    4,  -19 }, // ')'
	  {   179,  12,  12,  15,    2,  -14 }, // '*'
	  {   197,  12,  13,  15,    1,  -15 }, // '+'
	  {   217,   4,   8,  15,    4,   -3 }, // ','
	  {   221,  10,   3,  15,    3,   -9 }, // '-'
	  {   225,   4,   4,  15,    5,   -4 }, // '.'
	  {   227,   9,  18,  15,    3,  -17 }, // '/'
	  {   248,  11,  17,  15,    2,  -17 }, // '0'
	  {   272,   8,  17,  15,    2,  -17 }, // '1'
	  {   289,  12,  17,  15,    1,  -17 }, // '2'
	  {   315,  12,  17,  15,    1,  -17 }, // '3'
	  {   341,  12,  17,  15,    1,  -17 }, // '4'
	  {   367,  12,  17,  15,    1,  -17 }, // '5'
	  {   393,  12,  17,  15,    1,  -17 }, // '6'
	  {   419,  12,  17,  15,    1,  -17 }, // '7'
	  {   445,  12,  17,  15,    1,  -17 }, // '8'
	  {   471,  12,  17,  15,    1,  -17 }, // '9'
	  {   497,   4,  14,  15,    5,  -14 }, // ':'
	  {   504,   5,  19,  15,    5,  -14 }, // ';'
	  {   516,  10,  11,  15,    2,  -13 }, // '<'
	  {   530,  11,   8,  15,    2,  -11 }, // '='
	  {   541,  10,  11,  15,    2,  -13 }, // '>'
	  {   555,  11,  17,  15,    2,  -17 }, // '?'
	  {   579,  14,  17,  15,    0,  -17 }, // '@'
	  {   609,  14,  17,  15,    0,  -17 }, // 'A'
	  {   639,  12,  17,  15,    2,  -17 }, // 'B'
	  {   665,  12,  17,  15,    1,  -17 }, // 'C'
	  {   691,  12,  17,  15,    1,  -17 }, // 'D'
	  {   717,  11,  17,  15,    2,  -17 }, // 'E'
	  {   741,  11,  17,  15,    2,  -17 }, // 'F'
	  {   765,  12,  17,  15,    1,  -17 }, // 'G'
	  {   791,  12,  17,  15,    1,  -17 }, // 'H'
	  {   817,  10,  17,  15,    2,  -17 }, // 'I'
	  {   839,  12,  17,  15,    1,  -17 }, // 'J'
	  {   865,  13,  17,  15,    2,  -17 }, // 'K'
	  {   893,  11,  17,  15,    2,  -17 }, // 'L'
	  {   917,  12,  17,  15,    1,  -17 }, // 'M'
	  {   943,  12,  17,  15,    1,  -17 }, // 'N'
	  {   969,  12,  17,  15,    1,  -17 }, // 'O'
	  {   995,  12,  17,  15,    2,  -17 }, // 'P'
	  {  1021,  13,  20,  15,    1,  -17 }, // 'Q'
	  {  1054,  12,  17,  15,    2,  -17 }, // 'R'
	  {  1080,  13,  17,  15,    1,  -17 }, // 'S'
	  {  1108,  14,  17,  15,    0,  -17 }, // 'T'
	  {  1138,  12,  17,  15,    1,  -17 }, // 'U'
	  {  1164,  14,  17,  15,    0,  -17 }, // 'V'
	  {  1194,  14,  17,  15,    0,  -17 }, // 'W'
	  {  1224,  14,  17,  15,    0,  -17 }, // 'X'
	  {  1254,  14,  17,  15,    0,  -17 }, // 'Y'
	  {  1284,  13,  17,  15,    1,  -17 }, // 'Z'
	  {  1312,   5,  24,  15,    5,  -20 }, // '['
	  {  1327,   9,  18,  15,    3,  -17 }, // '\'
	  {  1348,   5,  24,  15,    5,  -20 }, // ']'
	  {  1363,   9,   9,  15,    3,  -17 }, // '^'
	  {  1374,  10,   3,  15,    2,    0 }, // '_'
	  {  1378,   5,   3,  15,    5,  -17 }, // '`'
	  {  1380,  12,  13,  15,    1,  -13 }, // 'a'
	  {  1400,  11,  18,  15,    2,  -18 }, // 'b'
	  {  1425,  12,  13,  15,    1,  -13 }, // 'c'
	  {  1445,  12,  18,  15,    1,  -18 }, // 'd'
	  {  1472,  12,  13,  15,    1,  -13 }, // 'e'
	  {  1492,  13,  19,  15,    1,  -19 }, // 'f'
	  {  1523,  12,  18,  15,    1,  -13 }, // 'g'
	  {  1550,  11,  18,  15,    2,  -18 }, // 'h'
	  {  1575,  10,  18,  15,    3,  -18 }, // 'i'
	  {  1598,   7,  23,  15,    3,  -18 }, // 'j'
	  {  1619,  12,  18,  15,    2,  -18 }, // 'k'
	  {  1646,  11,  18,  15,    2,  -18 }, // 'l'
	  {  1671,  12,  13,  15,    1,  -13 }, // 'm'
	  {  1691,  11,  13,  15,    2,  -13 }, // 'n'
	  {  1709,  12,  13,  15,    1,  -13 }, // 'o'
	  {  1729,  11,  18,  15,    2,  -13 }, // 'p'
	  {  1754,  12,  18,  15,    1,  -13 }, // 'q'
	  {  1781,  10,  13,  15,    3,  -13 }, // 'r'
	  {  1798,  12,  13,  15,    1,  -13 }, // 's'
	  {  1818,  12,  16,  15,    1,  -16 }, // 't'
	  {  1842,  11,  13,  15,    2,  -13 }, // 'u'
	  {  1860,  13,  13,  15,    1,  -13 }, // 'v'
	  {  1882,  14,  13,  15,    0,  -13 }, // 'w'
	  {  1905,  13,  13,  15,    1,  -13 }, // 'x'
	  {  1927,  13,  18,  15,    1,  -13 }, // 'y'
	  {  1957,  12,  13,  15,    1,  -13 }, // 'z'
	  {  1977,   7,  23,  15,    4,  -19 }, // '{'
	  {  1998,   2,  22,  15,    6,  -17 }, // '|'
	  {  2004,   8,  23,  15,    4,  -19 } // '}'
};
const GFXfont Roboto_Mono_Bold_24 PROGMEM = {
(uint8_t  *)Roboto_Mono_Bold_24Bitmaps,(GFXglyph *)Roboto_Mono_Bold_24Glyphs,0x20, 0x7E, 29};