#include "ListMyJosephus.hpp"

ListMyJosephus::ListMyJosephus(int m, int n){
	this->_m = m;
	this->_n = n;
	this->_itc = _l.begin();
}

ListMyJosephus::~ListMyJosephus(){
	delete &_l;
}

void ListMyJosephus::clear(){
	_l.clear();
}

int ListMyJosephus::currentSize(){
	return _l.size();
}

bool ListMyJosephus::isEmpty(){
	return _l.empty();
}

Destination ListMyJosephus::eliminateDestination(){
	// Checking if there's only one element in the list
	Destination popped;
	if(_l.size() == 1){
		this->_itc = _l.begin();
		popped = *(this->_itc);
	 	_l.erase(this->_itc);
	 	return popped;
	}

	// Iterating through the loop M times
	for(int i = 0; i < this->_m; ++i){
		if(this->_itc == _l.end())  		// If the iterators at the end, set it equal to the front
			this->_itc = _l.begin();        // so the list is traversed like a loop
		else
			++this->_itc;
	}

	// if the iterator is at the end of the list, move it back to the front 
	if(this->_itc == _l.end()) 
		this->_itc = _l.begin();     


	// Creating another iterator so we don't lose the position of this->_itc when erase() is called
	popped = *(this->_itc);
	std::list<Destination>::iterator it = this->_itc;
	++this->_itc;											
	_l.erase(it);

	return popped; // Returning deleted element
}

void ListMyJosephus::printAllDestinations(){
	for(auto &it : _l) // auto keyword tells compiler to derive std::list<Destination>::iterator all from l
	{											
		it.printPosition();
		std::cout << " "; 
		it.printDestinationName();
		std::cout << std::endl;
	}
}

void ListMyJosephus::addDestination(const Destination &d){
	_l.push_back(d);
}

int ListMyJosephus::getN(){
	return this->_n;
}

int ListMyJosephus::getM(){
	return this->_m;
}