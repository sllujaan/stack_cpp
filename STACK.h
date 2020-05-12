#include"Exception.h"


#define MAX 10 


template<class T, int totalSize = MAX>
class STACK : public SizeException{
	
	public:
		int size;
	private:
		int topIndex;
		T arr[totalSize];
		
		pushElementToStack(T a) {
			this->canPushNewElement();
			if(this->isEmpty()) this->initStack();
			this->arr[++this->topIndex] = a;
			this->size++;
		}
		
		pushArrToStack(const T arr[], int len) {
			
			if(this->isEmpty()) this->initStack();
			this->validateArray(len);
			

			for(int i=0; i<len; i++) {
				cout<<arr[i]<<endl;
				this->arr[++this->topIndex] = arr[i];
			}
			this->size = len;
			
		}
		
	
	public:
		//int size;
		STACK();
		template<size_t n>
		STACK(T (&arr)[n]);
		STACK(T a);
		void push(T value);
		template<size_t n>
		void push(T (&arr)[n]);
		int pop();
		bool isEmpty();
		bool isFull();
		void print();
		void initStack();
		void debug();
		void validateArray(int array_size);
		void canPushNewElement();
};

template<class T, int totalSize>
STACK<T, totalSize>::STACK() {
	this->initStack();
}

template<class T, int totalSize>
template<size_t n>
STACK<T, totalSize>::STACK(T (&arr)[n]) {
	cout<<"arr called."<<endl;
	if(totalSize < 5) throw SizeException("Stack must be of size 5.");
	if(n > totalSize) throw SizeException("Provided array is larger than the stack size.");
	
	this->pushArrToStack(arr, n);
	
}

template<class T, int totalSize>
STACK<T, totalSize>::STACK(T a) {
	this->initStack();
	this->pushElementToStack(a);
}

template<class T, int totalSize>
void STACK<T, totalSize>::push(T value) {
	this->pushElementToStack(value);
}

template<class T, int totalSize>
int STACK<T, totalSize>::pop() {
	if(this->isEmpty()) return '\0';
	
	T popedElement = this->arr[this->topIndex];
	this->arr[this->topIndex--] = '\0';
	this->size--;
	
	return popedElement;
}


template<class T, int totalSize>
template<size_t n>
void STACK<T, totalSize>::push(T (&arr)[n]) {
	cout<<"push array"<<endl;
	this->pushArrToStack(arr, n);
}


template<class T, int totalSize>
void STACK<T, totalSize>::validateArray(int array_size) {
	cout<<"validating...."<<endl;
	int remaindStackSpace = (totalSize - this->size);
	cout<<"remaindStackSpace = "<<remaindStackSpace<<endl;
	if(totalSize < 1) throw SizeException("Stack must be of size 1.");
	if( (array_size > totalSize) || (array_size > remaindStackSpace) ) throw SizeException("Provided array is larger than the stack size.");
}

template<class T, int totalSize>
void STACK<T, totalSize>::canPushNewElement() {
	if(totalSize < 1) throw SizeException("Stack must be of size 1.");
	if(this->isFull()) throw SizeException("Stack is Full.");
}

template<class T, int totalSize>
bool STACK<T, totalSize>::isFull() {
	if(this->size >= totalSize) return true;
	else return false;
}

template<class T, int totalSize>
bool STACK<T, totalSize>::isEmpty() {
	if(this->size <= 0) return true;
	else return false;
}



template<class T, int totalSize>
void print(STACK<T, totalSize> stack) {
	cout<<"print..."<<endl;
	stack.print();
}

template<class T, int totalSize>
void STACK<T, totalSize>::print() {
	
	cout<<"-------------------------------------"<<endl;
	cout<<"size = "<<this->size<<endl;
	cout<<"topIndex = "<<this->topIndex<<endl;
	cout<<"{";
	for(int i=0; i<this->size; i++) {
		cout<<this->arr[i];
		if(i < this->size-1) cout<<", ";
	}
	cout<<"}"<<endl;
	cout<<"-------------------------------------"<<endl;
}

template<class T, int totalSize>
void STACK<T, totalSize>::initStack() {
	this->topIndex = -1;
	this->size = 0;
}

template<class T, int totalSize>
void STACK<T, totalSize>::debug() {
	cout<<"###############################################"<<endl;
	cout<<"totalSize = "<<totalSize<<endl;
	cout<<"size = "<<size<<endl;
	this->print();
	cout<<"###############################################"<<endl;
}

/*
this->size += len;
			
			for(int i=0; i<len; i++) {
				
				cout<<"for = "<<arr[i]<<endl;
				
				cout<<this->topIndex<<endl;
				
				if(!this->topIndex) {cout<<"index was null ";this->topIndex = 0;}
				else {this->topIndex += 1;};
				
				this->arr[this->topIndex] = arr[i];
				
				//this->topIndex += 1;
				cout<<"top index = "<<this->topIndex<<endl;
			}

*/


/*
//length of the array.
			int len = sizeof(arr)/sizeof(arr[0]);
			/*
			this->topIndex = -1;
			for(int i=0; i<len; i++) {
				cout<<arr[i]<<endl;
				this->arr[++this->topIndex] = 12;
			}
			this->size = len;
			
			cout<<"fist = "<<this->arr[0]<<endl;
			cout<<"second = "<<this->arr[1]<<endl;
			cout<<this->topIndex<<endl;
			
			
			this->arr[0] = 20;
			this->arr[1] = 30;
			//this->topIndex = 1;
			
			cout<<"fist = "<<this->arr[0]<<endl;
			cout<<"second = "<<this->arr[1]<<endl;
			cout<<"this->topIndex address = "<<&this->topIndex<<endl;
			cout<<"this->arr[0] address = "<<&this->arr[0]<<endl;
			cout<<"this->arr[1] address = "<<&this->arr[1]<<endl;
			cout<<"this->size address = "<<endl;
*/

