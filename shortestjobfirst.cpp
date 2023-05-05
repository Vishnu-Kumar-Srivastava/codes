//This code is made by Vishnu Kumar Srivastava
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void selection_sort(vector<int>&arr,vector<int>&dm1,vector<string>&dm2, int n)
{
    int k;
    string y;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                k=arr[j];
                arr[j]=arr[i];
                arr[i]=k;

                k=dm1[j];
                dm1[j]=dm1[i];
                dm1[i]=k; 
                
                y=dm2[j];
                dm2[j]=dm2[i];
                dm2[i]=y; 
            }
        }
    }
}
int main()
{
   int n;
   vector<int>arrival;
   vector<int>execution;
   cout<<"enter the number of processes: ";
   cin>>n;
   for(int i=0; i<n; i++)
   {
      int et,at;
      cout<<"Enter the arrival time: ";
      cin>>at;
      arrival.push_back(at);
      cout<<"Enter the execution time: ";
      cin>>et;
      execution.push_back(et);
   }
   vector<string> processes;
   for(int i=0;i<n;i++)
   {
      char a[10] ;
      sprintf(a,"P%d",(i+1));
      processes.push_back(a);

   }
   // for(int i=0;i<n;i++)
   // {
   //    cout<<processes[i]<<" "<<arrival[i]<<" "<<execution[i]<<endl;
   // }
   selection_sort(execution,arrival,processes,n);
   selection_sort(arrival,execution,processes,n);

   

   // int sum= accumulate(execution.begin(), execution.end(),0);
   // int k=0;
   
   // while(k<sum)
   // {
   //    int min_exec=execution[0];
   //    // cout<<"the value of k is "<<k<<endl;
   //    // for(int l=0;l<n;l++)
   //    // {
   //    //    cout<<processes[l]<<" "<<arrival[l]<<" "<<execution[l]<<endl;
   //    // }
      
   //    for(int i=0;i<n;i++)
   //    {
   //       if(arrival[i]<=k)
   //       {
   //          if(execution[i]>=0)
   //          {
   //          min_exec=min(min_exec,execution[i]);
   //          // cout<<"minexec is "<<min_exec<<endl;
   //          }
   //       }
   //    }
   //    for(int i=0;i<n;i++)
   //    {
   //       if(execution[i]==min_exec)
   //       {
   //          // cout<<"if this is true"<<endl;
   //          cout<<processes[i]<<" "<<arrival[i]<<" "<<execution[i]<<endl;
   //          execution[i]--;
   //          if(execution[i]==0)
   //          {
   //             execution[i]=INT_MAX;   
   //          }
   //          break;
   //       }
   //    }
   //    k++;
   // } 
   vector<int> wt;
   int wait=0;
   int sumexec=0;
   wt.push_back(0);
   for(int i=1;i<n;i++)
   {
     
      sumexec=sumexec+execution[i-1];
      wait=sumexec-arrival[i];
       wt.push_back(wait);
   }
   for(int i=0;i<n;i++)
   {
      cout<<processes[i]<<" "<<arrival[i]<<" "<<execution[i]<<" "<<wt[i]<<endl;
   }
}


