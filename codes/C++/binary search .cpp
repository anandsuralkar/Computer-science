#include<iostream>
using namespace std;

int search(int *arr,int n,int m,int num){
    int mid = n/2;
    if(num==arr[mid])return 1;
    else if(num < arr[mid]){
        search(arr,0,mid,num);
    else{
        search(arr,mid,2*mid-1);
        }
    }
    return 0;
}
int main(){
    arr = {1,3,5,6,8,9}
    int n = 6; //size of array
    int num = 8; //Number to find in array
    if(search(arr,n,num))cout<<"Number found";
    else{
        cout<<"number not found";
    }
    return 0;
}