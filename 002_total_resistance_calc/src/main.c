#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum ResistancePareError {
	INVALID_INPUT = -1,
	NEGATIVE_NUMBER = -2,
};

float try_scan_resistance() {
	float resistance = NAN;
	scanf("%f", &resistance);
	if (isnan(resistance)) {
		return INVALID_INPUT;
	}
	if (resistance < 0) {
		return NEGATIVE_NUMBER;
	}
	return resistance;
}

void print_error(int error_code) {
	switch (error_code) {
		case INVALID_INPUT:{
			printf("Error: Input was not a number");
			return;
		}
		case NEGATIVE_NUMBER:{
			printf("Error: Negative numbers are not allowed");
			return;
		}
	}
}

int main(void) {
	printf("Total Resistance Calculator\n");

	printf("R1(Ohm): ");
	float r1 = try_scan_resistance();
	if(r1 <= -1) {
		print_error(r1);
		return EXIT_FAILURE;
	}

	printf("R2(Ohm): ");
	float r2 = try_scan_resistance();
	if(r2 <= -1) {
		print_error(r2);
		return EXIT_FAILURE;
	}

	float resistance_sum = (r1 * r2) / (r1 + r2);
	printf("Rsum(Ohm): %.4f", resistance_sum);

	return EXIT_SUCCESS;
}
