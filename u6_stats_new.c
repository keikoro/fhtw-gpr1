/*  Write a program that calculates statistics on word length for a userinput. The userinput is terminated by a ’.’ For each found length of a word the number of words of that length is printed. Only those lengths that are found in the input are printed. Only letters from a-z or A-Z are allowed to form words. Words are separated by a space. No punctuation characters other than ’.’ are allowed. If any other input character is recognized or the input is longer than 80 characters the program displays ”NOT VALID”. Note, that in the case that no word is present in the input, nothing is printed.

% u6_stats
Enter a userinput: Bolt was expected to use the super bark.
Length 2: 1
Length 3: 3
Length 4: 2
Length 5: 1
Length 8: 1

% u6_stats
Enter a userinput: Something wasn’t right.

NOT VALID
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    /*  Allow up to 82 chars so "NOT VALID" can be triggered on inputs with more than 81 chars (= 80 allowed characters + 1 null terminator).    */
    int maxchars = 82;
    char userinput[82] = {'\0'};
    //  max. 11 diff. possible word lengths in 80 chars (w/ spaces inbetween)
    int wordlengths[2][11] = {};
    int countchars = 0;
    int thislength = 0;
    int validletter = 0;
    int i=0;

    printf("Enter a userinput: \n");
    /*  fgets reads full userinputs from standard input including spaces, special chars and - if input is less than the allowed no. of character (= if there's space left in the array) - also new line characters (Enter key).  */
    fgets(userinput, maxchars, stdin);
    /*  As newline characters are also counted with strlen(), a potential '\n' character needs to be replaced with the null terminator.  */
    for (i=0;i<maxchars;i++) {
        if(userinput[i] == '\n') {
            userinput[i] = '\0';
            break;
        }
    }
    countchars = strlen(userinput); // all printable chars + spaces
    printf("character count: %d\n", countchars); // TODO remove later on

    // input is at least one character and not more than 80
    if(countchars > 0 && countchars <= 80) {
        // go through all characters of userinput
        for(i=0;i<countchars;i++) {
            // check if userinput[i] is a lowercase character a-z
            for(char ch='a';ch<='z';ch++) {
                if(userinput[i] == ch) {
                    thislength++;
                    validletter = 1;
                }
            }
            // if userinput[i] isn't lowercase, check if it's uppercase A-Z
            if (validletter != 1) {
                for(char ch='A';ch<='Z';ch++) {
                    if(userinput[i] == ch) {
                        thislength++;
                        validletter = 1;
                    }
                }
            }
            // userinput[i] is no character at all; check for spaces and '.'
            if(validletter != 1) {
                if(userinput[i] == ' ') {
                    if (thislength > 0) {
                        printf("Length %d: valid %d\n", thislength, validletter); // TODO remove later on
                        thislength = 0;
                    }

                } else if (userinput[i] == '.') {
                    if (thislength > 0) {
                        printf("Length %d: valid %d\n", thislength, validletter); // TODO remove later on
                        thislength = 0;
                    }
                    break;
                } else {    // userinput[i] is no valid character -> exit
                    printf("NOT VALID\n");
                    exit(0);
                }
            }
            validletter = 0;
        }
    } else if (countchars > 80) {   // more than allowed characters entered
        printf("NOT VALID\n");
    } else {   // no characters entered - do nothing
    }
    return 0;
}
