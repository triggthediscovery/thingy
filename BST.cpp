#ifndef _BST_CPP_
#define _BST_CPP_

#include"BST.h"
#include<stdlib.h>
#include<iostream>

using namespace std;

template<typename T> 
BST<T>::BST() {
	prev=NULL;
	left=NULL;
	right=NULL;
}
 
template<typename T> 
BST<T>::BST(T Val) {
	value = Val;
	prev = NULL;
	left = NULL;
	right = NULL;
}
 
template<typename T> 
BST<T>::~BST() {
	delete left;
	delete right;
}

template<typename T> 
bool BST<T>::insert(const T & Val) {
	if (Val<value) {
		if (this->left==NULL) {
			this->left = new BST(Val);
			this->left->prev = this;
			return true;
		} else {
			return this->left->insert(Val);
		}
	} else if (Val==value) {
		return false;
	} else {
		if (this->right==NULL) {
			this->right = new BST(Val);
			this->right->prev = this;
			return true;
		} else {
			return this->right->insert(Val);
		}
	}
}

template<typename T> 
bool BST<T>::find(const T & Val) {
	if (Val<value) {
		if (this->left==NULL) {
			return false;
		} else {
			return this->left->find(Val);
		}
	} else if (Val==value) {
		return true;
	} else {
		if (this->right==NULL) {
			return false;
		} else {
			return this->right->find(Val);
		}
	}
}

template<typename T> 
bool BST<T>::display() const {
	if (this->left!=NULL) {
		this->left->display();
	}
		
	cout << value << ",";
	
	if (this->right!=NULL) {
		this->right->display();
	}
	
	return true;
}

template<typename T> 
BST<T>* BST<T>::FindMax() {
	if (this->right!=NULL) {
		return this->right->FindMax();
	} else {
		return this;
	}
}

template<typename T> 
BST<T>* BST<T>::Locate(const T & Val) {
	if (Val<value) {
		if (this->left==NULL) {
			return NULL;
		} else {
			return this->left->Locate(Val);
		}
	} else if (Val==value) {
		return this;
	} else {
		if (this->right==NULL) {
			return NULL;
		} else {
			return this->right->Locate(Val);
		}
	}
}

template<typename T> 
bool BST<T>::remove(const T & Val) {
	BST* where;
	
	where = Locate(Val);
	
	if (where==NULL) return false;
	
	if (where->prev!=NULL) {
		if ((where->left!=NULL) && (where->right!=NULL)) {
			BST<T>* replace;
		
			replace = where->left->FindMax();
		
			T hold = replace->value;
		
			remove(replace->value);
			
			where->value = hold;
		
			return true;	
		} else if (where->left!=NULL) {
			if (where->prev->left==where) {
				where->prev->left=where->left;
			} else {
				where->prev->right=where->left;
			}
			delete where;
		} else if (where->right!=NULL) {
			if (where->prev->left==where) {
				where->prev->left=where->right;
			} else {
				where->prev->right=where->right;
			}
			delete where;
		} else {
			if (where->prev->left==where) {
				where->prev->left=NULL;
			} else {
				where->prev->right=NULL;
			}
			delete where;
		}
	} else {
		if ((where->left!=NULL) && (where->right!=NULL)) {
			BST<T>* replace;
		
			replace = where->left->FindMax();
		
			T hold = replace->value;
		
			remove(replace->value);
			
			where->value = hold;
		
			return true;
		} else if (where->left!=NULL) {
			BST* holdLeft=where->left;
		
			where->value = holdLeft->value;
			where->left = holdLeft->left;
			where->right = holdLeft->right;
			
			if (where->left!=NULL) where->left->prev=where;
			if (where->right!=NULL) where->right->prev=where;
			
			delete holdLeft;
		} else if (where->right!=NULL) {
			BST* holdRight=where->right;
		
			where->value = holdRight->value;
			where->left = holdRight->left;
			where->right = holdRight->right;
			
			if (where->left!=NULL) where->left->prev=where;
			if (where->right!=NULL) where->right->prev=where;
			
			delete holdRight;
		} else {
			delete this;
		}
	}
}

#endif




