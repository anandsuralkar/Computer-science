#include<iostream>
using namespace std;
int max(){
	int n,maxtype=1;
	for(int i=0;i<n;i++){
		int type,typecur=1,count=0,max;
		cin>>type;
		if(type==typecur){
			count++;
		}
		else
		{
			typecur=type;
			count=0;
			if(max<count){
				max=count;
				maxtype=typecur;
			}else if(max==count){
				max=count;
				if(maxtype>typecur){
					maxtype=typecur;
				}
			}
		}
		
	}
	cout<< maxtype;
	return 0;
}


int main(){
	int T;
	cin>>T;
	for (int i=0;i<T;i++){
		max();
	}
	return 0;
	}
