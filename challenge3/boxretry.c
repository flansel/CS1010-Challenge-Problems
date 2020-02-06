#include <stdio.h>
#include <stdlib.h>

void arrSort(int* arr, int n, int d);
int goesIn(int bigger [], int smaller [],int  d);
int maxdist(int* edges,int* box ,int* max,int size);
int notIn(int x, int* arr, int size);
int findmax(int* arr, int size);

int main(int argc, char* argv[]){
	//load in the data
	int number;
	int dim;
	scanf("%d %d", &number, &dim);
	int box [number][dim];
	int i,j,k,n;
  	for(i = 1; i < number; i++){
    	for(j = 0; j < dim; j++){
       		scanf("%d", &(box[i][j]));
    	}
  	}

	//sort the data
	arrSort(&box[0][0],number,dim);

	//find what goes into what
	int edges[number][number];
	for(i = 0;i<number;i++){
		for(j = 0;j<number;j++){
			edges[i][j] = -1;
		}
	}
	for(i = 0;i<number;i++){
		k = 0;
		for(j = 0;j<number;j++){
			if(goesIn(box[i], box[j],dim)){
				edges[i][k] = j;
				k++;	
			}
		}
	}
	for(i = 0;i<number;i++){
		printf("Goes into %d: ", i);
		for(j=0;j<number;j++){
			printf("%d", edges[i][j]);
		}
		printf("\n");
	}

	//find longest path
	int max[number];
	printf("%d", maxdist(box[3],&box[0][0],max,number));


	return 0;
}

int maxdist(int* edges,int* box,int* max,int size){
	static int layers = 1;
	int newedges[size];
	int i,j,k;
	if(edges[0] == -1){
		return findmax(max, size);
	}
	for(i=0;i<size;i++){
		max[i] = layers;
	}
	layers++;
	k = 0;
	for(i=0;i<size;i++){
		newedges[i] = -1;
	}
	for(i = 0;i<size;i++){
		if(edges[i] != -1){
			for(j = 0;j<size;j++){
				if(notIn(box[edges[i]],newedges, size)){
					newedges[k] = box[edges[i]];
					k++;
				}
			}
		}
	}
	maxdist(newedges,box,max,size);
}

int findmax(int* arr, int size){
	int currlargest = arr[0];
	int currindex = 0;
	int i;
	for(i = 0;i<size;i++){
		if(arr[i] > currlargest){
			currlargest = arr[i];
			currindex = i;
		}
	}
	return currindex;
}
int notIn(int x, int* arr, int size){
	int i;
	for(i = 0;i<size;i++){
		if(arr[i] == x)
			return 0;
	}
	return 1;
}

int goesIn(int bigger[], int smaller[], int d){
	int i;
	for(i = 0;i<d;i++){
		if(bigger[i] <= smaller[i]){
			return 0;
		}
	}
	return 1;
}

void arrSort(int* arr, int n, int d){
	int i,k,j;
	for(i = 0;i<n;i++)
		for(k = 0;k<d-1;k++)
			for(j = 0;j<d-k-1;j++)
				if(*((arr+i*d) + j) > *((arr+i*d) +j+1)){
					int temp = *((arr+i*d) + j);
					int* p1 = ((arr+i*d)+j);
					int* p2 = ((arr+i*d)+j+1);
					*p1  = *((arr+i*d) + j+1);
					*p2  = temp;
				}
}












