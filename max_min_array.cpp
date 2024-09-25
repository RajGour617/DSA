#include<iostream>
using namespace std;

int maxi(int arr[]){
	int max= 0;
	for(int i=0; i<7; i++){
		if(max<arr[i]){
		 max=arr[i];
	    }
	}
	return max;
}

int mini(int arr[]){
	int min=0;
	for(int i=0; i<7; i++){
		if(min>arr[i]){
			min=arr[i];
		}
	}
	return min;
}

int main(){
	int arr[7]= {790,45,23,71,650,18,346};
	cout<<"Max value:"<<maxi(arr)<<endl;
	cout<<"Min value:"<<mini(arr)<<endl;
	return 0;
}
