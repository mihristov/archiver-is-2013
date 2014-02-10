#include "HuffmanCompressor.h"
#include "HuffmanEncoder.h"
//#include <map>
#include <string>

using std::string;
//using std::map;

HuffmanCompressor::HuffmanCompressor(ReadStream* input, WriteStream* output)
{
	this->input_ = input;
	this->output_ = output;
}

HuffmanCompressor::~HuffmanCompressor()
{
}

std::map<char, unsigned int> HuffmanCompressor::GetByteFrequencies()
{
	std::map<char, unsigned int> frequencies;

	while (true)
	{
		char byte;
		if (!input_->ReadByte(byte))
		{
			break;
		}
		frequencies[byte]++;
	}

	return frequencies;
}

void HuffmanCompressor::CompressFile()
{
	std::map<char, unsigned int> frequencies = GetByteFrequencies();
}