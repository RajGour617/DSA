#include<iostream>
using namespace std;

int search(int arr[], int key){
	for(int i=0; i<7; i++){
		if(arr[i]==key){
		 return 1;
		}
	}
	return 0;
}

int main(){
	int key;
	int arr[7]={13,21,37,42,56,65,71};
	cout<<"Enter element to search"<<endl;
	cin>>key;
	
	int found= search(arr, key);
	if(found){
		cout<<key<<" is found"<<endl;	
	}
	else{
		cout<<key<<" not found"<<endl;
	}
}
