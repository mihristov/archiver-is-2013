#ifndef SERIALIZATOR_H
#define SERIALIZATOR_H

#include "ReadStream.h"
#include "WriteStream.h"
#include "FileCompressor.h"
#include <string>

class Serializator
{
public:
	Serializator(std::string input, WriteStream* output, FileCompressor* compressor);
	~Serializator();
	void Serialize();

private:
	//ReadStream* input_;
	std::string input_;
	WriteStream* output_;
	FileCompressor* compressor_;
};

#endif