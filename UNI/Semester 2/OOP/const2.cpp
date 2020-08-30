#include<iostream>
using namespace std;
class hotel{
	private:
		const int cost;
		
		int noofdays,rent;
		public:
        const char *name;
		  hotel(){  }
			hotel(int c,char *n):cost(c),name(n){}
			void calculaterent(int no){
				noofdays=no;
				if (noofdays>7){
					noofdays=noofdays-1;
				}
				rent=cost*noofdays;
		
			}
			void display(){
				cout<<"NAME:"<<*name<<"\n number of days"<<noofdays<<"\nrent"<<rent;
			}
};
int main(){
	hotel h1;
	cin>>h1.name;
	//hotel h(100.85,"sarah");
	h.calculaterent(8);
	h.display();
}
