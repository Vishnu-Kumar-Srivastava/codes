
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> q={98,183,37,122,14,124,65,67};
	int z=53;
	int minn= INT_MAX;
	int minLast;
	int pos;
	int i= q.size();
	int sub=0;
	while(i)
	{
	    minn= INT_MAX;
	    
	   for(int j=0;j<q.size();j++)
	   {
	       
	       int a= abs(q[j]-z);
	       cout<<"a is : "<<a<<endl;
	       minLast=minn;
	       minn=min(a,minn);
	       if(minLast!=minn)
	       {
	           pos=j;
	       }
	   }
	   cout<<"difference is: "<<abs(z-q[pos])<<endl;
	   sub=sub+abs(z-q[pos]);
	   z=q[pos];
	   q[pos]=INT_MAX;
	   i--;
	}
	cout<<sub;
}
