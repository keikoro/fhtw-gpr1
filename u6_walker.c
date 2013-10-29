/*
Write a program that computes a ”walk” (of a cute robot) across a 10x10 array. The array contains characters (all initially ’.’). The user can enter four different directions north, east, south, west, by entering the characters n,e,s,w to control the walk. If the user enters x the program exits. After each direction-command the array is printed with the walk being display by capital letter starting with A to Z. We use A for the starting point, with 25 remaining letters to denote the steps. After having used letter Z to denote a step, we wrap around and start again with A. To make the walk more interesting, the user is not allowed to revisit a location. In this case the program does not print the array, but prints ”You cannot go there!” - Yes, you can trap yourself.

Starting in the upper left corner (position 0,0):

% u6_walker
A.........
..........
..........
..........
..........
..........
..........
..........
..........
..........
Enter direction command: n

You cannot go there!
Enter direction command: s

A.........
B.........
..........
..........
..........
..........
..........
..........
..........
..........
Enter direction command: e

A.........
BC........
..........
..........
..........
..........
..........
..........
..........
..........
Enter direction command: w

You cannot go there!
Enter direction command: s

A.........
BC........
.D........
..........
..........
..........
..........
..........
..........
..........
Enter direction command: x

%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char field[10][10] = {};
    char direction[2] = {'\0'};
    // initial position of robot
    int robotX = 0;
    int robotY = 0;
    int wrongmove = 0;
    int resetarray = 0;
    int i=0, j=0;

    // fill array
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            field[i][j] = '.';
        }
    }
    field[0][0] = 'A';

    // print initial playing field
    for (i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }

    // start moving the robot on the playing field
    for(char ch='A';ch<='Z';ch++) {
        if (robotX == 0 && robotY == 0) {
            ch = 'B';
        }
        if (resetarray == 1) {
            ch = 'A';
            resetarray = 0;
        }

        printf("Enter direction command: ");
        scanf("%s", direction);
        printf("\n");

        switch(direction[0]) {
            case('n'):  if (robotX == 0 || field[robotX-1][robotY] != '.') {
                            printf("You cannot go there!\n");
                            wrongmove = 1;
                        } else {
                            robotX -= 1;
                        }
                        break;
            case('e'):  if (robotY == 9 || field[robotX][robotY+1] != '.') {
                            printf("You cannot go there!\n");
                            wrongmove = 1;
                        } else {
                            robotY += 1;
                        }
                        break;
            case('s'):  if (robotX == 9 || field[robotX+1][robotY] != '.') {
                            printf("You cannot go there!\n");
                            wrongmove = 1;
                        } else {
                            robotX += 1;
                        }
                        break;
            case('w'):  if (robotY == 0 || field[robotX][robotY-1] != '.') {
                            printf("You cannot go there!\n");
                            wrongmove = 1;
                        } else {
                            robotY -= 1;
                        }
                        break;
            case('x'):  exit(0);
                        break;
        }

        // if input was valid, print the array
        if (wrongmove != 1) {
            for (i=0;i<10;i++) {
                for(j=0;j<10;j++) {
                    if(i == robotX && j == robotY) {
                        field[i][j] = ch;
                    }
                    printf("%c", field[i][j]);
                }
                printf("\n");
            }
        } else {    // reset current letter on invalid input
            ch--;
        }
        wrongmove = 0;

        if(ch == 'Z') {
            ch = 'A';
            resetarray = 1;
        }
    }

    return 0;
}
