#include "CancerData.h"

CancerData::CancerData(){
	this->_name = " ";
	this->_cancerRate = 0.0;
}
CancerData::CancerData(std::string s, double r){
	this->_name = s;
	this->_cancerRate = r;
}
CancerData::~CancerData(){
	this->_name = "\0";
	this->_cancerRate = 0.0;
}

//Member functions
const std::string CancerData::getName()const{return this->_name;}
const double CancerData::getRate()const{return this->_cancerRate;}
void CancerData::setName(std::string s){this->_name = s;}
void CancerData::setRate(double r){this->_cancerRate = r;}

//Operators
bool CancerData::operator>=(const CancerData &rhs){
	return (this->_cancerRate >= rhs._cancerRate) ? true : false;
} 

bool CancerData::operator<(const CancerData &rhs){
	return (this->_cancerRate < rhs._cancerRate) ? true : false;
}