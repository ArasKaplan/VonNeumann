#include <stdio.h>
#include <stdlib.h>
#include <math.h>


	void changer(int i,int mid,int **matrix){
			int j;
			for(j=0;j<2*mid+1;j++){
				if(j>mid-i && j<mid+i){
					matrix[i][j]=1;
					matrix[2*mid-i][j]=1;	
		}
	}
}
	void func(int i,int mid,int **matrix){
		changer(i,mid,matrix);

		if(i==mid)
		return;

		func(i+1,mid,matrix);		
	}
	
	void init_func(int n,int **matrix){
		int mid=(2*n+3)/2;
		int i=0;
		func(i,mid,matrix);
	}



int main(){
	int n;
	int Satir_siyah=0;
	printf("N degeri giriniz:");
	scanf("%d",&n);
	
	int **matrix;										//matrisin satýr ve sütun büyüklüðü için formül 2*n+3
	matrix=(int**)malloc(sizeof(int*)*(2*n+3));			//matris init
	int i;
	for(i=0;i<(2*n+3);i++){
		matrix[i]=(int*)malloc(sizeof(int)*(2*n+3));
	}	
	int j;
	for(i=0;i<(2*n+3);i++){								//matrisin içi 0lanýr
		for(j=0;j<(2*n+3);j++){
			matrix[i][j]=0;
		}
	}
	
	
	
	printf("\n");
	init_func(n,matrix);
	for(i=0;i<(2*n+3);i++){
		for(j=0;j<2*n+3;j++)
		printf("%2d",matrix[i][j]);
		printf("\n");
	}
	return 0;
	
	}
