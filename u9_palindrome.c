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

// defines allowed length of message -> allowed chars + 1x newline
#define maxchars 41

int main() {

    char message[maxchars] = {'\0'};
    int countinput = 0;
    char letters[maxchars] = {'\0'};
    int countletters = 0;
    char specialchars[maxchars] = {'\0'};
    // int bla[] = {1,2,3};
    // int (*b)[] = &bla;
    char (*p)[maxchars] = &message;
    int i=0, j=0, k=0;

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

    /*  STEPS
        separate the input into alphabetical and non-alphabetical characters, put them into two separate arrays. Use ASCII instead of checking against all letters!

        ASCII table
        A-Z ... 65-90
        a-z ... 97-122
    */
    for(i=0;i<countinput;i++) {

        if( (message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122) ) {
            letters[j] = message[i];
            j++;
        }

    }
    countletters = strlen(letters);
    printf("number of letters: %d\n", countletters);

    if(countletters > 1) {

    } else {
        // if letters array is empty or contains only 1 letter
        printf("Not a palindrome\n");
    }

    /*
        if the array with alphabetic chars is not empty:
        adjust countinput (count length of array)

        if there's only one letter -> palindrome

        if there's more than one letter:
        - divide countinput by two, save result in variable looptimes
        - check the first letter against last, 2nd against one but last etc., so (*p)[0] vs. (*p)[countinput-1], (*p)[1] vs. (*p)[countinput-2] => (*p)[i] vs. (*p)[countinput-i-1] looptimes times
    */
    return 0;
}
