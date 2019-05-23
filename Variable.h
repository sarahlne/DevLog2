#ifndef VARIABLE_ 
#define VARIABLE_
#include"Noeud.h"
#include <string>
class Variable : public Noeud{

public:
/* Constructor */
Variable(int); 

/*Calcule() method */
float Calcule(float*) const override;
/* 
Return the value of the boolean
@param Pointer to a boolean value
@retuun A boolean value (wich is the result of the operation)
*/


/*Affiche() method */
std::string Affiche() const override;
/*
Return the position of the variable
@param None
@return A the position in a string
*/


/* Destructor */
void Unasigne()  override;

/* Copy() method */
Noeud* Copy() const override;
/*
Create a new Variable node with the same position
@param None
@return A pointer to a node
*/

/* GetNods method */
void GetNods(Noeud**,int*) override;
/*
Recursive function: return the adresses of all nodes of a give array
@param A pointer to a pointer to a node, a pointer to a int
@return None
*/

//Atributs
protected:
int posit_;
};
#endif //VARIABLE_
