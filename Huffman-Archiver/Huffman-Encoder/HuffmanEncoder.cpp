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

	while (!huffmanTree->IsEmpty())
	{
		if (huffmanTree->GetSize() == 1) break;
		HuffmanNode* first = huffmanTree->RemoveMin();
		HuffmanNode* second = huffmanTree->RemoveMin();
		huffmanTree->Add(new HuffmanNode(first, second));
	}

	std::string code = "";
	BuildTable(huffmanTree->GetMin(), code);
}

void HuffmanEncoder::BuildTable(HuffmanNode* root, std::string code)
{
	while (true)
	{
		if (root->GetLeftChild() == NULL)
		{
			root->SetCode(code);
			huffmanTable.insert(std::pair<char, std::string>(root->GetLetter(), code));
			return;
		}
		else
		{
			BuildTable(root->GetLeftChild(), code + "0");
			BuildTable(root->GetRightChild(), code + "1");
		}
	}
}

std::map<char, std::string> HuffmanEncoder::GetTable()
{
	return this->huffmanTable;
}