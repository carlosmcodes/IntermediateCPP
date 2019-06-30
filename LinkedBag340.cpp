//	LinkedBag340.cpp
//	Created by: CSC340
#include "LinkedBag.h"


template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {

	std::shared_ptr<Node<ItemType>> curNode = headPtr;
	std::shared_ptr<Node<ItemType>> temp = nullptr;
	if (curNode->getNext()) {
		std::shared_ptr<Node<ItemType>> toDelete = nullptr;
		toDelete = curNode->getNext();
		temp = curNode->getNext()->getNext();
		curNode->setNext(temp);

		// delete
		//toDelete->setNext(nullptr);
		toDelete.reset();
		itemCount--;
	}
	return true;



};

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item) {
	std::shared_ptr<Node<ItemType>> Iteratepiano = headPtr;
	while (Iteratepiano->getNext()) {
		Iteratepiano = Iteratepiano->getNext();
	}
	std::shared_ptr<Node<ItemType>> add {std::make_shared<Node<ItemType>>()}; // creates pointer to new node
	add->setItem(item);
	Iteratepiano->setNext(add);

	itemCount++;
	return true;
};

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	std::shared_ptr<Node<ItemType>> count = headPtr;
	int i = 1;
	while (count->getNext()) {
		i++;
		count = count->getNext();
	}
	return i;
};

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	int i = 1;
	std::shared_ptr<Node<ItemType>> counter = headPtr;
	while (counter->getNext()) {
		i = getCurrentSize340RecursiveHelper(counter->getNext());
		counter = counter->getNext();
	}
	return i;
};

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(std::shared_ptr<Node<ItemType>> thing) const {
	static int i = 1;
	if (thing) {
		i++;
	}
	return i;
}; // if needed

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
	static int i = 1;
	static std::shared_ptr<Node<ItemType>> node = headPtr;
	if (node->getNext()) {
		node = node->getNext();
		i++;
		getCurrentSize340RecursiveNoHelper();
		return i;
	}
	if (!node->getNext()) {
		return i;
	}
};

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& thing) const {
	static int i = 0;
	std::shared_ptr<Node<ItemType>> node = headPtr;
	if (node = headPtr) {
		i = 0;
	}

	while (node->getNext()) {
		i = i + getFrequencyOf340RecursiveHelper(node, thing);
		node = node->getNext();
	}

	if (node) {
		i = i + getFrequencyOf340RecursiveHelper(node, thing);
	}
	return i;
};


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(std::shared_ptr<Node<ItemType>> ptr, const ItemType& thing) const {
	int i = 0;
	if (ptr) {
		if (ptr->getItem() == thing) {
			i++;
			return i;
		}
		else return 0;
	}
};  // if needed

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& thing) const {
	static std::shared_ptr<Node<ItemType>> node = headPtr;
	static int i = 0;
	static int j = 0;
	if (i == itemCount) {
		i = 0;
		j = 0;
		node = headPtr;
	}
	if (i < itemCount) {
		if (node->getNext()) {

			i++;
			if (node->getItem() == thing) {
				j++;
			}
			node = node->getNext();
			getFrequencyOf340RecursiveNoHelper(thing);
			return j;



		}
		else if (node) {
			i++;
			if (node->getItem() == thing) {
				j++;
				return j;
			}

		}

	}
	else {
		return j;
	}
};




template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	std::shared_ptr<Node<ItemType>> node = headPtr;
	std::shared_ptr<Node<ItemType>> toDeletePtr = headPtr;
	ItemType deleteNode;

	int i = rand() % itemCount + 1;
	// delete at head
	if (i == 0) {
		deleteNode = toDeletePtr->getItem();
		headPtr = headPtr->getNext();
	}
	else {

		for (int j = 1; j < i; ++j) {
			node = node->getNext();
		}
		deleteNode = node->getItem();
		node->setItem(headPtr->getItem());
		headPtr = headPtr->getNext();

	}


	//// delete
	//toDeletePtr->setNext(nullptr);
	toDeletePtr.reset();
	//toDeletePtr = nullptr;
	itemCount--;

	return deleteNode;
};
