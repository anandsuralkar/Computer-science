#include <iostream>
#include <string>
using namespace std;
int counter(string binary, int n)
{
    int count = 0;
    int i = 0;
    //looping through the given string
    while (i < n){
    	//if starting character in substring is 0
    	if(binary[i] == '0'){
	    	int zeros = 0 ; int ones = 0;int k=0;
	    	
	    	//count 0s
	    	while(binary[i+k] == '0'){
	    		zeros++;
	    		k++;
			}
			
			//count 1s
			while(binary[i+k] == '1' && k<2 * zeros){
	    		ones++;
	    		k++;
			}
			if(ones == zeros)count++;
		}
		//if starting character in substring is 1
		else if(binary[i] == '1'){
	    	int zeros = 0;int ones = 0;int k=0;
	    	
	    	//count 1s
	    	while(binary[i+k] == '1'){
	    		ones++;
	    		k++;
			}
			//count 0s
			while(binary[i+k] == '0' && k<2 * ones){
	    		zeros++;
	    		k++;
			}
			//increament count by 1 if number of zeros equal to number of 1s
			if(ones == zeros)count++;
		}
        i++;
    }
    return count;
}
int main(){
	string binary;
	cout << "Enter the string of binary (0,1) characters"<<endl;
	cin >> binary;
	
    cout << "count is " << counter(binary, binary.size());
    return 0;
}
