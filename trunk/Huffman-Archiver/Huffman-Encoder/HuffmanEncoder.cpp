#include "HuffmanEncoder.h"

HuffmanEncoder::HuffmanEncoder(const std::map<char, unsigned int>& frequencies)
{
	this->frequencyTable = frequencies;
	this->huffmanTree = new HuffmanBinaryHeap(this->frequencyTable.size());
}

HuffmanEncoder::~HuffmanEncoder()
{
	delete huffmanTree;
}

void HuffmanEncoder::BuildTree()
{
	for (std::map<char, unsigned int>::iterator it = this->frequencyTable.begin();
		it != this->frequencyTable.end(); ++it)
	{
		this->huffmanTree->Add(new HuffmanNode(it->second, it->first));
	}

	// Fixes bug if file consists of only one byte
	// or one byte repeated many times
	if (this->huffmanTree->GetSize() == 1)
	{
		huffmanTable.insert(std::pair<char, std::string>(huffmanTree->GetMin()->GetLetter(), "0"));
		return;
	}

	while (!huffmanTree->IsEmpty())
	{
		if (huffmanTree->GetSize() == 1) break;
		HuffmanNode* first = huffmanTree->RemoveMin();
		HuffmanNode* second = huffmanTree->RemoveMin();
		huffmanTree->Add(new HuffmanNode(first, second));
	}

	// std::string code = "";
	// BuildTable(huffmanTree->GetMin(), code);
}

void HuffmanEncoder::BuildTable(HuffmanNode* root, std::string code)
{
		if (root->GetLeftChild() == NULL)
		{
			root->SetCode(code);
			huffmanTable.insert(std::pair<char, std::string>(root->GetLetter(), code));
			return;
		}
		else
		{
			BuildTable(root->GetLeftChild(), code + std::string(1, (char)0));
			BuildTable(root->GetRightChild(), code + std::string(1, (char)1));
		}
}

HuffmanNode* HuffmanEncoder::GetTree()
{
	return this->huffmanTree->GetMin();
}

std::map<char, std::string> HuffmanEncoder::GetTable()
{
	return this->huffmanTable;
}