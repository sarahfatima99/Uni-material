#include "cars.h"
#include<iostream>
using namespace std;
int main(){
	cars c2;
	cars c1;
	c1.set(2,4,"yellow");
	c1=c2;
	c2.print();
	   car  c2(c1);
      c2.~car()
}
