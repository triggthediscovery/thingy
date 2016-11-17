#include "BST.h"
#include <math.h>
#include <fstream>
#include <chrono>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;
#define nodes 10000
#define micro 1000000
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::duration<float> fsec;

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
void createCSV(vector<float> arr, vector<float> arr1, vector<float> arr2, string file) {
	ofstream out;
	out.open(file);
	out << "nodes,sorted,random,balanced" << endl;
	for(int i=0; i < arr.size(); i++) {
		out << pow(10,i+1) << "," << arr[i] << "," << arr1[i] << "," << arr2[i] << endl;
	}
	out.close();
}
int main() {
	srand(time(NULL));

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
		vector<float> sortedRT;
		vector<float> shuffledRT;
		vector<float> balancedRT;
		//sorted
		int num_nodes = 10;
		while(num_nodes <= nodes) {
			auto t0 = Time::now();
			for(int i=0; i < num_nodes; i++) {
				sortedBST.insert(sorted[i]);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/num_nodes;
			sortedRT.push_back(duration);
			num_nodes *= 10;
		}
		num_nodes = 10;
		while(num_nodes <= nodes) {
			auto t0 = Time::now();
			for(int i=0; i < num_nodes; i++) {
				shuffledBST.insert(shuffled[i]);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/num_nodes;
			shuffledRT.push_back(duration);
			num_nodes *= 10;
		}
		num_nodes = 10;
		while(num_nodes <= nodes) {
			auto t0 = Time::now();
			for(int i=0; i < num_nodes; i++) {
				balancedBST.insert(balanced[i]);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/num_nodes;
			balancedRT.push_back(duration);
			num_nodes *= 10;
		}
		createCSV(sortedRT, shuffledRT, balancedRT, "./insertRT.csv");
	}
	
	//display test:
	{
		//create three trees
		BST<int> sortedBST;
		BST<int> shuffledBST;
		BST<int> balancedBST;
		vector<float> sortedRT;
		vector<float> shuffledRT;
		vector<float> balancedRT;

		//sorted
		int num_nodes = 10;
		int leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				sortedBST.insert(sorted[i]);
			}
			auto t0 = Time::now();
			for(int i=0; i < 100; i++) {
				sortedBST.display();
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			sortedRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		//shuffled
		num_nodes = 10;
		leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				shuffledBST.insert(shuffled[i]);
			}
			auto t0 = Time::now();
			for(int i=0; i < 100; i++) {
				shuffledBST.display();
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			shuffledRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		//sorted
		num_nodes = 10;
		leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				balancedBST.insert(balanced[i]);
			}
			auto t0 = Time::now();
			for(int i=0; i < 100; i++) {
				balancedBST.display();
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			balancedRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		createCSV(sortedRT, shuffledRT, balancedRT, "./displayRT.csv");
	}
	
	//find test: 
	{
		BST<int> sortedBST;
		BST<int> shuffledBST;
		BST<int> balancedBST;
		vector<float> sortedRT;
		vector<float> shuffledRT;
		vector<float> balancedRT;
		//sorted
		int num_nodes = 10;
		int leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				sortedBST.insert(sorted[i]);
			}
			auto t0 = Time::now();
			//find an element not inside the tree
			for(int i=0; i < 100; i++) {
				sortedBST.find(num_nodes);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			sortedRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		//shuffled
		num_nodes = 10;
		leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				shuffledBST.insert(shuffled[i]);
			}
			auto t0 = Time::now();
			//find an element not inside the tree
			for(int i=0; i < 100; i++) {
				shuffledBST.find(num_nodes);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			shuffledRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		//balanced
		num_nodes = 10;
		leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				balancedBST.insert(balanced[i]);
			}
			auto t0 = Time::now();
			//find an element not inside the tree
			for(int i=0; i < 100; i++) {
				balancedBST.find(num_nodes);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			balancedRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		createCSV(sortedRT, shuffledRT, balancedRT, "./findRT.csv");
	}

	//remove test:
	{
		BST<int> sortedBST;
		BST<int> shuffledBST;
		BST<int> balancedBST;
		vector<float> sortedRT;
		vector<float> shuffledRT;
		vector<float> balancedRT;
		//sorted
		int num_nodes = 10;
		int leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				sortedBST.insert(sorted[i]);
			}
			auto t0 = Time::now();
			//try to remove an element not inside the tree
			for(int i=0; i < 100; i++) {
				sortedBST.remove(num_nodes);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			sortedRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		//shuffled
		num_nodes = 10;
		leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				shuffledBST.insert(shuffled[i]);
			}
			auto t0 = Time::now();
			//try to remove an element not inside the tree
			for(int i=0; i < 100; i++) {
				shuffledBST.remove(num_nodes);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			shuffledRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		//shuffled
		num_nodes = 10;
		leftOff = 0;
		while(num_nodes <= nodes) {
			for(int i=leftOff; i < num_nodes; i++) {
				balancedBST.insert(balanced[i]);
			}
			auto t0 = Time::now();
			//try to remove an element not inside the tree
			for(int i=0; i < 100; i++) {
				balancedBST.remove(num_nodes);
			}
			auto t1 = Time::now();
			fsec fs = t1 - t0;
			//time in microseconds
			float duration = fs.count()*micro;
			duration = duration/100;
			balancedRT.push_back(duration);
			leftOff = num_nodes;
			num_nodes *= 10;
		}
		createCSV(sortedRT, shuffledRT, balancedRT, "./removeRT.csv");
	}
	delete [] balanced;
	return 0;
}
