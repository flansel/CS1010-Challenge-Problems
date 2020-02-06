#include <stdio.h>
#include <stdbool.h>

bool isSafe(double bounds[5][3]);

/**
 * scan for the number of tests, then for all the test data at once.
 * take in the data to a 3d array SET->LINE->A,B and C
 * sends each set to be tested for safety
 **/
int main(int argc, char* argv[]){
	int sets;
	printf("Enter number of sets\n");
	scanf("%d",&sets);
	printf("Enter all the data\n");
	double allData[sets][5][3];
	int i,j,k;
	for(i=0;i<sets;i++)
		for(j=0;j<5;j++)
			for(k=0;k<3;k++)
				if(j != 4 || k != 2)
					scanf("%lf",&allData[i][j][k]);
	
	for(i=0;i<sets;i++){
		if(isSafe(allData[i]))
			printf("SAFE\n");
		else
			printf("UNSAFE\n");
	}
	return 0;
}

/**
 * takes in a single set of data
 * tests it against all of the constraints
 * return true if safe, false is not safe
 **/
bool isSafe(double bounds[5][3]){
	double temp = bounds[4][0];
	double volts = bounds[4][1];
	if(bounds[0][0]*temp+bounds[0][1]*volts >= bounds[0][2])
		if(bounds[1][0]*temp+bounds[1][1]*volts >= bounds[1][2])
			if(bounds[2][0]*temp+bounds[2][1]*volts <= bounds[2][2])
				if(bounds[3][0]*temp+bounds[3][1]*volts <= bounds[3][2])
					return true;
	return false;
}
