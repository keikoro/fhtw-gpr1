/*	Write a program that computes the surface area and volume of a cube. The program prompts the user to enter the side of a side of the cube. The input to the program is an integer.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int side = 0;
	int surface = 0;
	int volume = 0;

	printf("Length of a side: ");
	scanf("%d", &side);

	surface = 6*(side*side);
	volume = side*side*side;

	printf("Surface area: %d\n", surface);
	printf("Volume: %d\n", volume);

/*	printf("The surface area of a cube with a side side of %.2f is %.2f, and its volume is %.2f\n", side, surface, volume);*/

	return 0;
}
