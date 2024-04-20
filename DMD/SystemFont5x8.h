#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef SYSTEM5x8_H
#define SYSTEM5x8_H

#define SYSTEM5x8_WIDTH 5
#define SYSTEM5x8_HEIGHT 8

#define SystemFont5x8 System5x8

const static uint8_t System5x8[] PROGMEM = {
    0x0, 0x0, // size of zero indicates fixed width font, actual length is width * height
    0x05, // width
    0x08, // height
    0x20, // first char
    0x60, // char count
    
    // Fixed width; char width table not used !!!!
    
	0x00, 0x00, 0x00, 0x00, 0x00,// (space)
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x7E, 0xFF, 0x81, 0xFF, 0x7E,// 0
	0x00, 0x82, 0xFF, 0xFF, 0x80,// 1
	0xE2, 0xF1, 0x99, 0x8F, 0xC6,// 2
	0x42, 0x81, 0x89, 0xFF, 0x76,// 3
	0x30, 0x2C, 0x23, 0xF8, 0xFF,// 4
	0x47, 0x87, 0x85, 0xFD, 0x79,// 5
	0x7E, 0xFF, 0x89, 0xF9, 0x70,// 6
	0x03, 0xF1, 0xF9, 0x0F, 0x07,// 7
	0x76, 0xFF, 0x89, 0xFF, 0x76,// 8
	0x4E, 0x9F, 0x91, 0xFF, 0x7E,// 9
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0xFE, 0xFF, 0x21, 0xFF, 0xFE,// A
	0xFF, 0xFF, 0x89, 0xFF, 0x76,// B
	0x7E, 0xFF, 0x81, 0x81, 0x42,// C
	0xFF, 0xFF, 0x81, 0x81, 0x7E,// D
	0xFF, 0xFF, 0x89, 0x89, 0xC3,// E
	0xFF, 0xFF, 0x09, 0x09, 0x01,// F
	0x7E, 0xFF, 0x89, 0xF9, 0xFA,// G
	0xFF, 0xFF, 0x10, 0xFF, 0xFF,// H
	0x00, 0x81, 0xFF, 0xFF, 0x81,// I
	0x60, 0xE1, 0x81, 0xFF, 0x7F,// J
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00,//
	0x00, 0x00, 0x00, 0x00, 0x00//	  
};

#endif