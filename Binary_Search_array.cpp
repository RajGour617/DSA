#include<iostream>
using namespace std;

int binsearch(int arr[],int size,int key){
	int start=0;
	int end=size-1;
	int mid= (start+end)/2;
	
	while(start<=end){
		
		if(arr[mid]==key){
			return mid;
		}
		else{
			if(key>arr[mid]){
				start= mid+1;
			}
			else{
				end= mid-1;
			}
		mid= (start+end)/2;
		}
	}
	return -1;
}

int main(){

	int key;
	int arr[6]={2,4,7,8,11,12};
//	int odd[5]={1,3,5,7,9};
	
	cout<<"Enter element to search"<<endl;
	cin>>key;
	
	int arrInd= binsearch(arr,6,key);
	cout<<"Index of "<<key<<": "<<arrInd<<endl;
	
//	int oddInd= binsearch(odd,5,key);
//	cout<<"Index of "<<key<<": "<<oddInd<<endl;
	
}
