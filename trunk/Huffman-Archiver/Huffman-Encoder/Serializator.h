#ifndef SERIALIZATOR_H
#define SERIALIZATOR_H

#include "ReadStream.h"
#include "WriteStream.h"
#include "FileCompressor.h"
#include <string>

class Serializator
{
private:
	//ReadStream* input_;
	std::string input_;
	WriteStream* output_;
	FileCompressor* compressor_;

public:
	Serializator(std::string, WriteStream* output, FileCompressor* compressor);
	~Serializator();
	void Serialize();
};

#endif