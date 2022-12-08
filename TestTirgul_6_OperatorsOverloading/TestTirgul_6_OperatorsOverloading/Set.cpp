#include "Set.h"

Set::Set(int maxAmountOfNumbers) : maxAmountOfNumbers(maxAmountOfNumbers)
{
	this->arr = new int[maxAmountOfNumbers];
}

Set::Set() : maxAmountOfNumbers(1000)
{
	this->arr = new int[maxAmountOfNumbers];
}

const Set& Set::operator=(const Set& theObjectThatIWillPutInMe)
{
	if (this != &theObjectThatIWillPutInMe)
	{
		if (this->arr != nullptr)
		{
			delete[]this->arr;
		}
		this->maxAmountOfNumbers = theObjectThatIWillPutInMe.maxAmountOfNumbers;
		this->arr = new int[this->maxAmountOfNumbers];
		for (size_t i = 0; i < theObjectThatIWillPutInMe.currentAmountOfNumbers; i++)
		{
			this->arr[i] = theObjectThatIWillPutInMe.arr[i];
		}
		this->currentAmountOfNumbers = theObjectThatIWillPutInMe.currentAmountOfNumbers;
	}
	return *this;
}

Set operator+(const Set& other, const int newNumberToAdd)
{
	Set tmpReturn;
	tmpReturn = other;
	if (tmpReturn.currentAmountOfNumbers > tmpReturn.maxAmountOfNumbers)
	{
		tmpReturn.maxAmountOfNumbers = tmpReturn.maxAmountOfNumbers * 2;
		delete[]tmpReturn.arr;
		tmpReturn.arr = new int[tmpReturn.maxAmountOfNumbers];
		for (size_t i = 0; i < other.currentAmountOfNumbers; i++)
		{
			tmpReturn.arr[i] = other.arr[i];
		}
	}
	tmpReturn.arr[tmpReturn.currentAmountOfNumbers] = newNumberToAdd;
	tmpReturn.currentAmountOfNumbers++;

	return tmpReturn;
}

Set operator+(const int newNumberToAdd, const Set& other)
{
	return other + newNumberToAdd;
}

std::ostream& operator<<(std::ostream& os, const Set& objectToPrint)
{
	for (size_t i = 0; i < objectToPrint.currentAmountOfNumbers - 1; i++)
	{
		os << objectToPrint.arr[i] << ",";
	}
	if (objectToPrint.currentAmountOfNumbers != 0)
	{
		os << objectToPrint.arr[objectToPrint.currentAmountOfNumbers -1] << ".";
	}
	return os;
}

const Set& Set::operator+=(const int newNumberToAdd)
{
	*this = *this + newNumberToAdd;
	return *this;
}

Set Set::operator+(const Set& object) const
{
	Set tmpReturn;
	tmpReturn = *this;

	for (size_t i = 0; i < object.currentAmountOfNumbers; i++)
	{
		tmpReturn = tmpReturn + object.arr[i];
	}
	return tmpReturn;
}

bool Set::operator>(const Set& objectoToCompare) const
{
	if (this->currentAmountOfNumbers > objectoToCompare.currentAmountOfNumbers)
		return true;
	return false;
}

bool Set::operator<(const Set& objectoToCompare) const
{
	if (this->currentAmountOfNumbers < objectoToCompare.currentAmountOfNumbers)
		return true;
	return false;
}

bool Set::operator==(const Set& objectToCompare) const
{
	if ((this->currentAmountOfNumbers == objectToCompare.currentAmountOfNumbers))
	{
		for (size_t i = 0; i < this->currentAmountOfNumbers; i++)
		{
			if (this->arr[i] != objectToCompare.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Set::operator!=(const Set& objectToCompare) const
{
	return !(*this == objectToCompare);
}

int& Set::operator[](int index)
{
	return this->arr[index];
}

Set::Set(Set& toCopy)
{
	*this = toCopy;
}

Set::Set(Set&& toCopy) : maxAmountOfNumbers(toCopy.maxAmountOfNumbers)
{
	this->arr = toCopy.arr;
	toCopy.arr = nullptr;
	this->currentAmountOfNumbers = toCopy.currentAmountOfNumbers;
}

Set::~Set()
{
	if (arr != nullptr)
	{
		delete[]arr;
	}
}





