#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
void print(string s){
	int n=s.size();
	bool table[n][n];
	memset(table,0,sizeof(table));
	int max=1;
	for(int i=0;i<n;++i){
		table[i][i]=true;
	}
	int S=0;
	for(int i=0;i<n-1;++i){
		if(s[i]==s[i+1]){
			table[i][i+1]=true;
			S=i;
			max=2;
		}
	}
	for(int k=3;k<=n;++k){
		for(int i=0;i<n-k+1;++i){
			int j=i+k-1;
			if(table[i+1][j-1]&&s[i]==s[j]){
				table[i][j]=true;
				if(k>max){
					S=i;
					max=k;
				}
			}
		}
	}
	int e=S+max-1;
	for(int i=S;i<=e;++i){
		cout<<s[i];
	}
	cout<<endl;
}
int main(){
	string s="11231312313213132359878";
	print(s);
}
