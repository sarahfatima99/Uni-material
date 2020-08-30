#include<iostream>
using namespace std;
class student{
		int age,batch;
	public:
		
		student(){		}
			student(int a, int b):age(a),batch(b){
				}
	friend ostream & operator<<(ostream &o ,student &s);
    friend istream & operator >>(istream,student);
				};
	ostream &operator <<(ostream &o,student& s){
		o<<s.age;
		o<<s.batch;
		return o;
	}
	istream &operator >>(istream &o,student& s){
		cout<<"enter input";
		o>>s.age;
		o>>s.batch;
		return o;
	}				
	int main(){
		student st;
		cin>>st;
		cout<<st;
		
	}//https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
