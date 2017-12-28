#pragma once
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

/*
PROPERTIES OF VECTOR:
1. ELEMENTS REAMINED IN THE SAME ORDER AS THEY ARE INSERTED
2. FAST INDEXING WITH OPERATOR '[]'
3. INSERTION AND DELETION PERFORMED ONLY AT THE END OF VECTOR
4. STORES COPY OF ELEMENTS WITH DIFFERENT REFERENCE, COPY CONSTRUCTOR IS REQUIRED IN CLASS DEFINITION
*/

template <class T>
void printVector(const std::vector<T>& vector1) {
	for (T num : vector1)
		std::cout << num << ' ';
	std::cout << '\n';
}

template <class T>
void eraseElement(std::vector<T>& vector1, T elem) {
	//remove() shifts the non-match element to the start of the container
	//erase() ERASES it while remove() NOT
	vector1.erase(std::remove(
		vector1.begin(), vector1.end(), elem)
		, vector1.end());
}

struct RandomGenerator {
	int max;
	RandomGenerator(int max) :max(max) {}
	int operator()() {
		//calling srand(time(null)) here will have a constant seed of the time of that moment
		return rand() % max;
	}
};

#endif