#include "Huffman.h"
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

huffman_node* join(huffman_node* L, huffman_node* R) {
	auto new_node = new huffman_node{ L->priority + R->priority };
	new_node->left = L;
	new_node->right = R;
	return new_node;
}

void build_huffman_tree(huffman_node*& my_tree,
	const std::map<char, int>& freq_dist) {
	//Create the Priority Queue
	std::priority_queue<huffman_node*, std::vector<huffman_node*>, huffman_less> Q;
	for (auto pair : freq_dist) {
		auto new_node = new huffman_node{ pair.second, pair.first };
		Q.push(new_node);
	}

	while (Q.size() > 1) {
		auto left = Q.top();
		Q.pop();
		auto right = Q.top();
		Q.pop();
		Q.push(join(left,right));
	}

	my_tree = Q.top();
}

void freq_dist_from_file(std::map<char, int>& freq_dist, std::ifstream& my_file) {
	char c;
	char end_of_file = 3;

	while (my_file.get(c)) {
		freq_dist[c]++;
	}
	freq_dist[end_of_file] = 1;
}

void test_print_dist(const huffman_node* root, std::string path){
	std::string mypath;
	mypath = path;
		
	if (root == nullptr) return;
	if (root->letter == ' ') {
		std::cout <<std::setw(11)<<"space" << '\t'<< root->priority << '\t' << path << '\n';
	}
	else if (root->letter == '\n') {
		std::cout <<std::setw(13)<< "newline " << '\t' << root->priority << '\t' << path << '\n';
	}
	else if (int(root->letter) == 3) {
		std::cout <<std::setw(14)<<"end_of_file" << '\t' << root->priority << '\t' << path << '\n';
	}	
	else {
		if (root->left == nullptr && root->right == nullptr) {
			std::cout << '\t' << (root->letter) << '\t' << root->priority << '\t' << path << '\n';
		}
	}
	test_print_dist(root->left, path + "0");
	test_print_dist(root->right, path + "1");
} 

