#include "BST.h"
#include <math.h>
#include <chrono>
#include <deque>
using namespace std;
#define nodes 10000
#define micro 1000000
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

	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::duration<float> fsec;

	int sorted[nodes];
	int shuffled[nodes];
	int pre_balanced[nodes];
	for(int i=0; i < nodes; i++) {
		sorted[i] = i;
		shuffled[i] = i;
		pre_balanced[i] = i;
	}
	random_shuffle(shuffled, shuffled + nodes);
	int* balanced = balancedBST(pre_balanced, nodes);

	//insert test:
	{
		//create three trees
		BST<int> sortedBST;
		BST<int> shuffledBST;
		BST<int> balancedBST;
		float sortedRT[nodes];
		float shuffledRT[nodes];
		float balancedRT[nodes];
		//sorted
		for(int i=0; i < nodes; i++) {
			//take the time
			auto t0 = Time::now();
			sortedBST.insert(sorted[i]);
    		auto t1 = Time::now();
    		//time in microseconds
    		fsec fs = t1 - t0;
    		float duration = fs.count()*micro;
    		sortedRT[i] = duration;
			//insert this into an array
		}
		//shuffled
		for(int i=0; i < nodes; i++) {
			//take the time
			auto t0 = Time::now();
			shuffledBST.insert(shuffled[i]);
    		auto t1 = Time::now();
    		//time in microseconds
    		fsec fs = t1 - t0;
    		float duration = fs.count()*micro;
    		shuffledRT[i] = duration;
			//insert this into an array
		}
		//balanced
		for(int i=0; i < nodes; i++) {
			//take the time
			auto t0 = Time::now();
			balancedBST.insert(balanced[i]);
    		auto t1 = Time::now();
    		//time in microseconds
    		fsec fs = t1 - t0;
    		float duration = fs.count()*micro;
    		balancedRT[i] = duration;
			//insert this into an array
		}
		//graph them
		//for(int i=0; i< nodes; i++) {
			cout << sortedRT[nodes-1] << " ";
		//}
		cout << endl;
		//for(int i=0; i< nodes; i++) {
			cout << shuffledRT[nodes-1] << " ";
		//}
		cout << endl;
		//for(int i=0; i< nodes; i++) {
			cout << balancedRT[nodes-1] << " ";
		//}
	}
	//display test:
	{

	}
	//find test:
	{

	}
	//remove test:
	{

	}

	delete [] balanced;
	return 0;
}