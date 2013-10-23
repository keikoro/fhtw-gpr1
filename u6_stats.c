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

    printf("Enter a sentence: ");
    scanf("%c", sentence);
    printf("%s\n", sentence);
    return 0;
}
