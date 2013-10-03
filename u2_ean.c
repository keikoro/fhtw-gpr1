/* EAN Check Digit Computation */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int ean1 = 0;
	int ean2 = 0;
	int ean3 = 0;
	int ean4 = 0;
	int ean5 = 0;
	int ean6 = 0;
	int ean7 = 0;
	int ean8 = 0;
	int ean9 = 0;
	int ean10 = 0;
	int ean11 = 0;
	int ean12 = 0;
	int checkdigit = 0;
	int oddsum = 0;
	int evensum = 0;

	printf("Enter the first 12 digits of an EAN: ");

	scanf("%01d%01d%01d%01d%01d%01d%01d%01d%01d%01d%01d%01d", &ean1, &ean2, &ean3, &ean4, &ean5, &ean6, &ean7, &ean8, &ean9, &ean10, &ean11, &ean12);

	evensum = ean2 + ean4 + ean6 + ean8 + ean10 + ean12;
	oddsum = ean1 + ean3 + ean5 + ean7 + ean9 + ean11;

	checkdigit = 9-(((evensum*3 + oddsum)-1)%10);

	printf("Check digit: %d\n", checkdigit);

	return 0;
}
