/*
1.Rangkaian:
  Modul Output Aktif Low.
  Nama Input  : '1','2','3','4','5','6','7','8','9'
  Nama Output : Y1, Y2, Y3, Y4
  Kaki Input  : kaki A0, A1, A2, A3, A4 dan A5 Arduino
  Kaki Output : kaki D2, D3, D4 dan D5 Arduino
  Alat Input  : Keypad (3x3) 1x
  Alat Output : Relay 4x

2.Program:
  Seringkali diperlukan pembacaan sisi naik atau sisi turun dari 
  sinyal yang dikeluarkan oleh input tombol. 
  
  Program berikut ini membaca 4 kondisi tombol pada keypad, yaitu:
  1. Saat terjadi perubahan sinyal ketika tombol ditekan. 
  2. Sisi naik pulsa yang dihasilkan ketika tombol ditekan.
  3. Sisi datar pulsa ketika tombol sedang ditekan. 
  4. Sisi turun pulsa ketika tombol ditekan kemudian dilepas.
  
  Untuk melihat perbedaan diantara keempat kondisi itu, 
  jalankan program berikut ini.
  */
  #include <Keypad.h>  
  #include <PLCArduinoku.h>
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
  unsigned int RY1, RY2, RY3, RY4;
  void setup() {
    setupku();
    outHigh();
    Serial.begin(9600);
    keypad.addEventListener(keypadEvent);
  }
  void loop() {
    //bagian input
    tombolku = keypad.getKey(); 
    if (tombolku) Serial.println(tombolku);

    //bagian proses    
    if(tombolku=='1') RY1=1;
    if(tombolku=='2') RY1=0;
    
    //bagian output
    in(RY1); outNot(Y1);
  }
  
  void keypadEvent(KeypadEvent tombolku){
    switch (keypad.getState()){
    case PRESSED: //sisi naik pulsa, saat tombol ditekan
        if (tombolku == '3') RY2=1;
        if (tombolku == '4') RY2=0;
        in(RY2); outNot(Y2);
        break;

    case HOLD: //saat tombol sedang ditekan lama
        if (tombolku == '5') RY3=1;
        if (tombolku == '6') RY3=0;
        in(RY3); outNot(Y3);
        break;

    case RELEASED: //sisi turun pulsa, saat tombol dilepas
        if (tombolku == '7') RY4=1;
        if (tombolku == '8') RY4=0;
        in(RY4); outNot(Y4);
        break;
    }
}
  
