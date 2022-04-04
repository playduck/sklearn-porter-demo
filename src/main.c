#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int predict(double features[4]) {

    int classes[3];

    if (features[3] <= 0.800000011920929) {
        classes[0] = 11;
        classes[1] = 0;
        classes[2] = 0;
    } else {
        if (features[2] <= 4.8500001430511475) {
            if (features[3] <= 1.6500000357627869) {
                classes[0] = 0;
                classes[1] = 12;
                classes[2] = 0;
            } else {
                if (features[1] <= 3.0) {
                    classes[0] = 0;
                    classes[1] = 0;
                    classes[2] = 2;
                } else {
                    classes[0] = 0;
                    classes[1] = 1;
                    classes[2] = 0;
                }
            }
        } else {
            classes[0] = 0;
            classes[1] = 0;
            classes[2] = 11;
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
    printf("%d\n", predict(features));
    return 0;

}
