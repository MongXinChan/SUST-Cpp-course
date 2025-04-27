//main.c
#include <stdio.h>
#include "area.h"

int main()
{
    double r, area;

    printf("Please input a radius:");
    scanf("%lf", &r);

    area = compute_area(r);

    printf("The area of %lf is %.4lf\n", r, area);

    return 0;
}
