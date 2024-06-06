#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void calculateNonRightAngledTriangleArea(double a, double b, double c);
void calculateNonRightAngledTrianglePerimeter(double a, double b, double c);
void calculateNonRightAngledTriangleVolume(double a, double b, double c, double length);

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <shape> <triangle type> <side1> <side2> <side3>\n", argv[0]);
        printf("Shape: triangle\n");
        printf("Triangle type: non-right-angled\n");
        return 1;
    }

    char *shape = argv[1];
    char *triangleType = argv[2];

    if (strcmp(shape, "triangle") == 0 && strcmp(triangleType, "non-right-angled") == 0) {
        double a, b, c;
        printf("Enter side lengths: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        calculateNonRightAngledTriangleArea(a, b, c);
        calculateNonRightAngledTrianglePerimeter(a, b, c);

        double length;
        printf("Enter the length of the prism: ");
        scanf("%lf", &length);
        calculateNonRightAngledTriangleVolume(a, b, c, length);
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    return 0;
}

void calculateNonRightAngledTriangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("Area of non-right-angled triangle: %.2f\n", area);
}

void calculateNonRightAngledTrianglePerimeter(double a, double b, double c) {
    printf("Perimeter of non-right-angled triangle: %.2f\n", a + b + c);
}

void calculateNonRightAngledTriangleVolume(double a, double b, double c, double length) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("Volume of triangular prism: %.2f\n", area * length);
}
