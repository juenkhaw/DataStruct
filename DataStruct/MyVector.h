#pragma once
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

/*
PROPERTIES OF VECTOR:
1. ELEMENTS REAMINED IN THE SAME ORDER AS THEY ARE INSERTED
2. FAST INDEXING WITH OPERATOR '[]'
3. INSERTION AND DELETION PERFORMED ONLY AT THE END OF VECTOR
4. STORES COPY OF ELEMENTS WITH DIFFERENT REFERENCE, COPY CONSTRUCTOR IS REQUIRED IN CLASS DEFINITION
5. ELEMENTS STORE IN CONTIGUOUS MEMORY LOCATION
*/

/*
VECTOR VS DEQUE
1. INSERTION AT MIDDLE AND END ONLY IN VECTOR; DEQUE has push/pop_back/front()
2. VECTOR: GOOD PERFORMANCE FOR INSERTION AT END AND BAD AT MIDDLE
2a DEQUE: SAME PERFORMANCE FOR ISNERTION AT MIDDLE END AND GOOD AT FRONT
3. VECTOR STORES CONTIGUOUSLY WHILE DEQUE STORES AS A MEMORY CHUNKS
4. NO ITERATOR INVALIDATION FOR INSERTION AND DELETION AT FROND AND END
4a ITERATOR INVALIDATION HAPPENS AT THE MIDDLE, DEQUE SAME AS VECTOR IN THIS CASE
5. RANDOM ACCESS PERFORMANCE, VECTOR > DEQUE, BOTH AVAILABLE WITH OPERATOR []

DEQUE == QUEUE
VECTOR == STACK

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