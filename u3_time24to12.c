/*	Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form. The 12-hour time should not contain leading zeros. AM or PM must be printed in capital letters only. Your program only has to handle correct 24h time formats as input.

%u3_time24to12
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM
%
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int hours = 0;
	int minutes = 0;
	char *am = "AM";
	char *pm = "PM";
	char *abbreviation = "";

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hours, &minutes);

	if (hours == 0) {
		hours = 12;
		abbreviation = am;
	} else if (hours < 12) {
		abbreviation = am;
	} else if (hours == 12) {
		abbreviation = pm;
	} else {
		hours = hours - 12;
		abbreviation = pm;
	}

	printf("Equivalent 12-hour time: %d:%02d %s\n", hours, minutes, abbreviation);

	return 0;
}
