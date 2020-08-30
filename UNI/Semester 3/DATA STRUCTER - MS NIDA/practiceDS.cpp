/***********************************
* https://github.com/Muhammad4hmed *
* Overall Complexity: O(n^2)       *
***********************************/
#include<iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
        node(int d) {
            data = d;
        }
        node(int d,node *next) {
            data = d;
            this->next = next;
        }
};

class list {
    node *head = NULL;
    int nodeCounter = 0;
    public:
        list() {}
        list(int d) {
            head = new node(d,NULL);
            nodeCounter++;
        }

        void add_node(int d,int pos) {
            nodeCounter++;
            if( head == NULL ) {
                head = new node(d,NULL);
                return;
            }
            if(pos == 0) {  // head
                    head = new node(d,head);
            } else {
                node *n = head;
                int i = 0;
                while(n != NULL && i < pos - 1) {
                    n = n->next;
                    i++;
                }
                node *temp = n->next;
                n->next = new node(d,temp);
            }
        }
        display_list() {
            node *n = head;
            while(n != NULL) {
                cout<<n->data<<" ";
                n = n->next;
            }
            cout<<endl;
        }
        void RemoveDuplicate() {
            node *n = head,*prev = NULL;
            while(n->next != NULL) {
                prev = n;
                n = n->next;
                if(n->data == prev->data) {
                    node *nextElement = n->next;
                    prev->next = nextElement;
                    delete n;
                    n = prev;
                }
            }
        }
        void swap_Nodes(int data) {
            node *temp = head,*prev = NULL,*nextElement = NULL;
            if(temp->data == data) {
                nextElement = temp->next;
                if(nextElement == NULL) return;
                temp->next = nextElement->next;
                nextElement->next = temp;
                head = nextElement;
                return;
            }
            while( temp != NULL && temp->data != data ) {
                prev = temp;
                temp = temp->next;
                nextElement = temp->next;
            }
            if(nextElement == NULL) return;
            prev->next = nextElement;
            temp->next = nextElement->next;
            nextElement->next = temp;
        }
        void Reverse() {
            node *prev = NULL,*temp = head,*nextElement = head;
            while(nextElement != NULL) {
                temp = nextElement;
                nextElement = nextElement->next;
                temp->next = prev;
                prev = temp;
            }
            head = temp;
        }

        void bubble_Sort() {
            for( node *i = head, *prev = NULL; i->next != NULL; i = i->next) {
                for( node *j = i->next, *prevJ = NULL; j != NULL; j = j->next) {
                    if( i->data > j-> data ) {
                        int tempData = i->data;
                        i->data = j->data;
                        j->data = tempData;
                    }
                }
            }
        }
};

int main() {
    list l;
    for(int i=0;i<10;i++) l.add_node((i+1)*10,i);
    l.add_node(50,5);
    l.add_node(50,5);
    l.add_node(50,5);
    l.add_node(10,1);
    l.add_node(10,1);
    l.add_node(10,1);
    cout<<"Original list: ";
    l.display_list(); // simple display
    l.RemoveDuplicate(); // removing duplicates
    cout<<"After removing duplicates: ";
    l.display_list();
    l.swap_Nodes(50); // swapping 50 with 60
    cout<<"After swapping 50 with 60 (links): ";
    l.display_list();
    l.Reverse();
    cout<<"Reversed: ";
    l.display_list();
    l.bubble_Sort();
    cout<<"Sorted List: ";
    l.display_list();
}
