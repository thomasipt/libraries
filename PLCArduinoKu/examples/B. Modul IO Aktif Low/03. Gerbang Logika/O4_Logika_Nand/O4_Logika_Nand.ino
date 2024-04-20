/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 1x

2. Program:
            X1               X2               Y1        
 1 ||-------] [--------------] [--------------(/)-------||

  Ketika tombol di X1 dan di X2 ditekan maka Relay di Y1 mati.  
  Di luar kondisi itu maka Relay di Y1 hidup.
*/
#include<PLCArduinoku.h>
unsigned int RX1, RX2, RY1;
void setup() {
  setupku();
  outHigh();
}

void loop() {
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  
  //bagian proses
  in(RX1); andBit(RX2); outNot(RY1);
  
  //bagian output
  in(RY1); outNot(Y1);
}