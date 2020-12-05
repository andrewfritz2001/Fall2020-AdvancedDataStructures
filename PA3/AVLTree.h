#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"

int COUNTER = 0; // This is for printing nodes

template <typename T>
class AVLTree{
private:
	AVLNode<T>* _root;


	// Simple helper that returns max of two nums
	int max(int a, int b){
		return (a > b)? a : b;
	}

	// Function to create a new tree node
	AVLNode<T>* newNode(T data){
		AVLNode<T>* node = new AVLNode<T>(data);
		return node;
	}

	/* RR and LL rotations are the exact same but with left and right values swapped   */
	AVLNode<T>* RRroto(AVLNode<T>* parent){
		//Rotation
		AVLNode<T>* temp;
		temp = parent->getRight();
		parent->setRight(temp->getLeft());
		temp->setLeft(parent);
		//Adjust for Height
		parent->setHeight(max(height(parent->getLeft()),height(parent->getRight()))+ 1);
		temp->setHeight(max(height(temp->getLeft()),height(temp->getRight()))+ 1);
		return temp;
	}
	AVLNode<T>* LLroto(AVLNode<T>* parent){
		//Rotation
		AVLNode<T>* temp;
		temp = parent->getLeft();
		parent->setLeft(temp->getRight());
		temp->setRight(parent);
		//Height Adjustment
		parent->setHeight(max(height(parent->getLeft()),height(parent->getRight()))+ 1);
		temp->setHeight(max(height(temp->getLeft()),height(temp->getRight()))+ 1);
		return temp;
	}

	/* LR and RL rotations are the exact same but with left and right values swapped   */
	AVLNode<T>* LRroto(AVLNode<T>* parent){
		AVLNode<T>* temp;
		temp = parent->getLeft();
		parent->setLeft(RRroto(temp));  // First rotation
		return LLroto(parent);          // Second rotation
	}
	AVLNode<T>* RLroto(AVLNode<T>* parent){
		AVLNode<T>* temp;
		temp = parent->getRight();
		parent->setRight(LLroto(temp));  // First rotation
		return RRroto(parent);           // Second rotation
	}		

	// Function takes in root and if tree is unbalanced a rotation is made
	AVLNode<T>* balanceTree(AVLNode<T>* r){
		if (balanceFactor(r) > 1){			      // If the tree is unbalanced on the left side
			if(balanceFactor(r->getLeft()) > 0)
				r = LLroto(r);
			else
				r = LRroto(r);
		}
		else if (balanceFactor(r) < -1){          // If the tree is unbalanced on the right side
			if(balanceFactor(r->getRight()) > 0)
				r = RLroto(r);
			else
				r = RRroto(r);
		}
		return r;
	}

	// Insertion Function similar to BST but with extra balancing step
	AVLNode<T>* insertHelp(AVLNode<T>* r, T data){
		/*  Inserting the Node like a typical BST  */
		if(r == nullptr)
			return newNode(data);
		
		/*Recursive calls to insert like a BST, but with
		    an 2 extra lines to adjust height and balance the tree */
		if (data >= r->getData())
			r->setRight(insertHelp(r->getRight(), data)); 				   
		else if (data < r->getData())
			r->setLeft(insertHelp(r->getLeft(), data)); 
		else
			return r;

		/*After BST insertion, setting height and 
			balancing tree to adhere to AVL Tree properties */
		r->setHeight(1 + max(height(r->getLeft()),height(r->getRight())));
		r = balanceTree(r);	

		return r;
	}

	/*****
		When removing a node, one of three cases is true. 
		1. The target node has no children 
		2. The target node has one child
		3. The target node has two children       *****/
	AVLNode<T>* removeHelp(AVLNode<T>* r, T data){
		if (r == nullptr)
			return r;

		AVLNode<T>* temp;
		if( data < r->getData())
			r->setLeft(removeHelp(r->getLeft(), data));
		else if (data > r->getData())
			r->setRight(removeHelp(r->getRight(), data));
		else{
			if(r->getLeft() == nullptr || r->getRight() == nullptr){
				if (r->getLeft() == nullptr && r->getRight() == nullptr){ 
					temp = r;
					r = nullptr;                       //CASE 1
					free(temp);
				}
				else{		                          
					if(r->getLeft() != nullptr){
						temp = r->getLeft();		   //CASE 2
						*r = *temp;
						free(temp);
					}
					else{
						temp = r->getRight();
						*r = *temp;
						free(temp);
					}
				}
			}
			else{
				temp = minHelp(r->getRight());         // CASE 3
				r->setData(temp->getData());  
				r->setRight(removeHelp(r->getRight(), temp->getData()));
			}
		}

		if(r == nullptr)
			return r;

		// Height adjustment and balancing to adhere to AVL Tree properties 
		r->setHeight(1 + max(height(r->getLeft()),height(r->getRight())));
		r = balanceTree(r);	

		return r;
	}

	// Clear Function
	void clearHelp(AVLNode<T>* r){
		if (r!= nullptr){
			clearHelp(r->getLeft());
			clearHelp(r->getRight());
			delete r;
		}
	}

	// Print Function
	void printInOrderHelp(AVLNode<T>* r, std::string label){
		if(r == nullptr)
			return;
		printInOrderHelp(r->getLeft(), label);
		
		++COUNTER; 
		std::cout << "<" << std::setw(6) << label<< ":"
				  << std::setw(3) << COUNTER << ". " << r->getData()  << ">" << std::endl;

		printInOrderHelp(r->getRight(), label);
	}     

	//Helper to get smallest tree value
	AVLNode<T>* minHelp(AVLNode<T>* r){
		AVLNode<T>* temp = r;
		while(temp->getLeft() != nullptr)
			temp = temp->getLeft();
		return temp;
	}

	//Helper to get largest tree value
	AVLNode<T>* maxHelp(AVLNode<T>* r){
		AVLNode<T>* temp = r;
		while (temp->getRight() != nullptr)
			temp = temp->getRight();
		return temp;
	}

/* ********* ** PUBLIC MEMBER FUNCTIONS ** ********* */

public:
	// Necessary Constructors and Destructor 
	AVLTree(){
		this->_root = nullptr;
	}
	AVLTree(T data){
		this->_root = this->newNode(data);
	}
	~AVLTree(){
		clear();
	}

	// Basic isEmpty() function
	bool isEmpty(){
		return (this->_root == nullptr) ? true : false;
	}

	// Returns height of the node or 0 if nullptr
	int height(AVLNode<T>* node){
		return (node == nullptr) ? 0 : node->getHeight();
	}

	// Returns the balance factor of any given node
	int balanceFactor(AVLNode<T>* n){
		if(n == nullptr)
			return 0;
		return height(n->getLeft())-height(n->getRight());
	}

	// Recursively destroys tree
	void clear(){ 			
		this->clearHelp(this->_root);
		this->_root = nullptr;
	}

	// Print function
	void printInOrder(std::string label){ 
		this->printInOrderHelp(this->_root, label); 
		COUNTER = 0;
	}

	//AVL Insert
	void insert(T data){ 
		this->_root = this->insertHelp(this->_root, data);
	}

	//AVL removal 
	void remove(T data){ 
		this->_root = this->removeHelp(this->_root, data);
	}	

	// Returns smallest item
	T findMin(){ 
		return (this->minHelp(this->_root))->getData(); 
	}

	// Returns largest item 
	T findMax(){ 
		return (this->maxHelp(this->_root))->getData(); 
	}
};

#endif