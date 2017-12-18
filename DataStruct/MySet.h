#pragma once
#ifndef MY_SET_H
#define MY_SET_H

/*
PROPERTIES OF SET:
1. CONTAINS ONLY UNIQUE ELEMENTS, DUPLICATED ELEMENT WILL BE DROPPED
2. CONTAINS ANY TYPE OF ELEMENT
3. STORED IN BALANCED BINARY TREE
4. DEFAULT OPERATOR TO COMPARE BETWEEN ELEMENTS '<'
5. KEEP THE ELEMENTS IN SORTED ORDER BASED ON THE SORTING ALGORITHM
*/

bool setCompare(int x, int y) {
	return x > y;
}

template <typename T>
void printSet(const std::set<T>& set1) {
	for (typename std::set<T>::iterator it = set1.begin(); it != set1.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

template <typename T, typename S>
void printSet(const std::set<T, S>& set1) {
	for (typename std::set<T, S>::iterator it = set1.begin(); it != set1.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

template <typename T>
bool searchSet(const std::set<T>& set1, T value) {
	typename std::set<T>::iterator it = set1.find(value);
	if (it == set1.end()) {
		std::cout << value << " not found.\n";
		return false;
	}
	return true;
}

template <typename T>
bool insertSet(std::set<T>& set1, T value) {
	//Set::insert() returns a pair which first is the iterator pointing to the newly inserted element
	//OR the existed element with the same value as new value
	//second is set to true if the new value is inserted, else false
	std::pair<std::set<T>::iterator, bool> ret = set1.insert(value);
	if (!ret.second) {
		std::cout << value << " is already inserted previously.\n";
		return false;
	}
	return true;
}

template <typename T, typename S>
void set_erase_if(S& container, T first, T last, std::function<bool(T)> checker) {
	while (first != last) {
		if (checker(first))
			first = container.erase(first);
		else
			first++;
	}
}

#endif