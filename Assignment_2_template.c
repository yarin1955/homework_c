#define _CRT_SECURE_NO_WARNINGS
#define N 4

/*Libraries*/
#include <stdio.h>

/*
	Assigned by:
		Student1_Full_Name #ID
		Student2_Full_Name #ID
*/

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();

/* Declarations of other sub-functions */

int equalArrays(int[], int[], int, int);
int equalArraysSameSize(int[], int[], int);

void SelectionSort(int[], int);
void swap(int*, int*);
void maxItem(int[], int, int*);

int sortRemoveDup(int[], int);

void printArr(int[], int);

char findFirstVowel(char*);

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : ", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			}
		} while (all_Ex_in_loop && select);
	return 0;
}


/* Function definitions */

void Ex1() {
	int A[] = { 1,2,5,3 }, B[] = { 1,2,3,5 }, // Initialize the arrays
		sizeA = sizeof(A) / sizeof(int), sizeB = sizeof(B) / sizeof(int);
	printf("\n%s\n\n", equalArrays(A, B, sizeA, sizeB) ? "Arrays are equal" : "Arrays are not equal");
}

void Ex2() {
	int ar[] = { 56, 32, 5, 90, 40, 42, 19 }, // Initialize the array
		size = sizeof(ar) / sizeof(int);
	SelectionSort(ar, size);
	printf("\nSorted array:\n");
	printArr(ar, size);
	printf("\n");
}

void Ex3() {
	int ar[] = { 56, 32, 56, 90, 56, 32, 19, 56, 31, 32 }, // Initialize the array
		size = sizeof(ar) / sizeof(int), new_size = 0;
	SelectionSort(ar, size); // Sort the source array
	printf("\nArray with duplications:\n");
	printArr(ar, size);
	new_size = sortRemoveDup(ar, size);
	printf("\nArray without duplications:\n");
	printArr(ar, new_size);
	printf("\n");
}

void Ex4() {
	char str[] = "Her name is Ann", // Initialize the string
		firstVowel;
	firstVowel = findFirstVowel(str);
	if (firstVowel)
		printf("\nThe first vowel is %c\n", firstVowel);
	else
		printf("\nNo vowels in the string\n");
}

/* Sub-Function definitions */

int equalArrays(int A[], int B[], int sizeA, int sizeB) {
	/*Write Code Here!*/
}

int equalArraysSameSize(int A[], int B[], int size) {
	/*Write Code Here!*/
}

void SelectionSort(int ar[], int n) {
	int i, maxIndex;
	// Iterate from the full size down to 2
	for (i = n; i > 1; i--) {
		// Find the index of the max item in the subarray 0 to i
		maxItem(ar, i, &maxIndex);
		// Swap the max item with the last item of the current subarray (i-1)
		swap(&ar[maxIndex], &ar[i - 1]);
	}
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void maxItem(int ar[], int size, int* p_max) {
	int i;
	*p_max = 0; // Assume first element is max
	for (i = 1; i < size; i++) {
		if (ar[i] > ar[*p_max]) {
			*p_max = i; // Update index if we find a larger value
		}
	}
}

int sortRemoveDup(int ar[], int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	int writeIdx = 0; // Index where we write the unique elements
	int readIdx;

	// Iterate through the array starting from the second element
	for (readIdx = 0; readIdx < n - 1; readIdx++) {
		// If current element is different from the next element
		if (ar[readIdx] != ar[readIdx + 1]) {
			ar[writeIdx++] = ar[readIdx];
		}
	}

	// The last element is always unique or the last of a series of duplicates
	ar[writeIdx++] = ar[n - 1];

	return writeIdx; // Return the new effective size
}

void printArr(int ar[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", ar[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("\n");
}

char findFirstVowel(char* str) {
	/*Write Code Here!*/
}

/* ------------------- */