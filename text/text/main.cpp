#include <stdio.h>

long long int a, b, c, d;
double result;

int main()
{
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    result = a*b*c*d/8.0;
    result /= 1024*1024.0;
    printf("%.1lf MB", result);
}
