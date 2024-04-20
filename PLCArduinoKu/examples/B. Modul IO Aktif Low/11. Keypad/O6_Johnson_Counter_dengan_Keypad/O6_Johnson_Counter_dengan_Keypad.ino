/*
1.Rangkaian:
  Modul Output Aktif Low.
  Nama Input  : '1','2','3','4','5','6','7','8','9'
  Nama Output : Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12
  Kaki Input  : kaki A0, A1, A2, A3, A4 dan A5 Arduino
  Kaki Output : kaki D2, D3, D4, D5, D6, D7, 8, D9, D10, D11, D12, D13 Arduino
  Alat Input  : Keypad (3x3) 1x
  Alat Output : Relay 4x dan LED 8x

2.Program:
  Program berikut ini menerapkan Counter Circular dengan tombol Keypad.
  Perhatikan bahwa dengan Keypad tidak diperlukan timerOn untuk Debouncing,
  karena ketika tombol Keypad ditekan selalu hanya menghasilkan satu karakter.
  
  Perhatikan juga reset Counter tidak memerlukan timerOff,
  karena perubahan nilai input yang cukup singkat, 
  lebih singkat dari instruksi clear counter, 
  sehingga counter belum sempat mencacah naik
*/
  #include <Keypad.h>  
  #include <PLCArduinoku.h>
  Shift SF1(0x0001);      
  unsigned long T1, T2;
  unsigned int R1, RX1, RX2;
  unsigned int RY1, RY2, RY3, RY4, RY5, RY6, RY7, RY8, RY9, RY10, RY11, RY12;
  char tombolku = 0; 
  const byte ROWS = 3; 
  const byte COLS = 3; 
  char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
   };
  byte rowPins[ROWS] = { 14, 15, 16 };
  byte colPins[COLS] = { 17, 18, 19 }; 
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );//objek keypad

  void setup() {
    setupku();
    outHigh();
    Serial.begin(9600);
  }
  
  void loop() {
    //bagian input
    tombolku=keypad.getKey();
    if(tombolku) {
      Serial.print(tombolku);
      Serial.print(',');
      Serial.println(SF1.value(),BIN);}
      
    //bagian output
    SF1.bitValue(11); outNot(R1);   
    in(R1); SF1.inputBit();
    if(tombolku=='1') RX1=1;
    else RX1=0;
    in(RX1);  SF1.shiftLeft();   
    if(tombolku=='2') RX2=1;
    else RX2=0;  
    in(RX2);  SF1.reset();
  
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
    in(RY1); outNot(Y1);
    in(RY2); outNot(Y2);    
    in(RY3); outNot(Y3);  
    in(RY4); outNot(Y4); 
    in(RY5); outNot(Y5);
    in(RY6); outNot(Y6);    
    in(RY7); outNot(Y7);  
    in(RY8); outNot(Y8); 
    in(RY9); outNot(Y9);
    in(RY10); outNot(Y10);    
    in(RY11); outNot(Y11);  
    in(RY12); outNot(Y12); 
 }

