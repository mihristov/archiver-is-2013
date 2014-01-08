#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>

#define STREAM_BUFFER_SIZE 4096

using std::ifstream;
using std::string;

class FileReadStream
{
public:
	FileReadStream(const string& filename);
	~FileReadStream();
	bool ReadBit(char& bit);
	bool ReadByte(char& byte);
	bool ReadUnsignedInt32(unsigned int& value);
	bool Reset();
	unsigned int Bytes();
private:
	string filename;
	char* buffer_;
	ifstream file_stream_;
	unsigned int bit_index_;
	unsigned int total_bits_;
};

#endif