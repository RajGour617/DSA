#include<iostream>
using namespace std;

void PairSum(int arr[],int size,int target){
	int i=0;
	int j=size-1;
	while(i<j){
		int pairsum= arr[i]+arr[j];
		if(pairsum>target)
			j--;	
		else if(pairsum<target)
			i++;
		else{
			cout<<"("<<i<<", "<<j<<")"<<endl;
			break;
		}
//			else
//				cout<<"No pair sum= "<<target<<endl;
	}
}

int main(){
	int size,target;
	cout<<"Enter the size"<<endl;
	cin>>size;
	cout<<"Enter target"<<endl;
	cin>>target;
	int arr[size];
	cout<<"Enter elements: "<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	PairSum(arr,size,target);
}
