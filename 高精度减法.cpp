#include<iostream>
#include<cstring>
using namespace std;
int a[10088],b[10088];
char s1[10088],s2[10088],s[10088]/*,fh*/;
bool fn=false;
int main(){  
	int len,len1,len2;  
	cin>>s1>>s2; 
	if (strcmp(s1,s2)==0)
	{
	cout<<"0";
	}
	len1=strlen(s1);    
	len2=strlen(s2);    	
	if (len1<len2 || ( (len1==len2) && (strcmp(s1,s2)<0) ) )
	{
		/*fh='-';*/
		fn=true;
		strcpy(s,s1);
		strcpy(s1,s2);
		strcpy(s2,s);
		int t=len1;len1=len2;len2=t;
	}
	
	for (int i= 0;i<len1;i++)
	{
		a[i]=s1[len1-i-1]-'0';
	}


	for (int i= 0;i<len2;i++) 
	{
		b[i]=s2[len2-i-1]-'0';	
	}


	for (int i=0;i<len1;i++)
	{
	    if (a[i]<b[i])
		{
	        a[i+1]=a[i+1]-1;
	        a[i]=a[i]+10;
	    }
	    a[i]=a[i]-b[i];
	}


	int k=len1;
	while (a[k]==0) { 
		k--;
	}
	if(fn==true)
	{
	cout<<"-";
	}
	for (int i=k;i>=0;i--)
	{
		cout<<a[i]; 
	}
	return 0;
}
