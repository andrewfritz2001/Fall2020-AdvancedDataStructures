/*
	Andrew Fritz
	CPTS 223- Advanced Data Structures
	Programming Assignment 2
		Josephus Problem Variant
	9.21.2020
*/

//*******************************************************/
// The processor on the machine running the algorithm most
// definitely matters. Some machines will be faster, and
// some machines will be slower than others. That's why we
// make our code efficient. Not everyone has a super powerful
// CPU, so we build our code for the worst case so it can 
// run on anything relatively quickly.
//
// When compaing list vs vector, list has lower runtimes 
// when N and M are small. When N and M are both large,
// the vector is more efficient. This makes sense as a 
// list object is much more complex than a vector object,
// so the vector is much more efficient.
//
// The size of N and M both have an effect on the program's
// runtime. Looks at my test.cpp files, it seems as though
// an increasing M value adds much more time than an 
// increasing N vlaue. This makes sense when you consider
// the code. The higher M is, the more times you'll have
// to traverse the list. Doubling M has a much more profound
// effect than doubling N.
//
///////////////////////////////////////////

#include "TestListMyJosephus.hpp"
#include "TestVectorMyJosephus.hpp"

int main(int argc, char* argv[]){
	std::srand((unsigned)time(0));

	/* Calling Test functions and Recording excecution time in results.log */
	testList();
	testVector();

	return 0;
}