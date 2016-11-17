# thingy
it exists

To run the runtime tests run "make" and then "./driver"
The runtime tests will be stored in the insertRT.csv, 
displayRT.csv, findRT.csv, and insertRT.csv

The tester is for seperate tests for the BST.h.
The driver will contain the actual run time tests.
To run the tester functions run "make clean" then "./tester".

	tests:

	generate a random set of integers of size: 10000

	create three trees, one with that will be balanced versus a tree
	whose nodes will be randomly inserted and the final tree which will
	represent the worse time complexity -> its elements are inserted in sorted order

	we will compare the runtime complexity of these trees

	the 1st test will be a comparison of run time of inorder display
	hypothesis -> the runtime for each should be the same 
		do this test for trees of size 10, 100, 1000, 10000, etc.

	the 2nd test will consist of comparing the run times of the trees 
	for insertion
		take the time to insert 10 elements, then empty the tree, then take the time 
		insert 100 elements, then empty, etc.

		take the average runtime to insert an element in each case

	the 3rd test will be comparing runtime of find operation
		measure the time it takes to find an element not in the tree
		each tree would then have to search until it reached the bottom of the tree
		which is worst case scenario

	the 4th test is for remove
		basically the same as find
		try to remove an element not present in the tree
		this represents worst case scenario


	How the binary tree is built:

	write a function that returns an array which is passed a sorted array
	an array whose elements are ordered in such a way that 
	would create a balanced BST
	cannot take duplicates
	
	create a deque
	take the midpoint of the array
	insert into new array
	take the bounds of the subarray
	insert into deque
	while deque is not empty
	take the 2 numbers at end 
	repeat the above process

	if there are no duplicates then this method will always create 
	a balanced binary search treeå
