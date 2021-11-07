////////////// CLASSE DATA //////////////
class Data{
 protected:
    float temp;
    unsigned int moist;
    float illum;
 public:
  // initialisation d'un point data vide
  Data();
  // constructeur de base
  Data(float valtemp, unsigned int valmoist, float valillum);
  // constructeur de recopie d'un point data dans un autre
  Data(const Data & dat1);
  // fonction pour accéder à la température d'un point data
  float getTemp();
  // fonction pour accéder à l'humidité d'un point data
  unsigned int getMoist();
  //fonction pour accéder à la luminosité d'un point data
  float getLum();
  // fonction pour afficher les valeurs du point data
  void afficherEcrain();
};