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
	//using normal iterator causes error
	for(typename std::list<T>::const_iterator it = list1.begin(); it!=list1.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

#endif