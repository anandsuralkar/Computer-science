#include<iostream>
using namespace std;

int max(int* arr,int n){
	int temp;
	for(int i=0;i<n-1;i++){
//		cout<<"loop1 \n";
		for(int j=0;j<n-i-1;j++){
//			cout<<"loop2 \n";
			if(arr[j]<arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
			
		}
		
	}
	
	return arr[0]*arr[1];
}

int main(){
	int i=0,n;
	
	while(1){
		cout<<"\n";
		cin>>n;
		int arr[n];
	
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<"\n"<<max(arr,n);
}
	return 0;
}
