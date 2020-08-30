#include<iostream>
using namespace std;
class intArr{
	private:
		int array[5],j,i;
	public:
		
	intArr(int arr[])
	{
	for(i=0;i<5;i++)
	{
		 array[i]=arr[i];
	}}
	void display()
	{
		for(i=0;i<5;i++)
		cout<<array[i]<<" ";
	}
	
};
int main()
{
	
	int myarray[]={1,2,3,4,5};
	intArr obj(myarray);
	obj.display();
}
