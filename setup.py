import os
os.environ["CC"] = "c++"
from distutils.core import setup, Extension
#Binary Symbolic Regression
module = Extension('NumSymReg', ["Solve.cpp","MyWrapper.cpp","Sur.cpp","Fonction.cpp","Noeud.cpp","Moins.cpp","Plus.cpp","Valeur.cpp","Variable.cpp","Fois.cpp"],include_dirs=[],libraries=[])
#importer la librairie 
module.extra_compile_args = []#,'-pg']

setup(name='NumSymReg',
	  version='1.0',
	  author='Poquillon Dandou Mikec Bonnal',
	  author_email='aurore.bonnal-conduzorgues@insa-lyon.fr',
	  ext_modules=[module])
