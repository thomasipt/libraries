/*
  Library ini disalin dari plcLib Versi 1.0, oleh W. Ditch,
  dengan sedikit penambahan, dan diupdate terakhir tgl 20 maret 2015.
  Lebih jauh mengenai plcLib, dapat dilihat di www.electronics-micros.com

*/

#ifndef PLCArduinoku_h
#define PLCArduinoku_h
#include "Arduino.h"

// Penugasan kaki IO
const int X1 = A0;
const int X2 = A1;
const int X3 = A2;
const int X4 = A3;
const int X5 = A4;
const int X6 = A5;
const int Y1 = 2;
const int Y2 = 3;
const int Y3 = 4;
const int Y4 = 5;
const int Y5 = 6;
const int Y6 = 7;
const int Y7 = 8;
const int Y8 = 9;
const int Y9 = 10;
const int Y10 = 11;
const int Y11 = 12;
const int Y12 = 13;

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__SAM3X8E__)
const int X7 = A6;
const int X8 = A7;
const int X9 = A8;
const int X10 = A9;
const int X11 = A10;
const int X12 = A11;
const int X13 = A12;
const int X14 = A13;
const int X15 = A14;
const int X16 = A15;
const int Y13 = 14;
const int Y14 = 15;
const int Y15 = 16;
const int Y16 = 17;
const int Y17 = 18;
const int Y18 = 19;
const int Y19 = 20;
const int Y20 = 21;
const int Y21 = 22;
const int Y22 = 23;
const int Y23 = 24;
const int Y24 = 25;
const int Y25 = 26;
const int Y26 = 27;
const int Y27 = 28;
const int Y28 = 29;
const int Y29 = 30;
const int Y30 = 31;
const int Y31 = 32;
const int Y32 = 33;
const int Y33 = 34;
const int Y34 = 35;
const int Y35 = 36;
const int Y36 = 37;
const int Y37 = 38;
const int Y38 = 39;
const int Y39 = 40;
const int Y40 = 41;
const int Y41 = 42;
const int Y42 = 43;
const int Y43 = 44;
const int Y44 = 45;
const int Y45 = 46;
const int Y46 = 47;
const int Y47 = 48;
const int Y48 = 49;
const int Y49 = 50;
const int Y50 = 51;
const int Y51 = 52;
const int Y52 = 53;
#endif

void setupku();
void outHigh();
void outLow();
unsigned int osf(int input,unsigned int &dulu);
unsigned int osf(unsigned int input,unsigned int &dulu);
unsigned int osf(unsigned long input,unsigned long &dulu);
unsigned int osr(int input,unsigned int &dulu);
unsigned int osr(unsigned int input,unsigned int &dulu);
unsigned int osr(unsigned long input,unsigned long &dulu);
unsigned int in(int input);
unsigned int in(unsigned int input);
unsigned int in(unsigned long input);
unsigned int inNot(int input);
unsigned int inNot(unsigned int input);
unsigned int inNot(unsigned long input);
unsigned int inAnalog(int input);
unsigned int inAnalog(unsigned int input);
unsigned int inAnalog(unsigned long input);
unsigned int out(int output);
unsigned int out(unsigned int &output);
unsigned int out(unsigned long &output);
unsigned int outNot(int output);
unsigned int outNot(unsigned int &output);
unsigned int outNot(unsigned long &output);
unsigned int outPWM(int output);
unsigned int andBit(int input);
unsigned int andBit(unsigned int input);
unsigned int andBit(unsigned long input);
unsigned int andNotBit(int input);
unsigned int andNotBit(unsigned int input);
unsigned int andNotBit(unsigned long input);
unsigned int orBit(int input);
unsigned int orBit(unsigned int input);
unsigned int orBit(unsigned long input);
unsigned int orNotBit(int input);
unsigned int orNotBit(unsigned int input);
unsigned int orNotBit(unsigned long input);
unsigned int xorBit(int input);
unsigned int xorBit(unsigned int input);
unsigned int xorBit(unsigned long input);
unsigned int latch(int output, int reset);
unsigned int latch(int output, unsigned int reset);
unsigned int latch(int output, unsigned long reset);
unsigned int latch(unsigned int &output, int reset);
unsigned int latch(unsigned long &output, int reset);
unsigned int latch(unsigned int &output, unsigned int reset);
unsigned int latch(unsigned long &output, unsigned long reset);
unsigned int timerOn(unsigned long &timerState, unsigned long timerPeriod);
unsigned int RTO(unsigned long &timerState, unsigned long timerPeriod, unsigned long &simpan);
unsigned int timerPulse(unsigned long &timerState, unsigned long timerPeriod);
unsigned int timerOff(unsigned long &timerState, unsigned long timerPeriod);
unsigned int timerCycle(unsigned long &timer1State, unsigned long timer1Period, unsigned long &timer2State, unsigned long timer2Period);
unsigned int compareGT(int input);
unsigned int compareGT(unsigned int input);
unsigned int compareGT(unsigned long input);
unsigned int compareLT(int input);
unsigned int compareLT(unsigned int input);
unsigned int compareLT(unsigned long input);
unsigned int compareEQ(int input);
unsigned int compareEQ(unsigned int input);
unsigned int compareEQ(unsigned long input);
unsigned int set(int output);
unsigned int set(unsigned int &output);
unsigned int set(unsigned long &output);
unsigned int reset(int output);
unsigned int reset(unsigned int &output);
unsigned int reset(unsigned long &output);

class Counter
{
  public:
    Counter(unsigned int presetValue);
    Counter(unsigned int presetValue, unsigned int direction);
    void countUp();
    void countDown();
    void preset();
    void clear();
    unsigned int upperQ();
    unsigned int lowerQ();
    unsigned int count();
    unsigned int presetValue();
  private:
    unsigned int _pv;
    unsigned int _ct;
    unsigned int _ctUpEdge;
    unsigned int _ctDownEdge;
    unsigned int _uQ;
    unsigned int _lQ;
};

class Shift
{
  public:
    Shift();
	Shift(unsigned int sreg);
	unsigned int bitValue(unsigned int bitno);
	unsigned int value();
	void reset();
	void inputBit();
	void shiftLeft();
	void shiftRight();
  private:
    unsigned int _srLeftEdge;
    unsigned int _srRightEdge;
	unsigned int _sreg;
	unsigned int _inbit;
};

class Stack
{
  public:
    Stack();
	void push();
	void pop();
	void orBlock();
	void andBlock();
  private:
	unsigned long _sreg;
};

#endif
