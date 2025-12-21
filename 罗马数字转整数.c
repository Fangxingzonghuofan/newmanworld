#include <stdio.h>
#include <string.h>
int romanToInt(char* s) {
    char pre='I';
    int num=0;
    int len=strlen(s);
    for (int  i = len-1; i >=0; i--)
    {
        switch (s[i])
        {
        case 'I':
        if (pre=='V'||pre=='X')
        {
            num-=1;
        }
        else num+=1;
        pre='I';
            break;
        case 'V':
        num+=5;
        pre='V';
        break;
         case 'X':
         if (pre=='L'||pre=='C')
        {
            num-=10;
        }
        else num+=10;
        pre='X';
        break;
         case 'L':
         num+=50;
         pre='L';
        break;
         case 'C':
         if (pre=='D'||pre=='M')
        {
            num-=100;
        }
        else num+=100;
        pre='C';
        break;
         case 'D':
         num+=500;
         pre='D';
        break;
         case 'M':
         num+=1000;
         pre='M';
        break;
        default:
        printf("error\n");
        return -1;
            break;
        }
    }
    return num;
}//简单题也确实就是简单哈，轻松拿下；