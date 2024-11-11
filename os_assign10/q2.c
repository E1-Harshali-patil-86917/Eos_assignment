#include<stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main(){
    double radius = 5.0;
    double side = 4.0;
    double length = 6.0;
    double width = 3.0;

    printf("Area of circle with radius %d.2f: %.2f\n",radius,circle_area(radius));
    printf("Area of square with side %.2f: %.2f\n",side,square_area(side));
    printf("Area of rectangle with lenght %.2f and width %.2f: %.2f\n",length,width,rectangle_area(length,width));
    return 0;
}