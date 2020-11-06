'''
Created on 13 ene. 2018
Esta clase permite leer y escribir en el archivo de configuracion de cada paquete
@author: Javi-PC
'''

import ConfigParser  
import sys

nombreArchivo = "config.cfg"
cfg = ConfigParser.ConfigParser()  

#actualizar archivo de configuracion
def update():
    f = open(nombreArchivo, "w")  
    cfg.write(f) 
    f.close()

def nuevaSeccion(nombre):
    cfg.add_section(nombre)
    update()

def nuevaOpcion(section, option, value):
    cfg.set(section, option, value)
    update()

def leer(seccion, nombre):
    cfg.read(nombreArchivo)
    return cfg.get(seccion, nombre)

  
    




if __name__ == '__main__':
    print(leer("login", "nombre"))   
