#include<iostream>
using namespace std;
class employee{
private:
	string firstname;
	string lastname;
	int sal;
public:
	void setter(string name,string lname,int bsal){
		firstname=name;
		lastname=lname;
		if (bsal<0){
		
		sal=0;}
		else 
		sal=bsal;
	}
	 string getnme()
	{ 
	return firstname;
	}
	string getlnme()
	{
		return lastname;
	}
	int getsalary(){
		return sal;
	}
	void displayinfo(string name,string lname,int bsal)
	{
		cout<<"first name:"<<firstname;
		cout<<"\nLast name:"<<lastname;
		cout<<"\n salary:"<<sal;
		
	}
	int raise(int sal){
		sal=sal+(sal*0.1);
		return sal;
	}
};
int main()
{
	employee emp1;
	employee emp2;
      string name;
	string lname;
	int bs,bs1;
	cout<<"enter employee  1 info";
	cin>>name>>lname>>bs;
	emp1.setter(name,lname,bs);
	cout<<"enter employee 2 info";
	cin>>name>>lname>>bs1;
	emp2.setter(name,lname,bs1);
	cout<<"employee one info:\n";
	emp1.displayinfo(name,lname,bs);
	cout<<"\nemployee 2 info:\n";
	emp2.displayinfo(name,lname,bs1);
    cout<<"employee 1 raise="<<emp1.raise(bs);
    cout<<"\nemployee 2 raise="<<emp2.raise(bs1);
}
