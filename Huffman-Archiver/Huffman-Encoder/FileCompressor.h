#ifndef FILE_COMPRESSOR_H
#define FILE_COMPRESSOR_H

#include "ReadStream.h"
#include "WriteStream.h"

class FileCompressor
{
public:
	virtual ~FileCompressor() {};
	virtual void CompressFile() = 0;
	virtual void SetReadStream(ReadStream*) = 0;
};

#endif