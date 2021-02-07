// map values can be overridden the final value being the latest update
#include<bits/stdc++.h>
using namespace std;
void show(map<char, int, greater<int>> my){
    map<char, int>::iterator it = my.begin();
    while(it!=my.end()){
        cout<<it->first<<"=>"<<it->second<<endl;
        it++;
    }
}
void showmap(unordered_map<char, int> my){
    unordered_map<char, int>::iterator it = my.begin();
    while(it!=my.end()){
        cout<<it->first<<"=>"<<it->second<<endl;
        it++;
    }
}
int main(){
    unordered_map<char, int> mymap;
    mymap['a'] = 10;
    mymap['c'] = 60;
    mymap['g'] = 0;
    mymap['r'] = 20;
    mymap['t'] = 80;
    mymap.insert(pair<char, int>('w',34)); // way of inserting 
    unordered_map<char, int> mymap2;
    mymap2.insert(mymap.begin(),mymap.find('a')); //way of inserting till N;
    showmap(mymap);
    cout<<"the new map is\n";
    showmap(mymap2);
    unordered_map <char, int>::iterator it;
    it = mymap2.find('w');
    cout<<"Key is:"<<it->first<<" The value at key is"<<it->second<<endl;
	mymap2.erase(it);//erasing by reference iterator pointing to the map;
	mymap.erase('c'); //erasing a value
	showmap(mymap2);
	cout<<mymap2.size()<<endl;
	cout<<mymap2.empty()<<endl;
	
	// Map is exactly similar to the unordered map we can implement things easily with this too;
	// Syntax map<key_data_type,val_data_type> name;
	// stored in form of pair pair<key type, value type> 
	//sorted by key // It is bidirectional;
	map<char, int> my1;
	// exactly same Syntaxas unordered map
	map<char, int, greater<char>> my2; // map<char, int, greater<int>> my2;  alternativelhy for ordering with second element;
	my2['a'] = 12;
	my2['d'] = 13;
	my2['e'] = 88;
	cout<<"The map begins in reverse heirarchy order"<<endl;
	show(my2);
	return 0;    
}
