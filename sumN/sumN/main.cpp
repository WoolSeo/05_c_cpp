#include <stdio.h>

int n;

int f(int n) {
    if(n <=1) return 1;
    return f(n/2)*f(n/2);
}

int g(int n) {
    if(n <=1) return 1;
    return g(n-1)+n;
}

int main(){
    scanf("%d", &n);
    printf("%d",g(n));
    return 0;
}
