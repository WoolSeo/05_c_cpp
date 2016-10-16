#include <cstdio>
long long int a,b,c,n,half_n,third_n;
long long int cnt;

int main()
{
    scanf("%lld", &n);
    half_n = n/2;
    third_n = n/3;
    if( n<= 2)
        printf("%d", 0);
    else {
        if(n%2 == 0){
            cnt = 0;
            for (a = 2; a*2<=half_n ; a++) {
                cnt += (a/2);
            }
        }
        else {
            cnt = 1;
            for (a = 2; a*2<=half_n ; a++) {
                if(a%2==0)
                    cnt += (a/2);
                else
                    cnt += (a/2)+1;
            }
            
        }
        for(; a<=third_n; a++){
            cnt += (n-a)/2 -a+1;
        }
        printf("%lld", cnt);
    }
}
