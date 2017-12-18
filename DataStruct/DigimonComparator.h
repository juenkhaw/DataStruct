#pragma once
class DigimonComparator {
private:
	int hp;
public:
	DigimonComparator(int hp) :hp(hp) {}
	bool operator() (const Digimon& d1, const Digimon& d2) const;
};

bool DigimonComparator::operator()(const Digimon& d1, const Digimon& d2) const {
	return d1.hp > d2.hp;
}