#include<iostream>
using namespace std;

class Employee
{
	protected:
		string name;
		string code;
	public:
		Employee(string n, string c): name(n),code(c)
		{		};
};

class Consultant : public Employee
{
	protected:
		int years;
	public:
		Consultant(string n, string c, int y): Employee(n,c), years(y)
		{		};	
};

class Manager : public Employee
{
	protected:
		int teams;
	public:
		Manager(string n, string c, int t): Employee(n,c), teams(t)
		{		};	
};


class ConsultantManager : public Manager, Consultant
{
	public:
		ConsultantManager(string n, string c, int y, int t):Manager(n,c,t), Consultant(n,c,y),Employee(n,c)
		{		}
		void Display( )
		{
			cout<<"Name: "<<Manager::name<<endl;
			cout<<"Code: "<<Manager::code<<endl;
			cout<<"Years of Experience: "<<years<<endl;
			cout<<"Number of Teams: "<<teams<<endl;
		};
	
};

int main(void)
{
	ConsultantManager cm("Ali","S-123",17,5);
	cm.Display();
	return 0;
}
