/*	Write a program that finds the largest in a series of numbers entered by the user. The program must prompt the user to enter arbitrary many numbers one by one. When the user enters 0 or a negative number, the program must display the largest positive number entered before.

% u4_largest
Enter a number: 50
Enter a number: 55.670
Enter a number: 4.44
Enter a number: 0
The largest number entered was 55.67

% u4_largest
Enter a number: 0
No number was entered.
%
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	double userinput = 0;
	double largestnumber = 0;

	do {
		printf("Enter a number: ");
		scanf("%lf", &userinput);
		if(largestnumber < userinput) {
			largestnumber = userinput;
		}
	} while(userinput > 0);

	if(largestnumber > 0) {
		printf("\nThe largest number entered was %.2lf\n", largestnumber);
	} else {
		printf("\nNo number was entered.\n");
	}

	return 0;
}
