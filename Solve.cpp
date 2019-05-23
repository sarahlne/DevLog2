#include "Solve.h"
#include<iostream>



//##################CONSTRUCTORS and DESTRUCTORS ##################

// Constructeur par défaut (très mauvaise idée, ne fait pas de sens)(Titouan)
/*
Solve::Solve(){
  lambda_=5;
  nbvar_=3;
  popFonct_ = (Fonction**) malloc(lambda_*sizeof(Fonction*));

  popFonct_[0]=new Fonction(new Valeur(true),nbvar_);

  //HistoricFitness_[0]=new int(popFonct_[0.fitness()]);
  //il faut initialiser les cases de popFonct_
  for (int i=1; i<lambda_; i++){
    popFonct_[i]=NULL;
  }
  //HistoricFitness_[0]=new int(popFonct_[0].fitness());
}
*/
Solve::Solve(int dim , int nbfille,float ** X,int rangeX, float *Y, int generations){ //Modification des tableaux de boolean en tableau de float
  lambda_= nbfille;
  nbvar_= dim;
  x_=X;
  y_=Y;
  rangex_=rangeX;
  popFonct_ = (Fonction**) malloc(lambda_*sizeof(Fonction*));
  popFonct_[0]=new Fonction(new Variable(0),nbvar_);
  nbGeneration_=generations;
  HistoricFitness_=new float[nbGeneration_];

  //il faut initialiser les cases de popFonct_
  for (int i=1; i<lambda_; i++){
    popFonct_[i]=nullptr;
  }
}

//destructeur
Solve::~Solve(){
  for(int i=0; i<lambda_; i++){ //delete chaque pointeur de tableau
    //vérifie que  le pointeur n'est pas nulle , c'est à dire , si il y a une valeur on le supprime
    //faire ça à chaque fois qu'on supprimer les éléments de popFunction
    if (popFonct_[i]!= nullptr){
      delete popFonct_[i];
    }
  } 
  free(popFonct_) ;
  delete[] HistoricFitness_;
}

//##################FUNCTIONS##################

int Solve::bestFitness(int * HistoricFitness_){//return l'emplacement de la meilleur fitness du tableau
  int place;
  for(int i=0; i<lambda_;++i){
    int best = HistoricFitness_[0];
    
    if(HistoricFitness_[i]>best){
      best=HistoricFitness_[i];
      place=i;
    }
  }
  return place;
}

void Solve::ReplaceFitness(int place){
  HistoricFitness_[0]=HistoricFitness_[place]; 
}

Fonction * Solve::bestFct(Fonction ** popFonct_,int place){//return le meilleure fonction
  return popFonct_[place];
}

void Solve::PlacementFct(int place ){//Met la meilleure fonction en premier rang

  Fonction* f1 = bestFct(popFonct_,place);
  
  for(int i=0;i<lambda_;++i){
    if (popFonct_[i]!=nullptr){
      delete popFonct_[i];
    }
  }
  
  popFonct_[0]=f1;
}


void Solve::evolve(){
  for(int n=0;n<nbGeneration_;++n){
    int place =0;
    HistoricFitness_[n] = popFonct_[0]->Fitness(x_,rangex_,y_)/rangex_; //x_ et y_ sont des tableaux de float
    
    for(int i=1; i< lambda_;i++){
      popFonct_[i]=new Fonction(*popFonct_[0]);
      for (int j=1; j< 10;j++){ //nobre de mutation entre parent et enfant, arbitraire
        popFonct_[i]->Mute();
      }
      float ffit=popFonct_[i]->Fitness(x_,rangex_,y_)/rangex_; // x_ et y_ sont des tableaux de float
      if(ffit>HistoricFitness_[n]){
        place=i;
        HistoricFitness_[n]=ffit;
      
      }
      //popFonct_[i]=popFonct_[0]->mute();
      //HistoricFitness_[i]=popFonct_[i]->fitness();
    }
    
    Fonction* best_func=new Fonction(*popFonct_[place]);
    for(int i=0;i<lambda_;++i){
      delete popFonct_[i];
      popFonct_[i]=nullptr;
    }
    popFonct_[0]=best_func;
  }    
}

void Solve::affiche_final_fonction()const{
	std::cout<<popFonct_[0]->Affiche()<<std::endl;
}
float* Solve::getHistoricFitness() const{
   
   return HistoricFitness_;
}
float Solve::getFinalFitness() const{
   return HistoricFitness_[nbGeneration_-1];
}
float Solve::CalculeFinalFonction(float*X){ //Prend un tableau de float en parametre et renvoi un float et non un bool
  return popFonct_[0]->Calcule(X);
}
