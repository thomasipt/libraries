/*
1.Rangkaian:
  Modul Output Aktif High.
  Nama Input  : Tombol "^", "<", "OK", ">", "V"
  Nama Output : Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12 
  Kaki Input  : kaki A5 Arduino
  Kaki Output : D2, D3, D4, D5, D6, D7, 8, D9, D10, D11, D12, D13 Arduino
  Alat Input  : Remote InfraRed 1x 
  Alat Output : Relay 4x dan LED 8x

2.Program:
  Program berikut ini menerapkan Counter Circular dengan tombol Remote.
  Perhatikan bahwa dengan Remote tidak diperlukan timerOn untuk Debouncing,
  karena ketika tombol Remote ditekan selalu hanya menghasilkan satu karakter.
  
  Di sini untuk instruksi Clear memerlukan timerCycle, karena sempitnya lebar pulsa instruksi Clear,
  mengakibatkan ketidak tepatan sisi naik Counter Up, sehingga setiap kali di buat Clear, Counter 
  sempat bertambah nilainya 1 dulu. Untuk memperbaiki agar nilainya tidak melompat dari nilai 11 ke 1,
  ditambahkan TimerCycle yang akan menahan Counter bertambah saat Counter Clear telah bekerja.
  */
#include "IRremote.h"
#include "PLCArduinoku.h"
  int receiver = 19; 
  IRrecv irrecv(receiver);           
  decode_results results;         
  Counter C1(13);
  unsigned int RXUp, RXDown, RXClear, RXPreset;
  unsigned int RY1, RY2, RY3, RY4, RY5, RY6, RY7, RY8, RY9, RY10, RY11, RY12;
  unsigned int R1=0;
  unsigned int R2=1;
  unsigned int R3=2;
  unsigned int R4=3;
  unsigned int R5=4;
  unsigned int R6=5;
  unsigned int R7=6;
  unsigned int R8=7;
  unsigned int R9=8;
  unsigned int R10=9;
  unsigned int R11=10;
  unsigned int R12=11;
  unsigned int R13=12;
  unsigned long T1, T2;
  
void setup() {
  setupku();
  outLow();
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}  
  void loop() {
  //bagian input dan proses
  if (irrecv.decode(&results)) {
    translateIR(); 
    irrecv.resume(); 
  }  
  in(RXUp); C1.countUp();           
  in(RXDown); C1.countDown(); 
  in(RXClear); C1.clear();    
  in(RXPreset); C1.preset();
  
  inAnalog(C1.count()); compareEQ(R1); out(RY1);
  inAnalog(C1.count()); compareEQ(R2); out(RY2);
  inAnalog(C1.count()); compareEQ(R3); out(RY3);
  inAnalog(C1.count()); compareEQ(R4); out(RY4);
  inAnalog(C1.count()); compareEQ(R5); out(RY5);
  inAnalog(C1.count()); compareEQ(R6); out(RY6);
  inAnalog(C1.count()); compareEQ(R7); out(RY7);
  inAnalog(C1.count()); compareEQ(R8); out(RY8);
  inAnalog(C1.count()); compareEQ(R9); out(RY9);
  inAnalog(C1.count()); compareEQ(R10); out(RY10);
  inAnalog(C1.count()); compareEQ(R11); out(RY11);
  inAnalog(C1.count()); compareEQ(R12); out(RY12);
  inAnalog(C1.count()); compareEQ(R13); timerCycle(T1,100,T2,100); C1.clear();      
  
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
  case 0xFF629D: Serial.println("Up"); RXUp=1; break;
  case 0xFF22DD: Serial.println("Clear"); RXClear=1; break;
  case 0xFFC23D: Serial.println("Preset"); RXPreset=1; break;
  case 0xFFA857: Serial.println("Down"); RXDown=1; break;
  case 0xFFFFFFFF: Serial.println(C1.count());     
  RXUp=0; RXClear=0; RXDown=0; RXPreset=0; break;  
  delay(100); }
 }
