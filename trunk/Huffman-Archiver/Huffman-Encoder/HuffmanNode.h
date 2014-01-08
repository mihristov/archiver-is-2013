#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>
#include <iostream>

class HuffmanNode
{
private:
	int frequency;
	char letter;
	std::string code;
	HuffmanNode* leftChild;
	HuffmanNode* rightChild;

public:
	HuffmanNode();
	HuffmanNode(int frequency, char letter);
	HuffmanNode(HuffmanNode* left, HuffmanNode* right);
	~HuffmanNode();

	int GetFrequency();
	char GetLetter();
	std::string GetCode();
	HuffmanNode* GetLeftChild();
	HuffmanNode* GetRightChild();

	void SetCode(std::string code);

	void PrintNode();

	HuffmanNode& operator=(const HuffmanNode& node);
};

#endif