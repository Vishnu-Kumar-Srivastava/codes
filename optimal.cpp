#include<iostream>
#include<vector>
using namespace std;
int frameSize;
int isPresent (int arr[],int num)
{
    for(int i=0;i<frameSize;i++) 
    {
        if(arr[i]==num) return 1;
    }
    return 0;

}


int main()
{
    int page_arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

    cout<<"Enter number of frames";
    cin>>frameSize;
    int count=0;
    int page_fault=0;
    int *frame_arr =new int[frameSize];

    for (int i = 0; i < 20; i++)
    {
        if(count>frameSize-1) 
        {
            count =i;
            break;
        }
        if(!isPresent(frame_arr,page_arr[i]))
        {
            frame_arr[count]=page_arr[i];
            count++;
            page_fault++;
        }
    }
    int max_dist=-1;
    int max_index=-1;
    int flag=0;
    for (int i = count; i < 20; i++)
    {
        if(!isPresent(frame_arr,page_arr[i]))
        {
            for (int j = 0; j < frameSize; j++)
            {
                for (int k = i; k < 20; k++)
                {
                    if(page_arr[k]==frame_arr[j])
                    {
                        if(k>max_dist)
                        {
                            max_dist=k;
                            max_index=j;
                            
                        }
                        break;
                    }
                    else if(k==19)
                    {
                        max_index=j;
                        flag=1;
                    }
                }
                if(flag) break;
            }
            frame_arr[max_index]=page_arr[i];
            page_fault++;
            max_dist=-1;
            max_index=-1;
            flag=0;
        }
    }
    
cout<<page_fault;






return 0;
}