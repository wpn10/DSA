/*
    Problem->Range Sum Query with Update operations
    Segment Tree Implementation
*/

#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> st; //Segment tree array
int n;  //Size of array

void build_st()    //N->No of array elements
{
    for(int i=n-1;i>=1;--i)
        st[i] = st[2*i] + st[2*i+1];
}

void update(int index,int newValue)
{
    index += n;
    st[index] = newValue;
    for(; index>1; index/=2)    //index can't move to root of st as it has no parent
        st[index/2] = st[index] + st[index^1];
}

int query(int l,int r)  //Range sum [l,r)
{
    int res=0;
    l+=n;
    r+=n;
    for(; l<r; l/=2,r/=2){
        if(l&1) res += st[l++];
        if(r&1) res += st[--r];
    }
    return res;
}

int main()
{
    FAST_IO;

    cin>>n;
    st.resize(4*n+1);
    for(int i=0;i<n;++i)   //Input N array elements starting from index N in st
        cin>>st[n+i];

    build_st();
    cout<<"Indixes are 0-based\n";
    cout<<"Sum(3,6): "<<query(3,7)<<"\n";
    cout<<"Sum(1,7): "<<query(1,8)<<"\n";
    cout<<"Sum(2,6): "<<query(2,7)<<"\n";
    cout<<"Sum(1,3): "<<query(1,4)<<"\n";
    update(3,10);
    cout<<"Sum(3,6): "<<query(3,7)<<"\n";
    update(5,100);
    cout<<"Sum(2,6): "<<query(2,7)<<"\n";
    return 0;
}
