import BinSymReg as bsr

print("Hello World")
monX=[[3,2,5],[,4,8,6]]
monY= [,2,5]
gene=100
lamba=5
S1=bsr.create_solver(gene,monX,monY,lamba)
bsr.print_fonct(S1)
bsr.evolve(S1)
bsr.print_fonct(S1)
print(bsr.get_fitness(S1))
test= [2,6]
print(bsr.calcul(S1,test))
histfit=[0 for i in range(gene)]
print(bsr.get_historic(S1,histfit))


