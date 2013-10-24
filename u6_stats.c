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
    int countletters = 0;
    int i;

    printf("Enter a sentence: ");

    // read full sentence (with spaces)
    fgets(sentence, 80, stdin);

    countletters = strlen(sentence);
    countletters -= 1; // subtract one for final symbol \0

    // check if sentence only contains valid characters
    for(i=0;i<countletters;i++) {
        if(strpbrk(allowed, sentence+i)) {
        //if(sentence[i] != ' ') {
            printf("%c\n", sentence[i]);
        } else {
            printf("NOT VALID\n");
        }
    }

    // printf("%c\n", sentence[0]); // use %c to print an array elements
    // printf("%s\n", sentence); // use %s to print whole array

    return 0;
}
