#ifndef CANCERDATA_H
#define CANCERDATA_H
#include <iostream>
#include <iomanip>

class CancerData{
private:
	std::string _name;
	double _cancerRate;
 
public:
	CancerData();
	CancerData(std::string s, double r);
	~CancerData();

	//Member functions
	const std::string getName()const;
	const double getRate()const;
	void setName(std::string s);
	void setRate(double r);
	// Overloaded Operators
	bool operator>=(const CancerData &rhs);
	bool operator<(const CancerData &rhs);
};

inline std::ostream& operator<<(std::ostream &os, const CancerData c) {
	os << std::setw(22) << std::left << c.getName();
	os << std::setw(10) << std::right << c.getRate();
	return os;
}

#endif