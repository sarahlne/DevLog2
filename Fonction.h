#ifndef FONCTION_
#define FONCTION_ 
#include <iostream>
#include <string>

#include "Noeud.h"
#include "Plus.h"
#include "Moins.h"
#include "Fois.h"
#include "Sur.h"
#include "Valeur.h"
#include "Variable.h"


#include <cstdlib>
#include <ctime>
#include <random>




extern int SIZE1;
extern int SIZE2;
class Fonction{
	public:
	Fonction() = delete;
	/* Constructor */
	Fonction(Noeud* noeud,int);
	
	/* Copy constructor */
	Fonction(const Fonction& model);
	
	/* Destructor */
	~Fonction();
	
	/* AdressFirstNode getter */
	Noeud* get_Adress();
	/* Renvoie l'adresse du premier noeud pointé par la fonction
	@param None
	@return un pointeur vers un booléen
	*/
	
	/* Calcul() method */
	float Calcule(float* input);
	/*Fonction récursive, faisant appel à la méthode Calcul() des booléens passer en paramètre par référence
	@param un pointeur vers une adresse contenant un booléen
	@return un booléen
	*/
	
	/* Affiche() method() */
	std::string Affiche();
	/* Méthode récursive faisant appel à la méthode Calcul() d'un booléen passer en paramètre par référence
	@param None
	@return un string contenant les informations de la fonction
	*/
	

  /*Deletion methode*/
  bool Deletion(int posit);
  /*provoque une deletion du noeud suivant le noeud à la position posit, si c'est possible.
	renvoi True si la deletion s'est faite, False sinon
	@param un entier
	@return une valeur booléenne
	*/


  /*Insertion methode*/
  bool Insertion(int posit,const Noeud*);
	/*
	provoque une insertion d'un noeud (copie) après le noeud à la position posit(si -1 ainsertion en tête) si c'est possible.
	renvoi True si l'insertion s'est faite, False sinon
	@param une entier, l'adresse d'un noeud passer par référence
	*/

  /*EchangeN1N2(posit)*/
  bool EchangeN1N2(int posit);
  /*provoque l'échange de Noeud1_ et Noeud2_ à la position posit si c'est possible.(Un grand nombre de methode agissent
   sur Noeud1_ et non Noeud2_, concrètement cette methode permet d'établir une équivalence 	entre Noeud1_ et Noeud2_ 
   dans la façon dont il seront ciblé par les methodes)
	 renvoi True si l'échange s'est fait, False sinon
	 @param un entier
	 return une booléen
	 */

  /*Remplace(int posit,const Noeud*)*/
  bool Remplace(int posit,const Noeud*);
	/*remplace le noeud par le noeud en parametre(copie) après le noeud à la position posit(si -1 ainsertion en tête) si c'est possible.
	renvoi True si l'insertion s'est faite, False sinon
	@param un entier, l'adresse d'un Noeud passer par référence
	@return un booléen
	*/


  /*Mute(int MutNumber)*/
  void Mute();
	/*effectue (si elle est possibles) une transformation de type Remplace, Echange, Insertion ou Deletion sur des noeuds aléatoire de la fonction
	@param None
	@return None
	*/
	
	
	/* Fitness() method */
  float Fitness(float** ,int range, float *);  
	/* Calule la Fitness de la fonction en comparant un tableau de résultats obtenu par la fonction à un tableau résultats attendu donné en paramêtre
	@param Un pointer référent vers un pointer de booléean, un entier, un pointer vers un booléen
	@return un Float représentant la valeur de la Fitness
	*/
	protected:
	
	private:
	Noeud* AdressFirstNode_;
  Noeud** Nodes_;
  size_t len_;
  size_t maxlen_;
  int Nombre_Var_;
	
};
#endif //CHARACTER_
