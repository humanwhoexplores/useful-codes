
#define pc putchar_unlocked

void print(int n)
{
    char num[20];
    register int i=0;
    do
    {
        num[i++]=n%10+'0';
        n/=10;
    }while(n);
    i--;
    while(i>=0)
        pc(num[i--]);
    pc('\n');
}

