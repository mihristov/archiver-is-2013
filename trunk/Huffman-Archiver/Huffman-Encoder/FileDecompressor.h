#ifndef FILE_DECOMPRESSOR_H
#define FILE_DECOMPRESSOR_H

#include "ReadStream.h"
#include "WriteStream.h"

class FileDecompressor
{
public:
	virtual ~FileDecompressor() {};
	virtual void DecompressFile() = 0;
	virtual void SetWriteStream(WriteStream*) = 0;
};

#endif