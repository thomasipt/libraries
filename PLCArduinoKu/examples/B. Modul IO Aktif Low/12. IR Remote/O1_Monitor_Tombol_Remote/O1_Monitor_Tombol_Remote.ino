/*
1.Rangkaian:
  Nama Input  : "^", "V", "<", ">", "OK", "1", 
  "2", "3", "4", "5", "6", "7", "8", "9", "*", "0", "#"
  Kaki Input  : Penerima Remote di kaki A5 Arduino
  Alat Input  : Remote InfraRed 1x
  Alat Output : Serial Monitor
  
2.Program:
  Sebuah Remote menawarkan banyak kelebihan; di antaranya adalah 
  komunikasi tanpa kabel dan tombol input dalam jumlah yang cukup 
  banyak hanya dengan satu buah kaki input saja.
  Di modul hardware PLCArduino ini, sebuah Remote Infrared produksi
  Keyes digunakan, dengan jumlah tombol input sebanyak 17 buah, 
  yang dihubungkan pada kaki A5 Arduino.
   
  Program berikut ini akan membaca tombol Remote yang ditekan dan 
  menampilkannya di Serial Monitor.
*/
#include "IRremote.h"
#include "PLCArduinoku.h"
int receiver = 19; 
IRrecv irrecv(receiver);           
decode_results results;         

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop(){
  if (irrecv.decode(&results)) {
    translateIR(); 
    irrecv.resume(); 
    }  
}

void translateIR(){
  switch(results.value) {
  case 0xFF629D: Serial.println("^"); break;
  case 0xFF22DD: Serial.println("<");    break;
  case 0xFF02FD: Serial.println("OK");    break;
  case 0xFFC23D: Serial.println(">");   break;
  case 0xFFA857: Serial.println("V"); break;
  case 0xFF6897: Serial.println(" 1");    break;
  case 0xFF9867: Serial.println(" 2");    break;
  case 0xFFB04F: Serial.println(" 3");    break;
  case 0xFF30CF: Serial.println(" 4");    break;
  case 0xFF18E7: Serial.println(" 5");    break;
  case 0xFF7A85: Serial.println(" 6");    break;
  case 0xFF10EF: Serial.println(" 7");    break;
  case 0xFF38C7: Serial.println(" 8");    break;
  case 0xFF5AA5: Serial.println(" 9");    break;
  case 0xFF42BD: Serial.println(" *");    break;
  case 0xFF4AB5: Serial.println(" 0");    break;
  case 0xFF52AD: Serial.println(" #");    break;
  case 0xFFFFFFFF: Serial.println("Tombol ditahan"); break;  
  default: Serial.println("Tak terbaca");}
  delay(500); 
}
 
  
