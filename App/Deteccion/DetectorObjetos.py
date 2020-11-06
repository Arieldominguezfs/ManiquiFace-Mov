'''
Created on 19 ene. 2018

@author: Javi-PC
'''
from Deteccion.HaarDetector import HaarDetector
from Deteccion.MeanshiftTracker import MeanshiftTracker

class Detector(object):
    '''
    Esta clase se encarga de encontrar y dar seguimiento determinado patron dado por el haar feature pasado en el constructor
    '''


    def __init__(self, hPath):
        self.haarDetector = HaarDetector(hPath)
        self.meanshiftTracker = None 
        
        
        
    def detectar(self,image):
        #primero se  el objeto en la foto con haar feature
        if(self.meanshiftTracker == None):
            seEncontro, x,y,w,h = self.haarDetector.detectar(image)
            if seEncontro:
                self.meanshiftTracker = MeanshiftTracker(image, (x,y,w,h))
                self.meanshiftTracker.identificarBlob()
                return seEncontro, x,y,w,h
        else:
            seEncontro,x,y,w,h = self.meanshiftTracker.rastrear(image)
            if(seEncontro):
                return seEncontro,x,y,w,h
        self.meanshiftTracker = None
        return False,0,0,0,0
            
            
            
        