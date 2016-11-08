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
	next = NULL;
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
			return true;
		} else {
			return this->left->insert(Val);
		}
	} else if (Val==value) {
		return false;
	} else {
		if (this->right==NULL) {
			this->right = new BST(Val);
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
bool BST<T>::display() {
	if (Val<value) {
		if (this->left!=NULL) {
			this->left->display(Val);
		}
	} else if (Val==value) {
		cout << T << ",";
	} else {
		if (this->right!=NULL) {
			this->right->display(Val);
		}
	}
	
	return true;
}

template<typename T> 
BST* BST<T>::FindMax() {
	if (this->right!=NULL) {
		return this->right->FindMax();
	} else {
		return this;
	}
}

template<typename T> 
BST* BST<T>::Locate(const T & Val) {
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
	
	if (where->left==NULL) {
		if (where->prev != NULL) {
			if (where->prev->left == where) {
				where->prev->left = where->right;
			} else {
				where->prev->right = where->right;
			}
			delete where;
			return true;
		} else {
			if (where->right!=NULL) {
				where->value = where->right->value;
				where->left = where->right->left;
				where->right = where->right->right;
				delete where->right
			} else {
				delete this;
				return true;
			}
		}
	} else if (where->right==NULL) {
		if (where->prev != NULL) {
			if (where->prev->left == where) {
				where->prev->left = where->left;
			} else {
				where->prev->right = where->left;
			}
			delete where;
			return true;
		} else {
			where->value = where->left->value;
			where->right = where->left->right;
			where->left = where->left->left;
			delete where->left;
		}
	} else {
		BST* replace;
		
		replace = FindMax(where->left);
		
		where->value = replace->value;
		
		remove(replace);
		
		return true;
	}
}






