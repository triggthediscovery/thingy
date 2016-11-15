#include "BST.h"
#include <math.h>
#include <deque>
using namespace std;
#define nodes 1000
//write a function that returns an array which is passed a sorted array
//an array whose elements are ordered in such a way that 
//would create a balanced BST
//cannot take duplicates
template <typename element> 
element* balancedBST(element list[], int length) {
	element* retVal = new element[length];
	for(int i=0; i < length; i++) {
		*(retVal + i) = 0;
	}
	//create a deque
	//take the midpoint of the array
	//insert into new array
	//take the bounds of the subarray
	//insert into deque
	//while deque is not empty
	//take the 2 numbers at end 
	//repeat the above process
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