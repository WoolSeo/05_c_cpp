// 수열 속 보물 찾기 - 큰버전

#include <cstdio>
 int n, k, i, j, tmp;
 int sum=0;
 int cnt=0;
 int a[100000] = {};
 
 int main() {
     scanf("%d %d\n", &n, &k);
 
 
 
     for(i=0;i<n;i++)
         scanf("%d", &a[i]);
 
 
     for(i=0; i<n;i++) {
         for( j=i ; (sum < k && j < n); j++) {
             sum += a[j];
             //printf("%d : %d : %d\n", i, j, sum);
        }
         if(sum == k) {
             cnt++;
             sum = 0;
         }
         else {
             sum = 0;
         }
         //printf("endend\n\n\n");
     }
 
     printf("%d", cnt);
}

// 수열 속 보물 찾기 - 작은 버전

/*#include <cstdio>
int n, k, i, j, tmp;
int sum=0;
int cnt=0;
int a[100000] = {};

int main() {
    scanf("%d %d\n", &n, &k);
    
    
    
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    
 
    for(i=0; i<n;i++) {
        for( j=i ; (sum < k && j < n); j++) {
            sum += a[j];
            //printf("%d : %d : %d\n", i, j, sum);
        }
        if(sum == k) {
            cnt++;
            sum = 0;
        }
        else {
            sum = 0;
        }
        //printf("endend\n\n\n");
    }

    printf("%d", cnt);
}*/

/*
20 10
1 2 3 5 3 2 4 6 8 39 3 4 2 4 6 3 4 5 7 2
 5
 */


// 난수 만들기

//소 문제 ver2
/*#include <cstdio>

long long int n, i, tmp, tmp_p;
long long int sum;
long long int cnt;

int main() {
    scanf("%lld", &n);
    
    scanf("%lld", &tmp_p);
    cnt = 0;
    
    for(i = 1; i<n; i++) {
        scanf("%lld", &tmp);
        
        if(tmp >= tmp_p) {
            sum += cnt * (cnt+1) /2;
            //printf("%lld : %lld\n", tmp, sum);
            cnt = 0;
        }
        else {
            cnt++;
        }
        tmp_p = tmp;
    }
    
    sum += cnt * (cnt+1) /2;
    
    printf("%lld", sum);
}*/


//소 문제
/*#include <cstdio>

int n;
int a[80000]={};
int sum=0;
int cnt=0;
int i, j;
bool chk=0;

int max, max_p, max_pp;

int main() {
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    
    //for(int i=0;i<n;i++)
    //    printf("%d %d\n", i , a[i]);\
    
    if(a[0]>a[1])
        cnt++;
    
    for(i=0;i<(n-1);i++) {
        if(max <= a[i]) {
            max = a[i];
            max_p = i;
            printf("%d %d\n", max , max_p);
            chk = 1;
            cnt = cnt + max_p - max_pp;
            max_pp = max_p;
        }
        
        //if(chk ==1) {
            
        //    chk = 0;
        //}
        
    }
    
    
    for(i=0;i<(n-1);i++) {
        j=i+1;
        if(a[i] > a[j]) {
            while( (a[i]>a[j]) && j<n ) {
                j++;
            }
        }
        //printf("%d %d\n", i, sum);
        cnt = cnt + j-(i+1);
        j = 0;
        
    }
    printf("%d", cnt);
}*/
/*
 10
 1
 34
 23
 43
 52
 34
 52
 12
 1
 23 
 => 6
20
120
231
21
234
345
43
23
34
546
232
23
234
123
446
563
234
453
234
664
342
 =>18
 */

//부분합 - 완성본
/*#include <cstdio>
long long int n, i, tmp;
long long int sum_plus=0, sum_minus=0;
long long int max=0, minus_max = -1001;
long long int cnt=0;
long long int a[100000] = {};

int main() {
    scanf("%lld\n", &n);
    
    for(i=0;i<n;i++)
        scanf("%lld", &a[i]);
    
    //for(i=0;i<n;i++)
      //  printf("%lld : %lld\n", i, a[i]);
    
    for(i = 0; i<n; i++) {
        //scanf("%lld", &tmp);
        
        if(a[i] >= 0) {
            if(sum_plus < sum_minus) {
                sum_plus = 0;
                sum_minus = 0;
            }
            sum_plus -= sum_minus;
            sum_plus += a[i];
            sum_minus = 0;
            
            if(sum_plus > max) {
                max = sum_plus;
            }
            cnt++;
        }
        else {
            sum_minus = sum_minus - a[i];
            if( a[i] > minus_max) {
                minus_max = a[i];
            }
        }
        //printf("%lld\n", i);
    }
    
    if( cnt == 0) {
        printf("%lld", minus_max);
    }
    else
        printf("%lld", max);
}*/


/*#include <cstdio>

int n;
int a[100000] = {};
long long int sum;
long long int max;

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    
    //for(int i=1;i<=n;i++)
    //    printf("%d\n", a[i]);
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++) {
            sum += a[j];
        }
        if (sum >= max)
            max = sum;
        sum = 0;
    }
    printf("%lld", max);
}*/

//삼각형 화단 만들기
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
}*/


//약수의 갯수가 짝수인 수
/*#include <cstdio>
#include <cmath>

int a, b;
double tmp;
int cnt=0;
int i, j;

int main() {
    scanf("%d %d", &a, &b);
    
    
    if(a == 1) {
        cnt++;
    }
    
    
    for(i=2;tmp<=b;i++) {
        tmp = i*i;
        if(tmp >= a && tmp <=b)
            cnt++;
    }
    //cnt--;
    
    printf("%d", b-a+1-cnt);
    
}*/

//사각형 겹침 문제
/*#include <cstdio>


int a[1][8];
//int a, b, c, d;
//int x, y, p, q;
int o, p, q, r, s, t;
char result[1];

int main() {
    //for(int i=0;i<1;i++)
    for(int j=0;j<8;j++)
        scanf("%d", &a[0][j]);
    
    for(int i=0; i<1;i++) {
        o = (a[i][0]-a[i][4])*(a[i][0]-a[i][6]);
        p = (a[i][2]-a[i][4])*(a[i][2]-a[i][6]);
        q = (a[i][0]-a[i][6])*(a[i][2]-a[i][4]);
        
        r = (a[i][1]-a[i][5])*(a[i][1]-a[i][7]);
        s = (a[i][3]-a[i][5])*(a[i][3]-a[i][7]);
        t = (a[i][1]-a[i][7])*(a[i][3]-a[i][5]);
        
        //none 일 경우
        if( (o>0 && p>0) || (r>0 && s>0) ) {
            if( q<0 && t<0 ) {
                printf("rectangle\n");
            }
            else if(q>0 || t>0) {
                printf("none\n");
            }
            else {
                printf("line\n");
            }
            
        }
        
        //point
        else if( (a[i][2]==a[i][4] && (a[i][3]==a[i][5] || a[i][1]==a[i][7]) )|| ( a[i][0]==a[i][6] && (a[i][3]==a[i][5] || a[i][1]==a[i][7]) ) ) {
            printf("point\n");
        }
        
        //line
        
        
        else if(a[i][2] == a[i][4] || a[i][0]==a[i][6] || a[i][3] == a[i][5] || a[i][1]==a[i][7]  ) {
            printf("line\n");
        }
        
        
        else
            printf("rectangle\n");
    }
}*/


//사각형 겹침 문제
/*#include <cstdio>

int a, b, c, d;
int x, y, p, q;

int main() {
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &x, &y, &p, &q);
    
    //none 일 경우
    if( (a>p || c<x) || (b>q || d<y)) {
        printf("d");
    }
    
    else if( (c==x && (d==y || b==q) )|| ( a==p && (d==y || b==q) ) ) {
        printf("c");
    }
    else if( (a==x || c==x) || (a==p || c==p) || (b ==y || d==y) || (b == q || d == q) ){
        printf("b");
    }
    else
        printf("a");
}
*/

//숫자 반대로 거꾸로 출력
/*#include <cstdio>

int n;
int power=10000;
int a[5]={};
int k=1, chk=0;

int main() {
    scanf("%d", &n);
    
    for(int i=0;i<5;i++){
        if( n >= k)
            chk++;
        k=k*10;
    }
    
    for(int i=4;i>=0;i--) {
        a[i]= n / power;

        if(a[i] == 0) {
        }
        else {
            n = n-a[i]*power;
        }
        
        power = power/10;
    }
    for(int i=0;i<chk;i++) {
        //if(a[i]!=0)
        printf("%d",a[i]);
    }
    //printf("%d", chk);
    
    
}*/

//삼각형 종류 찾기
/*#include <cstdio>

int a, b, c;

int main() {
    scanf("%d %d %d", &a, &b, &c);
    
    if(a > b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    if(b > c) {
        b = b+c;
        c = b-c;
        b = b-c;
    }
    if(a > b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    
    if(a+b <= c) {
        printf("Not");
    }
    else if( a==b & b==c) {
        printf("Regular");
    }
    else if( (a*a + b*b) == c*c) {
        printf("Right");
    }
    else if( a==b || b==c || c==a) {
        printf("Isosceles");
    }
    else {
        printf("Normal");
    }
    
}*/


//암호화
/*#include <cstdio>

int n;
char a[8];

int main() {
    scanf("%d\n", &n);
    
    for (int i=0; i<8; i++) {
        scanf("%c", &a[i]);
    }
    //printf("\n");
    for (int i=0; i<8; i++) {
        printf("%c", a[i]+n);
    }
}*/


/*
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
}*/

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
