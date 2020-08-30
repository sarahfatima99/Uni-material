/* strtok example */
#include <iostream>
#include <string.h>
#include <stack>
#include <fstream>

using namespace std;

void showstack(stack <int> s) 
{ 
     
} 
int main ()
{
	ifstream fin;
	fin.open("input (1).txt");
	string InLine;
	getline(fin, InLine);
	cout<<InLine<<endl;
  
    int n = InLine.length(); 
  
    // declaring character array 
    char arr[n + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(arr, InLine.c_str()); 
  	
	stack<string> stk; 
	  char * pch;
	  pch = strtok (arr," !,.-");
	  while (pch != NULL)
	  {
	    //cout<<pch<<endl;
	    stk.push(pch);
	    pch = strtok (NULL, " !,.-");
	  }
	  
	  while (!stk.empty()) 
	    { 
	    	string temp = stk.top(); //each word of the string stored in temp
	        cout<<temp<<endl;
	      		//checks the first letter of the string
	
	        	ifstream ftake;
	        	ftake.open("words.txt"); //opens the relative file
	        	string bwords;
	        	while(getline(ftake, bwords))
	        	{
	        		int n = bwords.size();
					string NewBWord = bwords.substr(0, n-1); 
					
					if(temp == NewBWord) //compares the word in the file
					{
						cout<<bwords[n-1]<<endl; //outputs the coressponding calue
						break;
					}
				
				}
	        stk.pop(); 
	    
	    } 
	    cout << '\n'; 
  
  return 0;
}
