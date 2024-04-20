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
  Sesuai tujuannya, seharusnya tombol-tombol di Keypad
  bisa bekerja menggantikan tombol input biasa yang sudah ada. 
  
  Hanya saja, tombol-tombol di Keypad ternyata menghasilkan sinyal
  aktif yang sesaat, seperti pulsa denyut, yang mengabaikan berapa lama
  tombol tersebut ditekan. Berbeda dengan tombol biasa, yang akan
  memberikan sinyal aktifnya selama tombol ditekan.
  
  Untuk mengatasi nilai input tombol yang hanya sesaat tersebut,
  maka perlu sebuah instruksi untuk mengunci sinyal keluaran dari Keypad tersebut,
  seperti contoh program Latch berikut:
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
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  unsigned int RY1, RY2, RY3, RY4;
  void setup() {
    setupku();
    outHigh();
    Serial.begin(9600);
  }
  void loop() {
    //bagian input
    tombolku = keypad.getKey();   
    if(tombolku) Serial.println(tombolku);
    
    //bagian proses
    if(tombolku=='1') RY1=1;
    if(tombolku=='2') RY1=0;
    if(tombolku=='3') RY2=1;
    if(tombolku=='4') RY2=0;
    if(tombolku=='5') RY3=1;
    if(tombolku=='6') RY3=0;
    if(tombolku=='7') RY4=1;
    if(tombolku=='8') RY4=0;

    //bagian output
    in(RY1); outNot(Y1);
    in(RY2); outNot(Y2);    
    in(RY3); outNot(Y3);
    in(RY4); outNot(Y4);
  }
