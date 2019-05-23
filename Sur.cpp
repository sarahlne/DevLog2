#include"Sur.h"

/* Constructor */
Sur::Sur(Noeud* N1,Noeud* N2){
Noeud1_=N1;
Noeud2_=N2;
}

/*Calcul method */
float Sur::Calcule(float* b) const{
return Noeud1_->Calcule(b) / Noeud2_->Calcule(b);
}

/*Affiche() method */
std::string Sur::Affiche() const{
return  "("+Noeud1_->Affiche() +" / "+ Noeud2_->Affiche()+")";
}

/* Destructor */
void Sur::Unasigne(){
  Noeud1_->Unasigne();
  Noeud2_->Unasigne();
  delete this;
}

/* Copy() method */
Noeud* Sur::Copy() const{
return new Sur(Noeud1_->Copy(),Noeud2_->Copy());
}

/* GetNods method */
void Sur::GetNods(Noeud** tab,int* posit) {
  tab[*posit]=this;
  *posit = *posit+1;
  Noeud1_->GetNods(tab,posit);
  Noeud2_->GetNods(tab,posit);
}
