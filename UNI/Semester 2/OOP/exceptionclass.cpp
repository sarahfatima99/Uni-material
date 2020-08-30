#include<iostream>
#include<exception>
using namespace std;
class myexc:public exception{
	virtual const char* what() const throw(){
		return "hi";
	}}ex;

int main(){
	try{
		cout<<"enter two numbers";
		int a,b,c;
		cin>>a>>b>>c;
		
	throw ex;
	
	
	}
	catch(exception &e)
	{
		cout<<"hi"<<e.what()<<"\n";
	}
}
