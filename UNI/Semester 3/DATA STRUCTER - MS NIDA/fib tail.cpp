#include<iostream>
using namespace std;
int fib(int n, int next, int result){
	if(n==0){
		return result;
	}
	return fib(n-1,next+result,next);
}
int main()
{
	cout<<"Enter a number";
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cout<<fib(i,1,0)<<endl;
	}
	
}
