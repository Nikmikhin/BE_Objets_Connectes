#include <Data.h>
#include <iostream>
using namespace std;
Data :: Data(){
 temp=0;
 moist=0;
 illum=0;
 }
  // constructeur de base
 Data ::  Data(float valtemp, unsigned int valmoist, float valillum){ 
    temp=valtemp;
    moist=valmoist;
    illum=valillum;
  }
  // constructeur de recopie d'un point data dans un autre
  Data :: Data(const Data & dat1){
    temp=dat1.temp;
    moist=dat1.moist;
    illum=dat1.illum;
  }
  // fonction pour accéder à la température d'un point data
  float Data ::  getTemp(){
    return temp;
  }
  // fonction pour accéder à l'humidité d'un point data
  unsigned int Data ::  getMoist(){
    return moist;
  }
  //fonction pour accéder à la luminosité d'un point data
  float Data ::  getLum(){
    return illum;
  }
  // fonction pour afficher les valeurs du point data
  void Data :: afficherEcrain(){
    cout << "temperature:       " <<temp<< "°C" << endl;
    cout << "soil moisture:     " <<moist<< "%"<< endl;
    cout << "illuminance :      " <<illum<< " lux" << endl;
  }
