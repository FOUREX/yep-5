#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define EMPTY (-1)


void clear() {
	printf("\n");
	system("cls");
}


void pause() {
	printf("\n");
	system("pause");
}


void fillArray(int array[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++)
		array[i] = rand() % 21;
}


void displayArray(int array[], int arrayLength, char title[]) {
	printf("%s: [ ", title);

	for (int i = 0; i < arrayLength; i++) {
		if (array[i] == EMPTY)
			break;

		printf("%d ", array[i]);
	}

	printf("]\n");
}


int getArrayLength() {
	int arrayLength;

	printf("Enter array length: ");
	scanf("%d", &arrayLength);

	return arrayLength;
}


int checkValueInArray(int value, const int array[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		int element = array[i];

		if (value == element)
			return 1;
	}

	return 0;
}


void yep_1() {
	printf("FUNCTION: The number of different elements in the array\n\n");

	int arrayLength = getArrayLength();
	int countOfDifferentElements = 0;

	int array[arrayLength];
	int differentElements[arrayLength];

	memset(differentElements, EMPTY, arrayLength * sizeof(differentElements[0]));

	fillArray(array, arrayLength);
	displayArray(array, arrayLength, "\nArray");

	for (int i = 0; i < arrayLength; i++) {
		int element = array[i];

		if (!checkValueInArray(element, differentElements, arrayLength)) {
			differentElements[countOfDifferentElements] = element;
			countOfDifferentElements++;
		}
	}

	displayArray(differentElements, arrayLength, "differentElements");
	printf("Count of different elements: %d\n", countOfDifferentElements);
}


void yep_2() {
	printf("FUNCTION: An array with the maximum elements of two arrays\n\n");

	int arrayLength = getArrayLength();
	int A[arrayLength], B[arrayLength], C[arrayLength];

	fillArray(A, arrayLength);
	fillArray(B, arrayLength);

	displayArray(A, arrayLength, "A");
	displayArray(B, arrayLength, "B");

	for (int i = 0; i < arrayLength; i++) {
		int toInsert;

		if (A[i] > B[i])
			toInsert = A[i];
		else
			toInsert = B[i];

		C[i] = toInsert;
	}

	displayArray(C, arrayLength, "C");
}


void yep_3() {
	printf("FUNCTION: The maximum sum of two adjacent array elements\n\n");

	int arrayLength = getArrayLength();
	int array[arrayLength];

	int offset;
	int maxSum = 0;

	fillArray(array, arrayLength);
	displayArray(array, arrayLength, "Array");

	for (int i = 0; i < arrayLength - 1; i++) {
		int sum = array[i] + array[i + 1];

		if (sum > maxSum) {
			maxSum = sum;
			offset = i;
		}
	}

	printf("Max sum: %d + %d = %d", array[offset], array[offset + 1], maxSum);
}


int main() {
	srand(time(NULL));

	int running = 1;
	int user_input;

	while (running) {
		clear();

		printf("FUNCTIONS:\n");
		printf("1. The number of different elements in the array\n");
		printf("2. An array with the maximum elements of two arrays\n");
		printf("3. The maximum sum of two adjacent array elements\n");
		printf("4. Quit\n");
		printf("\nSelect function: ");

		scanf("%d", &user_input);
		clear();

		switch (user_input) {
			case 1:
				yep_1();
				break;
			case 2:
				yep_2();
				break;
			case 3:
				yep_3();
				break;
			case 4:
				running = 0;
				break;
			default:
				printf("Bruh... %d, rly?", user_input);
		}

		pause();
	}

	return 0;
}
