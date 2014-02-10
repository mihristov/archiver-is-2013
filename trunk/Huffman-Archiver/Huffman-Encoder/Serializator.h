#ifndef SERIALIZATOR_H
#define SERIALIZATOR_H

#include "ReadStream.h"
#include "WriteStream.h"
#include "FileCompressor.h"

class Serializator
{
private:
	ReadStream* input_;
	WriteStream* output_;
	FileCompressor* compressor_;

public:
	Serializator(ReadStream* input, WriteStream* output, FileCompressor* compressor);
	~Serializator();
	void Serialize();
};

#endif