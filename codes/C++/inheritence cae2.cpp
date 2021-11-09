#include<iostream>
#include<string>
using namespace std;

class Student{
	public:
		int roll_no;
		string name;
	Student(int roll,string Name){
		roll_no = roll;
		name = Name;
	}
};
class Fees : public Student{
	public:
		int fees;
		void submit(int fee)fees=fee;
		void reciept(){
			cout << "Roll no : " <<roll_no <<endl;
			cout << "Name : " <<name <<endl;
			cout << "Fees Paid : " <<fees <<endl;
		}
};
class Result :public Student, public Fees{
	int marks;
	void print(){
		cout<<"Student roll no : "<< roll_no<<endl;
		cout<<"Student name : "<< name<<endl;
		cout<<"Student name : "<< Fees<<endl;
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


int main(){
	Result s1(44,"Anand");
	s1.submit(500);
	s1.print();
	s1.grade();
	return 0;
}