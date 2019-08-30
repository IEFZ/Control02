# openCV
Empezando con OPENCV


Ir a terminal linux y ejecutar los siguientes comandos

# sudo apt install cmake
# sudo apt install libopencv-dev python-opencv
# mkdir Ejemplo
# cd Ejemplo

crear en el directorio, un archivo llamado CMakeLits.txt y agregar lo siguiente

# cmake_minimum_required(VERSION 2.8)
# project( Ejemplo )
# find_package( OpenCV REQUIRED )
# add_executable( Ejemplo Ejemplo.cpp )
# target_link_libraries( Ejemplo ${OpenCV_LIBS} )
volver a la terminal y ejecutar (dentro de carpeta)
# cmake .
# make

por ultimo ejecutar el programa .cpp de la siguiente forma, donde image.jpeg puede ser cualquier imagen

# ./Ejemplo image.jpeg 
