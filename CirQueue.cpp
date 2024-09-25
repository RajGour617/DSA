#include<iostream>
using namespace std;

class cirqueue{
	int size, front, rear;
	int* arr;
	
	public:
	cirqueue(int size){
		this->size=size;
		arr=new int[size];
		front=rear=-1;
	}
	
	void add(int d){
		if(front==0&&rear==size-1||front!=0&&rear==front-1){
			cout<<"Queue overflow"<<endl;
			return;
		}
		else  if(rear==-1){
			front=rear=0;
			arr[rear]=d;
		}
		else if(front!=0&&rear==size-1){
			rear=0;
			arr[rear]=d;
		}
		else{
			arr[++rear]=d;
		}
	}
	
	int del(){
		if(front==-1){
			cout<<"Queue underflow"<<endl;
			return -1;
		}
		int t=arr[front];
		arr[front]=-1;
		if(front==rear){
			front=rear=-1;
		}
		else if(front==size-1){
			front=0;
		}
		else{
			front++;
		}
		return t;
	}
	
	void display(){
		if(front==-1){
			cout<<"Queue underflow"<<endl;
			return;
		}
		for(int i=front;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	cirqueue cq(3);
	cq.add(2);
	cq.add(4);
	cq.add(6);
	cq.display();
	cq.del();
	cq.display();
	cq.del();
	cq.display();
	cq.del();
	cq.display();
	
}
