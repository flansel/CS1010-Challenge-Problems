#include <stdio.h>
#include <stdlib.h>


void arrSort(int* arr, int number, int dim);

int main(int argc, char* argv[]){
	int number;
	int dim;
	printf("enter Number of boxes and the demensions\n");
	scanf("%d %d", &number, &dim);
	int box [number][dim];
	int i,j;
  	for(i = 0; i < number; i++){
		printf("enter box %d\n", i+1);
    	for(j = 0; j < dim; j++){
       		scanf("%d", &(box[i][j]));
    	}
  	}
	arrSort(&box[0][0],number,dim);
	return 0;
}

void arrSort(int* arr, int number, int dim){
	int i,j;
	for(i = 0;i<number;i++){
		for(j = 0;j<dim-1;j++){
			if(*((arr+i*dim) + j) > *((arr+i*dim) +j+1)){
				int temp = *((arr+i*dim) + j);
				int* p1 = ((arr+i*dim)+j);
				int* p2 = ((arr+i*dim)+j+1);
				*p1  = *((arr+i*dim) + j+1);
				*p2  = temp;
			}
		}
	}

	for(i = 0;i<number;i++){
		for(j = 0;j<dim;j++){
			printf("%d ", *((arr + i*dim)+j));
		}
		printf("\n");
	}
}
