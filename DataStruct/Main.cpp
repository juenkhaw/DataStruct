#include <iostream>
#include <string>
#include <functional>

#include <set>
#include <vector>

#include "MySet.h"
#include "MyVector.h"

#include "Digimon.h"
#include "DigimonComparator.h"

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
	set1.erase(++++it); //erase second element
						//set1.erase(it, set1.end()); //erase from second element through the end
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
	std::function<bool(std::set<int>::iterator)> lambda =
		[](std::set<int>::iterator it)->bool {return *it % 15 == 0; };
	set_erase_if(set1, set1.begin(), set1.end(), lambda);
	printSet(set1);

	//set with classes
	Digimon digimon[]{
		Digimon("Gabumon", "Howling Claw", 87),
		Digimon("Renamon", "Koe No Katsu", 102),
		Digimon("Wargreymon", "Gaia Force", 1024),
		Digimon("Metalgarurumon", "Howling Abyss", 999)
	};

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
	//when the size almost > capacity, it copies all element from old memory to new one
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

}

int main() {
	//demoSet();
	demoVector();

	system("pause");
}