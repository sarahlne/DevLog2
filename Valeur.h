#ifndef VALEUR_ 
#define VALEUR_
#include"Noeud.h"
#include <string>
class Valeur : public Noeud{

public:
/* Constructor */
Valeur(float); 

/*Calcule() method */
float Calcule(float*) const override;
/* 
Recursive method wich return the value itself
@param Pointer to a boolean value
@retuun A boolean value (wich is the result of the operation)
*/

/*Affiche() method */
std::string Affiche() const override;
/*
Recursive method: return the results of the Affiche() methods of the Nodes given in parameters
@param None
@return A String: True if the value is 1, False if the value is 0
*/

/* Destructor */
void Unasigne() override;

/* Copy() method */
Noeud* Copy() const override;
/*
Create a new Valeur node the same value
@param None
@return A pointer to a node
*/

/* GetNods method */
void GetNods(Noeud**,int*)  override;
/*
Recursive function: return the adresses of all nodes of a give array
@param A pointer to a pointer to a node, a pointer to a int
@return None
*/

//Atributs

protected:
float val_;

};
#endif //VALEUR_
