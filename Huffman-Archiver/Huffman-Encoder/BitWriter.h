#ifndef BIT_WRITER_H
#define BIT_WRITER_H

#include <fstream>
#include <string>

using std::ofstream;
using std::string;

class BitWriter
{
private:
	const int MAX_SIZE = 8;
	int size;
	unsigned char buffer;
	string fileName;
	ofstream output;

public:
	BitWriter(const string fileName);
	~BitWriter();
	void WriteBit(unsigned char bit);
	void Flush();
};

#endif