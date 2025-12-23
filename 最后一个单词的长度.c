#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLastWord(char* s) {
    int len=strlen(s);
    int i=len-1;
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    len=i;
    for (;i >= 0 && s[i] != ' '; i--)
    {
        
    }
    return len-i;
}