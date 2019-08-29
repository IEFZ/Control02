#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

bool validar_argumentos(string arg_resolucion, string arg_entrada, string arg_salida){
    if (arg_resolucion.compare("")==0){
        cout << "ATENCION:Falta argumento -e y/o la resolucion " << endl; //No se especifico un cambio de resolucion
        return false;
    }
    if (arg_entrada.compare("")==0){
        cout << "ATENCION:Falta argumento -f y/o la ruta del arhivo entrada " << endl; //No se especifico una ruta de entrada de la imagen
        return false;
    }
    if (arg_salida.compare("")==0){
        cout << "ATENCION:Falta argumento -o y/o la ruta del arhivo salida " << endl; //No se especifico una ruta de salida de la imagen
        return false;
    }
    return true;
}

void crear_nueva_imagen(string arg_resolucion,string arg_salida, cv::Mat image){
    cv::Mat imagen_resize;
    bool resolucion_correcta = true;
    if (arg_resolucion.compare("FHD") == 0 || arg_resolucion.compare("fhd") == 0){ //Aumenta la resolucion de la imagen a Full HD
        cv::resize(image,imagen_resize,cv::Size(1920,1080));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (arg_resolucion.compare("2K") == 0 || arg_resolucion.compare("2k") == 0){ // Aumenta la resolucion de la imagen a 2K 
        cv::resize(image,imagen_resize,cv::Size(2048,1080));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (arg_resolucion.compare("4K") == 0 || arg_resolucion.compare("4k") == 0){ // Aumenta la resolicion de la imagen a 4K
        cv::resize(image,imagen_resize,cv::Size(4096,2160));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (arg_resolucion.compare("8K") == 0 || arg_resolucion.compare("8k") == 0){ // Aumenta la resolucion de la imagen a 8K
        cv::resize(image,imagen_resize,cv::Size(7680,4320));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (resolucion_correcta){
        cout << "ATENCION: Especifique correctamente la resolucion (FHD, 2K, 4K, 8K)" << endl;
    }
}

int leer_imagen(string arg_entrada,string arg_resolucion,string arg_salida){
    cv::Mat image = cv::imread(arg_entrada, CV_LOAD_IMAGE_COLOR);
    if(!image.data) {
        std::cout << "Error: no se cargo la imagen." << std::endl; //Imagen dañada o no se especifico bien la ruta de entrada o de salida
        return -1;
    }
    crear_nueva_imagen(arg_resolucion,arg_salida,image); //Crea la imagen con la resolucion nueva
}

void asociar_argumentos_imagen(int argc, char const *argv[]){
    string arg_resolucion; //Variable que guarda la resolucion de la imagen de entrada
    string arg_entrada; //Variable que guarda la ruta de entrada de la imagen
    string arg_salida; //Variable que guarda la ruta de salida de la imagen generada
    string dato;
    for (int i=1; i<argc; i=i+2){ //Comparacion tamaño de redimension
        dato=argv[i];
        if (dato.compare("-e") == 0){
            if (!(i==(argc-1))){
                arg_resolucion=argv[i+1]; //Guardado de la resolucion
            }
        }
        if (dato.compare("-f") == 0){ //Comparacion ruta de entrada
            if (!(i==(argc-1))){
                arg_entrada=argv[i+1]; //Guardado de la ruta entrada
            }
        }
        if (dato.compare("-o") == 0){ //Comparacion ruta de salida
            if (!(i==(argc-1))){
                arg_salida=argv[i+1]; //Guardado de la ruta de salida
            }
        }
    }
    if (validar_argumentos(arg_resolucion,arg_entrada,arg_salida)){ 
        leer_imagen(arg_entrada,arg_resolucion,arg_salida); //Validacion de datos ingresados
    }
}

int main(int argc, char const *argv[]) {
    asociar_argumentos_imagen(argc,argv);
    cv::waitKey();
    return 0;
}