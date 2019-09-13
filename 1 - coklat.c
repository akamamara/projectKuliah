#include<stdio.h>
#include<math.h>
 
int main(){
    unsigned long long int n;
    double sn;
    scanf("%llu", &n);
    
    sn = sqrt(2.0*n+0.25)-(0.5);
    
    printf("%.0lf\n", floor(sn)+1);
    return 0;
}
