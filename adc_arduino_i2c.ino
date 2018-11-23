#include <Wire.h>

int val_8bits=0;

void setup(){
  Wire.begin(0x22); //inicia conexión i2c en la dirección #0x22
  Wire.onRequest(lectura_adc);
  Wire.onReceive(selec_adc);
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  delay(100);
}

void lectura_adc(){
  Wire.write(val_8bits);  //envía dato convertido
}

void selec_adc(int bytesReceived){
  int canal=0;
  while(Wire.available()){
    canal=Wire.read();
    switch(canal){
      case 5:
      val_8bits=(analogRead(A5)/4);
      break;
      case 4:
      val_8bits=(analogRead(A4)/4);
      break;
      case 3:
      val_8bits=(analogRead(A3)/4);
      break;
      case 2:
      val_8bits=(analogRead(A2)/4);
      break;
      default:
      break;
    }
  }
  
}
