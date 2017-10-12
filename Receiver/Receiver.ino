#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
IRrecv sensor(13);
decode_results hasil;

void setup(){
  Serial.begin(9600);
  sensor.enableIRIn();
  lcd.begin(16, 2);
  pinMode(10,OUTPUT);
  pinMode(8, OUTPUT);
  String teks = "Welcome !";
  lcd.print(teks);
  delay(5000);
  lcd.clear();
}

void loop() {  
  if (sensor.decode(&hasil)) {
    Serial.println(hasil.value, HEX); 
    //delay(500);
    if(hasil.value == 0x38863BE0 || hasil.value == 0x3886){
      lcd.setCursor(0,0);
      String teks = "Dilarang parkir";
      lcd.print(teks);
      digitalWrite(8,1);
      delay(1000);
    }else if(hasil.value == 0xAAAA4445){
      lcd.setCursor(0,0);
      String teks = "Dilarang stop !";
      lcd.print(teks);
      delay(2000);
    }else if(hasil.value == 0xAAAA4445){
      lcd.setCursor(0,0);
      String teks = "Dilarang putar balik";
      lcd.print(teks);
      delay(2000);
    }
    digitalWrite(8,0);
    sensor.resume();
  }
  else{
    lcd.clear();
  }
}
