#ifndef LZ77_ENCODER_H
#define LZ77_ENCODER_H

#include "FileEncoder.h"

class LZ77Encoder : public FileEncoder
{
public:
	virtual void EncodeFile();
};

#endif