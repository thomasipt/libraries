/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Nama Input  : Tombol "OK"
  Nama Output : Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12 
  Kaki Input  : kaki A5 Arduino
  Kaki Output : D2, D3, D4, D5, D6, D7, 8, D9, D10, D11, D12, D13 Arduino
  Alat Input  : Remote InfraRed 1x
  Alat Output : Relay 4x dan LED 8x

2.Program:
  Program berikut ini menerapkan Shift Register tipe Johnson Counter pada 12 buah LED
  yang akan menyala dan padam secara berurutan setiap kali tombol OK Remote ditekan.
*/

  #include "IRremote.h"
  #include "PLCArduinoku.h"
  Shift SF1(0x0001);      
  int receiver = 19; 
  IRrecv irrecv(receiver);           
  decode_results results;         
  unsigned int R1, RXok;
  unsigned int RY1, RY2, RY3, RY4, RY5, RY6, RY7, RY8, RY9, RY10, RY11, RY12;

  void setup() {
    setupku();
    outLow();
    Serial.begin(9600);
    irrecv.enableIRIn(); 
  }

  void loop() {
  //bagian input
  if (irrecv.decode(&results)) {
    translateIR(); 
    irrecv.resume(); 
  }
 
  //bagian proses
  SF1.bitValue(11); outNot(R1);   
  in(R1); SF1.inputBit();
  in(RXok);  SF1.shiftLeft();   

  SF1.bitValue(11); out(RY12);
  SF1.bitValue(10); out(RY11);
  SF1.bitValue(9); out(RY10);
  SF1.bitValue(8); out(RY9);
  SF1.bitValue(7); out(RY8);
  SF1.bitValue(6); out(RY7);
  SF1.bitValue(5); out(RY6);
  SF1.bitValue(4); out(RY5);
  SF1.bitValue(3); out(RY4);
  SF1.bitValue(2); out(RY3);
  SF1.bitValue(1); out(RY2);
  SF1.bitValue(0); out(RY1);

  //bagian output
  in(RY1); out(Y1);
  in(RY2); out(Y2);    
  in(RY3); out(Y3);  
  in(RY4); out(Y4); 
  in(RY5); out(Y5);
  in(RY6); out(Y6);    
  in(RY7); out(Y7);  
  in(RY8); out(Y8); 
  in(RY9); out(Y9);
  in(RY10); out(Y10);    
  in(RY11); out(Y11);  
  in(RY12); out(Y12); 
 }

void translateIR(){
  switch(results.value) {
  case 0xFF02FD: Serial.println("OK"); RXok=1; break;
  case 0xFFFFFFFF: Serial.println("Tombol Ditahan"); RXok=0; break;  
  delay(100); 
}}

