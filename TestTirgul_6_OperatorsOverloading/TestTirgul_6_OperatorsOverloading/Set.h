#include <iostream>

class Set
{
public:
	Set(int maxAmountOfNumbers);
	Set();
	const Set& operator=(const Set& other);
	friend Set operator+(const Set& other, const int newNumberToAdd); // add number to object
	friend Set operator+(const int newNumberToAdd, const Set& other); // add number to object
	const Set& operator+=(const int newNumberToAdd);
	Set operator+(const Set& object) const; // add object to object
	friend std::ostream& operator<<(std::ostream& os, const Set& objectToPrint);
	Set(Set& toCopy);
	Set(Set&& toCopy);
	~Set();

private:

	int maxAmountOfNumbers;
	int currentAmountOfNumbers;
	int* arr;

};

