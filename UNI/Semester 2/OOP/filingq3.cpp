#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class person{
	public:
	string name;
	int age;
	person(int a, string n):name(n),age(a){}
	
};
int main(){
	int a;
	char c[100];
	person p(21,"sarah");
	fstream f,o;
	f.open("person.dat",ios::binary|ios::out| ios::in);
	cout<<"saving stuff";
	f.write((char*)&p.age,sizeof(p));
	f.write((char*)&p.name,sizeof(string));
	f.close();
    o.open("person.dat",ios::binary| ios::in);
    o.read((char*)&c,sizeof(c));
    o.read((char*)&a,sizeof(a));
    cout<<"\n"<<c<<a;
}

