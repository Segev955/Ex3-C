/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "main.h"
#define TXT 1024
#define WORD 30

int main()
{
	
/*    char s1[] = "Helloworld";
    char s2[] = "laH";
    char s3 = s2[2];
    char *result;
    result = strchr(s1, s3);
    if (strchr(s1, s3))
    printf("The matching character : %c\n", *result);*/
    int sumOfWord(char str[]);
    char c[WORD] = "a";//= {'a','b','c','d','\0'};
    int i = 0;
    do {
        scanf("%[^\n]", &c[i]);
        i += 1;
    }
    while (c[i-1] != '\n' && c[i-1] != '\t' && c[i-1] != ' ');
    c[i] = '\0';
      //printf("%s",c);  
    int sum = 0;
    sum = sumOfWord(c);
    char text2[TXT];
    i = 0;
    do {
        scanf("%[^\n]", &text2[i]);
        i += 1;
    }
    while (text2[i-1] != '~');
    text2[i] = '\0';
    // scanf("%[^\n]", &text2); 
    char s[TXT];
    //gimel(text2,s,c);
    printf("\n");
    printf("%s",text2);


    return 0;
}

int sumOfWord(char str[]) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
	if (str[i] >= 'A' && str[i] <= 'Z') {
            sum += (str[i] - ('A'-1));
        
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            sum += (str[i] - ('a'-1));
        }
        else {
            continue;
        }
    }
    return sum;
}

void geo(int fsum, char text[],char s[]) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < strlen(text); i++) {
        int sum = 0;
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
        for (int j = i; j < strlen(text); j++) {
            if (text[j] >= 'A' && text[j] <= 'Z') {
                sum += (text[j] - ('A'-1));
                *(s+x) = text[j];
                x += 1;
            }
            else if (text[j] >= 'a' && text[j] <= 'z') {
                sum += (text[j] - ('a'-1));
                *(s+x) = text[j];
                x += 1;
            }
            else {
                *(s+x) = text[j];
                x += 1;
                // continue;
            }
            if (fsum < sum) { //if sum bigger then
                *(s+y) = '\0';
                x = y;
                break;
            }
            if (fsum == sum) { //if equal -> return
                *(s+x) = '~';
                y = x+1;
                x+=1;
                break;
            }

        }
        *(s+y) = '\0';
        x = y;
        }
    }
    *(s+y-1) = '\0';
}

void gimel(char text[],char s[],char word[]) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < strlen(text); i++) {
        char tempWord[TXT];
        strcpy(tempWord, word);
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            for (int j = i; j < strlen(text); j++) {
                char *result;
                char s1 = text[j];
                if (s1 == ' ') {
                    *(s+x) = s1;
                    x += 1;
                    continue;
                }
                if (strchr(word, s1)) { // if word contain char
                    result = strchr(word, s1);
                    *(s+x) = *result;
                    x += 1;
                    removeChar(tempWord,s1);
                }
                else {
                    *(s+y) = '\0';
                    x = y;
                    break;
                }
                if (!strpbrk(word, tempWord)) { // if tempWord dont contain chars from word
                    *(s+x) = '~';
                    y = x+1;
                    x+=1;
                    break;
                }
            }
        }
    }
    *(s+y-1) = '\0';
}



void removeChar(char tempWord[],char s1) {
    for (int i = 0; i < strlen(tempWord); i++) {
        if (tempWord[i] == s1) {
            *(tempWord+i) = ' ';
        }
    }
}



