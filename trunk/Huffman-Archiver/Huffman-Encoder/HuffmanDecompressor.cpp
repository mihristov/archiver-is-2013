#include "HuffmanDecompressor.h"
#include "HuffmanEncoder.h"
using std::map;
void HuffmanDecompressor::DecompressFile()
{
	map<char, unsigned int> frequencies;
	
	//Decode frequency table
	unsigned int elements;
	input_->ReadUnsignedInt32(elements);
	for (int i = 0; i < elements; i++) {
		char byte;
		input_->ReadByte(byte);
		unsigned int freq;
		input_->ReadUnsignedInt32(freq);
		frequencies[byte] = freq;
	}

	HuffmanEncoder* huffmanEncoder = new HuffmanEncoder(frequencies);
	huffmanEncoder->BuildTree();

	

}