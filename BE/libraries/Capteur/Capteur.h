
#include <DHT.h>
class Capteur {
  protected:
  int pin; 
  public:
  Capteur ();
  Capteur (int npin);
};
class CapteurDHT : public Capteur {
  private:
  DHT dht;
  public:
  CapteurDHT (int npin , int type) ;
  float getTemp (void);
  float getMoist (void);
};
class CapteurAnalog : public Capteur{
  public:
  CapteurAnalog ();
  CapteurAnalog(int npin);
  float getLum (void);

};