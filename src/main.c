#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int predict(double features[4]) {

    int classes[3];
        
    if (features[2] <= 2.599999964237213) {
        classes[0] = 25; 
        classes[1] = 0; 
        classes[2] = 0; 
    } else {
        if (features[3] <= 1.6500000357627869) {
            if (features[2] <= 5.0) {
                classes[0] = 0; 
                classes[1] = 22; 
                classes[2] = 0; 
            } else {
                if (features[0] <= 6.049999952316284) {
                    classes[0] = 0; 
                    classes[1] = 1; 
                    classes[2] = 0; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 0; 
                    classes[2] = 3; 
                }
            }
        } else {
            if (features[2] <= 4.8500001430511475) {
                if (features[1] <= 3.100000023841858) {
                    classes[0] = 0; 
                    classes[1] = 0; 
                    classes[2] = 3; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 1; 
                    classes[2] = 0; 
                }
            } else {
                classes[0] = 0; 
                classes[1] = 0; 
                classes[2] = 20; 
            }
        }
    }

    int index = 0;
    for (int i = 0; i < 3; i++) {
        index = classes[i] > classes[index] ? i : index;
    }
    return index;
}

int main(int argc, const char * argv[]) {

    /* Features: */
    double features[argc-1];
    int i;
    for (i = 1; i < argc; i++) {
        features[i-1] = atof(argv[i]);
    }

    /* Prediction: */
    printf("%d", predict(features));
    return 0;

}