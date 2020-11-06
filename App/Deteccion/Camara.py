'''
Created on 13 ene. 2018
Este modulo se encarga de tomarFoto las imagenes de la camara para cualquiera que las necesite
@author: Javi-PC
'''
import cv2
import Configuracion as Configuracion
from cv2 import imshow

#inicializacion de la camara
vc = cv2.VideoCapture(0)
alto = float(Configuracion.leer("ObtenedorDeImagenes","alto"))
ancho = float(Configuracion.leer("ObtenedorDeImagenes","ancho"))
#definimos el ancho y el alto de la imagen
vc.set(cv2.CAP_PROP_FRAME_WIDTH, ancho)
vc.set(cv2.CAP_PROP_FRAME_HEIGHT, alto)

def tomarFoto():
    _,imagen = vc.read()
    return cv2.flip(imagen, 1)#se debe voltear ya que si no sale espejada

def mostrar(imagen):
    imshow("TestCam", imagen)