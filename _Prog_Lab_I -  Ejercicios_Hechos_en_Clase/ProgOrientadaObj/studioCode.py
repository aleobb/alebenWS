class Persona:

    def __init__(self):
        self.nombre = ""
        self.edad = 0

    def setEdad(self, edad):
        self.edad = edad

    def setNombre(self, nombre):
        self.nombre = nombre

    def printPersona(self):
        print("Nombre: "+self.nombre+" - Edad: "+str(self.edad)+"\n")  ## Para concatenar todo tiene que ser string (hay que castear los int)

    def esMayorQue(self,p2):
        if self.edad > p2.edad:
            return True
        return False
    
# aca se termina class (es cuando se escribe a la altura de ese tab)


# Inicio del programa:

p1 = Persona()
p1.setNombre("Juancito")
p1.setEdad(99)
p1.printPersona()

p2 = Persona()
p2.setNombre("Pepito")
p2.setEdad(77)
p2.printPersona()

print(" Es o no mayor? ")
print( p1.esMayorQue(p2) )


# for i=0, i<len(lista), i+=1:
#     pAux = lista[i]
#     pAux.printPersona()

# esto lo hace la siguiente linea:

#for item in lista:  #item podría llamarse pAux, o como quiera
#    item.printPersona()

# lista2 = [0,1,2,3,4]
# for i in lista2:
# for pAux in range(0,len(lista)): # for i in range(0,1000,2) el 2 es el step: va de 2 en 2
for pAux in lista: 
    pAux.printPersona()

lista2 = [0,1,2,3,4]
for i in range(0,len(lista2)): # for i in range(0,1000,2) el 2 es el step: va de 2 en 2
    print(i)
