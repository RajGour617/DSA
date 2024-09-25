#include<iostream>
using namespace std;

void BubbleSort(int arr[],int size){
    int c=0;
	for(int i=0;i<size-1;i++){
		    bool flag=false;

		for(int j=0;j<size-i-1;j++){
			c++;
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				flag=true;
				
			}
		}
	
		if(flag==false)
			break;
		
	}
	cout<<c<<"=> ";
}

void swap(int a, int b){
			int temp;
			temp=a;
			a=b;
			b=temp;
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
	BubbleSort(arr,size);
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
