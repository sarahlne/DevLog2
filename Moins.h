#ifndef Moins_ 
#define Moins_
#include"Noeud.h"
#include <string>
class Moins : public Noeud{

public:
/* Constructor */
Moins(Noeud*,Noeud*); 

/*Calcul method */
float Calcule(float*) const override;
/* 
Recursive method, compute the OR operation between two nodes
@param Pointer to a boolean value
@retuun A boolean value (wich is the result of the operation)
*/


/*Affiche() method */
std::string Affiche() const override;
/*
Recursive method: return the results of the Affiche() methods of the Nodes given in parameters
@param None
@return A String describing the input Nodes
*/


/* Destructor */
void Unasigne() override;

/* Copy() method */
Noeud* Copy() const override;
/*
Create a new Moins node with copies of input nodes as parameters
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

};
#endif //Moins_
