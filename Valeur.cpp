#include"Valeur.h"

/* Constructor */
Valeur::Valeur(float b):val_(b){
}

/*Calcule() method */
float Valeur::Calcule(float* b) const{
return val_;
}

/*Affiche() method */
std::string Valeur::Affiche() const{
return  std::string(val_);
}

/* Destructor */
void Valeur::Unasigne() {
  delete this;
}

/* Copy() method */
Noeud* Valeur::Copy() const{
return new Valeur(val_);
}

/* GetNods method */
void Valeur::GetNods(Noeud** tab,int* posit){
  tab[*posit]=this;
  *posit = *posit+1;
}
