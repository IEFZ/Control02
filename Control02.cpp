//Autores:Israel Flores, Cristóbal Morales, Nicolas Alarcon

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
    cv::Mat imagen_final;
    bool resolucion_correcta = true;
    if (arg_resolucion.compare("FHD") == 0 || arg_resolucion.compare("fhd") == 0){ //Aumenta la resolucion de la imagen a Full HD
		if(image.rows<image.cols){  	//verifica orientacion de imagen, vertical u horizontal
			cv::resize(image,imagen_resize,cv::Size(1920,1080),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 10,10.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
		else{
			cv::resize(image,imagen_resize,cv::Size(1080,1920),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final,10,10.0, 7, 21) ; /* Elimina el ruido de la imagen 
			h: parámetro que decide la fuerza del filtro. Un valor h más alto elimina el ruido mejor, pero también elimina detalles de la imagen. (10 está bien)
			hForColorComponents: igual que h, pero solo para imágenes en color. (normalmente igual que h)
			templateWindowSize: debe ser impar. (recomendado 7)
			searchWindowSize: debe ser impar. (recomendado 21) */
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
    }
    if (arg_resolucion.compare("2K") == 0 || arg_resolucion.compare("2k") == 0){ // Aumenta la resolucion de la imagen a 2K 
	    if(image.rows<image.cols){  	//verifica orientacion de imagen, vertical u horizontal
			cv::resize(image,imagen_resize,cv::Size(2048,1080),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 10,10.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
		else{
			cv::resize(image,imagen_resize,cv::Size(1080,2048),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 10, 10.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
    }
    if (arg_resolucion.compare("4K") == 0 || arg_resolucion.compare("4k") == 0){ // Aumenta la resolicion de la imagen a 4K
		if(image.rows<image.cols){
			cv::resize(image,imagen_resize,cv::Size(4096,2160),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 20, 20.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
		else{
			cv::resize(image,imagen_resize,cv::Size(2160,4096),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 20, 20.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
    }
    if (arg_resolucion.compare("8K") == 0 || arg_resolucion.compare("8k") == 0){ // Aumenta la resolucion de la imagen a 8K
		if(image.rows<image.cols){
			cv::resize(image,imagen_resize,cv::Size(7680,4320),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 20, 40.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
		else{
			cv::resize(image,imagen_resize,cv::Size(4320,7680),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 20, 40.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
    }
	if (arg_resolucion.compare("16K") == 0 || arg_resolucion.compare("16k") == 0){ // Aumenta la resolucion de la imagen a 16K
		if(image.rows<image.cols){
			cv::resize(image,imagen_resize,cv::Size(15360,8640),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 10, 10.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
		else{
			cv::resize(image,imagen_resize,cv::Size(8640,15360),0,0, INTER_LANCZOS4); // Cambiar resolucion de matriz usando algoritmo de LANCZOS
			cv::fastNlMeansDenoisingColored(imagen_resize,imagen_final, 10, 10.0, 7, 21) ; // Elimina el ruido de la imagen
			cv::imwrite(arg_salida,imagen_final);
			resolucion_correcta = false;
		}
    }
    if (resolucion_correcta){
        cout << "ATENCION: Especifique correctamente la resolucion (FHD, 2K, 4K, 8K, 16K)" << endl;
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