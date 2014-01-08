#ifndef FILE_WRITE_STREAM_H
#define FILE_WRITE_STREAM_H

#include <fstream>
#include <string>

#define STREAM_BUFFER_SIZE 4096

using std::string;
using std::ofstream;

class FileWriteStream
{
public:
	FileWriteStream(const string& filename);
	~FileWriteStream();
	bool WriteBit(char bit);
	bool WriteByte(char byte);
	bool WriteUnsignedInt32(unsigned int value);
	bool Flush();
private:
	string filename_;
	char* buffer_;
	ofstream file_stream_;
	unsigned int bit_index_;
	unsigned int total_bits_;
};

#endif