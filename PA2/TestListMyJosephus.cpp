/************************************************
	TEST FUNCTION TIMES:

	Time When M = 3
	N = 4 -  -  -  -  -   0.000159s
	N = 10			      0.002181s
	N = 100 -  -  -  - -  0.003089s
	N = 500               0.003445s
	N = 1000 -  -  -  -   0.005450s

	Time When N = 512
	M = 2 -  -  -  -  -   0.004097s
	M = 10                0.004388s
	M = 50 -  -  -  -  -  0.004876s
	M = 250               0.010077s
	M = 510 -  -  -  -    0.014245s

*************************************************/
#include "TestListMyJosephus.hpp"

void testList(void){
	// For measuring excecution time
	clock_t k = clock();
	clock_t start;
	do start = clock();
	while (start == k);


	/* Reading in data from destinations file ********************/
	std::fstream destinationList;
	destinationList.open("destinations.csv", std::ios::in);

	// Checking if the .csv fule was opened correctly
	if(!destinationList.is_open())
		throw std::runtime_error("Could not open file");

	// Getting a number 1-25 to read from the .csv
	int readLine = rand() % 25 + 1;
	std::string line =  " ";

	// Passing each line until we reach readLine
	for (int i = 1; i < readLine; ++i)
		getline(destinationList, line); // Discarding values
	

	/*************************************************************/
	//Generating and testing values for M and N
	int n = rand () % 1025 + 1;
	int m = rand () % n;
	
	if( n <= 0 || m < 0){
		std::cout << "VALUE OF M OR N TOO LOW" << std::endl;
		return;
	}
	if( n > 1024){
		std::cout << "VALUE OF N TOO HIGH" << std::endl;
		return;
	}
	if ( m > n){
		std::cout << "M CANNOT BE HIGHER THAN N" << std::endl;
		return;
	}

	/************************************************************/
	// Once m and n are verified, and file stream is open, obj is created
	ListMyJosephus *list =  new ListMyJosephus(m, n);


	/* Reading in N destinations from line number:readLine and pushing
	*///   them into list                                           
	for(int i = 0; i < list->getN() ; ++i){
	 	getline(destinationList, line, '\"');
	 	getline(destinationList, line, '\"');
	 	Destination newD(i, line);
	 	list->addDestination(newD);
	}
	

	/****   Running Simulation to Eliminate Destinations  ****/
	double elimTime = 0.0;
	int t = 0, twoElims = 0;

	Destination *deleted = new Destination();
	while(list->currentSize() > 1){
	 	*deleted = list->eliminateDestination();
	 	++t;

	 	if(t == 2){
	 		t = 0;
	 		++twoElims;
	 	}
	}

	/*******   Printing Winnner of the List Simulation   ********/
	std::cout << "*******************" << std::endl;
	std::cout << "N = " << n << "  M = " << m << std::endl;
	*deleted = list->eliminateDestination();
	std::cout << "The winner is: ";
	deleted->printPosition();
	std::cout << ". ";
	deleted->printDestinationName();
	std::cout << std::endl;


	destinationList.close();

	/*  Writing Data to results.log and screen ********************/
	clock_t end = clock();
	elimTime = (double)(end-start) / CLOCKS_PER_SEC;
	std::cout << "CPU Time: " << elimTime << "s" << std::endl;

	std::ofstream results;
	results.open("results.log", std::ios::app); // So results.log contents aren't deleted

	// Checking if log opened correctly
	if(!results.is_open())
		throw std::runtime_error("Could not open file");

	// Writing Results
	results << "List: " << std::endl;
	results << "N = " << n << ", M = " << m << std::endl;
	results << "Total Runtime: " << elimTime << "s" << std::endl;
	results << "Average Elimination Time: " << elimTime/twoElims << "s" << std::endl << std::endl;

	results.close();
}