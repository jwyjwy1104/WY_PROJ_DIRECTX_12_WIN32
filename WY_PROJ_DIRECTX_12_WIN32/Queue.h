#pragma once

#include <stdio.h>

#define DEFAULT_QUEUE_CAPACITY 100

#ifndef _QUEUE_H_
#define _QUEUE_H_
template <class ElementType>
class Queue {
private:
	ElementType **queue;
	int numElements;
	int capacity;

public:
	// Default constructor
	Queue();

	// General constructor
	Queue(int capacity);

	// Destructor
	~Queue();

	// Main Queue print function
	void printQueue();

	// Description: Returns the number of elements in the Queue.
	// (This method eases testing.)
	// Time Efficiency: O(1)
	int getElementCount() const;

	// Description: Returns "true" is this Queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Adds newElement to the "back" of this Queue 
	//              (not necessarily the "back" of its data structure) and 
	//              returns "true" if successful, otherwise "false".
	// Time Efficiency: O(1)
	bool enqueue(ElementType &newElement);

	// Description: Removes the element at the "front" of this Queue 
	//              (not necessarily the "front" of its data structure) and  
	//              returns "true" if successful, otherwise "false".
	// Precondition: This Queue is not empty.
	// Time Efficiency: O(1)
	bool dequeue();

	// Description: Returns (a copy of) the element located at the "front" of 
	//				this Queue.
	// Precondition: This Queue is not empty.
	// Postcondition: This Queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
	// Time Efficiency: O(1)
	ElementType *peek();

	// Description: Get the element at the "index" of this Queue and
	//              returns the element's pointer if successful, otherwise NULL.
	// Precondition: This Queue is not empty. 
	//				 Index is smaller than element count.
	// Time Efficiency: O(N)
	ElementType *getElementAtIndex(int index);

	// Description: Remove all the element valid in this Queue.
	// Time Efficiency: O(N)
	void removeAll();
};
#endif

// Description: Default constructor
template <class ElementType>
Queue<ElementType>::Queue() {
	// Set maximum size of the queue with default constant value 100
	this->capacity = DEFAULT_QUEUE_CAPACITY;

	// Init queue data structure
	this->queue = new ElementType*[this->capacity]();
	for (int i = 0; i < this->capacity; i++) {
		this->queue[i] = NULL;
	}

	// Number of elements in queue
	this->numElements = 0;
}

// Description: General constructor
template <class ElementType>
Queue<ElementType>::Queue(int capacity) {
	// Set maximum size of the queue with default constant value 100
	this->capacity = capacity;

	// Init queue data structure
	this->queue = new ElementType*[this->capacity]();
	for (int i = 0; i < this->capacity; i++) {
		this->queue[i] = NULL;
	}

	// Number of elements in queue
	this->numElements = 0;
}

// Description: Destructor
template <class ElementType>
Queue<ElementType>::~Queue() {
	// De-init queue data structure
	delete[] this->queue;
	for (int i = 0; i < this->numElements; i++) {
		if (this->queue[i] != NULL) {
			delete this->queue[i];
		}
	}
	// Number of elements in queue
	this->numElements = 0;

	// Maximum size of the queue
	this->capacity = 0;
}

// Description: Main Queue print function
template <class ElementType>
void Queue<ElementType>::printQueue() {
	// Iterate and print the ElementType object stored in "this" queue data structure
	for (int i = 0; i < this->numElements; i++) {
		//cout << *this->queue[i];

		//_RPT1(0, "%d", *this->queue[i]);
		//_RPT1(0, "(%f,%f,%f)", ((XMFLOAT3)*this->queue[i]).x, ((XMFLOAT3)*this->queue[i]).y, ((XMFLOAT3)*this->queue[i]).z);
	}
	_RPT1(0, "\n", 0);
}

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int Queue<ElementType>::getElementCount() const {
	return this->numElements;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
	return (this->numElements == 0);
}

// Description: Adds newElement to the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement) {
	// Insert the element to where numElements index is
	this->queue[this->numElements] = new ElementType();
	*this->queue[this->numElements] = newElement;

	// Increment numElements index by one
	this->numElements++;

	return true;
}

// Description: Removes the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure) and  
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::dequeue() {
	// Return false if no element in the queue
	if (this->numElements <= 0) {
		return false;
	}
	// Return false if head of the queue is invalid 
	if (this->queue[0] == NULL) {
		return false;
	}

	// Else dequeue element
	delete this->queue[0];
	this->queue[0] = NULL;

	// Move all the rest of the element up by one index
	for (int i = 1; i < this->numElements; i++) {
		if (this->queue[i] != NULL) {
			this->queue[i - 1] = this->queue[i];
			this->queue[i] = NULL;
		}
	}

	// Decrement numElements index by one
	this->numElements--;

	return true;
}

// Description: Returns (a copy of) the element located at the "front" of this 
//				Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType *Queue<ElementType>::peek() {
	if (this->numElements > 0) {
		if (this->queue[0] != NULL) {
			return this->queue[index];
		}
	}
	// Error
	_RPT1(0, "################################################################################\n", 0);
	_RPT1(0, "ERROR::Queue::peek::Queue is empty cannot get peek of the queue!!!\n");
	_RPT1(0, "################################################################################\n", 0);
	throw std::runtime_error("Could not get peek of the queue");
	//return NULL;
}

// Description: Get the element at the "index" of this Queue and
//              returns the element's pointer if successful, otherwise NULL.
// Precondition: This Queue is not empty. 
//				 Index is smaller than element count.
// Time Efficiency: O(1)
template <class ElementType>
ElementType *Queue<ElementType>::getElementAtIndex(int index) {
	if (this->numElements > 0 && index < this->numElements) {
		if (this->queue[index] != NULL) {
			return this->queue[index];
		}
	}
	// Error
	//return NULL;
	//_RPT1(0, "################################################################################\n", 0);
	//_RPT1(0, "ERROR::Queue::getElementAtIndex::Cannot get the element on the given index of the queue!!!\n", 0);
	//_RPT1(0, "################################################################################\n", 0);
	throw std::runtime_error("Could not get the element on the given index of the queue");
}

// Description: Remove all the element valid in this Queue.
// Time Efficiency: O(N)
template <class ElementType>
void Queue<ElementType>::removeAll() {
	for (int i = 0; i < this->numElements; i++) {
		if (this->queue[i] != NULL) {
			delete this->queue[i];
			this->queue[i] = NULL;
		}
	}
	this->numElements = 0;
}