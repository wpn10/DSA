#include<bits/stdc++.h>
using namespace std;

vector<int> st;

void buildSegmentTree(int st_idx,vector<int>& arr,int start,int end){
	if(start > end)	//Invalid Case
		return;
	if(start==end){	//LeafNode case
		st[st_idx] = arr[start];
		return;
	}

	//InternalNode case
	int middle = start + (end-start)/2;
	buildSegmentTree(2*st_idx,arr,start,middle);
	buildSegmentTree(2*st_idx+1,arr,middle+1,end);
	st[st_idx] = st[2*st_idx] + st[2*st_idx+1];
}

int query(int qs,int qe,int st_idx,int start,int end){
	if(qs>end or qe<start)	//No Overlap
		return 0;
	if(start>=qs and end<=qe)	//Full Overlap
		return st[st_idx];

	//Partial Overlap case
	int middle = start + (end-start)/2;
	int leftSum = query(qs,qe,2*st_idx,start,middle);
	int rightSum = query(qs,qe,2*st_idx+1,middle+1,end);
	return leftSum + rightSum;
}

void updateNode(int st_idx,int start,int end,int pos,int newValue){
	if(start>pos or end<pos)	//No overlap case
		return;
	if(start==end){	//LeafNode Case
		st[st_idx] = newValue;
		return;
	}

	//Internal Node case
	int middle = start + (end-start)/2;
	updateNode(2*st_idx,start,middle,pos,newValue);
	updateNode(2*st_idx+1,middle+1,end,pos,newValue);
	st[st_idx] = st[2*st_idx] + st[2*st_idx+1];
}


int main()
{
	int n=6;
	vector<int> arr = {1,3,2,-2,4,5};

	st.resize(4*n+1);
	int st_idx = 1;
	int start = 0,end = n-1;

	//Preprocess
	buildSegmentTree(st_idx,arr,start,end);
	cout<<"\nSegment Tree is:-\n";
	for(int i=0;i<=4*n;++i)
		cout<<st[i]<<" ";
	cout<<"\n";

	cout<<"Query is 0-based indexed\n";
	cout<<"RangeSum(2,4): "<<query(2,4,st_idx,start,end)<<"\n";	
	cout<<"RangeSum(1,4): "<<query(1,4,st_idx,start,end)<<"\n";	
	cout<<"RangeSum(3,3): "<<query(3,3,st_idx,start,end)<<"\n";

	arr[2] = 100;
	updateNode(st_idx,start,end,2,100);

	cout<<"\nSegment Tree is:-\n";
	for(int i=0;i<=4*n;++i)
		cout<<st[i]<<" ";
	cout<<"\n";

	cout<<"Query is 0-based indexed\n";
	cout<<"RangeSum(2,4): "<<query(2,4,st_idx,start,end)<<"\n";	
	cout<<"RangeSum(1,4): "<<query(1,4,st_idx,start,end)<<"\n";	
	cout<<"RangeSum(3,3): "<<query(3,3,st_idx,start,end)<<"\n";

	return 0;
}
