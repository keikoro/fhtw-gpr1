/*
Implement selection sort in a program selsort and print information about the sorting process. The program reads in a series of positive numbers (separated by space). The list of numbers is terminated by the number 0. Ensure that your program can sort at least 1024 numbers (allocate enough memory). It sorts those numbers using the selection sort algorithm and prints the intermediate steps (as on the lecture slides) during sorting. It also marks the selected number and the number with which it is being swapped. If the positions of the numbers are the same, then both markings are displayed. Use the algorithm as shown on the lecture slides, and extend it with the proper intermediate outputs of all numbers and the marking of the numbers. After sorting, the program prints the total number of comparisons and the total number of swap operations performed. See the following example for the exact syntax of marking and displaying the numbers. The smallest element being found is printed between ’[’ and ’]’, the other number that is going to be swapped with is printed between ’(’ and ’)’:

￼% u12_selsort
Enter numbers: 15 2 43 17 4 8 47 0

Step 1: (15) [2] 43 17 4 8 47
Step 2: 2 (15) 43 17 [4] 8 47
Step 3: 2 4 (43) 17 15 [8] 47
Step 4: 2 4 8 (17) [15] 43 47
Step 5: 2 4 8 15 [(17)] 43 47
Step 6: 2 4 8 15 17 [(43)] 47
Result: 2 4 8 15 17 43 47

Number of comparisons: 21
Number of swaps: 6
%
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxinput 2000

int main() {

    int allnumbers[maxinput];
    int arraylength = 0;
    int smallestindex = 0;
    int temp = 0;
    int comparisons = 0;
    int swaps = 0;
    int loopstart = 1;
    int i=0, j=0;

    printf("Enter numbers: ");

    // have user input numbers; stop taking input when 0 is entered
    while(scanf("%d", &allnumbers[i]) && allnumbers[i] != 0) {
        i++;
    }
    arraylength = i;
    printf("\n");

    for(i=0;i<arraylength+1;i++) {

        for(j=loopstart;j<arraylength;j++) {
            // compare 1st (2nd, 3rd) element to subsequent elements in array
            if (allnumbers[smallestindex] > allnumbers[j]) {
                smallestindex = j;
            }
            comparisons++;
        }

        if (i < arraylength-1) {
            swaps = i+1;
            printf("Step %d: ", swaps);
        } else if (i < arraylength) {
            printf("Result: ");
        }

        for(j=0;j<arraylength;j++) {

            if (i < arraylength-1) {
                if (j == smallestindex) {
                    printf("[");
                }
                if(j==i) {
                    printf("(");
                }
                printf("%d", allnumbers[j]);
                if(j==i) {
                    printf(")");
                }
                if (j == smallestindex) {
                    printf("]");
                }
            } else if (i < arraylength) {
                // print "Result" line
                printf("%d", allnumbers[j]);
            }
            if (i < arraylength) {
                printf(" ");
            }
        }
        temp = allnumbers[smallestindex];
        allnumbers[smallestindex] = allnumbers[i];
        allnumbers[i] = temp;
        smallestindex = i+1;
        loopstart++;

        if (i < arraylength) {
            printf("\n");
        }
    }
    printf("\n");

    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    return 0;
}
