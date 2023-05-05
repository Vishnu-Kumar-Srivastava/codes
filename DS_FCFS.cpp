
#include <bits/stdc++.h>
using namespace std;
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> q={98,183,37,122,14,124,65,67};
    int z=53;
    int sub=0;
    for(auto elm: q)
    {
        sub=sub+abs(elm-z);
        z=elm;
    }
    
    cout<<"total head movement: "<<sub;
}
