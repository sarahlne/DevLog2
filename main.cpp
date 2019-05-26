#include <iostream>
#include "Noeud.h"
#include "Plus.h"
#include "Moins.h"
#include "Fois.h"
#include "Sur.h"
#include "Valeur.h"
#include "Variable.h"
#include "Fonction.h"
#include "Solve.h"
#include <string>

#include <cstdlib>
#include <ctime>



int main(){
srand(time(NULL));
std::cout << "Bonjour monde" << std::endl;

Valeur v1=Valeur(3.0);
Valeur v2=Valeur(2.0);
Plus p= Plus(&v1,&v2);
Moins m=Moins(&v1,&v2);
Fois f=Fois(&v1,&v2);
Sur s = Sur(&v1,&v2);
Variable va1=Variable(0);
Variable va2=Variable(1);

float* t= new float[2];
t[0]=1.0;
t[1]=-3.0;

std::cout << v1.Affiche() << " = "<< v1.Calcule(t)<<std::endl;
std::cout << v2.Affiche() << " = "<< v2.Calcule(t)<< std::endl;
std::cout << va1.Affiche() << " = "<< va1.Calcule(t)<<std::endl;
std::cout << va2.Affiche() << " = "<< va2.Calcule(t)<< std::endl;
std::cout << p.Affiche() << " = "<< p.Calcule(t)<<std::endl;
std::cout << m.Affiche() << " = "<< m.Calcule(t)<< std::endl;
std::cout << f.Affiche() << " = "<< f.Calcule(t)<< std::endl;
std::cout << s.Affiche() << " = "<< s.Calcule(t)<< std::endl;

Fonction fo(f.Copy(),2);
for (int i = 0; i<30;i++){
  fo.Mute();
}

std::cout << fo.Affiche() << " = "<< fo.Calcule(t)<< std::endl;
delete[] t;

std::cout << "test solveur"<< std::endl;

float * X1=new float[4];
float* X2=new float[4];
float* X3=new float[4];
float* X0=new float[4];

X1[0]=1.0;
X1[1]=2.0;
X1[2]=3.0;
X1[3]=4.0;

X2[0]=3.0;
X2[1]=0.5;
X2[2]=6;
X2[3]=9.8;


X3[0]=1.0;
X3[1]=7.3;
X3[2]=5;
X3[3]=9.0;

X0[0]=1.0;
X0[1]=1.0;
X0[2]=1.0;
X0[3]=1.0;

float** X=new float*[4];
X[0]=X0;
X[1]=X1;
X[2]=X2;
X[3]=X3;

float* Y=new float[4];
Y[0]=4.0;
Y[1]=8.0;
Y[2]=6.3;
Y[3]=5.4;

Solve S(4,10000,X,4,Y,20);

S.evolve();
std::cout <<"fonction finale "<< std::endl;
S.affiche_final_fonction();

for(int i=0;i<4;i++){
  std::cout <<"f(";
  for(int j=0;j<4;j++){
    std::cout<<X[i][j]<<"   ";
  }
  std::cout <<") = "<<S.CalculeFinalFonction(X[i])<< std::endl;
  std::cout <<"résultat attendu: "<<Y[i]<< std::endl;
}

std::cout <<S.getFinalFitness()<< std::endl;

std::cout <<"historique des fitnesses"<< std::endl;

float*H= S.getHistoricFitness();
for (int i=0; i<20;i++){
  std::cout <<H[i]<< std::endl;
}
delete[] X;
delete[]X1;
delete[]X2;
delete[]X3;
delete[]X0;
delete[] Y;
return 0;
}
