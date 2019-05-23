#ifndef NODE_
#define NODE_
#include <string>
class Noeud{



public:
virtual float Calcule(float*) const=0;

virtual std::string Affiche() const;


virtual void Unasigne() =0;

virtual Noeud* Copy() const =0;

virtual void GetNods(Noeud**,int*)  =0;

protected:
Noeud* Noeud1_=nullptr;
Noeud* Noeud2_=nullptr;

friend class Fonction; // je n'ai pas réussi à rendre friend les methode de function, juste la classe elle même, sinon je dois includ la classe ce qui pose un problème car elle inclu elle même noeud

};

#endif //NODE_
