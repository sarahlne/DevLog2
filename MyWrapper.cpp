#include <Python.h> //include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include<iostream>
#include "def_PyC.h"
#include "Solve.h"
#include <ctime>


// Name for the cpp object "capsules"
#define NAME_CAPSULE_SOLVE "SOLVE"

//Receives a Python capsule for object A, and extracts the pointer of the C++ object
//Pyobjet : onejt du Python.h
static Solve* SolvePythonToC(PyObject* args){
	Solve* my_Solve;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_Solve = (Solve*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_SOLVE);
	return my_Solve;
}

// Frees object A Python capsule
void SolveCapsuleDestructor(PyObject* capsule){
	Solve* my_solve = (Solve*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_SOLVE);
  delete my_solve;
}

// Calls the Print function of object A
static PyObject* PrintSolve(PyObject* self, PyObject* args){
    Solve*  my_Solve = SolvePythonToC(args);
    my_Solve->affiche_final_fonction();
    //incremente une nouvelle instance de Pynone et le renvoie 
    //en Python, les méthodes renvoie un None si on ne renvoie rien 
    Py_INCREF(Py_None);
    return Py_None;
}
//Calls method evolve of object Solve
static PyObject* EvolveSolve(PyObject* self, PyObject* args){
		Solve*  my_Solve = SolvePythonToC(args);
    my_Solve->evolve();
		Py_INCREF(Py_None);
    return Py_None;
}
//Get Final Fitness of Object Solve
static PyObject* GetFitness(PyObject* self, PyObject* args){
		Solve*  my_Solve = SolvePythonToC(args);
    float fitness=my_Solve->getFinalFitness();
  	return Py_BuildValue("f",fitness);
}

//Calcul Final Fonction of Object Solve
static PyObject* CalculFonction(PyObject* self, PyObject* args){
		PyObject* argsobj;
	  PyListObject* Yobj;
		if (!PyArg_ParseTuple(args, "OO",&argsobj,&Yobj)){
		    return NULL;
	  }
	  int rangeY = PyList_Size((PyObject*)Yobj);
	  printf("size  %d\n",rangeY);
	  float * Y=new float [rangeY];
	  for (int i = 0; i <rangeY; i++){
        Y[i]= float(PyLong_AsLong((PyObject*) PyList_GetItem( (PyObject*) Yobj, (Py_ssize_t) i)));
    }
    //argsobj n'est plus un tuple , on ne peut pas utiliser PythontoC
    Solve*  my_Solve = (Solve*) PyCapsule_GetPointer(argsobj,NAME_CAPSULE_SOLVE);
    float resultat = my_Solve->CalculeFinalFonction(Y);
    std::cout << resultat << std:: endl;
  	return Py_BuildValue("f",resultat);
}
//Get Final Fitness of Object Solve
static PyObject* GetHistoric(PyObject* self, PyObject* args){
	PyListObject* list;
	PyObject* argsobj;
	// The function receives a python list as parameter
	if (!PyArg_ParseTuple(args, "OO",&argsobj,&list)){
		    return NULL;
	}
	//get the wanted object
	Solve*  my_Solve = (Solve*) PyCapsule_GetPointer(argsobj,NAME_CAPSULE_SOLVE);
	//get the historic of fitness of this object
	float* historic = my_Solve->getHistoricFitness();
	// get the size of the list
	int size = PyList_Size((PyObject*) list);
  for (int j = 0; j < size; j++){
    // get the j-th element of the python list and convert it to long
		float listItem = (float) PyFloat_AsDouble(PyList_GetItem( (PyObject*) list , (Py_ssize_t) j));// check PyFloat_AsDouble for doubles
		listItem=historic[j];
		// Set the python list element to the new value
		PyList_SetItem((PyObject *) list, (Py_ssize_t) j, PyFloat_FromDouble((double) listItem) ); // check PyFloat_FromDouble for floats
    
  }
	return Py_BuildValue("O",list);
}

// Receive and parse parameters, constructs an object Solve, encapsulate it and return the capsule
//self : librairie  , args : objet python , les arguments donnés
static PyObject* SolveTranslator(PyObject* self, PyObject* args){
	srand(time(NULL)); // for better random generator (for mutation of Fonction)
	PyObject* lambdaO;
	PyListObject* Xobj;
	PyListObject* Yobj;
	PyObject* generationsO;
	if (!PyArg_ParseTuple(args, "OOOO", &generationsO, &Xobj, &Yobj,&lambdaO)){
		return NULL;
	}
  int lambda=int(PyLong_AsLong(lambdaO));
  int generations=int(PyLong_AsLong(generationsO));
	int rangeX=PyList_Size((PyObject*)Xobj);
	int dim=PyList_Size((PyObject*) ((PyObject*) PyList_GetItem( (PyObject*) Xobj, (Py_ssize_t) 0)));
	float ** X=new float* [rangeX];
	float * Y=new float [rangeX];
    for (int i = 0; i <rangeX; i++){
    		float * x=new float [dim];
        PyObject* ligne_de_X = (PyObject*) PyList_GetItem( (PyObject*) Xobj, (Py_ssize_t) i); 
        for (int j=0 ; j<dim ; j++){
        	  x[j]=float(PyLong_AsLong((PyObject*) PyList_GetItem( (PyObject*)ligne_de_X, (Py_ssize_t) j)));
        }
        Y[i]= float(PyLong_AsLong((PyObject*) PyList_GetItem( (PyObject*) Yobj, (Py_ssize_t) i)));
        X[i]=x;
    }
	Solve* my_Solve = new Solve(dim,lambda, X,rangeX,Y, generations);
	PyObject* capsule = PyCapsule_New(my_Solve, NAME_CAPSULE_SOLVE, SolveCapsuleDestructor);
	return capsule;
}

// Module functions {<python function name>, <function in wrapper>, <parameters flag>, <doctring>}
// https://docs.python.org/3/c-api/structures.html
static PyMethodDef module_funcs[] = {
    {"create_solver", (PyCFunction)SolveTranslator, METH_VARARGS, "Create an instance of class Solve\n\nArgs:\n\t int generation : number of generation \n\t tableau 3D X : vector with input variables \n\t tableau 2D  Y : vector of output variables  \n\t int nbfille numbers of new Fonctions created at each generation \n\nReturns:\n\t capsule: Object Solve capsule"},
    {"print_fonct", (PyCFunction)PrintSolve, METH_VARARGS,  "Print class Solve instance\n\n Args:\n\t Solver Object\n\n Print the final Function find by the solver"},
    {"evolve", (PyCFunction)EvolveSolve, METH_VARARGS,  "Evolve the function of the solver through symbolic regression\n\n Args:\n\t Solver Object so be evolved  \n\n Returns : None"},
    {"get_fitness", (PyCFunction)GetFitness, METH_VARARGS,  "Returns the fitness of the Function given by the symbolic regression  \n\n Returns : int "},
    {"calcul", (PyCFunction)CalculFonction, METH_VARARGS,  "Calculate the result of a given input through the fonction found by the symbolic regression \n\n Args:\n\t Solver Object \n\t vector of input to test in the fonction\n\n Returns : int 0 if results is False 1 if True "},
    {"get_historic", (PyCFunction)GetHistoric, METH_VARARGS,  "Get Historic of fitness from the regression \n\n Args:\n\t Solver Object \n\t list of length equals to number og generation given to the Solver\n\n Returns : table of int"},
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "NumSymReg",
        "NumSymReg is a library for Binary symbolic Regression",
        //taille du module
        sizeof(PyObject*),
        //toutes les focntions: 
				module_funcs,
				NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC PyInit_NumSymReg(void){
    PyObject* module = PyModule_Create(&moduledef);
		return module;
}
