#include<iostream>
#include<math.h>
#define size 10
using namespace std;
class node{
	public:
	node *next;
	int data;
		 node( int a,node* in){
			data=a;
			next=in;
		}
		 node(int a){
			next=NULL;
			data=a;
			
		}
};
class queue{
	public: 
		node *head,*tail;
		int front,rear;
		int arr[size];
		queue(){
			head=NULL;
			tail=NULL;
			rear=front=-1;
		}

        void insert(int x){
        	if(rear+1==size){
        		cout<<"no space";
			}
			else{front=0;
				rear++;
				arr[rear]=x;
			}

        }
        void del(){
        	if(rear==-1){
        		cout<<"queue is empty";
			}
			else {
			swap(arr[rear],arr[1]);
			front++;}
			
		}

		void enqueue(int a){
	this->addtotail(a)	;}

void heapify(int i){
	int largest=i;
	int l= 2*i+1;
	int r=2*i+2;
	

if(r<=rear &&arr[r]>arr[largest]){
	largest=r;
}
if(l<=rear && arr[l]>arr[largest]){
	largest=l;
}
if(largest!=i){
	swap(arr[i],arr[largest]);
	heapify(largest);
}}
void heapsort(int n){
	for(int i=n/2-1;i>=0;i--)
	heapify(i);
for(int i=n-1;i>=0;i--){
	swap(arr[0],arr[i]);
heapify(0);}
}
/*void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}*/
	

		
		
	void addtotail(int a){
			if(head==NULL){
			head=tail= new node(a);
			
		}	
		else{
			node *p=head;
		while(p!=NULL){
		
		if(a<tail->data){
            int temp=tail->data;
			tail->data=a;	
	
			tail->next=new node(temp);
			tail=tail->next;}
			else{
			tail->next=new node(a);
			tail=tail->next;
			}
			
		}
		}
		void enque(int a){
			this->addtotail(a);
			
		}
		void deque(int a){
			node *temp=head;
			if(head!=NULL){
			head=head->next;
			delete temp;	
			}
			else if(head==tail){
				head=tail=NULL;
			}
			}
		
	void display(){
		node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void display1(){
		for(int i=0;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
		
	}
 
};
int main(){
	int x;
	queue q;
	for(int i=0;i<10;i++){ //using linkedlist data structure
		cin>>x;
		q.enqueue(x);
		cout<<endl;
		q.display();
		cout<<endl;
	}
		for(int i=0;i<10;i++){
		cin>>x;  //insert using array data structure
		q.insert(x);
		cout<<endl;
	q.heapsort(i);
		q.display1();
		cout<<endl;
	}

}

