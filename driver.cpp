#include "BST.h"
#include <math.h>
#include <deque>
using namespace std;
#define nodes 1000
template <typename element> 
element* balancedBST(element list[], int length) {
	element* retVal = new element[length];
	for(int i=0; i < length; i++) {
		*(retVal + i) = 0;
	}
	deque<element> deque;
	int count = 0;
	retVal[count++] = list[length/2];
	deque.push_back(0);
	deque.push_back((length/2)-1);
	deque.push_back((length/2)+1);
	deque.push_back(length - 1);
	while(!deque.empty()) {
		int lower = deque.front();
		deque.pop_front();
		int upper = deque.front();
		deque.pop_front();
		retVal[count++] = list[(lower+upper)/2];
		if(upper - lower == 1) {
			deque.push_back(upper);
			deque.push_back(upper);
		} else if(upper - lower == 0) {
			//don't do anything
		} else  {
			deque.push_back(lower);
			deque.push_back(((lower+upper)/2) - 1);
			deque.push_back(((lower+upper)/2) + 1);
			deque.push_back(upper);
		}
	}	
	return retVal;
}

int main() {
	srand(time(NULL));
	BST<int> tree; 
	int arr[nodes];
	for(int i=0; i < nodes; i++) {
		arr[i] = i;
	}
	int* balancedArr = balancedBST(arr, nodes);
	random_shuffle(arr, arr + nodes);
	/*
	for(int i=0; i < nodes; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for(int i=0; i < nodes; i++) {
		cout << *(balancedArr + i) << " ";
	}
	*/
	delete [] balancedArr;
	return 0;
}