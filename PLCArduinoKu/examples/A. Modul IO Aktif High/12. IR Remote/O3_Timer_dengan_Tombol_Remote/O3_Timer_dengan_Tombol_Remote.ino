/*
1.Rangkaian:
  Modul Output Aktif High.
  Nama Input  : Tombol "1", "2", "3", "4", "5"
  Nama Output : Y1, Y2, Y3, Y4, Y5
  Kaki Input  : kaki A5 Arduino
  Kaki Output : kaki D2, D3, D4, D5 dan D6 Arduino
  Alat Input  : Remote InfraRed 1x 
  Alat Output : Relay 4x dan LED 1x

2.Program:
  Berbeda dengan tombol biasa dan tombol di Keypad yang bisa menyediakan 
  pendeteksian sisi pulsa ketika tombol ditekan, ditahan dan dilepas, 
  tombol di Remote ini hanya bisa men-set dan mereset outputnya.
  
  Namun demikian, untungnya tombol di Remote ini menyediakan pendeteksian 
  ketika tombol ditekan cukup lama, atau ditahan penekanannya.
  Dengan pendeteksian kapan tombol ditekan sebentar dan kapan tombol ditekan lama ini,
  dapat dibuat output yang berbeda, yaitu ketika ditekan sebentar, maka output diset 1,
  sedangkan ketika tombol ditekan lama, maka output tombol tersebut dibuat 0 (direset).
 
  Dengan cara ini, untuk Timer ON misalnya, karena membutuhkan input tombol yang selalu 1, 
  sebelum waktu tundanya tercapai, maka tombol hanya perlu ditekan sebentar.
  Sedangkan untuk Timer Off karena membutuhkan input 1 kemudian 0, maka tombol harus ditekan
  dan ditahan lama. Setelah muncul pesan di Serial Monitor "Tombol ditahan", barulah tombol
  tersebut dilepas. Ini akan membuat tombol menghasilkan output dari 1 kemudian 0.
  Begitu juga untuk Timer Pulse, dibutuhkan penekanan tombol yang lama untuk menghasilkan 
  output tombol dari 1 kemudian 0.
  Untuk Timer Cycle, karena butuh input yang selalu 1 agar bisa membangkitkan gelombang,
  maka penekanan tombol hanya sebentar saja.
  Untuk RTO, karena butuh akumulasi tombol hidup dan mati beberapa kali (input tidak harus
  selalu 1), maka perlu penekanan tombol yang ditahan dan dilepas, dan kemudiaan diulangi lagi.   
  */
#include "IRremote.h"
#include "PLCArduinoku.h"
  int receiver = 19; 
  IRrecv irrecv(receiver);           
  decode_results results;         
  unsigned int RX1, RX2, RX3, RX4, RX5;
  unsigned int RY1, RY2, RY3, RY4, RY5;
  unsigned long T1, T2, T3, T4, T5, T6, T7;
void setup() {
  setupku();
  outLow();
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop(){
  //bagian input
  if (irrecv.decode(&results)) {
    translateIR(); 
    irrecv.resume(); 
    }

  //bagian proses
  in(RX1); timerOn(T1, 2000); out(RY1); //tekan tombol angka 1 sebentar
  in(RX2); timerOff(T2,3000); out(RY2); //tekan tombol angka 2 dan tahan hingga di Serial Monitor 
                                        //muncul tulisan "Tombol ditahan", barulah dilepas
  in(RX3); timerPulse(T3,4000); out(RY3); //tekan tombol angka 3 dan tahan, kemudian dilepas
  in(RX4); timerCycle(T4,200,T5,100); out(RY4);  //tekan tombol angka 4 sebentar
  in(RX5); RTO(T6, 5000, T7); out(RY5);   //tekan tombol angka 5 dan tahan, 
                                          //kemudian tombol dilepas dan ulangi kembali penekanannya
  
  //bagian output
  in(RY1); out(Y1);
  in(RY2); out(Y2);    
  in(RY3); out(Y3);
  in(RY4); out(Y4);
  in(RY5); out(Y5);
}

void translateIR(){
  switch(results.value) {
  case 0xFF6897: Serial.println(" 1"); RX1=1; break; //penekanan sebentar untuk men-set 1
  case 0xFF9867: Serial.println(" 2"); RX2=1; break; //penekanan sebentar untuk men-set 1
  case 0xFFB04F: Serial.println(" 3"); RX3=1; break; //penekanan sebentar untuk men-set 1
  case 0xFF30CF: Serial.println(" 4"); RX4=1; break; //penekanan sebentar untuk men-set 1
  case 0xFF18E7: Serial.println(" 5"); RX5=1; break; //penekanan sebentar untuk men-set 1
  case 0xFFFFFFFF: Serial.println("Tombol Ditahan"); //penekanan yang lama untuk mereset   
  RX1=0; RX2=0; RX3=0; RX4=0; RX5=0; break;  
  }
  delay(500); 
}

