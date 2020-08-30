#include<iostream>
using namespace std;
class comp{
	private:
		int x,y;
		public:
			comp(){};
	comp(int a, int b):x(a),y(b){
	};
	comp operator +(comp c){
		comp temp;
		temp.y=y+c.y;
		temp.x=x+c.x;
	return temp;
	}
	void show(){
		cout<<x<<" "<<y;
	}
};
int main(){
	comp c1,c2(5,5),c3(5,5);
	c1=c2+c3;
	c1.show();
}
