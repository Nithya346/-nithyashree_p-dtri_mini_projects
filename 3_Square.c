#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void calculateSquareArea(double side);
void calculateSquarePerimeter(double side);
void calculateSquareVolume(double side);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <shape> <parameter>\n", argv[0]);
        printf("Shape: square\n");
        printf("Parameters for square: side, diagonal, perimeter\n");
        return 1;
    }

    char *shape = argv[1];
    char *parameter = argv[2];

    if(strcmp(shape, "square") == 0) {
        double side, diagonal, perimeter;

        if(strcmp(parameter, "side") == 0) {
            printf("Enter side length: ");
            scanf("%lf", &side);
            diagonal = side * sqrt(2);
            perimeter = 4 * side;
        }
        else if(strcmp(parameter, "diagonal") == 0) {
            printf("Enter diagonal length: ");
            scanf("%lf", &diagonal);
            side = diagonal / sqrt(2);
            perimeter = 4 * side;
        }
        else if(strcmp(parameter, "perimeter") == 0) {
            printf("Enter perimeter: ");
            scanf("%lf", &perimeter);
            side = perimeter / 4;
            diagonal = side * sqrt(2);
        }
        else {
            printf("Invalid parameter for square.\n");
            return 1;
        }

        calculateSquareArea(side);
        calculateSquarePerimeter(side);
        calculateSquareVolume(side);
    }
    else {
        printf("Invalid shape.\n");
        return 1;
    }

    return 0;
}

void calculateSquareArea(double side) {
    printf("Area of square: %.2f\n", side * side);
}

void calculateSquarePerimeter(double side) {
    printf("Perimeter of square: %.2f\n", 4 * side);
}

void calculateSquareVolume(double side) {
    printf("Volume of cube: %.2f\n", pow(side, 3));
}
