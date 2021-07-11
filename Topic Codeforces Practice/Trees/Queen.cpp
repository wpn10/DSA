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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vll children[100005];
    ll c[n+10];
    vll ans;
    fi(i,0,n){
        ll x;
        cin>>x>>c[i];
        if(x!=-1){
            x--;
            children[x].pb(i);
        }}
        fi(i,0,n){
            if(c[i]==1){
                bool pos = 1;
                for(auto y : children[i]){
                    if(c[y]==0){
                        pos = 0;
                        break;
                    }
                }
                if(pos){
                    ans.push_back(i+1);
                }
            }
        }
        if(ans.size()>0){
            for(ll x : ans){
                cout<<x<<" ";
            }
        }else cout<<"-1\n";

    return 0;
}
