#pragma once
#include <iostream>
#include<string>
using std::string; using std::ostream;using std::istream;
class Train
{
public:
	Train() = default;
	~Train() = default;
	const bool operator< (const Train&)const;
	string getDestination()const { return this->destination; }
	string getNumber()const { return this->number; }
	bool getExpress()const { return this->express; }
	int getHours()const { return this->hours; }
	int getMinutes()const { return this->minutes; }
	friend istream& operator>>(istream& in, Train& object);
	friend ostream& operator<<(ostream& out,const Train& object);
	Train& operator= (string str) { this->destination = str; return *this; };
private:
	
   string destination;
	string number;
	bool express;
	int hours;
	int minutes;
};
istream& operator>>(istream& in, Train& object)
{
	in >> object.destination;
	in >> object.number;
	in >> object.express;
	in >> object.hours;
	in >> object.minutes;
	return in;
}
ostream& operator<<(ostream& out, const Train& object)
{
out<<"destination " <<object.getDestination()<<" ";
out << "number " << object.getNumber() << " ";
out << "express "; if (object.getExpress()) { out << "yes"; }
else out << "no";out << " ";
out << "time " << object.getHours() << ":" << object.getMinutes() << std::endl;



return out;
}
const bool Train::operator< (const Train&obj2)const
{
	if (this->getHours() < obj2.getHours())
	{
		return true;
	}
	else if (this->getHours() == obj2.getHours())
	{
		return this->getMinutes() < obj2.getMinutes() ? true : false;
	}
	else
	{
		return false;
	}

}
