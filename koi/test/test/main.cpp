#include <cstdio>
#include <cstdlib>
#include <ctime>


#define MAX 50
long long int j=1;
long long int a[100000] = {};
long long int i;

long long int n;
int main()
{
    
    srand((int)time(NULL));
    
 
    for (i=0; i < 500; i++) {
        printf("%lld ", rand()%1000);
    }

    /*printf("DONE");
    scanf("%lld", &n);
    printf("YEAH");

    for(i=0;i<n;i++)
    {
        scanf("%lld", &a[i]);
        printf("currently printed %lld\n",a[i]);
    }
    for(i=0;i<n;i++)
        printf("%lld : %lld\n", i, a[i]);*/
}
