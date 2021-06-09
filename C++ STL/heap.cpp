#include<bits/stdc++.h>
using namespace std;
void show(std::vector<int> v){
    std::vector<int>::iterator it = v.begin();
    while(it!=v.end()){
        std::cout << *it << " ";it++;
    }
    cout<<"\n";
}
int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,88};
    make_heap(v.begin(),v.end());
    show(v);
    v.push_back(23);
    show(v);
    push_heap(v.begin(),v.end());
    show(v);
    pop_heap(v.begin(),v.end());
    std::cout << v.back() << std::endl;
    v.pop_back();
    pop_heap(v.begin(),v.end());
    v.pop_back();
    std::cout << v.back() << std::endl;show(v);

}
