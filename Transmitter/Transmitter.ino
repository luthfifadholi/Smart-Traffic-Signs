#include <IRremote.h>

IRsend irsend;

void setup(){
  pinMode(13, OUTPUT);
  digitalWrite(13,0);
}

void loop(){
    irsend.sendNEC(0xAAAA4444, 32); //harus 8 digit
    delay(500);
    
    digitalWrite(13,1);   //untuk indikator mengirim sinyal
    delay(50);
    digitalWrite(13,0);
}
