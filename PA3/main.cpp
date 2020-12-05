/* * * *  * * * *  * * * *  * * * *  * * * * * 
	Andrew Fritz
	Cpts223 Advanced Data Structures
	PA3: AVL Trees and Reporting Cancer Rates
	10.6.2020
/* * * * * * * * * * * * * * * * * * * * * * * 

	Big-O Worst Case for insert()
	The worst case for insertion in the AVL tree is O(logn)
	it acheives this time complexity by balancing itself 
	everytime a node is inserted or removed. This makes the
	insertion much faster, as whenever we go down a level in
	the tree, we cut the data set in half. A BST has a worst
	case time complexity of O(n) because it doesn't balance
	itself, so linear formations of branches are possbile.


	Big-O Worst Case for printInOrder()
	Print in order has a worst case time complexity of 
	O(n). This is because in order to traverse the entire
	list, you have to traverse through each node at least
	once. When implemented using recursion, each nodes is
	only traversed once


	Big-O Worst Case for findMax()
	The worst case for findMax() is O(nlog(n)). This is
	because all you have to do is find the right-most node,
	and every time you go down a branch of the tree you're
	cutting the data set in half. For a BST the worst case
	would be O(n), but because the AVL tree balances itself
	it goes down to O(log(n))

* * * * * * * * * * * * * * * * * * * * * * */
#include "CancerData.h"
#include "AVLTree.h"

int main(int argc, char *argv[]){
	// Opening the three files that will be used to build the trees
	std::ifstream men, women, both;
	men.open("mencancerdata2018.csv");
	women.open("womencancerdata2018.csv");	
	both.open("bothcancerdata2018.csv");

	AVLTree<CancerData> *tboth = new AVLTree<CancerData>;
	AVLTree<CancerData> *tmen = new AVLTree<CancerData>;
	AVLTree<CancerData> *twomen = new AVLTree<CancerData>;
	CancerData data;
	std::string country;
	double rate;

	// Building the three trees from data in .csv files
	if (!both.is_open())
		throw std::runtime_error("Could not open file");
	while(!both.eof()){
		getline(both, country, ',');
		data.setName(country);

		getline(both, country);
		rate = std::stod(country);
		data.setRate(rate);

		tboth->insert(data);
	}

	if (!men.is_open())
		throw std::runtime_error("Could not open file");
	while(!men.eof()){
		getline(men, country, ',');
		data.setName(country);

		getline(men, country);
		rate = std::stod(country);
		data.setRate(rate);

		tmen->insert(data);
	}
	
	if (!women.is_open())
		throw std::runtime_error("Could not open file");
	while(!women.eof()){
		getline(women, country, ',');
		data.setName(country);

		getline(women, country);
		rate = std::stod(country);
		data.setRate(rate);

		twomen->insert(data);
	}
	both.close();
	men.close();
	women.close();


	//Printing the data from trees
	std::cout<< "\n** *** * CANCER STATISTICS FOR BOTH  * **** **" << std::endl;
	tboth->printInOrder("both");
	std::cout<< "\n** *** * CANCER STATISTICS FOR MEN   * **** **" << std::endl;
	tmen->printInOrder("men");
	std::cout<< "\n** *** * CANCER STATISTICS FOR WOMEN * **** **" << std::endl;
	twomen->printInOrder("women");


	std::cout<< "\n * *** **** HIGHEST CANCER RATES **** *** *" << std::endl;
	data = tboth->findMax();
	std::cout << "<" << std::setw(6) << "both" << ":" 
			  << std::setw(3) << 1 << ". " << data << ">" << std::endl;

	data = tmen->findMax();
	std::cout << "<" << std::setw(6) << "men" << ":" 
			  << std::setw(3) << 1 << ". " << data << ">" << std::endl;

	data = twomen->findMax();
	std::cout << "<" << std::setw(6) << "women" << ":" 
			  << std::setw(3) << 1 << ". " << data << ">" << std::endl;


	std::cout<< "\n * *** **** LOWEST CANCER RATES **** *** *" << std::endl;
	data = tboth->findMin();
	std::cout << "<" << std::setw(6) << "both" << ":" 
			  << std::setw(3) << 50 << ". " << data << ">" << std::endl;

	data = tmen->findMin();
	std::cout << "<" << std::setw(6) << "men" << ":" 
			  << std::setw(3) << 50 << ". " << data << ">" << std::endl;

	data = twomen->findMin();
	std::cout << "<" << std::setw(6) << "women" << ":" 
			  << std::setw(3) << 50 << ". " << data << ">" << std::endl << std::endl;


	//Destroy all memory for trees before exit
	tboth->clear();
	tmen->clear();
	twomen->clear();

	return 0;
}