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
	void Deserialize();
private:
	std::string input_;
	ReadStream* output_;
};
#endif