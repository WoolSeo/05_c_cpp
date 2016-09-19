#include <stdio.h>
#include <map>
using namespace std;
int n, memo[50];
map<int, int> memo2;

int f(int x)
{
    if( x <= 2 ) return x;
    if( memo[x] != 0 ) return memo[x];
    return memo[x] = f(x-1) + f(x-2);
}

int g(int x)
{
    if( x <= 1 ) return 1;
    if( memo2[x] != 0 ) return memo2[x];
    if( x%2==0 ) return memo2[x] = g(x/2)*g(x/2) + g(x/2-1)*g(x/2-1);
    return memo2[x] = g(x/2)*g(x/2+1) + g(x/2)*g(x/2-1);
}

int main()
{
    scanf("%d", &n);
    printf("%d", g(n));
    return 0;
}