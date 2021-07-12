#include<bits/stdc++.h>
using namespace std;
typedef long long ll;           //Type Names;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef queue<int> qi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef pair<int,int> pii;
typedef pair<char,int> pci;
typedef unordered_map<int,int> umii;
typedef map<int,int> mii;
typedef unordered_map<char,int> umci;
typedef map<char,int> mci;
#define F first                //Macros;
#define S second
#define pb push_back
#define mp make_pair
#define fi(i,a,b) for(int i=a; i<b; i++)
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
vll child[100005];
int ans;
ll a[100005];
ll sum[100005];
void dfs(ll curr, ll parent){
    ll parent_sum = 0;
    if(parent !=-1) parent_sum = sum[parent];
    if(sum[curr] == -1){
        ll minval = 2e9;
    for(ll it : child[curr]){
        minval = min(minval, sum[it]);
    }
    if(child[curr].size() == 0) minval = parent_sum;
    sum[curr] = minval ;}
    for(auto temp : child[curr]){
        dfs(temp, curr);
    }
    a[curr] = sum[curr] - parent_sum;
    ans =ans + a[curr];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i =0; i< n-1; i++){
        int m; cin>>m;
        m--;
        child[m].pb(i+1);
    }
    fi(i,0,n){
        cin>>sum[i];
    }
    bool pos = 1;
    dfs(0,-1);
    fi(i,0,n){
        if (a[i] == -1){
            pos = 0;break;
        }
    }
    if(pos)cout<<ans;
    else cout<<"-1";
    return 0;
}





