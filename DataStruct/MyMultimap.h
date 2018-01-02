#pragma once
#ifndef MYMULTIMAP_H
#define MYMULTIMAP_H

template <typename T, typename S>
void printMultimap(const std::multimap<T, S>& mmap1) {
	for (typename std::multimap<T, S>::const_iterator it = mmap1.begin();
		it != mmap1.end(); it++) {
		std::cout << it->first << "::" << it->second << '\n';
	}
	std::cout << '\n';
}

template <typename T, typename S>
bool searchMultimapWithKey(const std::multimap<T, S>& mmap1, const T& key) {
	typedef typename std::multimap<T, S>::const_iterator MMAPIT;
	//equal_range() returns two iterators pointing to the start of the result to the end of it
	std::pair<MMAPIT, MMAPIT> resultRange = mmap1.equal_range(key);
	//calculate the number of entry resided in the result pairs
	std::cout << "RESULT FOUND = " << std::distance(resultRange.first, resultRange.second) << "\nRESULT MAP:\n";
	for (MMAPIT it = resultRange.first; it != resultRange.second; it++) {
		std::cout << it->first << "::" << it->second << '\n';
	}
	return std::distance(resultRange.first, resultRange.second) > 0;
}

#endif