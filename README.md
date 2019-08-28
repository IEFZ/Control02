# openCV
Empezando con OPENCV


Ir a terminal linux y ejecutar los siguientes comandos

sudo apt install libopencv-dev python-opencv
mkdir Prueba
cd Prueba

crear un archivo llamado CMakeLits.txt y agregar lo siguiente

cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

volver a la terminar y ejecutar 
#cmake .
#make

por ultimo ejecutar el programa .cpp de la siguiente forma, donde image.jpeg puede ser cualquier imagen

#./DisplayImage image.jpeg 
