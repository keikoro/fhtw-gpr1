/*	EAN Check Digit Computation */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int 12digits = 0;
	int checkdigit = 0;

	printf("Enter the first 12 digits of an EAN: ");
	scanf("%d", &12digits);

	printf("Check digit: %d\n", checkdigit);

	return 0;
}
