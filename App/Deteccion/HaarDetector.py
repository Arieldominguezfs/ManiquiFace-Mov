'''
Created on 19 ene. 2018

@author: Javi-PC
'''

import cv2

class HaarDetector(object):
    '''
    Esta clase se encarga de detectar un objeto dentro de una imagen de acuerdo a el haar feature pasado en el constructor
    '''


    def __init__(self, hPath):
        self.clasificador = cv2.CascadeClassifier(hPath)
        

    def detectarTodos(self, imagen):
        gris = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY) #aplicamos filtro para poner la imagen en blanco y negro
        cv2.equalizeHist(gris, gris)
        rostrosFrontal = self.clasificador.detectMultiScale( gris, scaleFactor = 1.2, minNeighbors = 5, minSize= (30,30), flags = cv2.CASCADE_SCALE_IMAGE)
        return rostrosFrontal;
        
    def detectar(self,imagen):
        seIndentifico = False
        rostrosFrontal = self.detectarTodos(imagen)
        if len(rostrosFrontal) == 1:
            seIndentifico = True
            for (x,y,w,h) in rostrosFrontal:
                return seIndentifico, x,y,w,h
            
        return False,0,0,0,0
        