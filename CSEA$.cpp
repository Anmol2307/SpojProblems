#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define q 27
 
using namespace std;
     
int first[q];
int original[q];
int match[q];
string s;
 
void input()
    {
    	for(int i = 0 ; i < 26; ++i)
    	{
    		original[i] = s[i] - 'A';
    		first[i] = 1;
    		match[i] = 0;
    	}
    }     
 
int check()
    {
    for(int i = 0 ; i < 26; ++i){
	if( first[i] ){
    		int count = 1;
    		int j = original[i];
    		first[i] = 0;
    		while(j != i)
    		{
    			first[j] = 0;
    			j = original[j];
    			++count;
    		}
    		match[count]++;
    	}
    }
    for(int i = 0 ; i < 26; ++i){
        cout << match[i] << " ";
    }
    cout << endl;
    exit(0);
    for(int i = 2; i < 27; i += 2)
    {
    	if( match[i]) {
    		if( match[i]%2 ){
    			return 0;
		    }
    	}
    }
    return 1;
}
     
int main()
{
    int Test;
    cin>>Test;
    while(Test--)
    {
    	cin>>s;
    	input();
    	if( check() ){
    		cout<<"Yes"<<endl;
	}
    	else{
    		cout<<"No"<<endl;
	}
    }
    return 0;
}
 