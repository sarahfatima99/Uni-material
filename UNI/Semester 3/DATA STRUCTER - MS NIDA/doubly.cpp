#include<iostream>
using namespace std;

	class node {
	public:
		int data;
		node(int a){
			data=a;
			next=NULL;
		    prev=NULL;
		}
		node(int a, node *in,node *ip){
			data=a;
			next=in;
			prev=ip;
		}
		node *next, *prev;
		node(){
			data=0;
			next=NULL;
			prev=NULL;
		}};

class linkedlist{
	node *head, *tail;
	public:
		linkedlist(){
			head=NULL;
			tail=NULL;
		}
		linkedlist(const linkedlist &rhs){
			this->head=NULL;
			this->tail=NULL;
			node *q=rhs.head;
			while(q!=NULL){
				addtotail(q->data);
				q=q->next;
			}
		}
		linkedlist& operator = (const linkedlist& rhs){
			if(this!=&rhs){
				node *ptr;
				while(head!=NULL){
					ptr=this->head->next;
					delete this->head;
					this->head=ptr;
				}
				ptr=NULL;
				this->head=NULL;
				this->tail=NULL;
			node *q=rhs.head;
			while(q!=NULL){
				addtohead(q->data);
				q=q->next;
				
			
			}
			}
			return *this;
		}
		void addtohead(int n){
			if(head==NULL){
				head=tail=new node(n);
			}
			else{
				head=new node(n,head,NULL);
				head->next->prev=head;
			}
		}
		void addtotail(int n){
			
			if(head==NULL){
				head=tail=new node(n);
			}
			else {
				tail= new node(n,NULL,tail);
				tail->prev->next=tail;
			}
		}
		void display(){
			node *temp= new node;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		~linkedlist(){
			node *ptr;
		
			while(head!=NULL){
				ptr=head->next;
				delete head;
				head=ptr;
			}
			delete ptr;
			ptr=NULL;
		}
		void addsomewhere(int a,int n){
			if(head==tail){
				head=tail=new node(a,NULL,NULL);
			}
			else {
				node *temp=new node,*place;
				temp=head;
				while(temp!=NULL){
					if(temp->data==n){
						place=new node(a,temp->next,temp);
						if(temp->next!=NULL){
								cout<<temp->next->prev->data;
							temp->next->prev=place;
						
						}
						else tail=place;
							temp->next=place;
					}
				
					temp=temp->next;
				}
			}
		}
		void addtosomewhere(int n, int a){
 if(head==tail){
 head=tail=new node(n,NULL,NULL);

 }
 else{
 node *tmp, *place;
 for(tmp=head;tmp!=0;tmp=tmp->next){
 if(tmp->data==a){
 place=new node(n,tmp->next,tmp);
 if(tmp->next!=NULL){
 tmp->next->prev=place;
 }
 else{
 tail=place;
 }
 tmp->next=place; 

 }

 }

 }

 }
		void reversing(){
			node *temp;
			node *current=head;
			while(current!=NULL){
				temp=current->prev;
				current->prev=current->next;
				current->next=temp;
				current=current->prev;
		
			}
		if(temp!=NULL){
			head=temp->prev;
		}
		}
		void swap(int a){
			node *temp;
			temp=head;
			node *ptr,*ptr2;
			 
			while(temp!=NULL){
				if(temp->data==a){
					
				ptr2=temp->prev->next;
					cout<<ptr2->data;
				temp->prev->next=temp->next->prev;
				temp->next->prev=ptr2;
							  
					ptr= temp->next;
					temp->next=temp->prev;
		
				}
				temp=temp->next;
			}
		
		}
	
};
int main()
{
 linkedlist a;
 a.addtohead(1);
 //adding nodes to a
 a.addtohead(2);
 a.addtotail(4);
 a.addtotail(5);
 a.display();
a.swap(4);
cout<<endl;
 a.display();
 cout<<endl;
 /*
 cout<<endl;
 
a.addsomewhere(8,4);
 a.display();
 a.reversing();
 cout<<endl;
 a.display();


 /*linkedlist b(a); //case of copy constructor
 b.display();

 linkedlist c;
 c.addtohead(6);
 c.addtohead(7);
 c=a; //case of operator assignment
  c.addtohead(6);
 c.addtohead(7);
 cout<<endl;
 c.display();

*/
 return 0;
}
