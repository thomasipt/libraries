/*
1.Rangkaian:
  Modul Output Aktif Low.
  Nama Input  : "^", "<", "OK", ">", "V", "1", "2", 
  "3", "4", "5", "6", "7", "8", "9", "*", "0", "#"
  Nama Output : Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12
  Kaki Input  : Penerima Remote di kaki A5 Arduino
  Kaki Output : D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13 Arduino
  Alat Input  : Remote InfraRed 1x
  Alat Output : Relay 4x dan LED 8x

2.Program:
  Sama seperti Keypad, tombol Remote menghasilkan sinyal aktif yang hanya sesaat, 
  yaitu seperti pulsa denyut, yang mengabaikan berapa lama tombol ditekan. 
  Untuk mengatasi input tombol yang hanya sesaat tersebut, diperlukan sebuah instruksi 
  yang dapat mengunci sinyal output dari tombol tersebut, seperti program Latch berikut.
  Program berikut akan menghidupkan Relay dan atau LED setiap kali tombol tertentu ditekan.
  Kecuali tombol OK, semua tombol hanya bisa menghidupkan satu buah Relay atau LED.
  Ketika tombol OK ditekan, maka semua Relay dan LED akan menyala. 
  Untuk mematikannya, tekan tombol yang telah ditekan sebelumnya, cukup lama dan ditahan.    
*/
#include "IRremote.h"
#include "PLCArduinoku.h"
int receiver = 19; 
IRrecv irrecv(receiver);           
decode_results results;         
unsigned int RY1, RY2, RY3, RY4, RY5, RY6, RY7, RY8, RY9, RY10, RY11, RY12;
void setup() {
  setupku();
  outHigh();
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop(){
  //bagian input dan proses
  if (irrecv.decode(&results)) {
    translateIR(); 
    irrecv.resume(); 
    }

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

void translateIR(){
  switch(results.value) {
  case 0xFF629D: Serial.println("^"); RY1=1; break;
  case 0xFF22DD: Serial.println("<"); RY2=1; break;
  case 0xFF02FD: Serial.println("OK"); 
  RY1=1; RY2=1; RY3=1; RY4=1; RY5=1; RY6=1; 
  RY7=1; RY8=1; RY9=1; RY10=1; RY11=1; RY12=1; break;
  case 0xFFC23D: Serial.println(">"); RY3=1; break;
  case 0xFFA857: Serial.println("V"); RY4=1; break;
  case 0xFF6897: Serial.println(" 1"); RY1=1; break;
  case 0xFF9867: Serial.println(" 2"); RY2=1; break;
  case 0xFFB04F: Serial.println(" 3"); RY3=1; break;
  case 0xFF30CF: Serial.println(" 4"); RY4=1; break;
  case 0xFF18E7: Serial.println(" 5"); RY5=1; break;
  case 0xFF7A85: Serial.println(" 6"); RY6=1; break;
  case 0xFF10EF: Serial.println(" 7"); RY7=1; break;
  case 0xFF38C7: Serial.println(" 8"); RY8=1; break;
  case 0xFF5AA5: Serial.println(" 9"); RY9=1; break;
  case 0xFF42BD: Serial.println(" *"); RY10=1; break;
  case 0xFF4AB5: Serial.println(" 0"); RY11=1; break;
  case 0xFF52AD: Serial.println(" #"); RY12=1; break;
  case 0xFFFFFFFF: Serial.println("Tombol Ditahan");     
  RY1=0; RY2=0; RY3=0; RY4=0; RY5=0; RY6=0;
  RY7=0; RY8=0; RY9=0; RY10=0; RY11=0; RY12=0; break;
  }
  delay(500); 
}

