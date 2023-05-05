#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> q={98,183,37,122,14,124,65,67};
	int z=53;
	sort(q.begin(),q.end());
	for(auto elm: q)
	{
	    cout<<elm<<" ";
	}
	cout<<endl;
	int i=0;
	while(q[i]<53)
	{
	    i++;
	}
	i--;
	int j=i+1;
	int sub=0;
	cout<<"53"<<" ";
	
	while(j<q.size())
	{
	    cout<<q[j]<<" ";
	    
	    j++;
	    
	}
	sub=abs(53-*max_element(q.begin(),q.end()));
	sub=sub+abs(*max_element(q.begin(),q.end())-*min_element(q.begin(),q.end()));
	int k;
	for(k=0;k<=i;k++)
	{
	    cout<<q[k]<<" ";
	}
	sub=sub+abs(*min_element(q.begin(),q.end())-q[--k]);
	cout<<endl;
	cout<<sub;
	
	
}
