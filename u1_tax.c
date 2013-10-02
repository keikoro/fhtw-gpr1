/* Write a program that asks the user to enter a euro-and-cents amount, then displays the amount with 20% tax added. */

#include <stdio.h>
#include <stdlib.h>

int main() {

	float amount = 0;
	float withtax = 0;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	withtax = amount + amount * 0.2;

	printf("With tax added : %.2f\n", withtax);

	return 0;
}
