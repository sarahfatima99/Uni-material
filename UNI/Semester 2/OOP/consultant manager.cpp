#include<iostream>
using namespace std;
class employee{
	protected:
		string name,code;
		public:
		employee(string n,string c):name(n),code(c){}
		
};

class manager :virtual public employee{
	protected:
		int noofteams;
		public:
		manager(string n,string c,int no):employee(n,c),noofteams(no){}
		
};
class consultant: virtual  public employee{
	protected:
	int yearsexp;
	public:
	consultant(string n, string c, int y):employee(n,c),yearsexp(y){}
	
};
class consultantmanager:public manager, public consultant{
	public:
	consultantmanager(string n, string c, int y, int no):consultant(n,c,y),manager(n,c,no),employee(n,c){}
void display(){
	cout<<"name:"<<name<<"\ncode"<<manager::code<<"\nnumber of teams"<<noofteams<<"\nyears exp"<<yearsexp;
}	
};
int main(){
	consultantmanager c("sarah","python",4,1);
	c.display();
	
}
