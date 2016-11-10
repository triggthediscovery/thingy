#ifndef _BST_H_
#define _BST_H_

template<typename T> class BST{
	public:
		BST();
		
		BST(T);
		
		~BST();
		
		bool insert(const T &);
		bool remove(const T &);
		bool find(const T &);
		bool display() const;
	private:
		BST* FindMax();
		BST* Locate(const T & Val);
		
		T value;
		BST* prev;
		BST* left;
		BST* right;
};

#include "BST.cpp"

#endif
