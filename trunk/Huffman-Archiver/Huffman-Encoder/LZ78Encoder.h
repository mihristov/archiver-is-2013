#ifndef LZ78_ENCODER_H
#define LZ78_ENCODER_H

#include "FileEncoder.h"

class LZ78Encoder : public FileEncoder
{
public:
	virtual void EncodeFile();
};
#endif