#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
class Actionneur {
    public:
    Actionneur();
};

class Display : public Actionneur{
    protected:
    U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2;
    public: 
    Display();
    void afficherSurDisplay(float temp , float moist, float lum);


};

class Buzzer : public Actionneur {
private : 
  int pin;
  int length = 15;         /* the number of notes */
  char notes[15] = {'c','c','g','g','a','a','g','f','f','e','e','d','d','c','\0'};
  int beats[15] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4};
  int tempo = 250;
public :
  Buzzer (int npin);
  void playTone(int tone, int duration);
  void playNote(char note, int duration);
  void playMelody();
};