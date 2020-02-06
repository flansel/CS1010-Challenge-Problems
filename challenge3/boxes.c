/*
 * First dort each of the boxes for easy compare
 * then create a graph where each box is a vertex and if two boxes go together than they are connected by an edge
 * find the longest path created by the graph (recursive)??
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isIn(int a, int compare[], int n);
void arrSort(int* arr, int n, int d);
int findLongest(int* paths, int n, int* longest, int start);
int searchForSub(int* paths, int n, int index);
int goesIn(int a1 [], int a2 [],int  d);

int main(int argc, char* argv[]){
	int number;
	int dim;
	scanf("%d %d", &number, &dim);
	int box [number][dim];
	int i,j;
  	for(i = 0; i < number; i++){
    	for(j = 0; j < dim; j++){
       		scanf("%d", &(box[i][j]));
    	}
  	}
	arrSort(&box[0][0],number,dim);
	int paths[number][number];
	for(i=0;i<number;i++){
		for(j = 0;j<number;j++){
			paths[i][j] = -1;
		}
	}
	for(i=0;i<number;i++){
		int n = 0;
		for(j = 0;j<number;j++){
			if(goesIn(box[i],box[j],dim)){
				paths[i][n] = j;
				n++;
			}
		}
	}
	int longPT[number];
	int longPTln = 0;
	int longReal[number];
	int longRealln = 0;
	for(i = 0;i<number;i++){
		longPTln  = findLongest(&paths[0][0],number,&longPT[0], i);
		if(longPTln > longRealln){
			memcpy(longReal, longPT,number*sizeof(int));
			longRealln = longPTln;
		}
	}/*
	for(i=0;i<number;i++){
		printf("%d", longReal[i]);
	}*/
	return 0;
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

int findLongest(int* paths, int n, int* longest, int start){
	int newArr[n][n];
	memcpy(newArr, paths, n*n*sizeof(int));
	int lc = 1;
	int next;
	*(longest) = start;
	printf("%d ", *(longest));
	if(newArr[start][0] != -1){
		while(true){
			next = searchForSub(paths,n,start);
			if(next == -1){
				*(longest+lc*sizeof(int)) = newArr[start][0];
				printf("%d\n", newArr[start][0]);
				break;
			}
			start = next;
			*(longest+lc*sizeof(int)) = next;
			printf("%d ", next);
			lc++;	
		}
	}
	return lc;
}

int searchForSub(int* paths,int n, int index){
	int newArr[n][n];
	memcpy(newArr, paths, n*n*sizeof(int));
	int compareTo [n];
	memcpy(compareTo, newArr[index],n*sizeof(int));
	int foundIndex = -1;
	int maxInCommon = 0;
	int i,j;
	for(i=0;i<n;i++){
		int inCommon = 0;
		for(j = 0;j<n;j++){
			if(newArr[i][j] == -1||!isIn(i,compareTo,n)){
				if(inCommon > maxInCommon){
					maxInCommon = inCommon;
					foundIndex = i;
					break;
				}
			}else{
				if(isIn(newArr[i][j], compareTo, n)){
					inCommon++;
				}
			}
		}
	}
	return foundIndex;
}

bool isIn(int a, int compare[], int n){
	int i,j;
	for(i = 0;i<n;i++){
		if(compare[i] == a){
			return true;
		}
	}
	return false;
}

int goesIn(int a1 [], int a2 [],int  dim){
	int i;
	for(i = 0;i<dim;i++){
		if(a1[i] <= a2[i]){
			return false;
		}
	}
	return true;
}












