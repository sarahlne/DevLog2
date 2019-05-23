#include <iostream>
#include <string>


#include "Fonction.h"

using std::cout;
using std::cin;
using std::endl;

//Constructor//
Fonction::Fonction(Noeud* noeud, int Var){
	AdressFirstNode_ = noeud;
  Nombre_Var_=Var;
  maxlen_=100;
  Nodes_=new Noeud*[100];
  int posit=0;
  AdressFirstNode_->GetNods(Nodes_,&posit);
  len_=posit;
  
}

//Copy constructor//
Fonction::Fonction(const Fonction& model){
	AdressFirstNode_ = model.AdressFirstNode_->Copy();
  Nombre_Var_=model.Nombre_Var_;
  len_= model.len_;
  maxlen_=100;
  int posit=0;
  Nodes_=new Noeud*[100];
  AdressFirstNode_->GetNods(Nodes_,&posit);
}

//Destructor// 
Fonction::~Fonction(){
  AdressFirstNode_->Unasigne();
  delete[] Nodes_;
}

//AdressFirstNode getter//
Noeud* Fonction::get_Adress(){
	return AdressFirstNode_;
}

// Calcul() method //
float Fonction::Calcule(float* input){
	return AdressFirstNode_->Calcule(input);
}

// Affiche() method //
std::string Fonction::Affiche(){
	return AdressFirstNode_->Affiche();
}

//Deletion() methode//
bool Fonction::Deletion(int posit){
  if (posit == -1){ //cas ou l'on suprime le premier noeud
    if(AdressFirstNode_->Noeud1_!=nullptr){// on ne veux pas suprimer une variable
      Noeud* Nprov = AdressFirstNode_;// on sauvegarde l'adresse de la branche que l'on va suprimer
      AdressFirstNode_=AdressFirstNode_->Noeud1_->Copy();// on cré une nouvelle branche, copie de la branche actuelle avec un noeud en moins, on l'acroche à notre arbre à la place de la branche que l'on va suprimer
      Nprov->Unasigne();//On suprime l'ancienne branche
      int p=0;
      AdressFirstNode_->GetNods(Nodes_,&p); // on recré la liste des noeuds
      len_=p;
      return true;
    }
   return false;    
  }
  else{
    if(Nodes_[posit]->Noeud1_!=nullptr and  Nodes_[posit]->Noeud1_->Noeud1_!=nullptr){// Une variable n'a pas de noeud suivant et on ne veux pas suprimer une variable
      Noeud* Nprov = Nodes_[posit]->Noeud1_;
      Nodes_[posit]->Noeud1_=Nodes_[posit]->Noeud1_->Noeud1_->Copy();
      Nprov->Unasigne();
      int p=0;
      AdressFirstNode_->GetNods(Nodes_,&p);
      len_=p;
      return true;
    }
   return false;
  }
}

//Insertion(int posit, const Noeud* n) method//
bool Fonction::Insertion(int posit,const Noeud* n){
  if(n->Noeud1_==nullptr){
    return false; //on ne peut pas insérer de valeur ou de variable (cela suprimerait le reste de la branche) 
  }

  if (posit==-1){ 
    Noeud* InsN= n->Copy();
    InsN->Noeud1_->Unasigne(); //on à créé une copie du Noeud à insérer auquel on à suprimé la branche ataché à son premier noeud. 
    InsN->Noeud1_=AdressFirstNode_;
    AdressFirstNode_=InsN; //On à insérer le noeud dans notre arbre
  }else{
    if(Nodes_[posit]->Noeud1_==nullptr){
      
      return false; //on ne peut pas insérer  après une variable ou une valeur (il n'y à alors plus de branche)
    }
    Noeud* InsN= n->Copy();
    InsN->Noeud1_->Unasigne(); //on à créé une copie du Noeud à insérer auquel on à suprimé la branche ataché à son premier noeud.
    InsN->Noeud1_=Nodes_[posit]->Noeud1_;
    Nodes_[posit]->Noeud1_=InsN;//On à insérer le noeud dans notre arbre

  }
  int p=0;
  AdressFirstNode_->GetNods(Nodes_,&p); // on recré la liste des noeuds
  len_=p;// on recaclcule la taille de la fonction 
  return true;
}


//EchangeN1N2(int posit) method//
bool Fonction::EchangeN1N2(int posit){
  if (posit==-1 or Nodes_[posit]->Noeud1_== nullptr or Nodes_[posit]->Noeud2_== nullptr ){
    return false;
  }
  Noeud * provisoir = Nodes_[posit]->Noeud1_;
  Nodes_[posit]->Noeud1_ =Nodes_[posit]->Noeud2_;
  Nodes_[posit]->Noeud2_ =provisoir;
  return true;

}
// Remplace(int posit,const Noeud*) method //
bool Fonction::Remplace(int posit,const Noeud* n){
  if(posit==-1){
    Noeud* InsN= n->Copy();
    if(AdressFirstNode_->Noeud1_!= nullptr and InsN->Noeud1_!= nullptr ){
      InsN->Noeud1_->Unasigne();
      InsN->Noeud1_=AdressFirstNode_->Noeud1_->Copy();
      if(AdressFirstNode_->Noeud2_!= nullptr and InsN->Noeud2_!= nullptr){
          InsN->Noeud2_->Unasigne();
          InsN->Noeud2_=AdressFirstNode_->Noeud2_->Copy();
      }
    
    }
    AdressFirstNode_->Unasigne();
    AdressFirstNode_=InsN;
  }
  else if (Nodes_[posit]->Noeud1_== nullptr){
    return false;
  }else{
    Noeud* InsN= n->Copy(); 
    if(Nodes_[posit]->Noeud1_->Noeud1_!= nullptr and InsN->Noeud1_!= nullptr ){
      InsN->Noeud1_->Unasigne();
      InsN->Noeud1_=Nodes_[posit]->Noeud1_->Noeud1_->Copy();
      if(Nodes_[posit]->Noeud1_->Noeud2_!= nullptr and InsN->Noeud2_!= nullptr){
          InsN->Noeud2_->Unasigne();
          InsN->Noeud2_=Nodes_[posit]->Noeud1_->Noeud2_->Copy();
      }
      
    }
    Nodes_[posit]->Noeud1_->Unasigne();
    Nodes_[posit]->Noeud1_=InsN;
  }   
  int p=0;
  AdressFirstNode_->GetNods(Nodes_,&p); // on recré la liste des noeuds
  len_=p;// on recaclcule la taille de la fonction 
  return true;
}


// Mute()method //
void Fonction::Mute(){
    int posit = int((rand()/(double) RAND_MAX) *(len_+1))-1;
    int type = int((rand()/(double) RAND_MAX) *4);
  if (type==0){
    this->Deletion(posit);
  }else if (type==1){
    this->EchangeN1N2(posit);
  }else if (type==2){
    int operateur = int((rand()/(double) RAND_MAX) *4);
    Variable V1(rand()%Nombre_Var_);
    Variable V2(rand()%Nombre_Var_);
    if (operateur==0){
      Plus O=Plus(&V1,&V2);
      this->Insertion(posit,&O);
    }else if (operateur==1){
      Moins E=Moins(&V1,&V2);
      this->Insertion(posit,&E);
    }else if (operateur==2){
      Fois N=Fois(&V1,&V2);
      this->Insertion(posit,&N);
    }else if (operateur==3){
      Sur S=Sur(&V1,&V2);
      this->Insertion(posit,&S);
    }
  }else if (type==3){
  int ntype1 = int((rand()/(double) RAND_MAX) *2);
  int ntype2 = int((rand()/(double) RAND_MAX) *3);// obligé d'utiliser deux générateur car sinon la distribution est trop peu uniforme. Un des doublet va corespondre à une absence de mutation
    Variable V1(rand()%Nombre_Var_);
    Variable V2(rand()%Nombre_Var_);
    if (ntype1==0 and ntype2==0){
      Plus O=Plus(&V1,&V2);
      this->Remplace(posit,&O);
    }else if (ntype1==1 and ntype2==0){
      Moins E=Moins(&V1,&V2);
      this->Remplace(posit,&E);
    }else if (ntype2==1 and ntype1==0){
      Fois N=Fois(&V1,&V2);
      this->Remplace(posit,&N);
    }else if (ntype2==2 and ntype1==1){
      Valeur V= Valeur((rand()/(double) RAND_MAX) *10);
      this->Remplace(posit,&V);
    }else if (ntype2==1 and ntype1==1){
      float v =(rand()/(double) RAND_MAX) *Nombre_Var_;
      int i= int(v);
      Variable V(i);
      this->Remplace(posit,&V);      
    }else if (ntype2==2 and ntype1==0){
      Sur S=Sur(&V1,&V2);
      this->Remplace(posit,&S);
    }    
  }
}

// Fitness() method //
float Fonction::Fitness(float** in,int range , float * out){
  float Fitness=0.0;
  for(size_t i = 0; i < range; i++){
       Fitness=Fitness-(Calcule(in[i])-out[i])*(Calcule(in[i])-out[i]);
  }
  return Fitness;
}

