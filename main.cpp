using namespace std;
#include<iostream>
#include"STACK.h"



int main(int argc, char *argv[]) {
	
	int arr[] = {5, 6, 7};
	int len = sizeof(arr) / sizeof(*arr);
	
	//STACK<int> _stack;
	try{
		//STACK<int, 5> _stack = arr;
		//print(_stack);
		STACK<int, 5> _stack = 1;
		_stack.push(2);
		_stack.push(3);
		
		int poped = _stack.pop();
		poped = _stack.pop();
		poped = _stack.pop();
		poped = _stack.pop();
		poped = _stack.pop();
		cout<<"poped = "<<poped<<endl;
		_stack.push(2);
		_stack.push(3);
		print(_stack);
	}
	catch(Exception e) {
		cout<<e.msg<<endl;
	}
	
	
	//int arr[] = {};
	//int len = siz(arreof)/sizeof(arr[0]);
	//cout<<len<<endl;
}
