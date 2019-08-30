Instalación de OpenCV
=====================


Ir a terminal linux y ejecutar los siguientes comandos:


$ sudo apt install cmake

$ sudo apt install libopencv-dev python-opencv


Git clone
====================


En la terminal clonar el repositorio:


$ git clone https://github.com/IEFZ/openCV.git Nuevo_Directorio

$ cd Nuevo_Directorio


Ejecutar dentro de carpeta:


$ cmake .

$ make


Ejercucion del programa
====================


Por ultimo ejecutar el programa .cpp de la siguiente forma, donde image.png puede ser cualquier imagen:


$ ./Control02 -e 2K -f /ruta/imagen_entrada.png -o /ruta/imagen_salida.png


Donde ruta es la ubicacion de la imagen.
