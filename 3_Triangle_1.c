#include <stdio.h>
#include <math.h>
#include <string.h>

void calculateRightAngledTriangleArea(double base, double height);
void calculateRightAngledTrianglePerimeter(double base, double height);
void calculateRightAngledTriangleVolume(double base, double height, double length);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <shape> <triangle type> <base> <height>\n", argv[0]);
        printf("Shape: triangle\n");
        printf("Triangle type: right-angled\n");
        return 1;
    }

    char *shape = argv[1];
    char *triangleType = argv[2];

    if (strcmp(shape, "triangle") == 0 && strcmp(triangleType, "right-angled") == 0) {
        double base, height;
        if (sscanf(argv[3], "%lf", &base) != 1 || sscanf(argv[4], "%lf", &height) != 1) {
            printf("Invalid input for base or height.\n");
            return 1;
        }

        calculateRightAngledTriangleArea(base, height);
        calculateRightAngledTrianglePerimeter(base, height);

        double length;
        printf("Enter the length of the prism: ");
        if (scanf("%lf", &length) != 1) {
            printf("Invalid input for length.\n");
            return 1;
        }
        calculateRightAngledTriangleVolume(base, height, length);
    } else {
        printf("Invalid shape or triangle type.\n");
        return 1;
    }

    return 0;
}

void calculateRightAngledTriangleArea(double base, double height) {
    printf("Area of right-angled triangle: %.2f\n", 0.5 * base * height);
}

void calculateRightAngledTrianglePerimeter(double base, double height) {
    double hypotenuse = sqrt(base * base + height * height);
    printf("Perimeter of right-angled triangle: %.2f\n", base + height + hypotenuse);
}

void calculateRightAngledTriangleVolume(double base, double height, double length) {
    double area = 0.5 * base * height;
    printf("Volume of triangular prism: %.2f\n", area * length);
}
