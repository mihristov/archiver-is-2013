#ifndef FILE_COMPRESSOR_H
#define FILE_COMPRESSOR_H

#include "ReadStream.h"
#include "WriteStream.h"

class FileCompressor
{
public:
	virtual void CompressFile(ReadStream*, WriteStream*) = 0;
};

#endif