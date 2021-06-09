        #include<bits/stdc++.h>
using namespace std;
void quick(vector<int>&arr, int s, int ind){
    if(s==ind){
        return;
    }
    int m = s-1;
    for(int i =s; i<ind; i++){
        if(arr[i]<arr[ind]){
            m++;
            swap(arr[m],arr[i]);
        }
    }
    swap(arr[ind],arr[m+1]);
    if(m>0){
    quick(arr,s,m);}
    if(m<ind){
    quick(arr,m+2,ind);
}}
int main() {
    int n,c;
    cin>>n;
    std::vector<int> arr;
    for(int i=0; i<n; i++){
        cin>>c;
        arr.push_back(c);
    }
    quick(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}
