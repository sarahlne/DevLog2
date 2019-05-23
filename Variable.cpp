#include <sstream>
#include <iostream>
#include"Variable.h"

/* Constructor */
Variable::Variable(int u){
posit_=u;
}

/*Calcule() method */
float Variable::Calcule(float* b) const{
return b[posit_];
}

/*std::string Variable::Affiche() const{
//std::string s= std::to_string(posit_);
std::string s= std::to_string(static_cast<int>(posit_));
return  "X"+s;
}*/

/*Affiche() method */
std::string Variable::Affiche() const{
std::ostringstream ostr;
ostr<<"X"<<posit_;
return  ostr.str();
}

/* Destructor */
void Variable::Unasigne(){
  delete this;
}

/* Copy() method */
Noeud* Variable::Copy() const{
return new Variable(posit_);
}


/* GetNods method */
void Variable::GetNods(Noeud** tab,int* posit){
  tab[*posit]=this;
  *posit = *posit+1;
}
