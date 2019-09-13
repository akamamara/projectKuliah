#include<stdio.h>
#include<math.h>

int main(){
	int n, k, max;
	scanf("%d", &n);
	int x[n];
	
	for(int j = 0; j<n; j++)
		scanf("%d", &x[j]);
	scanf("%d", &k);
	
	for(int i = 0; i <= n-k; i++){
		max = 0;
		for(int j = i; j < k+i; j++){
			if(x[j] >= max) max = x[j];
		}
		if(i == n-k) printf("%d\n", max);
		else printf("%d ", max);
	}
	return 0;
}

/*	
		if(i == 0) max = x[i];
		else{
			if(x[i] >= max) max = x[i];
		}
		
		if(i >= k - 1){
			printf("%d ", max);
		}
*/
