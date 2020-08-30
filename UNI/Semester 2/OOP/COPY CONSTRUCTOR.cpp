#include<iostream>
#include<cstring>
using namespace std;
class CopyConstructor
{
    char *s_copy;
    public:
    	void set(char *str){
    		strcpy(s_copy,str);
		}
    CopyConstructor(const char *str)
    {
        s_copy = new char[16]; //Dynamic memory allocation
        strcpy(s_copy, str);
    }
    /* concatenate method */
    void concatenate(const char *str)
    {
        strcat(s_copy, str); //Concatenating two strings
    }
    /* copy constructor */
    ~CopyConstructor ()
    { 
        delete [] s_copy;
    }
    void display()
    {
        cout<<s_copy<<endl;
    }
};
/* main function */
int main()
{
    CopyConstructor c1("Copy");
    CopyConstructor c2 = c1; //Copy constructor
    c1.display();
    c2.display();
   // c1.concatenate("Constructor");    //c1 is invoking concatenate()
    c1.set("meow");
	c1.display();
    c2.display();
    return 0;
}
