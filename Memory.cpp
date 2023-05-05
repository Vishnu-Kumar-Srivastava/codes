//This code is made by Vishnu Kumar Srivastava
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
   vector<int>FreeList;
   cout<<"enter the number of free memeory blocks";
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int a;
      cout<<"enter the size of the block"<<endl;
      cin>>a;
      FreeList.push_back(a);
   }
   cout<<"enter the size of newly entered process"<<endl;
   int target;
   cin>>target;
   //First Fit
   int firstfit;
   int bestfit;
   int worstfit;
   for(auto elm: FreeList)
   {
      if(elm>=target)
      {

         firstfit=elm;
         break;
      }
   }
   
   int minn=INT_MAX;
   for(auto elm:FreeList)
   {
      if(elm>=target)
      {
         minn=min(minn,elm);
      }
   }
   
   bestfit=minn;
   int maxx=*max_element(FreeList.begin(), FreeList.end());
   
   if(maxx>=target)
    worstfit=maxx;

   cout<<"firstfit: "<<firstfit<<endl;
   cout<<"bestfit: "<<bestfit<<endl;
   cout<<"worstfit: "<<worstfit<<endl;

}