#include<iostream>
 
#include<cstring>
 
using namespace std;
string a,b;
char pd(char x,char y)
{
if(x>='a'&&x<='z'&&y>='a'&&y<='z') { y-=(x-'a'); if(y<'a') y+=26; } if(x>='a'&&x<='z'&&y>='A'&&y<='Z') { y-=(x-'a'); if(y<'A') y+=26; } if(x>='A'&&x<='Z'&&y>='a'&&y<='z') { y-=(x-'A'); if(y<'a') y+=26; } if(x>='A'&&x<='Z'&&y>='A'&&y<='Z') { y-=(x-'A'); if(y<'A') y+=26; } return y; }
int main()
{
int i,j; cin>>a>>b; for(i=0,j=0;i<b.size();i++,j++) { if(j==a.size()) j=0; cout<<pd(a[j],b[i]); } return 0; }
