#pragma once
#ifndef MYMAP_H
#define MYMAP_H

/*
PROPERTIES OF MAP
1. STORES ELEMENT IN KEY-VALUE PAIRS
2. KEYS ARE UNIQUE AND SORTED IN DEFAULT ORDER
3. 1 KEY <-> 1 VALUE
*/

template <typename T, typename S, typename U>
void printMap(const std::map<T,S,U>& map1) {
	for (typename std::map<T,S,U>::const_iterator it = map1.begin();
		it != map1.end(); it++) {
		std::cout << it->first << "::" << it->second << '\n';
	}
	std::cout << '\n';
}

//iterate a map through range-based for loop
template <typename T, typename S, typename U>
void printMapRangeBased(const std::map<T, S, U>& map1) {
	for (std::pair<T, S> elem : map1) {
		std::cout << elem.first << "::" << elem.second << "\n";
	}
	std::cout << '\n';
}

//iterate a map through for_each()
template <typename T, typename S, typename U>
void printMapForEach(const std::map<T, S, U>& map1) {
	std::for_each(map1.begin(), map1.end(),
		[](std::pair<T, S> elem) {
		std::cout << elem.first << "::" << elem.second << "\n";
	});
	std::cout << "\n";
}

template <typename T, typename S>
bool containsKeyMap(const std::map<T, S>& map1, const T& key) {
	return map1.find(key) != map1.end();
}

//another way to search for a key with count()
template <typename T, typename S>
bool containsKeyMap2(const std::map<T,S>& map1, const T& key) {
	return map1.count(key) > 0;
}

template <typename T, typename S, typename U>
bool searchMapByValue(std::vector<T>& result, const std::map<T, S, U>& map1, const S& value) {
	bool found = false;
	typename std::map<T, S, U>::const_iterator it = map1.begin();
	while (it != map1.end()) {
		if (it->second == value) {
			found = true;
			result.push_back(it->first);
		}
		it++;
	}
	return found;
}

//generic erase_if() with callback for map
template <typename T, typename S, typename U>
int map_erase_if(std::map < T, S, U > &map1, 
	std::function<bool(typename std::map<T,S,U>::const_iterator)> checker) {
	int totalDeleted = 0;
	typename std::map<T, S, U>::const_iterator it = map1.begin();
	while (it != map1.end()) {
		if (checker(it)) {
			it = map1.erase(it);
			totalDeleted++;
		}
		else it++;
	}
	return totalDeleted;
}

struct ReverseOrderSTRKey {
	bool operator()(const std::string& left, const std::string& right) const {
		return left > right;
	}
};

template <typename T, typename S>
S getSecond(const std::pair<T, S>& elem) {
	return elem.second;
}

#endif