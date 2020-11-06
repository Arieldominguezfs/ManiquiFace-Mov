import Calculador
import math
from threading import Thread
from threading import Event
import Configuracion

alto = float(Configuracion.leer("ObtenedorDeImagenes","alto"))
ancho = float(Configuracion.leer("ObtenedorDeImagenes","ancho"))

puntoCentro = (ancho/2,alto/2) 

def reorientar(xpos,ypos,diametroCara, cabeza):
    if xpos*ypos*diametroCara > 0:
        distancia = Calculador.calcularDistancia(diametroCara/2)

        c = Calculador.calcularPuntoCalibracion(cabeza, distancia, puntoCentro)
        cabeza.puntoCalibracion['x'] = c[0] 
        cabeza.puntoCalibracion['y'] = c[1]
        anguloHorizontal = Calculador.CalcularOrientacion(math.fabs(xpos-cabeza.getCalibracion()['x']),distancia)
        anguloVertical = Calculador.CalcularOrientacion(math.fabs(ypos-cabeza.getCalibracion()['y']),distancia)
    
        gx = cabeza.girar(anguloHorizontal,xpos, 'x')
        gy = cabeza.girar(anguloVertical,ypos, 'y')
        return gx,gy
    return 0,0
        


       