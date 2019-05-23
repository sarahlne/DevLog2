# DevLog2
### Autors
This project has been made in collaboration with: @Tpocquillon , @abonnalcon , @Dikec and @sarahlne

### Goals
The goal of this project was to create a python library coded in C++ language. The library give access to a solver wich allowed the user to do a symbolic regression from numerical values and operators addition, substraction, multiplication, soustraction. Since the solver we can access to the following methods:

	- A method that returns an optimal function by symbolic regression, for a given input/output set
	- A method that display the function in a tree form
	- A method able to get the fitness og the last function
	- A method able to give results given a dataset
	- A method able to give the evolution of the fitness during time
This projet tends to be finish be it can still be improved

### C++ core
+ `Solver.cpp , Solver.h'`:
 Use to manipulate the function Class
+ `Function.cpp ,Function.h`:
Use as a structure to represent the function used by the user and to do some operation to evolve the input function. 
+ `Noeud.cpp , Noeud.h`:
Hiden class , use to combine Value, Variable, And, Or, and Not classes in a same intance of classe. 
+ `Valeur.cpp , Valeur.h`:
Contains the value of a node, determine from given variables and one of the operators +  -  /  *.
+ `Variable.cpp , Variable.h`:
Contains the variable given to a Node to compute a return value.
+ `Plus.cpp , Plus.h`:
Returns the result of the + operation between two nodes.
+ `Moins.cpp , Moins.h`: 
Returns the result of the - operation between two nodes.
+ `Fois.cpp , Fois.h`:
Returns the result of the * operation between two nodes.
+ `Sur.cpp , Sur.h`:
Returns the result of the / operation between two nodes.



### Wrapper - Pylib

+ `setup.py` contains all the code needed to create the extension module using distutils library.
+ `install.sh` contains the command lines that should be executed to build the extension module .so:
  + Remove older .so file
  + Call the setup.py file with the `--inplace` option for `build_ext` command to put compiled .so extensions in the current folder (https://docs.python.org/2/distutils/configfile.html)
+ `script.py` a simple python script that calls the extension (simple example)
+ `def_PyC.h`: Header for a PyCapsule structure (used to encapsulate C/C++ pointers and pass them to python)
+ `MyWrapper.cpp`: C++/C - Python Wrapper. This file includes the <Python.h> header, that defines functions to parse and create python objects (e.g., lists ...). The basic idea is that when a C/C++ object is created, its pointer is stored in a Capsule and returned as a python object.
Then, if we need to apply new computations with this object we decapsulate the pointer, and run the computations. We can also return integers, floats, strs, lists ... A static PyMethodDef function (here module_funcs) is used to define the translation between the C++/C function names and their respective names in python (as well as their docstrings). The name, size, functions and docstring of the extension module are stored in a PyModuleDef struct (here moduledef). Finally, a function PyMODINIT_FUNC (here PyInit_my_wrapper_c) calls the PyModule_Create function to create the module. The name of this function should be as follows: PyInit_<name of the module as defined in setup.py>.
	Here the Wrapper uses object Solve and 2 of its methods
