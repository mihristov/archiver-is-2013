#ifndef HUFFMAN_COMPRESSOR_H
#define HUFFMAN_COMPRESSOR_H

#include "FileCompressor.h"
#include <map>

class HuffmanCompressor : FileCompressor
{
private:
	ReadStream* input_;
	WriteStream* output_;

public:
	HuffmanCompressor(ReadStream*, WriteStream*);
	virtual ~HuffmanCompressor();
	virtual void CompressFile();

private:
	std::map<char, unsigned int> GetByteFrequencies();
};

#endif