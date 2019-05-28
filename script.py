import NumSymReg as nsr

print("Hello World")
monX=[[3,2,5],[4,8,6]]
monY= [2,5]
gene=10
lamba=100
S1=nsr.create_solver(gene,monX,monY,lamba)
print("fonction : ")
nsr.print_fonct(S1)
nsr.evolve(S1)
nsr.print_fonct(S1)
print(nsr.get_fitness(S1))
test= [2,6,8]
print(nsr.calcul(S1,test))
histfit=[0 for i in range(gene)]
print(nsr.get_historic(S1,histfit))


