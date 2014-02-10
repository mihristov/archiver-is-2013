#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H
#include <map>
#include <string>
#include "HuffmanBinaryHeap.h"

class HuffmanEncoder
{
private:
	HuffmanBinaryHeap* huffmanTree;
	std::map<char, std::string> huffmanTable;
	std::map<char, unsigned int> frequencyTable;

	void BuildTree();
	void BuildTable(HuffmanNode* root, std::string code);

public:
	HuffmanEncoder(const std::map<char, unsigned int>& frequencies);
	~HuffmanEncoder();

	std::map<char, std::string> GetTable();
};

#endif