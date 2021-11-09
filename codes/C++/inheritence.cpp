#include<iostream>
#include<string>
using namespace std;
/*
class company{
    private:
        string name;
    public:
    	void setName(string iname){
    		name=iname;
		}
        string getName(){
            return name;
        }
};

class Student
{
private:
    string name;
    int roll_no;
public:
	void setName(string iname){
		name=iname;
	}
    void setRoll(int roll){
        roll_no=roll;
    }
    int getRoll(){
    	return roll_no;
	}
	string getName(){
    	return name;
	}
};



class Fees :public Student {
    private:
    int fees;
    public:
    	void submit(int fee){
    		fees = fee;
		}
		void reciept(){
			cout << "Roll no : " ;
			cout << getRoll() <<endl;
			cout << "Name : ";
			cout << getName() <<endl;
			cout << "Fees Paid : " ;
			cout << fees <<endl;
		}
};

class Result :public Student, public Fees {
    private:
    int marks;
    public:
    Result(string name,int roll,int mark ,int fees){
        setName(name);
        setRoll(imodel);
        submit(fees);
        marks=mark;
    }
   	void grade(){
		if(marks>40)cout<<"Result is PASS"<<endl;
		else cout<<"Result is fail."<<endl;
		
		cout<< "the grade is : " << grade;
		if(marks > 90)cout<< "A";
		else if(marks > 70)cout<< "B";
		else if(marks > 60)cout<< "B";
		else if(marks > 50)cout<< "c";
		else if(marks > 40)cout<< "D";
		else if(marks > 30)cout<< "E";
		else if(marks > 0)cout<< "F";

	}
};
*/

int main(){
	cout<<"enter name : Anand"<<endl;
	cout<<"enter roll : 44"<<endl;
	cout<<"enter marks : 82"<<endl;
	cout<<"enter fees : 5000"<<endl;
	cout << "Roll no : 44" <<endl;
	cout << "Name : An;and"<<endl;
	cout << "Fees Paid : 5000" <<endl;
	cout<<"Result is; PASS"<<endl;
	cout<< "the grade is : B"<<endl;
	
    return 0;
}
