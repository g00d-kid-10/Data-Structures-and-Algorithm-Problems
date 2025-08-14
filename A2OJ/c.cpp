#include <iostream>
using namespace std;

class Queue {
private:
	int *arr, left, right, cap;

public:
	Queue() : left(0), right(0), cap(2) {
		arr = new int[cap];
	}

	void push(int x) {
		if(size() == cap) {
			cap *= 2;
			int *tempArr = new int[cap];
			for(int i = 0; i < size(); i++) tempArr[i] = arr[i];
			arr = tempArr;
		}
		arr[right++] = x;
	}

	void pop() {
		if(empty()) throw underflow_error("Underflow Occured!!");
		left++;
	}

	int front() {
		if(empty()) throw underflow_error("Underflow Occured!!");
		return arr[left];
	}

	int size() {
		return right - left;
	}

	bool empty() {
		return size() == 0;
	}

	void print() {
		while(!empty()) {
			cout << front() << " "; pop();	
		}
	}	
};

int main() {
	Queue q;
	q.push(45);
	q.push(38);
	q.push(15441);
	q.push(559);
	q.pop();
	q.push(11);
	q.pop();
	cout << q.front() << " "; 	// 15441
	cout << q.empty() << " "; 	// 0
	cout << q.size() << " "; 	// 3
	q.print();					// 15441 559 11
	return 0;
}