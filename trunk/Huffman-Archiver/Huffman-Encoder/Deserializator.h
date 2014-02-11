#ifndef DESERIALIZATOR_H 
#define DESERIALIZATOR_H

#include "FileReadStream.h"
#include "FileWriteStream.h"
#include <string>

class Deserializator
{
public:
	Deserializator(std::string, ReadStream*);
	~Deserializator();
	bool Deserialize();
private:
	std::string input_;
	ReadStream* output_;
	bool DeserializeFile(const string& base_directory, ReadStream* read_stream);
	bool DeserializeFiles(const string& base_directory, ReadStream* read_stream);
	bool DeserializeDirectories(const string& base_directory,
		ReadStream* read_stream);
	bool DeserializeDirectory(const string& base_directory,
		ReadStream* read_stream);
};
#endif