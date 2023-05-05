//This code is made by Vishnu Kumar Srivastava
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Node{
    public:
    int k;
    int val;
    Node* prev;
    Node* next;

    Node(int key,int value)
    {
        k=key;
        val=value;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
private:
int cap;


void remove(Node* node)
{
    Node* prev=node->prev;
    Node* next=node->next;
    prev->next=next;
    next->prev=prev;
}
void insert(Node*node)
{
    Node* next=right;
    Node * prev= right->prev;
    node->next=next;
    node->prev=prev;
    next->prev=node;
    prev->next=node;
}
public:
   static int pagefault;
   static int hit;
   unordered_map<int,Node*>cache;
   Node*left;
   Node* right;
    LRUCache(int capacity) {
        cap=capacity;
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
            delete cache[key];
            hit++;
        }
        else
        {
         pagefault++;
        }
        cache[key]=new Node(key,value);
        insert(cache[key]);
        if(cache.size()>cap){
            Node*lru=left->next;
            remove(lru);
            cache.erase(lru->k);
            delete lru;
        }
    }

};
int LRUCache::pagefault;
int LRUCache::hit;
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
   cout<<"enter the value of frames";
   int n;
   cin>>n;
   LRUCache a(n);
   int i;
//    cout<<"enter the number of entries: ";
//    cin>>i;
//    while(i)
//    {
//       int z;
//       cout<<"enter the page: ";
//       cin>>z;
//       a.put(z,z);
//       i--;
//    }
    int u[]={7,0,7,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    for(auto elm: u)
    {
        a.put(elm,elm);
    }
   
   Node* p= a.left->next;
   while(p!=a.right)
   {
      cout<<p->val<<" ";
      p=p->next;
   }
   cout<<endl;
   cout<<"pagefault: "<<a.pagefault<<endl;
   cout<<"hit: "<<a.hit<<endl;
   
}