#define _CRT_SECURE_NO_WARNINGS
#define N 3

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

/* Declarations of other sub-functions */

int multiplication(int, int);

void primeNumbers(int, int);
int prime(int);

int rotateNumber(int, int);
int numberLength(int);

int inputIntNonNegative();

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
			}
		} while (all_Ex_in_loop && select);
	return 0;
}


/* Function definitions */

void Ex1() {
	int num1 = 0, num2 = 0, answer = 0;
	printf("\nplease enter two multipliers: ");
	scanf("%d%d", &num1, &num2);
	answer = multiplication(num1, num2);
	printf("%d * %d = %d\n", num1, num2, answer);
}

void Ex2() {
	int num1 = 0, num2 = 0;
	printf("\nplease enter the lower bound: ");
	num1 = inputIntNonNegative();
	printf("please enter the upper bound: ");
	num2 = inputIntNonNegative();
	primeNumbers(num1, num2);
}

void Ex3() {
	int number = 0, spins = 0, answer = 0;
	printf("\nplease enter the number: ");
	number = inputIntNonNegative();
	printf("please enter the amount of spins: ");
	spins = inputIntNonNegative();
	answer = rotateNumber(number, spins);
	printf("The number %d after %d spins is: %d\n", number, spins, answer);
}

/* Sub-Function definitions */

int multiplication(int num1, int num2) {
	/*Write Code Here!*/
}

void primeNumbers(int num1, int num2) {
	for (int i = num1; i <= num2; i++) {
		if (prime(i)) {
			printf("%d ", i);
		}
	}
}

int prime(int num) {

	if (num < 2) {
		return 0;
	}

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}

int rotateNumber(int num, int spins) {
	int num_of_digits = numberLength(num);
	int first_digit, power_multiplier;

	// If number has 1 digit or is 0, rotation doesn't change it
	if (num_of_digits <= 1) {
		return num;
	}

	// If a number has 4 digits, 5000 spins is the same as 0 spins
	spins = spins % num_of_digits;

	for (int i=0; i < spins; i++) {
		power_multiplier = 1;

		// Calculate 10^(length-1) to isolate the leftmost digit
		for (int k = 1; k < num_of_digits; k++) {
			power_multiplier *= 10;
		}

		// Extract the leftmost digit (e.g., 1234 / 1000 = 1)
		first_digit = num / power_multiplier;

		// Move the remaining digits left and append the original first digit to the end
		num = (num % power_multiplier) * 10 + first_digit;
	}

	return num;
}

int numberLength(int num) {
	int digit_counter = 0;

	// Handle the case where the number is 0
	if (num == 0) {
		return 1;
	}

	// Count digits by dividing by 10 until the value is 0
	while (num > 0) {
		num /= 10;
		digit_counter++;
	}

	return digit_counter;
}

int inputIntNonNegative() {
	int val;
	do {
		scanf("%d", &val);
	} while (val < 0);
	return val;
}
