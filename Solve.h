#include<iostream>
#include "Fonction.h"
#include "Noeud.h"
#include "Variable.h"
#include <string>


#ifndef SOLVE
#define SOLVE
class Solve{
  public:
    //Constructeur
    //Solve(); (en veilleuse pour le moment, dangeureux )
    Solve(int dim , int nbfille, float** X,int rangeX, float *Y,int generations);// Pas de tableau de boolean mais tableau  de float
    
    /* Constructeur
     Args : int dim : nombre de varaible de la fonction
            int nbfille : nombre de Fonction filles construites à chaque génération
            float ** X : vecteur de variables d'entrées 
            float * Y : vecteur de variable de sortie 
            int generation : nombre de générations à faire
            */
    
    //destructeur
    ~Solve();
        
    //Function

    
    int bestFitness(int * HistoricFitness_);
    /*This fonction research the best Fitness among all fitness of the generation
    argument : tabular of historicFitness (tabular of fitness value of all the generation)
    returns a int, value of place of tabular where is the best Fitness
    */
    
    Fonction * bestFct(Fonction ** popFonct_,int place);
     /*This fonction gives the best Fonction of the generation (found with place of the best fitness)
    argument : tabular of fonction of this generation and place of best fitness of this generation
    returns a fonction, the best fonction of the generation
    */
    
    void ReplaceFitness(int place);
    /*This fonction place the best Fitness at the first emplacement of the HistoricFitness tabular
    argument : place of the best Fitness
    returns nothing
    */
    
    void PlacementFct(int place);
    /*This fonction place the best Fonction at the first emplacement of fonction tabular and empty the rest of the tabular
    argument : place of the best Fitness (which is also the place of the best Fonction)
    returns nothing
    */
    
    void evolve();
    /*This fonction make mute the best fonction (which have the best Fitness) of each generation during a nomber of generation given
    argument 
    returns nothing
    */
    
    float CalculeFinalFonction(float*X); // tableau de float
  
    //Getters
    void affiche_final_fonction() const;
    float* getHistoricFitness() const;
    float getFinalFitness() const;
    
  protected:
    Fonction ** popFonct_ ; // pointeur d'un tableau de pointeurs
    float * HistoricFitness_ ;
    int nbGeneration_;
    float ** x_  ; // tableau de float
    float * y_  ; //tableau de float
    int lambda_ ; //nombre d'enfants crée à chaque génération
    int nbvar_; // nombre de variables , ex (x1,x2,x3) nbvar=3
    int rangex_;//nombre de serie de variable
    
};




#endif

