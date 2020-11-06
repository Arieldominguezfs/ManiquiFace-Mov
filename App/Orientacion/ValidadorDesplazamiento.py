import math
import Configuracion

alto = float(Configuracion.leer("ObtenedorDeImagenes","alto"))
ancho = float(Configuracion.leer("ObtenedorDeImagenes","ancho"))
puntoCentro = (ancho/2,alto/2) 

class ValidadorDesplazamiento(object):


   
    def __init__(self):
        self.proporsion = 30
        self.ubiActual = puntoCentro
        #no tendria que haver un para la  y otro para la y?
        
    def validarDesplazamiento(self,posicion):
        if(math.fabs(posicion[0]-self.ubiActual[0]) >= self.proporsion 
           or math.fabs(posicion[1]-self.ubiActual[1]) >= self.proporsion):
            self.ubiActual = posicion
            return True
        else:
            return False
        
    
    def getX(self):
        return self.ubiActual[0]
    
    def getY(self):
        return self.ubiActual[1]
