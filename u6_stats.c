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

    char sentence[80] = {'\0'};
    int wordlengths[2][11] = {}; // max. 11 diff. word lengths in 79 chars
    int countchars = 0;
    int newlength = 0;
    int valid = 1;
    int i=0, j=0, k=0, l = 0;
    int temp0 = 0, temp1 = 0;

    printf("Enter a sentence: \n");

    // fgets reads full sentences from standard input
    fgets(sentence, 80, stdin);
    /*  fgets includes newline character (for Enter) if input is less than
        the allowed number of characters (i.e. only if there's space left in
        the array). -> Check for '\n' and replace it with null terminator if it exists so it doesn't get counted toward character count. */
    for (i=0;i<80;i++) {
        if(sentence[i] == '\n') {
            sentence[i] = '\0';
            break;
        }
    }
    countchars = strlen(sentence);

    if((countchars > 0) && (countchars <= 79)) {    // expected input
        for(i=0;i<countchars;i++) {
            if(sentence[i] == '.' || sentence[i] == ' ') {
                if (j > 0) {    // length of preceding word
                    // printf("wordlength: %d\n", j);
                    // check array for word length j
                    for(k=0;k<11;k++) {
                        if (wordlengths[0][k] == j) {
                            // printf("count before: %d\n", wordlengths[1][k]);
                            wordlengths[1][k] += 1;
                            // printf("count after: %d\n", wordlengths[1][k]);
                            newlength = 1;  // word length already in array
                            break;
                            // printf("count before: %d\n", wordlengths[1][k]);
                        }
                    }
                    // if word length doesn't exist yet, add it
                    if (newlength == 0) {
                        for(k=0;k<11;k++) { // find empty column
                            if (wordlengths[0][k] == 0) {
                                wordlengths[0][k] = j;
                                // printf("count before: %d\n", wordlengths[1][k]);
                                wordlengths[1][k] = 1;
                                // printf("count before: %d\n", wordlengths[1][k]);
                                break;
                            }
                        }
                    }
                }
                j = 0;  // reset word length to zero
                newlength = 0;  // reset indicator for new word length

                if(sentence[i] == '.') {
                    break;
                }


            } else {
                // check for letters A-Z (GPR course materials, unit4, p10)
                for(char ch='A'; ch<='Z'; ch++) {
                    if (sentence[i] == ch) {
                        j++;
                    }
                }
                for(char ch='a'; ch<='z'; ch++) {
                    if (sentence[i] == ch) {
                        j++;
                    }
                }
                if (j == 0) {   // sentence[i] is not a valid letter
                    printf("NOT VALID\n");
                    valid = 0;
                    break;
                }
            }
        }
        /*  TODO loop over multi array - sort from word with lowest no.
            of letters to word with highest no. of letters
            output nothing if array is empty    */

        // only output word lengths in array if ALL input was valid
        if (valid == 1) {

            // sort by word length ascending
            for(k=1;k<11;k++) {
                if(wordlengths[0][k] < wordlengths[0][k-1]) {
                    temp0 = wordlengths[0][k-1];
                    temp1 = wordlengths[1][k-1];
                    wordlengths[0][k-1] = wordlengths[0][k];
                    wordlengths[1][k-1] = wordlengths[1][k];
                    wordlengths[0][k] = temp0;
                    wordlengths[1][k] = temp1;
                }
            }

            for(k=0;k<11;k++) {
                if (wordlengths[0][k] != 0) {   // ignore empty columns
                    printf("Length %d: %d\n", wordlengths[0][k], wordlengths[1][k]);
                }
            }
        }
    } else if (countchars == 0) {   // no input at all
    } else if (countchars > 79) {   // more characters than allowed
        printf("NOT VALID\n");
    }
    return 0;
}
