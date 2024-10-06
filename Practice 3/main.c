#include <stdio.h>
#include <string.h>
#include <time.h>


void randomize(char str[]){

    srand(time(NULL));

    int str_length = strlen(str);

    char temp;

    for (int i = 0; i < str_length; i++){
        int j = rand() % str_length;

        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main(){

    char str[32];

    printf("Pass a string: ");
    gets(str, sizeof(str), stdin);

    randomize(str);

    printf("%s\n", str);

    return 0;
}
 
