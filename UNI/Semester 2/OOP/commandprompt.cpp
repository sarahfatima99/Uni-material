#include<iostream>
#include<fstream>
#include<string>
using namespace std;
main(int argc,char* argv[]){
	fstream file1,file2;
	file1.open(argv[1],ios::in);
	file2.open(argv[2],ios::out);
	string line;
	if(!file1.is_open()){
		cerr << "File Not Found" << endl;
		return 6;
	}
	else{
	
		while(!file1.eof()){
			getline(file1,line);
			file2 << line << endl;
		}
	}
	file1.close();
	file2.close();
	return 0;
}

