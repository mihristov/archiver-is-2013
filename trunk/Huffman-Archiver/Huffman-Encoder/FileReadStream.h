#ifndef FILE_READ_STREAM_H
#define FILE_READ_STREAM_H

#define STREAM_BUFFER_SIZE 4096

#include "ReadStream.h"
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

class FileReadStream : public ReadStream {
public:
	FileReadStream(const string& filename);
	virtual ~FileReadStream();
	virtual bool ReadBit(char& bit);
	virtual bool ReadByte(char& byte);
	virtual bool ReadUnsignedInt32(unsigned int& value);
	virtual bool Reset();
	virtual unsigned int Bytes();
private:
	string filename;
	char* buffer_;
	ifstream file_stream_;
	unsigned int bit_index_;
	unsigned int total_bits_;
};

#endif