int Compare(char s1,char s2)
{
    if (s1=='{'&&(s2=='}'||s2=='['||s2=='('))
    {
        if(s2=='}') return 2;
        else return 1;
    }
    else if (s1=='['&&(s2==']'||s2=='('))
    {
        if(s2==']') return 2;//1进栈，2退栈
        else return 1;
    }
    else if (s1=='('&&s2==')')
    {
        
        return 2;
    }
    return 0;
}
bool isValid(char* s) {
    int len=strlen(s);
    int kuohao[len/2+1];
    int top=-1;
    for (int i = 0; i < len; i++)
    {
        if (top==-1)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                kuohao[++top]=s[i];
            }
            else
            {
                return 0;
            }
            
        }
        else
        {
            switch (Compare(kuohao[top],s[i]))
            {
            case 0:
                return 0;
                break;
            case 1:
            kuohao[++top]=s[i];
            break;
            case 2:
            top--;
            break;
            default:
            return 0;
                break;
            }
        }
    }
    return top==-1;
}//以上是我写的较为正确的，虽然我看错了题目，下面给出标准答案
bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // 左括号入栈
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        }
        else {
            // 右括号时栈不能为空
            if (top == -1) return false;

            char t = stack[top];

            // 不匹配直接失败
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                return false;
            }

            // 匹配，出栈
            top--;
        }
    }

    // 栈空才合法
    return top == -1;
}
