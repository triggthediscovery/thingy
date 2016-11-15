# thingy
it exists

The tester is for seperate tests for the BST.h.
The driver will contain the actual timer tests.
To run the tester functions run "make clean" then "./tester"

	tests:

	generate a random set of integers of size: 10000

	create three trees, one with that will be balanced versus a tree
	whose nodes will be randomly inserted and the final tree which will
	represent the worse time complexity -> its elements are inserted in sorted order

	we will compare the runtime complexity of these trees

	the 1st test will be a comparison of run time of inorder display
	hypothesis -> the runtime for each should be the same 
		do this test for trees of size 10, 100, 1000, 10000

	the 2nd test will consist of comparing the run times of the trees 
	for inserting one element at a time
		to be specific -> before an element is to be inserted, start the timer
		after every insert is called, stop the timer

		store the the runtime of the operation in an array
		for each tree store these times in an array and create a 
		graph comparing total runtime vs. # of nodes inside tree at time of insert
		do # of elements added in increments of 10

	the 3rd test will be comparing runtime of find operation
	this will occur at the same time as the test for insert
	after an insert has completed and been timed
	start the timer for a the find operation
	once done, stop the timer
	append these to an array

	seperate tree
	the last test will compare the times it takes to remove an element
	this test will be done in the same way
	after every 10 inserts
	start the timer for remove
	remove
	stop timer
	append this to an array
	create a graph of run time vs # of nodes inside the tree 

	the runtime will be compared for the 3 of these
	hypothesis -> ?



	the next test will cons
