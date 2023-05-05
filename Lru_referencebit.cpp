#include<iostream>
#include<vector>
using namespace std;
int isPresent(int a[3], int num)
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i]==num)
        return 1;
        
    }
    return 0;
};

int minIndex(int index[])
{
    int minInd=0;
    int minVal=index[0];
    for (int i = 0; i < 3; i++)
    {
        if(index[i]<minVal)
        { minInd=i;
        minVal=index[i];
        }
    }
    return minInd;
     
};

int findIndex(int a[], int &num)
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i]==num) return i;
    }
    
}

int main()
{
    int page_arr[]={7,0,7,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int frame_arr[3];
    int index[3];
    int page_fault=0;
    int count=0;

    for (int i = 0; i < 20; i++)
    {
        if(count>2) 
        {
            count=i;
            break;
        }
        if(!isPresent(frame_arr,page_arr[i]))
        {
            frame_arr[count]=page_arr[i];
            index[count]=i;
            count++;
            page_fault++;
        }
        else
        {
            int ind=findIndex(frame_arr,page_arr[i]);
            index[ind]=i;
        }
    }

    for (int i = count; i < 20; i++)
    {
       if(!isPresent(frame_arr,page_arr[i]))
       {
            int replace_ind=minIndex(index);
            cout<<page_arr[i]<<" present nahi hain & min index is "<<replace_ind<<endl;
            frame_arr[replace_ind]=page_arr[i];
            index[replace_ind]=i;
            page_fault++;
       }
       else
       {
            int ind=findIndex(frame_arr,page_arr[i]);
            index[ind]=i;
       }
       
    //    for (int i = 0; i < 3; i++)
    //    {
    //     cout<<frame_arr[i]<<" ";
    //    }

    //    for (int i = 0; i < 3; i++)
    //    {
    //     cout<<index[i]<<" ";
    //    }
       
    //    cout<<endl;
       
    }
    
    

    



cout<<page_fault;



// int a=min_element()


return 0;
}