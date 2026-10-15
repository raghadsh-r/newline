




#include <stdio.h>
int main()
{
    char *p;
    p = 'a';
    printf("%i\n",p);
    long long x = (int)p;
    printf("%p\n",p);
    printf("%x\n",p);
    printf("%llx\n", x);
    printf("%lli\n", x);


}