#include <stdio.h>

int n;

void f(int n, char a, char b, char c)
{
    if( n > 0 )
    {
        //f(n-1, a, c, b);
        f(n-1, a, c, b);
        printf("%d : %c -> %c\n", n, a, b);
        //f(n-1, b, a, c);
        //f(n-1, c, a, b);
    }
}

int main()
{
    scanf("%d", &n);
    f(n, 'A', 'B', 'C');
    return 0;
}