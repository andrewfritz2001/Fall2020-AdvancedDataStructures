#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

template <typename T>
class AVLNode{
private: 
	T data;
	int height;
	AVLNode<T>* left,
	          * right;

public:
	AVLNode(){
		height = 1;
		left = nullptr;
		right = nullptr;
	}
	AVLNode(T d){
		data = d;
		height = 1;
		left = nullptr;
		right = nullptr;
	}
	~AVLNode(){
		left = nullptr;
		right = nullptr;
	}

	// Setters
	void setData(T d){ this->data = d;}
	void setHeight(int h){ this->height = h;}
	void setLeft(AVLNode<T>* l){ this->left = l;}
	void setRight(AVLNode<T>* r){ this->right = r;}
	// Getters
	T getData(){ return this->data;}
	int getHeight(){ return this->height; }
	AVLNode<T>* getLeft(){ return this->left; }
	AVLNode<T>* getRight(){ return this->right; }
};

#endif