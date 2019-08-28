Instalación de OpenCV
=====================

Ir a terminal linux y ejecutar los siguientes comandos:


$ sudo apt install cmake

$ sudo apt install libopencv-dev python-opencv


Instalacion del CMake
====================

En la terminal se debe crear una carpeta para luego ubicarnos en ella:

$ mkdir displayImage

$ cd displayImage


Volver a la terminal y ejecutar (dentro de carpeta):

$ cmake .

$ make


Ejercucion del programa
====================

Por ultimo ejecutar el programa .cpp de la siguiente forma, donde image.png puede ser cualquier imagen:

$ ./DisplayImage image.png
