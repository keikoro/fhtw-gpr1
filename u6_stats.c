/*  Write a program that calculates statistics on word length for a sentence. The sentence is terminated by a ’.’ For each found length of a word the number of words of that length is printed. Only those lengths that are found in the input are printed. Only letters from a-z or A-Z are allowed to form words. Words are separated by a space. No punctuation characters other than ’.’ are allowed. If any other input character is recognized or the input is longer than 80 characters the program displays ”NOT VALID”. Note, that in the case that no word is present in the input, nothing is printed.

% u6_stats
Enter a sentence: Bolt was expected to use the super bark.
Length 2: 1
Length 3: 3
Length 4: 2
Length 5: 1
Length 8: 1

% u6_stats
Enter a sentence: Something wasn’t right.

NOT VALID
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char allowed[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ. ";
    char sentence[80] = {'\0'};
    int countallowed = 0;
    int countchars = 0;
    int i, j;
    int valid = 0;

    printf("Enter a sentence: ");

    // fgets reads full sentences from standard input (including spaces)
    fgets(sentence, 80, stdin);

    countallowed = strlen(allowed); // counts all chars except terminating
    countchars = strlen(sentence);

    /*  fgets includes newline character (for Enter) if input is less than
        the allowed number of characters (i.e. only if there's space left in
        the array). -> Check for '\n' and replace it with null terminator if it exists, so it doesn't get counted toward character count. */

    printf("%d\n", countchars);

    //if((countchars < 0) OR (countchars > 79)) {
    if(countchars > 0) {
        printf("there is input\n");
        for(i=0;i<countchars;i++) {
            printf("%c\n", sentence[i]);
        }
    } else {
        printf("NOT VALID\n");
    }

    /* check for characters (GPR course materials, unit4, p10)
    for(char ch='A'; ch<='Z'; ch++) {
            printf("%c, ", ch);
       }
    */


    // this does not work as expected:
    // check if sentence only contains valid characters
    // for(i=0;i<countchars;i++) {
    //     for(j=0; j<countallowed; j++) {
    //         if (sentence[i] == allowed[j]) {
    //             printf("%c\n", sentence[i]);
    //             valid = 1;
    //         }
    //     }

    //     if(valid == 1){

    //     } else {
    //         printf("NOT VALID");

    //     }
    // }

    // printf("%c\n", sentence[0]); // use %c to print an array elements
    // printf("%s\n", sentence); // use %s to print whole array

    return 0;
}
