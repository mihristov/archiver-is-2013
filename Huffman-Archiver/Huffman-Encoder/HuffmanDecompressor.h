#ifndef HUFFMAN_DECOMPRESSOR_H
#define HUFFMAN_DECOMPRESSOR_H

#include "ReadStream.h"
#include "WriteStream.h"
#include "FileDecompressor.h"

class HuffmanDecompressor
{
private:
private:
	ReadStream* input_;
	WriteStream* output_;
public:
	virtual ~HuffmanDecompressor() {};
	virtual void DecompressFile() = 0;
	virtual void SetWriteStream(WriteStream*) = 0;
};

#endif