#include <stdio.h>

int main(int argc, char* argv[]){
	int n;
	scanf("%d", &n);
	int i,j,k,x;
	int count = 0;
	for(i=0;i<=n/50;i++){
		for(j=0;j<=(n-50*i)/25;j++){
			for(k=0;k<=(n-50*i - 25*j)/10;k++){
				for(x=0;x<=(n-50*i-25*j-10*k)/5;x++){
					if(50*i + 25*j + 10*k + 5*x <= n)
						count++;
				}
			}
		}
	}	
	printf("%d", count);
}
