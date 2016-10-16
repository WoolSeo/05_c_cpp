#include <cstdio>

int a, b;

int result;

int cnt;

int main() {
    scanf("%d %d", &a, &b);
    
    if(a > b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }

    
    for(int i = a; i>=1; i--) {
        if( a%i == 0 && b%i == 0) {
            result = i;
            i = 0;
        }
    }
    printf("%d", result);
}

//2x2x2 cube solve
/*
#include <stdio.h>
#include <time.h>

#include <string>
#include <vector>
#include <queue>
#include <map>

int cnt = 0;

struct cube {char color[25]; std::vector<int> path;};
std::queue<cube> q;
std::map<std::string, int> m;

int trans[7][24]={         //90도 회전변환 관계, trans[1][]는 1번 회전
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23, //기본 상태(사용안함)
    0,9,2,11,4,5,6,7,8,21,10,23,14,12,15,13,3,17,1,19,20,18,22,16, //1번 변환 결과
    0,18,2,16,4,5,6,7,8,1,10,3,13,15,12,14,23,17,21,19,20,9,22,11, //2번...
    2,0,3,1,8,9,6,7,12,13,10,11,16,17,14,15,4,5,18,19,20,21,22,23, //3번...
    1,3,0,2,16,17,6,7,4,5,10,11,8,9,14,15,12,13,18,19,20,21,22,23, //4번...
    13,15,2,3,1,5,0,7,8,9,10,11,12,23,14,22,18,16,19,17,20,21,4,6, //5번...
    6,4,2,3,22,5,23,7,8,9,10,11,12,0,14,1,17,19,16,18,20,21,15,13  //6번...
};

cube turn(cube x, int n) {
    cube t;
    for(int i =0; i<24; i++)
        t.color[i]=x.color[trans[n][i]];
    t.path=x.path;
    t.path.push_back(n);
    return t;
}

bool check(cube x)
{
    for(int i=1; i<=4; i++)
        for(int t=i*4, j=1;j<=3; j++)
            if(x.color[t]!=x.color[t+j]) return 0;
    return 1;
}

void solove() {
    cube s, t;
    while(!q.empty()) {
        s=q.front();
        if(check(s)) {
            //printf("solved!->");
            for (int i=0; i<s.path.size(); i++) {
                //printf("%d", s.path[i]);
                cnt++;
            }
            //printf("\n");
            return;
        }
        else {
            q.pop();
            for(int i=1;i<=6;i++) {
                t=turn(s,i);
                if(m[t.color]!=1){
                    m[t.color]=1;
                    q.push(t);
                }
            }
        }
    }
}

int main() {
    cube t;
    //printf("color: ");
    for(int i=0;i<24;i++)
        scanf("%1c",&t.color[i]);
    
    //printf("strated...\n");
    q.push(t);
    m[t.color]=1;
    
    //clock_t st=clock();
    solove();
    //printf("%.2f(sec)\n",float(clock()-st)/CLOCKS_PER_SEC);
    printf("%d", cnt);
    return 0;
    
}


*/




//n진법
/*#include <cstdio>

int k, n;
int i;
char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


void f(int a, int b) {
    i = f(a/b, b);
    printf("%c", a[i]);
}

int main() {
    scanf("%d %d", &n, &k);

    f(n, k);
    
}*/



//Prob No.0082 : n번째 피보나치 수 구하기 [CH01.3.Training(Loop)]
/*#include <cstdio>

long long int n;
unsigned long long int a[300]={};

unsigned long long int f(long long int x) {
    
    if(x<=0)
        return 0;
    if(x==1)
        return 1;
    if(x==2)
        return 1;
    if(a[x] == 0)
        a[x] = (f(x-1)+f(x-2))%10009;
    return a[x];
}

int main() {
    scanf("%lld", &n);

    printf("%lld", f(n));
    
}*/

/*
//Prob No.007D : 3n+1 (기초) (NTTP) [CH01.3.Training(Loop)]
#include <cstdio>
long long int cnt=1;
long long int max_cnt=0;
long long int a, b;
long long int n, i;

int main(){
    scanf("%lld %lld", &a, &b);
    
    if(a > b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }

    while (i<=b) {
        n = i;
        if(n!=0) {
            while( n!=1) {
                //printf("%lld ", n);
                cnt++;
                if( n % 2 == 1) {
                    n = 3 * n + 1;
                }
                else {
                    n = n/2;
                }
            }
            //printf("%lld ", n);
            cnt++;
            if( a == b) {
                cnt--;
            }
            //printf("%lld ", cnt);
            if( cnt > max_cnt) {
                max_cnt = cnt;
            }
            cnt = 0;
            //printf("\n");
        }

        
        i++;
    }
    printf("%lld", max_cnt);

    
}

*/




//삼각형 큰거... 근데 더 큰게 있넹... ㅠㅠ
/*
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
*/

//삼각형문제(작은값)

/*#include <cstdio>
int a,b,c,n;
int at, bt;
long long int cnt;

int main()
{
    scanf("%d", &n);
    
    at = n/3;
    bt = n/2+1;
    
    for (a = 1; a <= at; a++) {
        for (b = bt; b > c; b--) {
            c = n - a - b;
            if( a<=c && a+c > b ) {
                //printf("%d %d %d\n", a, b, c);
                cnt++;
            }
        }
    }
    printf("%lld", cnt);
}
*/

/*
//2차방정식
#include <cstdio>
#include <cmath>

int a, b, c;
double dap;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    
    if( b*b - 4*a*c < 0)
        printf("none.");
    else if( b*b - 4*a*c == 0){
        dap = (-b) / 2.0 / a;
        printf("%g", dap);
    }
    else {
        dap = (-b + sqrt(b*b - 4*a*c) ) / 2.0 / a;
        printf("%g\n", dap);
        dap = (-b - sqrt(b*b - 4*a*c) ) / 2.0 / a;
        printf("%g", dap);
    }
}

//원 자르기
#include <stdio.h>

int a,b,c,d;
int t;
int cnt=0;

int main()
{
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    
    if(a > b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    if(c>d) {
        c = c+d;
        d = c-d;
        c = c-d;
    }
    
    if(a > d)
        printf("not cross");
    else if(b < c)
        printf("not cross");
    else if(a < c && b > d)
        printf("not cross");
    else if(a > c && b <d)
        printf("not cross");
    else
        printf("cross");
    return 0;
}*/
/*#include <cstdio>
 
 int n;
 int i,j, cnt=0;
 int sum = 0;
 
 int main(){
 scanf("%d", &n);
 
 for(i=2; i<=n; i++) {
 for(j=1; j<=i; j++) {
 if( i%j == 0) {
 cnt++;
 }
 }
 if(cnt == 2) {
 sum += i;
 }
 cnt =0;
 }
 
 printf("%d", sum);
 
 
 }*/

//70
/*
 #include <stdio.h>
 #include <cstdlib>
 
 int r,e,c;
 int t;
 int main() {
 scanf("%d %d %d", &r, &e, &c);
 t = abs(r-e);
 if( r > e && t > c)
 printf("do not advertise");
 else if( r < e && t > c)
 printf("advertise");
 else if( r == e || t <= c )
 printf("does not matter");
 else
 printf("does not matter");
 }*/

//1~10만이하의 자연수
//n 약수의 합을 구하시오.
/*
 9 1 3 9
 10 1 2 5 10
 16 1 2 4 8 16
 24 1 2 3 4 6 8 12 24 = 2 2 2 3
 28 1 2 4 7 14 28
 
 */
/*
 #include <stdio.h>
 #include <math.h>
 
 long long int a, sum = 0;
 long long int i=2;
 
 int main() {
 scanf("%lld", &a);
 
 
 for(i = 2; i*i <= a; i++) {
 if( i*i == a)
 sum += i;
 else if( a%i == 0) {
 sum += i + (a/i);
 }
 }
 
 if(a > 1)
 sum = sum + 1 + a;
 else
 sum = 1;
 printf("%lld", sum);
 }
 */
