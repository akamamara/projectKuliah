#include<stdio.h>

void readMatrix (int n, int m, int x[n][m]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &x[i][j]);
		}
	}
}

void printMatrix(int n, int m, int x[n][m]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d", x[i][j]);
			if(j < (m-1)) printf(" ");
			else printf("\n");
		}
	}
}

int main(){
	int row, col, p, q, sum, max;
	scanf("%d %d %d %d", &row, &col, &p, &q);
	
	int x[row][col];
	readMatrix(row, col, x);
	
//	printf("Matrix gua sekarang :\n");
//	printMatrix(row, col, x);
	
	for(int i = 0; i < row; i++){
		sum = 0;
		for(int j = 0; j < col; j++){
			for(int k = 0; k < p; k++){
				if(k+i==row) break;
				// printf("\nMatrix ke-%d, baris ke-%d\n", j+i, i);
				for(int l = 0; l < q; l++){
				if(l+j%col==col) {
//					printf("looping ke-%d, index gua sekarang : [%d][%d]\n", l, k+i, ((l%col)+j%col)%col);
					sum += x[k+i][(l+j%col)%col];
				}
				else {
//					printf("looping ke-%d, index gua sekarang : [%d][%d]\n", l, k+i, (l%col)+j%col);
					sum += x[k+i][l+j%col];
				}
//				printf("Sum sementara : %d\n", sum);
				}
			}
			if(i == 0) max = sum;
			else if(max < sum) max = sum;
//			printf("\nMax sekarang = %d\n", max);
			sum = 0;
		}
	}
	printf("%d\n", max);
}
