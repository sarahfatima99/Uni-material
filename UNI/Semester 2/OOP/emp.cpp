#include<iostream>
using namespace std;
class employee{
	private:
	string empname;
	  int rollno;
	 public:
	 	void set(string name,  int rno){
	 	   empname=name;
	 		rollno=rno;
		 }

	void display(){
		cout<<"employee name: "<<empname<<"\nempid: "<<rollno;
	}
};
int main(){
	employee emp;
	emp.set("sara",0205);
	emp.display();
	
}
