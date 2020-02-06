/**
 *Takes ina  number of trains and the order they are in currently
 * Ie:
 * 4
 * 1324
 *
 * find the shortest number of switches needed to put them in ascending order
 * can :only swap adjacent trains
 **/
#include <stdio.h>
#include <stdlib.h>


int findShortSwap(char* inptln, char* seq[]);

int main(int argc, char* argv[]){
	if(argc < 3){
		printf("not enough args");
		exit(0);
	}
	int answer = findShortSwap(argv[1], argv);
	printf("Optimal train swapping takes %d swaps\n", answer);
	return 0;
}

/**
 *Takes in the number of cars and the sequence, turns it into an int array and does a bubble sort while counting each swap
 **/
int findShortSwap(char* inptln, char* seq[]){
	int i;
	int size = atoi(inptln);
	int positions [size];
	for(i = 2;i<size+2;i++){
		int x = atoi(seq[i]);
		positions[i-2] = x;
	}
	int x;
	int y;
	int swaps = 0;
	for(x= 0;x<size-1;x++){
		for(y= 0;y<size-x-1;y++){
			if(positions[y] > positions[y+1]){
				int temp=positions[y];
				positions[y] = positions[y+1];
				positions[y+1] = temp;
				swaps++;
			}
		}
	}
	return swaps;
}
