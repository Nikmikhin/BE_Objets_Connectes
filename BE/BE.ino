#include <Capteur.h>
#include <Actionneur.h>
#include <Data.h>
#include <list>
#include <algorithm>  

using namespace std;

#define DHT_PIN D6 
#define DHT_TYPE DHT22
#define LUM_PIN A0
#define BUZZER_PIN D3
#define PERIOD 5000
#define SEUIL_MIN_TEMP 10
#define SEUIL_MAX_TEMP 60
#define SEUIL_MIN_LUM 20000
#define SEUIL_MIN_MOIST 10

// fonction qui retourne la moyenne des points data d'une liste
Data CalculMoy(list<Data> l1){
  Data dmoy;
  list<Data>::iterator it;
  int counter = 0;
  float tempmoy = 0;
  unsigned int moistmoy = 0;
  float illummoy = 0;
  for(it=l1.begin(); it!=l1.end(); it++){
    tempmoy = tempmoy + (it)->getTemp();
    moistmoy = moistmoy + (it)->getMoist();
    illummoy = illummoy + (it)->getLum();
    counter = counter + 1;
  }
  dmoy=Data(tempmoy/counter, moistmoy/counter, illummoy/counter);
  return dmoy;
}

// Creation des objects
  CapteurAnalog captLum(LUM_PIN);
  CapteurDHT captDht(DHT_PIN, DHT_TYPE);
  Display disp;
  Buzzer buzzer(BUZZER_PIN);
  list<Data> l1;
  
 void setup() {
  Serial.begin(9600); 
  Serial.println("Debut de programme");
  
 }
void loop(){
  for (int count = 0; count<10;count++){
    Data d1(captDht.getTemp(),captDht.getMoist(),captLum.getLum());
    disp.afficherSurDisplay(d1.getTemp(),d1.getMoist(), d1.getLum());
    d1.afficherEcrain();
    l1.push_back(d1);
    delay (PERIOD);
  }
    Data moyenne = CalculMoy(l1);
    Serial.println("MOYENNE : ");
    moyenne.afficherEcrain();
    Serial.println();
    if (moyenne.getTemp()>SEUIL_MAX_TEMP ||moyenne.getTemp()<SEUIL_MIN_TEMP || moyenne.getMoist()<SEUIL_MIN_MOIST || moyenne.getLum()<SEUIL_MIN_LUM) buzzer.playMelody();
    l1.clear();
}
