#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayFloatToInt(int n, float* x, uint8_t* y);

void incrfloat(long long int n, float* x) {
	int i;
	for (i = 0; i < n; i++)
		x[i]++;
}

int main() {
	unsigned int row, col;
	scanf_s("%u", &row);
	scanf_s("%u", &col);
	
	int total = row * col;
	float* fpixels = (float*)malloc(total * sizeof(float));
	uint8_t* npixels = (uint8_t*)malloc(total * sizeof(uint8_t));

	for (int i = 0; i < total; i++) {
		scanf_s("%f", &fpixels[i]);
	}

	printf_s("\n");

	imgCvtGrayFloatToInt(total, fpixels, npixels);

	for (int i = 0; i < total; i++) {
		printf_s("%u ", npixels[i]);
		if ((i + 1) % col == 0) {
			printf_s("\n");
		}
	}

	printf_s("\n");

	clock_t start, end;
	double time_taken;

	int array[3] = {10, 100, 1000};

	for (int n = 0; n < 3; n++) {
		row = array[n];
		col = array[n];
		total = row * col;
		fpixels = (float*)realloc(fpixels, total * sizeof(float));
		npixels = (uint8_t*)realloc(npixels, total * sizeof(uint8_t));
		srand(42);
		for (int i = 0; i < total; i++) {
			int randomNumber = rand();
			randomNumber %= 256;
			randomNumber += 1;
			float num = randomNumber / 256.0;
			num = (int)(num * 100 + 0.5) / 100.0;
			fpixels[i] = num;
		}

		double average_time = 0.0;
		for (int i = 0; i < 30; i++) {
			start = clock();
			imgCvtGrayFloatToInt(total, fpixels, npixels);
			end = clock();
			time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
			average_time += time_taken;
		}
		average_time /= 30.0;
		printf("Time of %d * %d = %lf ms\n", array[n], array[n], average_time);
	}

	return 0;
}