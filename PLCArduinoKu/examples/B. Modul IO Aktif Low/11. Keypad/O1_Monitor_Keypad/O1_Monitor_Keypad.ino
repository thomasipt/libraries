/*
1.Rangkaian:
  Nama Input  : '1','2','3','4','5','6','7','8','9'
  Kaki Input  : kaki A0, A1, A2, A3, A4 dan A5 Arduino
  Alat Input  : Keypad (3x3) 1x
  Alat Output : Serial Monitor
  
2.Program:
  Ketika diperlukan jumlah Input Tombol yang lebih banyak,
  namun dengan kaki IO Arduino yang terbatas,
  maka keypad merupakan solusi yang menarik.
  
  Di modul hardware PLCArduino ini, 8 konektor keypad 4x4 
  dihubungkan dengan 6 kaki Arduino, dengan pola sambungan seperti 
  berikut: L1-A0, L2-A1, L3-A2, R1-A3, R2-A4, R3-A5.
  Karena hanya 6 kaki Arduino yang dihubungkan ke Keypad, 
  maka tombol Keypad yang bisa digunakan hanyalah 9 tombol (3x3).
  
  Untuk mengetahui mana 9 tombol yang digunakan dari 16 tombol 
  yang ada di Keypad, maka program berikut ini menggunakan 
  instruksi Serial.print() untuk menampilkan angka ketika salah 
  satu dari 9 tombol tersebut ditekan.
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
  
  void setup() {
    setupku();
    outHigh();
    Serial.begin(9600);
  }
  
  void loop() {
    tombolku = keypad.getKey();   
    if(tombolku) Serial.println(tombolku);
    delay(100);
  }
