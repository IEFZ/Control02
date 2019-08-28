#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;



int main(int argc, char const *argv[]) {
    string arg_resolucion=argv[1];
    string arg_entrada=argv[3];
    string arg_salida=argv[5];
    if (arg_resolucion.compare("-e") == 0){
        arg_resolucion=argv[2];
    }
    if (arg_entrada.compare("-f") == 0){
        arg_entrada=argv[4];
    }
     if (arg_salida.compare("-o") == 0){
        arg_salida=argv[6];
    }
    cv::Mat image = cv::imread(arg_entrada, CV_LOAD_IMAGE_COLOR);
	cv::Mat dst;
    if(!image.data) {
        std::cout << "Error: no se cargo la imagen." << std::endl;
        return -1;
    }


    // Iteramos sobre todos los píxeles de la imagen
    /*for(int r = 0; r < image.rows; r++) {
        // Obtenemos un puntero al comienzo de la fila r
        cv::Vec3b* ptr = image.ptr<cv::Vec3b>(r);
		

        for(int c = 0; c < image.cols; c++) {
            // Invertimos los valores azul y rojo del píxel
            ptr[c] = cv::Vec3b(ptr[c][2], ptr[c][1], ptr[c][0]);
        }
    }*/

    cv::Mat imagen_resize;
    if (arg_resolucion.compare("FHD") == 0){
        cv::resize(image,imagen_resize,cv::Size(1920,1080));
        cv::imwrite(arg_salida,imagen_resize);
    }
    if (arg_resolucion.compare("2K") == 0){
        cv::resize(image,imagen_resize,cv::Size(2048,1080));
        cv::imwrite(arg_salida,imagen_resize);
    }
    if (arg_resolucion.compare("4K") == 0){
        cv::resize(image,imagen_resize,cv::Size(4096,2160));
        cv::imwrite(arg_salida,imagen_resize);
    }
    if (arg_resolucion.compare("8K") == 0){
        cv::resize(image,imagen_resize,cv::Size(7680,4320));
        cv::imwrite(arg_salida,imagen_resize);
    }
    
    cv::waitKey();
	
    return 0;
}