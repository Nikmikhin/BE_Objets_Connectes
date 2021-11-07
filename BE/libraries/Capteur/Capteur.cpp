
//#include <Arduino.h>
#include <Capteur.h>

Capteur :: Capteur () : pin(NULL){};
Capteur :: Capteur (int npin) : pin(npin){};


CapteurDHT ::  CapteurDHT (int npin , int type) : Capteur(npin) , dht(npin,type){
	dht.begin();
  }

float CapteurDHT :: getTemp (void) {
    return dht.readTemperature();
  }

float CapteurDHT :: getMoist (void) {
    return dht.readHumidity();
  }


CapteurAnalog :: CapteurAnalog() : Capteur(){};
CapteurAnalog :: CapteurAnalog(int npin) : Capteur(npin){};
float CapteurAnalog :: getLum (void){
  int val = analogRead(Capteur :: pin);
  float lum = (float)val*100000/1023;
  return lum;
}