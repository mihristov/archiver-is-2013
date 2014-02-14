#ifndef DESERIALIZATOR_H 
#define DESERIALIZATOR_H

#include "FileReadStream.h"
#include "FileWriteStream.h"
#include "FileDecompressor.h"
#include <string>

class Deserializator
{
public:
	Deserializator(std::string, std::string);
	~Deserializator();
	bool Deserialize();
private:
	std::string input_;
	std::string output_;
	ReadStream* inputStream_;
	bool DeserializeFile();
	bool DeserializeFiles();
	bool DeserializeDirectories();
	bool DeserializeDirectory();
};
#endif