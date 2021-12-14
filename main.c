#include <stdio.h>
#define TXT 1024
#define WORD 30
int main()
{
    char c[5] = {'a','b','c','d','\0'};
    // c = "abc";
    // int a = sumOfWord(c)
    int p =sizeof(c); 
    int sum = 0;
    sum = sumOfWord(c);
    char text2[7] = {'a','-','b','c',',','d','\0'};
    char s[TXT];
    
    geo(sum,text2,s);
    // *(s+10) = '\0';
    printf("%s",s);
    
    // printf("%d",sum);

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
/*            if (fsum < sum) { //if sum bigger then
                *(s+y) = '\0';
                x = y;
                break;
            }*/
            if (fsum == sum) { //if equal -> return
                *(s+x) = '\0';
                y = x;
                break;
            }

        }
        *(s+y) = '\0';
        x = y;
    }
    // return s;
}
