/* Write a program that accepts a date in US format mm/dd/yyyy and prints it in the form dd.mm.yyyy on the next line. Leading 0 are required in the output if the input is less than a maximum number of digits. You do not need to check for errors. */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int month = 0;
	int day = 0;
	int year = 0;

	scanf("%d/%d/%d", &month, &day, &year);
	printf("%02d.%02d.%d\n", day, month, year);

	return 0;
}
