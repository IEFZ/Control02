#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
    cv::Mat image = cv::imread("imagen.png", CV_LOAD_IMAGE_COLOR);
	cv::Mat dst;
    if(!image.data) {
        std::cout << "Error: no se cargo la imagen." << std::endl;
        return -1;
    }

    // Iteramos sobre todos los píxeles de la imagen
    for(int r = 0; r < image.rows; r++) {
        // Obtenemos un puntero al comienzo de la fila r
        cv::Vec3b* ptr = image.ptr<cv::Vec3b>(r);
		

        for(int c = 0; c < image.cols; c++) {
            // Invertimos los valores azul y rojo del píxel
            ptr[c] = cv::Vec3b(ptr[c][2], ptr[c][1], ptr[c][0]);
        }
    }



    cv::imshow("I", image);
    cv::waitKey();
	
    return 0;
}