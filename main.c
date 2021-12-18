#include <stdio.h>
#include <string.h>
#include "main.h"
#define TXT 1024
#define WORD 30

int main() {
    char word[WORD];
    for (int i = 0; i < WORD; i++) {
        if (word[i - 1] == '\n' || word[i - 1] == '\t' || word[i - 1] == ' ') {
            word[i] = '\0';
            break;
        }
        scanf("%c", &word[i]);
    }
    char text[TXT];
    for (int i = 0; i < TXT; i++) {
        if (text[i - 1] == '~') {
            text[i] = '\0';
            break;
        }
        scanf("%c", &text[i]);
    }

    int sum = sumOfWord(word);
    char s1[TXT];
    geo(sum,text,s1);
    printf("\n");
    printf("Gematria Sequences: ");
    printf("%s", s1);
/*    char s2[TXT];
    atbash(text,s2,word);
    printf("\n");
    printf("Atbash Sequences: ");
    printf("%s", s2);*/
    char s3[TXT];
    anagram(text,s3,word);
    printf("\n");
    printf("Anagram Sequences: ");
    printf("%s", s3);
    printf("\n");

    return 0;
}

int sumOfWord(char str[]) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            sum += (str[i] - ('A' - 1));

        } else if (str[i] >= 'a' && str[i] <= 'z') {
            sum += (str[i] - ('a' - 1));
        } else {
            continue;
        }
    }
    return sum;
}

void geo(int fsum, char text[], char s[]) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < strlen(text); i++) {
        int sum = 0;
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            for (int j = i; j < strlen(text); j++) {
                if (text[j] >= 'A' && text[j] <= 'Z') {
                    sum += (text[j] - ('A' - 1));
                    *(s + x) = text[j];
                    x += 1;
                } else if (text[j] >= 'a' && text[j] <= 'z') {
                    sum += (text[j] - ('a' - 1));
                    *(s + x) = text[j];
                    x += 1;
                } else {
                    *(s + x) = text[j];
                    x += 1;
                    // continue;
                }
                if (fsum < sum) { //if sum bigger then
                    *(s + y) = '\0';
                    x = y;
                    break;
                }
                if (fsum == sum) { //if equal -> return
                    *(s + x) = '~';
                    y = x + 1;
                    x += 1;
                    break;
                }

            }
            *(s + y) = '\0';
            x = y;
        }
    }
    *(s + y - 1) = '\0';
}

void anagram(char text[], char s[], char word[]) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < strlen(text); i++) {
        char tempWord[strlen(word)];
        strcpy(tempWord, word);
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            for (int j = i; j < strlen(text); j++) {
                char *result;
                char s1 = text[j];
                if (s1 == ' ') {
                    *(s + x) = s1;
                    x += 1;
                    continue;
                }
                if (strchr(word, s1)) { // if word contain char
                    result = strchr(word, s1);
                    *(s + x) = *result;
                    x += 1;
                    removeChar(tempWord, s1);
                    
                } else {
                    *(s + y) = '\0';
                    x = y;
                    break;
                }
                if (contain(tempWord) == 1) { // if tempWord dont contain chars from word

                    *(s + x) = '~';
                    y = x + 1;
                    x += 1;
                    break;
                }
                        
            }
        }
    }
    *(s + y - 1) = '\0';

}


void removeChar(char tempWord[], char s1) {
    for (int i = 0; i < strlen(tempWord); i++) {
        if (tempWord[i] == s1) {
            *(tempWord + i) = ' ';
        }
    }
}
int contain(char tempWord[]) {
    for (int i = 0; i < strlen(tempWord); i++) {
        if ((tempWord[i] >= 'A' && tempWord[i] <= 'Z') || (tempWord[i] >= 'a' && tempWord[i] <= 'z')) {
            return 0;
        }
    }
    return 1;
}
