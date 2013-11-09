/*
Write a program that reads a message, then checks whether it’s a palindrome (the letters in the message are the same from left to right as from right to left). Ignore all characters that are not letters only relevant are letter A-Z,a-z. A single character is a palindrome, and the empty message is considered a palindrome as well (this includes a message that consists of only non-letter characters).
% palindrome
Enter a message: He lived as a devil, eh?
Palindrome
% palindrome
Enter a message: Anne, I stay a day at Sienna.
Palindrome
% palindrome
Enter a message: Madam, I am Adam.
Not a palindrome
%
The maximum length of the message is 40 characters. Reading of the message should stop when more than 40 characters are read, or when the character ’\n’ is read (additional characters are ignored). The two possible messages printed by the program are “Palindrome” and “Not a palindrome”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// defines allowed length of message -> allowed chars + 1x newline
#define maxchars 41

int main() {

    char message[maxchars] = {'\0'};
    char letters[maxchars] = {'\0'};
    char specialchars[maxchars] = {'\0'};
    int countinput = 0;
    int countletters = 0;
    int countspecial = 0;
    int palindromeloop = 0;
    char (*p)[maxchars] = &letters;
    int i=0, j=0, k=0, l=0;

    printf("Enter a message: ");
    fgets(message, maxchars, stdin);

    /*  As newline characters are also counted with strlen(), a potential '\n' character needs to be replaced with the null terminator.  */
    for (i=0;i<maxchars;i++) {
        if(message[i] == '\n') {
            message[i] = '\0';
            break;
        }
    }
    countinput = strlen(message);

    /*  separate input into alphabetical and non-alphabetical characters and put them into two separate arrays. Use ASCII instead of checking against all letters.
    ASCII table:
    A-Z ... 65-90
    a-z ... 97-122
    */
    for(i=0;i<countinput;i++) {
        // check for alphabetical characters
        if( (message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122) ) {
            // make all letters lowercase, so mixed case letters also match
            letters[j] = tolower(message[i]);
            j++;
        // make separate array for special characters
        } else {
            specialchars[l] = message[i];
            l++;
        }
    }
    countletters = strlen(letters);
    countspecial = strlen(specialchars);

    /*  if the letter array is not empty, loop over it to check if the 1st letter equals the last, the 2nd equals the one but last etc.

    do this until the middle of the array is reached (array length/2). if there's a non-match in there, print "Not a palindrome" and exit the program.
    */
    if(countletters > 0) {
        // loop times = half the length of the array
        palindromeloop = countinput / 2;
        for(i=0;i<palindromeloop;i++) {
            // exit program if letters don't match
            if ( (*p)[i] != (*p)[countletters-i-1]) {
                printf("Not a palindrome\n");
                k = 1;
                i = palindromeloop;
                exit(0);
            }
        }
        printf("Palindrome\n"); // else print confirmation

    // input is a palindrome if there are only special characters
    } else if (countspecial > 0) {
        printf("Palindrome\n");

    // input is not a palindrome if there are no printable characters
    } else {
        printf("Not a palindrome\n");
    }
    return 0;
}
