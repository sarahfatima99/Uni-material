#include<iostream>
#define SIZE 10
#define prime 7
using namespace std;
int hash(int key){
	return key%SIZE;
}
int probe(int h[],int key){
	int index=hash(key);
	int i=0;
	while(h[(index+i)]%SIZE!=0){
		i++;
	}
	return (index+i)%SIZE;
}
int hash2(int key){
	return key%prime;
}
int doublehash(int h[],int key){
	int index=hash(key);
	int index2=hash2(key);
	int i=0;
	while(h[(index+i)*index2]%SIZE !=0)
	i++;
	int x=(index+i)*index2;
	return(x);
	
}
void insert2(int h[],int key){
	int index=hash(key);
	if(h[index]!=0){
	
	index=doublehash(h,key);}
   	h[index]=key;	
}
void insert(int h[],int key){
	int index=hash(key);
	if(h[index]!=0){
	
	index=probe(h,key);}
   	h[index]=key;	
}
int search(int h[],int key){
	int index=hash(key);
	int i=0;
	while(h[(index+i)%10]!=key)
	i++;
	return (index+i)%10;
}
int search1(int h[],int key){
	int index=hash(key);
	int index2=hash2(key);
	if(h[index]!=key){
	
	int i=0;
	while(h[(index+i)*index2]%SIZE!=key)
	i++;
	return((index+i)*index2);}
	else return index;
}
int main(){
	int ht[SIZE],h[SIZE];
	for(int i=0;i<10;i++)
	ht[i]=h[i]=0;
	insert(ht,12);
	insert(ht,10);
	insert(ht,22);
	insert(ht,42);
	insert(ht,45);
	insert2(h,12);
	insert2(h,17);
		insert2(h,42);
	insert2(h,10);
	insert2(h,22);
	insert2(h,52);
	insert2(h,45);
	cout<<search1(h,52);

}
