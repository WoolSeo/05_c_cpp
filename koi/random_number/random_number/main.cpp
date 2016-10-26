// 수열 속 보물 찾기 - 큰버전

#include <cstdio>
int n, k, i, j, tmp;
int sum=0;
int cnt=0;

int main() {
    scanf("%d %d\n", &n, &k);
    
    
    for(i=0; i<n;i++) {
        scanf("%d", &tmp);
        if(tmp<15) {
            
            sum += tmp;
            printf("%d :: %d\n", i, sum);
            
            if(sum == k) {
                cnt++;
                sum = 0;
            }
            else if(sum >= k) {
                sum = 0;
            }
            
        }
        //printf("endend\n\n\n");
    }
    
    printf("%d", cnt);
}
