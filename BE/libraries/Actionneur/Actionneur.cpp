#include <Actionneur.h>
#include <Arduino.h>
Actionneur :: Actionneur(){};

Display :: Display() : u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE) {
    u8g2.begin();
};

void Display :: afficherSurDisplay(float temp , float moist, float lum){
    char tab[20];
    u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    sprintf(tab, "temp: %.1f C", temp);
    u8g2.drawStr(0,24,tab);
    sprintf(tab, "moist: %.1f", moist);
    u8g2.drawStr(0,48,tab);
    sprintf(tab, "illum: %.1f lux", lum);
    u8g2.drawStr(0,72,tab);
  } while ( u8g2.nextPage() );
};


//////////// BUZZER ///////////////

Buzzer :: Buzzer(int npin) : Actionneur() , pin(npin){
   pinMode(npin, OUTPUT);    
};

void Buzzer :: playMelody(){
    for(int i = 0; i < length; i++) {
        if(notes[i] == ' ') {
            delay(beats[i] * tempo);
        } else {
            playNote(notes[i], beats[i] * tempo);
        }
        delay(tempo / 2);    /* delay between notes */
    }
}

/* play tone */
void Buzzer :: playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(pin, LOW);
    delayMicroseconds(tone);
  }
};

 void Buzzer :: playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}