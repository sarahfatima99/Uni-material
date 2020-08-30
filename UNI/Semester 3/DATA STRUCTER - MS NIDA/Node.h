
class Node  
{  
    public: 
    int data;  
    Node *next;  
    
    Node();
    Node(int,Node*);
    void Insert_at_Head(int, Node*);//Insert at Start 
    void Insert_at_End(int,Node*);//Insert at last
    void Insert_Before(int,Node*,int);//insert before a specific data
    void Insert_After(int, Node*,int);//Insert after a specific data
    void Insert_at(int,Node*,int);//Insert at a specific position
    void Delete_from_End(Node*);//Delete Last node
    void Delete_from_front(Node*);//Delete first node from front 
    void Delete_at(int,Node*);// Detele at a specific Position
    void Delete_before(int,Node*);// Delete the node before the data
    void Delete_After(int,Node*);//Delete the node after the data 
    void Display(Node*);//Displays the list
    int Search_data(int,Node*);//search the data and return the node number if present, else return -1.  
    int Length_of_list(Node*);//counts the number of nodes in list
};  
