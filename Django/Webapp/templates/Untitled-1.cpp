#include <iostream>
#include <string>
using namespace std;
int counter(string binary, int n)
{
    int count = 0;
    int i = 0;
    cout << binary[i] <<endl;
    //looping through the given string
    while (i < n){
    	
    	
    	if(binary[i] == "0"){
	    	int zeros = 0 ; int ones = 0;int k=0;
	    	
	    	while(binary[i+k] == "0"){
	    		cout << "A";
	    		zeros++;
	    		k++;
			}
			k = 0;
			while(binary[i+k] == "1"){
				cout << "B";
	    		ones++;
	    		k++;
			}
			if(ones == zeros)count++;
		}
		else if(binary[i] == "1"){
	    	int zeros = 0;int ones = 0;int k=0;
	    	while(binary[i+k] == "1"){
	    		cout << "C";
	    		ones++;
	    		k++;
			}
			k = 0;
			while(binary[i+k] == "0"){
				cout << "D";
	    		zeros++;
	    		k++;
			}
			if(ones == zeros)count++;
		}
		
        i++;
    }
  	

    return count;
}
int main(){
	string binary;
	cout << "Enter the string of binary (0,1) characters";
	cin >> binary;
	
    cout << counter(binary, binary.size());
    return 0;
}