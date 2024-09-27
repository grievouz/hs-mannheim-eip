#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INVALID_INPUT -1
#define NUMBER_TOO_BIG -2

int try_scan_angle() {
	int angle;
	if(scanf("%d", &angle) != 1) {
		return INVALID_INPUT;
	}
	return angle;
}

int try_scan_time() {
	int time = -1;
	if(scanf("%d", &time) != 1) {
		return INVALID_INPUT;
	}
	if (time >= 60) {
		return NUMBER_TOO_BIG;
	}

	return time;
}

void error_message(int error_code, char *buffer, size_t buffer_size) {
	switch(error_code) {
		case INVALID_INPUT: {
			strncpy(buffer, "Input was not a valid number", buffer_size - 1);
			return;
		}
		case NUMBER_TOO_BIG: {
			strncpy(buffer, "Number was too big", buffer_size - 1);
			return;
		}
	}
}

int try_main() {
	printf("Addition of two angles\n");

	printf("How many degrees has the first angle? ");
	int angle1 = try_scan_angle();
	if(angle1 <= -1) {
		return angle1;
	}

	printf("How many minutes has the first angle? ");
	int angle1_time = try_scan_time();
	if(angle1_time <= -1) {
		return angle1_time;
	}

	printf("How many degrees has the second angle? ");
	int angle2 = try_scan_angle();
	if(angle2 <= -1) {
		return angle2;
	}

	printf("How many minutes has the second angle? ");
	int angle2_time = try_scan_time();
	if(angle2_time <= -1) {
		return angle2_time;
	}

	int angle = angle1 + angle2 + ceil((float)angle1_time / (float)angle2_time);
	int angle_time = angle1_time % angle2_time;

	printf("%d Degrees %d Minutes + %d Degrees %d Minutes = %d Degrees %d Minutes", angle1, angle1_time, angle2, angle2_time, angle, angle_time);

	return EXIT_SUCCESS;
}

int main(void) {
	int status = try_main();
	if(status <= -1) {
		char error[50];
		error_message(status, error, 50);
		printf("Error: %s", error);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
