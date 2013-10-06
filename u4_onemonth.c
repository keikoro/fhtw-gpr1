/*	Write a program that prints a one-month calendar. The user specifies the number of days in a month and the day of the week on which the printed one-month calendar begins:

% u4_onemonth
Enter number of days in month: 31
Enter starting day of the week (1=Monday, 7=Sunday): 3

			1	2	3	4	5
	6	7	8	9	10	11	12
	13	14	15	16	17	18	19
	20	21	22	23	24	25	26
	27	28	29	30	31
%

After the month and day of week have been entered, a single new-line character is printed (see above example, there is a single empty line before the days are printed). Each day printed is followed by a single space character (including those at the end of the week in the 7th column; this also simplifies the implementation). After the last day one space character and a newline character is printed. Ensure that you do not print two new-line characters in case the last day is printed in the 7th column, but exactly one new-line character in all cases after the last day.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int daysinmonth = 0;
	int weekday = 0;
	int calendarstart = 0;
	int i = 0;

	printf("Enter number of days in month: ");
	scanf("%d", &daysinmonth);

	printf("Enter starting day of the week (1=Monday, 7=Sunday): ");
	scanf("%d", &weekday);
	printf("\n");

	/* loop through whole month */
	for(i=1; i<=daysinmonth; i++) {
		if (weekday > 1) {
			/* print spaces for "missing" weekdays */
			while(calendarstart<weekday-1) {
				printf("   ");
				calendarstart++;
			}
		}
		printf("%2d ", i);
		/* create line break after each Sunday (7th day of week) */
		if ((i+weekday-1)%7 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
