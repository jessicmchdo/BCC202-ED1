#include <stdio.h>
#include <string.h>

int main() {

    char phrase[1000];
    int counter = 0, lenght, i;

    while(fgets(phrase, 1000, stdin) != NULL) {

        lenght = strlen(phrase) - 1;

        for(i = 0; i < lenght; i++) {

            if(counter < 0) {
                break;
            }

            else if(phrase[i] == '(') {
                counter++;
            }

            else if(phrase[i] == ')') {
                counter--;
            }
        }

        if(counter == 0) {
            printf("correct\n");
        }

        else {
            printf("incorrect\n");
        }

        counter = 0;
    }

    return 0;
}