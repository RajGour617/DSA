#include<iostream>
using namespace std;

void InsertSort(int* arr,int size){
	for	(int i=0;i<size;i++){
//   		int minind=0;
		int temp=arr[i];
		for(int j=i-1;j>=0;j--){
			if(arr[j]>arr[i]){
				arr[j]=arr[j+1];
			}
		arr[j]=temp;			
		}
	}
}



int main(){
	int size;
	cout<<"Enter the size"<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter elements: "<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	InsertSort(arr,size);
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
