#include<stdio.h>

int main(){
	int n;
	scanf("%d",n);
	int ar[n];
	for (int j=0;j<n;j++){
		scanf("%d",ar[n]);
	}
	
	int count = 0, majorityElement;
    for (int i = 0; i < n; i++) {
        if (count == 0){
		
            majorityElement = ar[i];
        }
        if (ar[i] == majorityElement){
        	
            count++;
        }
        else{
		
            count--;
        }
    }
    count = 0;
    for (int k = 0; k < n; k++){
	
        if (ar[k] == majorityElement){
		
            count++;
        }
    }
    if (count > n/2){
	
        return majorityElement;
    	printf("NO Majority Element");
    }
    return 0;
}
    
