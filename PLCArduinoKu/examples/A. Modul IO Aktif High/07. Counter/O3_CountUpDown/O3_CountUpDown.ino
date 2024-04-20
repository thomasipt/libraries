/* 
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3, X4 (kaki A0, A1, A2 dan A3 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 4x
  Alat Output : Relay 2x
  
2.Program:
            X1                  _             C1         
 1 ||-------] [-----------[OSR_/ ]---------[CTU >=0]----||
   ||       X2                  _             C1        ||
 2 ||-------] [-----------[OSR_/ ]---------[CTD >=0]----||
   ||     [C1 >]                        {C1  :=      }  ||
 3 ||-----[ 12 ]------------------------{ 12      MOV}--||
   ||     [C1 <]                        {C1  :=      }  ||
 4 ||-----[ 0  ]------------------------{ 0       MOV}--||
   ||       X3                                C1        ||
 5 ||-------] [------------------------------{RES}------||
   ||       X4                          {C1  :=      }  ||
 6 ||-------] [-------------------------{ 12      MOV}--||
   ||     [C1 ==]                             Y1        ||
 7 ||-----[ 0   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y2        ||
 8 ||-----[ 12  ]-----------------------------( )-------||

  Program ini akan menghasilkan Counter Up Down, yang mulai dari 0, 
  dengan nilai maksimum Counter adalah 12.
  Ketika tombol X1 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah naik 1 nilai setiap kali ditekan.
  Ketika tombol X2 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah turun 1 nilai setiap kali ditekan.
  Ketika tombol X3 ditekan, nilai Counter akan direset ke 0.
  Ketika tombol X4 ditekan, nilai Counter akan dipreset ke 12.
  Ketika nilai Counter = 0, maka instruksi C1.lowerQ() bernilai 1,
  membuat Relay di Y1 hidup.
  Ketika nilai Counter = 10, maka instruksi C1.upperQ() bernilai 1,
  membuat Relay di Y2 hidup.
  Untuk mengetahui nilai Counter C1, digunakan instruksi Serial.print, yang
  akan menampilkan nilai Counter di Serial Monitor.
*/
#include <PLCArduinoku.h>
Counter C1(12); 
unsigned long T1, T2;  
void setup() {
  setupku();
  outLow();
  Serial.begin(9600);      
}

void loop() {
  in(X1); timerOn(T1,10); C1.countUp();            
  in(X2); timerOn(T2,10); C1.countDown();           
  in(X3); C1.clear();  
  in(X4); C1.preset();
  C1.lowerQ(); out(Y1);
  C1.upperQ(); out(Y2);
  Serial.println(C1.count());
}
