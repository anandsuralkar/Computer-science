#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct student{
	int rollno,phone;
	string name;
	
};

void student(int rollno,int phone,string name,struct student* arr,int i){
	char st;
	st=static_cast<char>(i);
	struct student* new_student = (struct student*) malloc(sizeof(struct student));
	new_student->name=name;
	new_student->phone=phone;
	new_student->rollno=rollno;
	arr[i]=*new_student;
}
void display(struct student* arr){
	for(int i=0;i<sizeof(arr)/sizeof (arr[0]);i++){
		cout<<arr[i].rollno<<endl;
		cout<<arr[i].name<<endl;
		cout<<arr[i].phone<<endl;
	}
	
}
int main(){
	int i=0;
	struct student* arr[5];
	student(20,8868868861,"anand",*arr,0);
	student(21,9090909090,"amit",*arr,1);
	student(22,8080808080,"sandeep",*arr,2);
	student(23,8868868861,"lokesh",*arr,3);
	student(24,9876543210,"rajesh",*arr,4);
	
	display(*arr);
	return 0;
}
