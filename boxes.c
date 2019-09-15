#include <stdio.h>
#include <stdlib.h>


void arrSort(int* arr, int number, int dim);

int main(int argc, char* argv[]){
	int number;
	int dim;
	printf("enter Number of boxes and the demensions\n");
	scanf("%d %d", &number, &dim);
	int** box;
	int i,j;
	box = malloc(number * sizeof *box);
	for(i = 0;i<number;i++){
		box[i] = malloc(dim * sizeof *box[i]);
	}
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
	printf("%p", arr);
	for(i = 0; i < number; i++){
     	for(j = 0; j < dim; j++){
			printf("%p\n", (arr+(i*dim)+j));
     	}
     	printf("\n");
  	}
	for(i = 0;i<number;i++){
		for(j = 0;j<dim-1;j++){
			if(*((arr+i*dim) + j) > *((arr+i*dim) +j+1)){
				int temp = *((arr+i*dim) + j);
				*((arr+i*dim) + j) = *((arr+i*dim) + j+1);
				*((arr+i*dim) + j+1) = temp;
			}
		}
	}
}
