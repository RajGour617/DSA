#include<iostream>
using namespace std;

class stack{
	public:
		int top;
		int arr[3];
	public:
		
		stack(){
			top=-1;
		}
		
		void push(int d){
			if(top>=2){
				cout<<"Stack overflow"<<endl;
				return;
			}
			arr[++top]=d;	
		}
		
		int pop(){
			if(top==-1){
				cout<<"Stack underflow"<<endl;
				return -1;
			}
			int t= arr[top];
			arr[top]=-1;
			top--;
			return t;	
		}
		
		int peek(){
			if(top==-1){
				cout<<"stack underflow"<<endl;
				return -1;
			}
			cout<<"Top element:"<<arr[top]<<endl;
		}
		
		void display(){
			if(top==-1){
				cout<<"Stack underflow"<<endl;
			}
			for(int i=0;i<3;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	stack s;
	s.push(2);
	s.push(4);
	s.push(6);
	s.display();
	s.peek();
	s.push(10);
	s.pop();
	s.display();
	s.peek();
	s.pop();
	s.pop();
	s.pop();
	s.display();
	s.peek();
}
