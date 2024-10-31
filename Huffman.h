#pragma once
#include <map>
#include <fstream>


struct huffman_node {
	int priority;
	char letter = 0;
	huffman_node*left = nullptr, *right = nullptr;
};

struct huffman_less {
	bool operator()(const huffman_node* A, const huffman_node* B) {
		return A->priority > B->priority; // least has highest priority
	}
};

huffman_node* join(huffman_node* L, huffman_node* R);

void build_huffman_tree(huffman_node*& my_tree,	const std::map<char, int>& freq_dist);

void freq_dist_from_file(std::map<char, int>&, std::ifstream&);

void test_print_dist(const huffman_node* root, std::string path);