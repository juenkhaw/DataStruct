#pragma once
#ifndef MYLIST_H
#define MYLIST_H

/*
PROPERTIES OF LIST:
1. IMPLEMENTED AS DOUBLY LINKED LIST
2. EACH NODE STORES AT DIFFERENT MEMORY BLOCK AND POINTS TO ITS PREVIOUS AND NEXT NODE
3. NO RANDOM ACCESS, ELEMENT CAN ONLY BE ACCESSED THROUGH ITERATION
*/

template <typename T>
void printList(const std::list<T>& list1) {
	//using normal iterator causes error, use const_iterator instead
	for(typename std::list<T>::const_iterator it = list1.begin(); 
		it!=list1.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

//different ways to iterate through lists
template <typename T>
void printListLambda(const std::list<T>& list1) {
	std::for_each(list1.begin(), list1.end(), [](const T& t) {
		std::cout << t << ' ';
	});
	std::cout << '\n';
}

template <typename T>
void printListRangeBaseForLoop(const std::list<T>& list1) {
	for (const T& t : list1) {
		std::cout << t << ' ';
	}
	std::cout << '\n';
}

//introducing reverse iterator whihc printing list in reverse order
template <typename T>
void printListReverseIterator(const std::list<T>& list1) {
	for (typename std::list<T>::const_reverse_iterator rit = list1.rbegin();
		rit != list1.rend(); rit++) {
		std::cout << *rit << ' ';
	}
	std::cout << '\n';
}

template <typename T>
bool containsList(const std::list<T, std::allocator<T>>& list1, const T& value) {
	//use std::find()
	typename std::list<T>::const_iterator it = 
		std::find(list1.begin(), list1.end(), value);
	return it != list1.end();
}

#endif