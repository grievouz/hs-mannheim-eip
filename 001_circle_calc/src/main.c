#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PIF
#define M_PIF 3.14159265358979323846
#endif

int main(void) {
	puts("Circle Calculator");

	printf("Radius(cm): ");
	float radius = -1;
	scanf("%f", &radius);
	if (radius == -1) {
		printf("Error: Invalid Number\n");
		return EXIT_FAILURE;
	}

	float circumference = 2.0 * M_PIF * radius;
	float surface_area = M_PIF * powf(radius, 2.0);

	printf("Circumference(cm): %f\n", circumference);
	printf("Surface Area(cm): %f\n", surface_area);

	return EXIT_SUCCESS;
}
