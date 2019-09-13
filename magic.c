#include<stdio.h>

void readMatrix (int n, int x[n]){
	for(int i = 0; i<n; i++){
		scanf("%d", &x[i]);
	}
}

void copyMatrix (int n, int x[n], int y[n]){
	for(int i = 0; i < n; i++){
		y[i] = x[i];
	}
}

void printMatrix(int n, int x[n]){
	for(int i = 0; i < n; i++){
		printf("%d", x[i]);
		if(i < (n-1)) printf(" ");
		else printf("\n");
	}
}

void magic(int n, int i, int x[n], int y[n]){
	copyMatrix(n, x, y);
	for(int j = i+1; j<n; j++){
		y[j] = x[j] - x[j-1];
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int x[n];
	int y[n];
	readMatrix(n, x);
	copyMatrix(n, x, y);
	for(int i = 0; i < n; i++) {
		if (i%2 == 1) magic(n, i, x, y);
		else magic(n, i, y, x);
	}
	printMatrix(n, x);
}
