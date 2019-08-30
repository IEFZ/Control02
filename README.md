Control 2 Computación paralela y distribuida
=====================

Descripción: Desarrollo de una aplicación en c++ que permite redimensionar una imagen png a un formato dado.

Instalación de paquetes para el funcionamiento (Ubuntu):
=====================

Ir a terminal linux y ejecutar los siguientes comandos:

1. Instalar compilador para c++

  $ sudo apt install g++

2. Instalar CMake

  $ sudo apt install cmake

3. Instalar libreria opencv

  $ sudo apt install libopencv-dev python-opencv

Clonar proyecto desde github (Ubuntu):
====================

Ir a terminal linux y ejecutar los siguientes comandos:

1. Clonar proyecto

  $ git clone https://github.com/IEFZ/Control02.git

  $ cd Control02

Ejecución del programa (Ubuntu):
====================

  $ cmake .

  $ make

  $ ./Control02 -e 2K -f /ruta/imagen_entrada.png -o /ruta/imagen_salida.png

Donde 2K es la resolucion a obtener (puede ser FHD, 2K, 4K, 8K) y ruta es la ubicacion de la imagen en la entrada y en la salida es donde se quiere obtener la imagen redimensionada.
