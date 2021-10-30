#include<iostream>
#include<string>
using namespace std;

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

class car
{
private:
    string model;
public:
	void setModel(string imodel){
		model=imodel;
	}
    string getModel(){
        return model;
    }
};

class audi :public car, public company {
    private:
    int weight;
    public:
    audi(string iname,string imodel, int iweight){
        setName(iname);
        setModel(imodel);
        weight=iweight;
    }


    int getWeight(){
        return weight;
    }
};

int main(){
    audi R8("audi","R8",1500);
	string name=R8.getName();
    string model=R8.getModel();
    int weight=R8.getWeight();
    
    cout<<"model "<<model<<endl;
    cout<<"name "<<name<<endl;
    cout<<"weight "<<weight<<endl;
	cout<<"car :- "<<name<<" "<<model<<" "<<weight<<endl;
    return 0;
}
