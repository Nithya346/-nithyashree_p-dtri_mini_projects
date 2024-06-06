#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265359

void calculateCircleArea(double radius);
void calculateCirclePerimeter(double radius);
void calculateCircleVolume(double radius);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <shape> <parameter>\n", argv[0]);
        printf("Shape: circle\n");
        printf("Parameter for circle: radius, diameter, circumference\n");
        return 1;
    }

    char *shape = argv[1];
    char *parameter = argv[2];

    if(strcmp(shape, "circle") == 0) {
        double radius, diameter, circumference;

        if(strcmp(parameter, "radius") == 0) {
            printf("Enter radius: ");
            scanf("%lf", &radius);
            diameter = 2 * radius;
            circumference = 2 * PI * radius;
        }
        else if(strcmp(parameter, "diameter") == 0) {
            printf("Enter diameter: ");
            scanf("%lf", &diameter);
            radius = diameter / 2;
            circumference = PI * diameter;
        }
        else if(strcmp(parameter, "circumference") == 0) {
            printf("Enter circumference: ");
            scanf("%lf", &circumference);
            radius = circumference / (2 * PI);
            diameter = 2 * radius;
        }
        else {
            printf("Invalid parameter for circle.\n");
            return 1;
        }

        calculateCircleArea(radius);
        calculateCirclePerimeter(radius);
        calculateCircleVolume(radius);
    }
    else {
        printf("Invalid shape.\n");
        return 1;
    }

    return 0;
}

void calculateCircleArea(double radius) {
    printf("Area of circle: %.2f\n", PI * radius * radius);
}

void calculateCirclePerimeter(double radius) {
    printf("Perimeter of circle: %.2f\n", 2 * PI * radius);
}

void calculateCircleVolume(double radius) {
    printf("Volume of circle: %.2f\n", (4.0 / 3.0) * PI * pow(radius, 3));
}
