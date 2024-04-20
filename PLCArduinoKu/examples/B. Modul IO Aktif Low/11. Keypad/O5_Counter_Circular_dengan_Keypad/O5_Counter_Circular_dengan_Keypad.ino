/*
1.Rangkaian:
  Modul Output Aktif Low.
  Nama Input  : '1','2','3','4','5','6','7','8','9' 
  Nama Output : Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12
  Kaki Input  : kaki A0, A1, A2, A3, A4 dan A5 Arduino
  Kaki Output : kaki D2, D3, D4, D5, D6, D7, 8, D9, D10, D11, D12, D13 Arduino)
  Alat Input  : Keypad (3x3) 1x
  Alat Output : Relay 4x dan LED 8x

2.Program:
  Program berikut ini menerapkan Counter Circular dengan tombol Keypad.
  Perhatikan bahwa dengan Keypad tidak diperlukan timerOn untuk Debouncing,
  karena ketika tombol Keypad ditekan selalu hanya menghasilkan satu karakter.
  
  Perhatikan juga reset atau clear Counter tidak memerlukan timerOff,
  karena perubahan nilai input yang cukup singkat, 
  lebih singkat dari instruksi clear counter, 
  sehingga counter belum sempat mencacah naik
  */
  #include <Keypad.h>  
  #include <PLCArduinoku.h>
  Counter C1(13);
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
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  unsigned int RX1, RX2, RX3, RX4;
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
    outHigh();
    Serial.begin(9600);
  }
  
  void loop() {
    //bagian input
    tombolku=keypad.getKey();
    if(tombolku) {
      Serial.print(tombolku);
      Serial.print(',');
      Serial.println(C1.count());}

    //bagian proses
    if(tombolku=='1') RX1=1; else RX1=0;
    in(RX1); C1.countUp();           
    if(tombolku=='2') RX2=1; else RX2=0;   
    in(RX2); C1.countDown(); 
    if(tombolku=='3') RX3=1; else RX3=0;   
    in(RX3); C1.clear();    
    if(tombolku=='4') RX4=1; else RX4=0;
    in(RX4); C1.preset();
    
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
    inAnalog(C1.count()); compareEQ(R13); C1.clear();
    
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
  
