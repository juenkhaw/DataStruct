#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <time.h>
#include <iterator>

#include <set>
#include <vector>
#include <list>
#include <map>

//actual map does NOT take only 2 template parameter
template <typename T, typename S>
using mymap = std::map<T, S>;

#include "MySet.h"
#include "MyVector.h"
#include "MyList.h"
#include "MyMap.h"

#include "Digimon.h"
#include "DigimonComparator.h"

int random[]{ 23, 12, 42, 9, 16, 13, 25, 37, 21 };
std::string randomStr[]{ "haku", "nope", "gabumon", "galileo", "kazeninaru", "okami", "yami", "amaterasu", "vadar" };

Digimon digimon[]{
	Digimon("Gabumon", "Howling Claw", 87),
	Digimon("Renamon", "Koe No Katsu", 102),
	Digimon("Wargreymon", "Gaia Force", 1024),
	Digimon("Metalgarurumon", "Howling Abyss", 999)
};

void demoSet() {
	//Initialization
	int nums[]{ 30, 20, 50, 10, 40 };
	std::set<int> set1(nums, nums + 5), set2(set1), set3(set2.begin(), set2.end());

	printSet(set1);

	//Intialization with user-defined comparator
	bool(*setComp)(int, int) = setCompare;
	std::set<int, bool(*)(int, int)> set4(setComp);
	set4.insert(set3.begin(), set3.end());

	printSet(set4);
	std::cout << "SIZE = " << set4.size() << '\n';

	//access element
	std::set<int>::iterator it = set1.begin();
	std::advance(it, 3); //move forward from iterator current place by value
	std::cout << "IT advance 3 = " << *it << '\n';

	//unlike advance(), next() does not increment the iterator, it returns one
	it = std::next(set1.begin(), 2);
	std::cout << "IT next 2 = " << *it << '\n';

	//Search for a value in a set
	searchSet(set1, 20);
	searchSet(set1, 60);

	//Insert into a set
	insertSet(set1, 60);
	insertSet(set1, 40);
	printSet(set1);

	//Delete from a set
	//with iterator
	it = set1.begin();
	set1.erase(++++it); //erase third element
						//set1.erase(it, set1.end()); //erase from third element through the end
	printSet(set1);

	//remove specific elements
	it = set1.begin();
	while (it != set1.end()) {
		if (*it % 20 == 0)
			it = set1.erase(it);
		else
			it++;
	}
	printSet(set1);

	//remove specific elements with generic erase_if()
	set1.insert(set4.begin(), set4.end());
	//std::function< return_type (parameter_type) > identifier = [](parameter) -> return type {function declaration}
	std::function<bool(std::set<int>::iterator)> lambda =
		[](std::set<int>::iterator it)->bool {return *it % 15 == 0; };
	set_erase_if(set1, set1.begin(), set1.end(), lambda);
	printSet(set1);

	//set with classes

	std::set<Digimon> dSet1(digimon, digimon + sizeof(digimon) / sizeof(Digimon));
	printSet(dSet1);

	//set with classes and comparator class
	std::set<Digimon, DigimonComparator> dSet2(DigimonComparator(0));
	dSet2.insert(dSet1.begin(), dSet1.end());
	printSet(dSet2);

}

void demoVector() {
	std::vector<int> vector1(4, 100); //initialize with 4x '100'
	std::vector<int> vector2(vector1.begin(), vector1.end());
	std::vector<int> vector3(10); //declare size = 10 with 10x '0'

	int nums[]{ 20, 10, 50, 40, 30 };
	std::vector<int> vector4(nums, nums + sizeof(nums) / sizeof(int));
	vector4.push_back(60);
	vector4.push_back(90);
	vector4.pop_back();

	printVector(vector4);

	//vector always assigns the memory on heap with bigger size than its actual size
	//when the size almost = capacity, it copies all element from old memory to new one
	std::cout << "Capacity = " << vector4.capacity() << "\nSize = " << vector4.size() << '\n';
	vector4.push_back(90);
	vector4.push_back(100);
	std::cout << "Capacity = " << vector4.capacity() << "\nSize = " << vector4.size() << '\n';

	//to prevent vector from constantly reassgining memory, we can use reserve()
	vector4.reserve(20);

	//insert element by index
	std::vector<int>::iterator it = vector4.emplace(vector4.begin() + 1, 99);
	vector4.emplace(it, 199);
	vector4.emplace(vector4.cend(), 299);
	printVector(vector4);

	//initializing with class object would be error if the default constructor is not defined
	std::vector<Digimon> vector5(4);
	printVector(vector5);

	it = vector1.begin();
	//insert '2' elements of '200' at the 4th position of vector
	vector1.insert(it + 3, 2, 200);
	//the iterator it could be invalid if reallocation occurs as
	//all data has been moved to a new bigger chunk of memory
	//while it is still pointing to that old memory
	it = vector1.begin() + 3;
	std::cout << *it << '\n';
	//SAME SITUATION FOR DELETION IN VECTOR, ITERATOR WILL BE INVALID AFTERMATH
	printVector(vector1);

	//Erase-Remove Idiom
	//erase any occurence of element
	eraseElement(vector1, 100);
	printVector(vector1);

	//resizing the vector
	vector1.resize(20);
	vector2.resize(20);

	//use generate() to insert random number into a vector with Functor (struct)
	std::generate(vector1.begin(), vector1.end(), RandomGenerator(500));
	//generate() with lambda function
	std::generate(vector2.begin(), vector2.end(), []() {return rand() % 100; });
	//assign(a,b) inserts a times of element b
	vector3.assign(5, 6);
	printVector(vector1);
	printVector(vector2);
	printVector(vector3);

	//vector with classess
	std::vector<Digimon> dVector1(digimon, digimon + sizeof(digimon) / sizeof(Digimon));
	//dVector1.insert(dVector1.begin(), 50, digimon[1]);
	printVector(dVector1);

}

void demoList() {
	std::list<int> list1;
	std::list<int>::const_iterator it;

	//Initialization of list using initialization list
	std::list<int> list2({ 1,2,3,4,5 });
	//..using fill constructor: insert 5 '113's
	std::list<int> list3(5, 113);
	//..using vector and array

	//insertion of element
	list1.push_back(23);
	list1.push_front(12);
	it = list1.begin();
	//current it->list[1]
	list1.insert(++it, 20);
	//current it->list[2], insert element at list[0..1] excluding list[2]
	list1.insert(++it, list1.begin(), ++++list1.begin());
	
	printList(list1);
	printListLambda(list1);
	printListRangeBaseForLoop(list1);
	printListReverseIterator(list1);

	//accessing element through std::next()/prev() and std::advance()
	it = list1.begin();
	//move it iterator from list[0] to list[2]
	std::advance(it, 2);
	std::cout << "advance(it, 2) = " << *it << '\n';
	//return an it with position list[3]
	it = std::next(list1.begin(), 3);
	std::cout << "next(begin, 3) = " << *it << '\n';
	it = std::prev(list1.end(), 2);
	std::cout << "prev(end, 2) = " << *it << '\n';

	//demonstrate generic containsList() to search for element
	std::cout << "contains '23'? " << containsList(list1, 23) << '\n';
	std::cout << "contains '19'? " << containsList(list1, 19) << '\n';

	//erase() deletes [1..n] elements in given range
	it = list1.begin();
	//erase() returns the iterator pointing to the element next to the deleted one
	it = list1.erase(it);
	printList(list1);
	//std::advance(it, 2);
	list1.erase(++++it, list1.end());
	printList(list1);

	list1.insert(list1.end(), random, random + sizeof(random) / sizeof(random[0]));
	//remove_if([function pointer](function object){lambda function})
	list1.remove_if([](int item) {
		return item > 30;
	});
	//while list::remove(x) remove any element with value x
	printList(list1);

	//sorting of list with default comparator '<'
	list1.sort();
	printList(list1);

	//sorting of list with classes
	std::list<Digimon> dList1(digimon, digimon + sizeof(digimon) / sizeof(Digimon));
	//sort with lambda function
	dList1.sort([](const Digimon& obj1, const Digimon& obj2) {
		return obj1.name < obj2.name;
	});
	printList(dList1);
	//sort with fucntion object comparator
	dList1.sort(DigimonComparator(0));
	printList(dList1);
}

void demoMap() {
	//initialization of map
	std::map<int, std::string> map1;
	std::map<int, std::string>::iterator it;

	//insert key-pair with insert(std::map_pair())
	for (int i = 0; i < (sizeof(random) / sizeof(random[0])); i++) {
		map1.insert(std::make_pair(random[i], randomStr[i]));
	}
	printMap(map1);

	//random access with key
	std::cout << "MAP[21] = " << map1[21] << '\n';
	//using [] to create new key with default value of value type
	map1[20] = "HI IM NEW";

	//alter value of a key
	map1[21] = std::string("Darth Vadar");
	std::cout << "new MAP[21] = " << map1[21] << '\n';
	//repeated insertion will return a pair->second set to false and first points to the existing element
	//map1.insert(std::make_pair(21, std::string("Darth Vadar"))).second = false

	//demonstrate find()
	std::cout << "find() MAP[21] exists? " << containsKeyMap(map1, 21) << '\n';
	std::cout << "find() MAP[22] exists? " << containsKeyMap(map1, 22) << '\n';

	//demonstrate count()
	std::cout << "count() MAP[21] exists? " << containsKeyMap2(map1, 21) << '\n';
	std::cout << "count() MAP[22] exists? " << containsKeyMap2(map1, 22) << '\n';

	//map element can be erased by iterator and key
	map1.erase(21);
	it = map1.begin();
	std::advance(it, 3);
	//it should erase map[3]
	map1.erase(it);
	printMap(map1);
	//delete map[0..2] where ease(x, y) erases map[x..y-1]
	it = map1.begin();
	auto it2 = ++++++map1.begin();
	map1.erase(it, it2);
	printMap(map1);
	//delete specific element using generic eraseif()
	std::cout << "ITEM DELETED with map_erase_if() = " <<
	map_erase_if(map1, [](std::map<int, std::string>::const_iterator it) {
		return it->second == "haku";
	}) << "\n";
	printMap(map1);

	//external sorting criteria and comparator for map
	std::map<std::string, int, ReverseOrderSTRKey> map2;
	for (int i = 0; i < (sizeof(random) / sizeof(random[0])); i++) {
		map2.insert(std::make_pair(randomStr[i], random[i]));
	}
	printMap(map2);

	std::map<std::string, int, ReverseOrderSTRKey> map3(map2);

	//comparison of 2 maps valid only when these 2 share the SAME sorting criteria
	//eg. map1 == map2 is unresolved
	//or comparing 2 maps with different types of key or value
	std::cout << (map2 == map3?"SAME":"NOT SAME") << '\n';

	//iterate a map to search by value
	std::vector<std::string> result;
	std::cout << "Search for value(21) : " <<
		searchMapByValue(result, map3, 21) << "\nResult Vector: ";
	printVector(result);
	std::cout << "\n";

	//copying element(key) from map to vector
	result.clear(); //empty a vector
	std::for_each(map3.begin(), map3.end(), 
		//[&result] indicates that we are passing outside variabl as reference
		//while [=] passing by value
		[&result](std::pair<std::string, int> elem) {
		result.push_back(elem.first);
	});
	printVector(result);
	std::cout << "\n";

	//another demo copying element(value) from map to vector
	std::vector<int> result2;
	//back_inserter(Container&) constructs an output iterator that isnerts new element
	//at the end of the container
	std::transform(map3.begin(), map3.end(), std::back_inserter(result2), 
		[](const std::pair<std::string, int>& elem) {
		return elem.second;
	});

	//another fancy way to print vector
	std::copy(result2.begin(), result2.end(),
		std::ostream_iterator<int>(std::cout, ", "));
	std::cout << "\n";

	//yet another way to transform through function pointer
	std::transform(map3.begin(), map3.end(), 
		std::back_inserter(result2), &getSecond<std::string, int>);
	printVector(result2);
}

int main() {
	//demoSet();
	//demoVector();
	//demoList();
	demoMap();

	system("pause");
}