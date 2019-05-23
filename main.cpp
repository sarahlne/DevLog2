#include <iostream>
#include "Noeud.h"
#include "Plus.h"
#include "Moins.h"
#include "Fois.h"
#include "Sur.h"
#include "Valeur.h"
#include "Variable.h"

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


delete[] t;
return 0;
}
