template<template T> class BST{
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
		BST* Locate();
		
		T value;
		T* prev;
		T* left;
		T* right;
}

#include <BST.cpp>
