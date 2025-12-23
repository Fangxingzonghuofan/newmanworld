#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* intToRoman(int num) {
    char *res = (char*)malloc(20); // 最大长度 < 20
    int idx = 0;
    int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    for (int i = 0; i < 13; i++) {
        while (num >= value[i]) {
            strcpy(res + idx, s[i]);
            idx += strlen(s[i]);
            num -= value[i];
        }
    }
    res[idx] = '\0';
    return res;
}