#pragma once

class Digimon {
public:
	std::string name;
	std::string signSkill;
	int hp;

	//default constructor is needed for initializing vector<Digimon>(size_t)
	Digimon() {
		name = signSkill = "MISSINGNO";
		hp = -999;
	}

	Digimon(std::string name, std::string signSkill, int hp) :
		name(name), signSkill(signSkill), hp(hp) {}

	//copy constructor is for vector to copying from memory to memory
	Digimon(const Digimon& obj) {
		name = obj.name;
		signSkill = obj.signSkill;
		hp = obj.hp;
	}

	bool operator< (const Digimon& d1) const;
	friend std::ostream& operator<< (std::ostream& out, const Digimon& d1);
};

//overloaded operator is required if comparation of object
bool Digimon::operator< (const Digimon& d1) const {
	return this->name < d1.name;
}

std::ostream& operator<< (std::ostream& out, const Digimon& d1) {
	out << "DIGIMON: " << d1.name << "\nSIGNATURE SKILL: " << d1.signSkill << "\nHP = " << d1.hp << '\n';
	return out;
}