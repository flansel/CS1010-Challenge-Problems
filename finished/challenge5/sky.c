#include <stdio.h>
#include <stdlib.h>
/*
 * get the range 0-->28 in this case(0->largest value in buildings[i][2]+1)
 * start x = 0;
 * xcount = 0 -> the number of times the height is the same meaning we are moving horizontally
 * look through the array for all buildings that contain the x value 1
 * while keeping track of the tallest(set to 0 to start so if none are found then it is a height of 0)
 * if the tallest is different from the current height then record the xcount, and the new tallest height xcount=0
 * otherwise xcount++;
 * 
 */
int findTallest(int xcoord, int currentHeight, short[][3], int size);
int findRange(short coords[][3], int size);

int main(int argc, char* argv[]){
	short buildings[5000][3];
	int size = 0;
	
	while(scanf("%hd",&buildings[size][0])!=EOF){
		scanf("%hd", &buildings[size][1]);
		scanf("%hd", &buildings[size][2]);
		size++;
	
	}

	int range = findRange(buildings, size);
	int ypos = 0;
	int x;
	for(x=0;x<=range;x++){
		int tallest = findTallest(x, ypos, buildings, size);
		if(tallest != ypos){
			ypos = tallest;
			printf("%d %d ", x, ypos); 
		}
	}		
	return 0;			
}

int findTallest(int xcoord, int currentHeight,short coords[][3], int size){
	int i;
	int tallest = 0;
	for(i=0;i<size;i++){
		if(coords[i][0] >xcoord){
			break;
		}
		if(xcoord >= coords[i][0] && xcoord < coords[i][2]){
			if(coords[i][1] > tallest){
				tallest = coords[i][1];
			}
		}
	}
	return tallest;
}

int findRange(short coords[][3], int size){
	int i;
	int furthestX = 0;
	for(i=0;i<size;i++){
		if(coords[i][2] > furthestX){
			furthestX = coords[i][2];
		}
	}
	return furthestX;
}
