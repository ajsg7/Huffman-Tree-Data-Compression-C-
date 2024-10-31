#include <iostream>
#include <iomanip>
#include <map>
#include "Huffman.h"

int main() {
	std::ifstream my_file("Bartleby.txt");
	if (!my_file.is_open()) { throw std::runtime_error("Can not open file."); }
	std::map<char, int> freq_dist;

	freq_dist_from_file(freq_dist, my_file);

	huffman_node* my_tree = nullptr;
	
	build_huffman_tree(my_tree, freq_dist);

	std::cout << std::setw(10)<<"char"<<std::setw(12)<<"frequency"<<std::setw(11)<<"encoding\n";
	std::cout << "------------------------------------------"<<std::endl;
	test_print_dist(my_tree, "");
}