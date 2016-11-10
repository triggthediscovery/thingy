#include <vector>
#include "BST.h"

#define nodes 10
using namespace std;
int main() {
	srand(time(NULL));
	//test insert
	{	
		int arr[nodes];
		int maxVal = 100;
		//primitive type
		BST<int> tree1;
		for(int i=0; i < nodes; i++) {
			int val = rand() % maxVal;
			//tree1.insert(val);
			arr[i] = val;
		}
		sort(arr, arr + nodes);

		//check that arr and tree1.display() match 
		//inorder traversal of tree1 is same as sorted array
		for(int i=0; i < nodes; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		//tree1.display();
		//type containing pointers
		BST<vector<int>> tree2;

		//passing a reference to an object on the heap
	}
	return 0;
}