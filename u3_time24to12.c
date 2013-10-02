/*	Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int hours = 0;
	int minutes = 0;
	char *am = "AM";
	char *pm = "PM";
	char *abbreviation;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hours, &minutes);

	if (hours == 0) {
		hours = 12;
		abbreviation = am;
	} else if (hours == 12) {
		abbreviation = pm;
	} else if (hours < 12) {
		abbreviation = am;
	} else {
		hours = hours - 12;
		abbreviation = pm;
	}

	printf("Equivalent 12-hour time: %d:%02d %s\n", hours, minutes, abbreviation);

	return 0;
}
