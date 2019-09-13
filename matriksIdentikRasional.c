#include<stdio.h>
#define N 100

void printMatrix(int n, int m, int x[N][N]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d", x[i][j]);
			if(j < (m-1)) printf(" ");
			else printf("\n");
		}
	}
}

void transposeMatrix(int n, int m, int x[N][N], int y[N][N]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			y[j][i] = x[i][j];
		}
	}	
}

void flipH(int n, int m, int x[N][N], int y[N][N]){
	for(int i=0; i < n; i++){
		for(int j=0; j<m; j++){
			y[i][m-j-1] = x[i][j];
		}
	}
}

void flipV(int n, int m, int x[N][N], int y[N][N]){
	for(int i=0; i < n; i++){
		for(int j=0; j<m; j++){
			y[n-i-1][j] = x[i][j];
		}
	}
}

void rotate(int r, int n, int m, int x[N][N], int y[N][N]){
	int temp[N][N];
	if(r == 0) printMatrix(n, m, x);
	if(r == 90) {
		transposeMatrix(n, m, x, temp);
		flipV(n, m, temp, y);
	}
	if(r == 180){
		rotate(90, n, m, x, temp);
		rotate(90, n, m, temp, y);
	}
	if(r == 270) {
		rotate(90, n, m, x, temp);
		rotate(90, n, m, temp, x);
		rotate(90, n, m, x, y);
	}
}

int main(){
	int x[N][N], y[N][N], n, r;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &x[i][j]);
		}
	}
	
	scanf("%d", &r);
	if(r == 0) rotate(0, n, n, x, y);
	if(r == 90) rotate(90, n, n, x, y);
	if(r == 270) rotate(270, n, n, x, y);
	if(r == 180) rotate(180, n, n, x, y);
	
	printMatrix(n, n, y);
}
