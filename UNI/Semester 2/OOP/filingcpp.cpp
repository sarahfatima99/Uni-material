#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	fstream f;
	char a[100];
	int len;
	cout<<"enter string";
	cin>>a;
	len=strlen(a);
	f.open("testfile.txt",ios::out);
	for(int i=0;i<len;i++){
		f.put(a[i]);
	}
	f.close();
	char ch;
	cout<<"reading data\n\n";
	f.open("testfile.txt",ios::in);
	while(f){
		f.get(ch);
		cout<<ch;
	}
	f.close();
}
