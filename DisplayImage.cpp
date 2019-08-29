#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

bool validar_argumentos(string arg_resolucion, string arg_entrada, string arg_salida){
    if (arg_resolucion.compare("")==0){
        cout << "ATENCION:Falta argumento -e y/o la resolucion " << endl;
        return false;
    }
    if (arg_entrada.compare("")==0){
        cout << "ATENCION:Falta argumento -f y/o la ruta del arhivo entrada " << endl;
        return false;
    }
    if (arg_salida.compare("")==0){
        cout << "ATENCION:Falta argumento -o y/o la ruta del arhivo salida " << endl;
        return false;
    }
    return true;
}

void crear_nueva_imagen(string arg_resolucion,string arg_salida, cv::Mat image){
    cv::Mat imagen_resize;
    bool resolucion_correcta = true;
    if (arg_resolucion.compare("FHD") == 0 || arg_resolucion.compare("fhd") == 0){
        cv::resize(image,imagen_resize,cv::Size(1920,1080));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (arg_resolucion.compare("2K") == 0 || arg_resolucion.compare("2k") == 0){
        cv::resize(image,imagen_resize,cv::Size(2048,1080));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (arg_resolucion.compare("4K") == 0 || arg_resolucion.compare("4k") == 0){
        cv::resize(image,imagen_resize,cv::Size(4096,2160));
        cv::imwrite(arg_salida,imagen_resize);
        resolucion_correcta = false;
    }
    if (arg_resolucion.compare("8K") == 0 || arg_resolucion.compare("8k") == 0){
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
        std::cout << "Error: no se cargo la imagen." << std::endl;
        return -1;
    }
    crear_nueva_imagen(arg_resolucion,arg_salida,image);
}

void asociar_argumentos_imagen(int argc, char const *argv[]){
    string arg_resolucion;
    string arg_entrada;
    string arg_salida;
    string dato;
    for (int i=1; i<argc; i=i+2){
        dato=argv[i];
        if (dato.compare("-e") == 0){
            if (!(i==(argc-1))){
                arg_resolucion=argv[i+1];
            }
        }
        if (dato.compare("-f") == 0){
            if (!(i==(argc-1))){
                arg_entrada=argv[i+1];
            }
        }
        if (dato.compare("-o") == 0){
            if (!(i==(argc-1))){
                arg_salida=argv[i+1];
            }
        }
    }
    if (validar_argumentos(arg_resolucion,arg_entrada,arg_salida)){
        leer_imagen(arg_entrada,arg_resolucion,arg_salida);
    }
}

int main(int argc, char const *argv[]) {
    asociar_argumentos_imagen(argc,argv);
    cv::waitKey();
    return 0;
}