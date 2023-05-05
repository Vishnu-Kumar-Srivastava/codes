#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int val;
    Node*prev;
    Node*next;
    
    Node(int k,int v)
    {
        key=k;
        val=v;
        Node*prev=NULL;
        Node*next=NULL;
    }
};
class fcfs{
    private:
    int cap;
    void remove(Node* node)
    {
        Node*prev=node->prev;
        Node*next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    void insert(Node*node)
    {
        Node*next=right;
        Node*prev=right->prev;
        node->next=next;
        node->prev=prev;
        prev->next=node;
        next->prev=node;
        
    }
    
    public:
    static int pagefault;
    static int hit;
    unordered_map<int,Node*> cache;
    Node*left;
    Node*right;
    
    fcfs (int capacity)
    {
        cap=capacity;
        left=new Node(0,0);
        right= new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    void put(int key,int val)
    {
        if(cache.find(key)!=cache.end())
        {
            hit++;
        }
        else
        {
            pagefault++;
            cache[key]= new Node(key,val);
            insert(cache[key]);
            if(cache.size()>cap)
            {
                Node* first=left->next;
                remove(first);
                cache.erase(first->key);
                delete first;
            }
        }
    }
};
int fcfs::pagefault;
int fcfs::hit;
int main()
{
    cout<<"enter the value of frames";
   int n;
   cin>>n;
   fcfs a(n);
   
   
   int u[]={7,0,7,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    for(auto elm: u)
    {
        a.put(elm,elm);
    }
   cout<<"pagefault: "<<a.pagefault<<endl;
   cout<<"hit: "<<a.hit<<endl;
   
}