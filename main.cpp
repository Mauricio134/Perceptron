#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string training_image_fn = "train-images.idx3-ubyte";
const string training_label_fn = "train-labels.idx1-ubyte";

const int nTraining = 60000;

const int height = 28;
const int width = 28;

const int neuronas = height*width;

ifstream image;
ifstream label;

vector<vector<double>> numeros(height+1, vector<double>(width+1));
vector<vector<double>> labels(nTraining, vector<double>(neuronas + 1, 0.0));

int main(){
    image.open(training_image_fn.c_str(), ios::in | ios::binary);
    label.open(training_label_fn.c_str(), ios::in | ios::binary );

    char number;
    for (int i = 1; i <= 16; ++i) {
        image.read(&number, sizeof(char));
	}
    for (int i = 1; i <= 8; ++i) {
        label.read(&number, sizeof(char));
	}

    for(int k = 0; k < nTraining; k++){
        char n;
        for (int j = 1; j <= height; ++j) {
            for (int i = 1; i <= width; ++i) {
                image.read(&n, sizeof(char));
                if (n == 0) {
                    numeros[i][j] = 0.0; 
                } else {
                    numeros[i][j] = 1.0;
                }
            }
        }

        label.read(&n, sizeof(char));
        labels[k][n + 1] = 1.0;
    }
}
