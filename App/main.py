'''
Created on 13 ene. 2018

@author: Javi-PC
'''
import Deteccion.Camara as camara
from cv2 import *
import sys
from Deteccion.DetectorObjetos import Detector
from Orientacion import Calculador
from Orientacion.Cabeza import Cabeza
import Orientacion.Orientador as Orientador
from Orientacion.ValidadorDesplazamiento import ValidadorDesplazamiento 

from multiprocessing import Process, Array, Value, Event 
import multiprocessing 


def procesoDeteccion():
    path ="cascade.xml"
    detector = Detector(path)

    
    #objetos compratidos entre procesos
    puntoDeteccion = Array('i', 2)
    puntoDeteccion[0] = 2
    diametro = Value('i') 
    
    
    procOrientacion = Process(target=procesoOrientacion , args = (puntoDeteccion,diametro))
    procOrientacion.start()

    
    while True:
        foto = camara.tomarFoto()
        seEncontro, x,y,w,h = detector.detectar(foto)
        puntoDeteccion[0] = x+w/2
        puntoDeteccion[1] = y+h/2
        diametro.value = h
        imshow("camara", foto)
        if waitKey(1) & 0xFF == ord('q'):
            sys.exit()
            
def procesoOrientacion(puntoDeteccion, diametroDeteccion):
    cabeza =  None
    validadorDesp = ValidadorDesplazamiento()

    while True: 
        px = puntoDeteccion[0]
        py = puntoDeteccion[1] 
        diametro = diametroDeteccion.value
        if cabeza == None:
            if px*py*diametro > 0:
                print("entro")
                posicion = Calculador.calcularPosicionCabeza(puntoDeteccion, diametro)
                cabeza = Cabeza((px,py),posicion,1)
        else:
            if validadorDesp.validarDesplazamiento((px,py)):
                gx, gy = Orientador.reorientar(px, py, diametro, cabeza)
                

    

def procesoCominucacion(puntoDeteccion):
    while True:
        x = puntoDeteccion[0]
        y = puntoDeteccion[1]
        
    

    
   
        
        
    
    
    
if __name__ == '__main__':
    multiprocessing.freeze_support()
    procesoDeteccion()