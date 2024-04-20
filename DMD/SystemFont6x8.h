#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef SYSTEM6X8_H
#define SYSTEM6X8_H

#define SYSTEM6X8_WIDTH 6
#define SYSTEM6X8_HEIGHT 8

#define SystemFont6x8 System6x8

const static uint8_t System6x8[] PROGMEM = {
    0x0, 0x0, // size of zero indicates fixed width font, actual length is width * height
    0x06, // width
    0x08, // height
    0x20, // first char
    0x60, // char count
    
    // Fixed width; char width table not used !!!!
    
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// (space)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x7E, 0xFF, 0x91, 0x89, 0xFF, 0x7E,// 0
	0x00, 0x00, 0x84, 0xFE, 0xFF, 0x80,// 1
	0xC6, 0xE7, 0xF1, 0x99, 0xCF, 0xC6,// 2
	0x62, 0xEB, 0x89, 0x89, 0xFF, 0x76,// 3
	0x30, 0x2C, 0x63, 0xF8, 0xFF, 0x20,// 4
	0x6F, 0xEF, 0x89, 0x89, 0xFB, 0x73,// 5
	0x7E, 0xFF, 0x89, 0x89, 0xFB, 0x72,// 6
	0x03, 0x03, 0xE1, 0xF9, 0x1F, 0x07,// 7
	0x76, 0xFF, 0x89, 0x89, 0xFF, 0x76,// 8
	0x4E, 0xDF, 0x91, 0x91, 0xFF, 0x7E,// 9  
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0xF8, 0xFC, 0x67, 0x27, 0xFC, 0xF8,// A
	0xFF, 0xFF, 0x89, 0x89, 0xFF, 0x76,// B
	0x7E, 0xFF, 0x81, 0x81, 0xE7, 0x66,// C
	0xFF, 0xFF, 0x81, 0x81, 0xFF, 0x7E,// D
	0xFF, 0xFF, 0x89, 0x89, 0xEB, 0xE3,// E
	0xFF, 0xFF, 0x09, 0x09, 0x0B, 0x03,// F
	0x7E, 0xFF, 0x81, 0x91, 0x76, 0xF6,// G
	0xFF, 0xFF, 0x08, 0x08, 0xFF, 0xFF,// H
	0x00, 0x81, 0xFF, 0xFF, 0x81, 0x00,// I
	0x60, 0xE0, 0x80, 0x80, 0xFF, 0x7F,// J
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00//   
};

#endif