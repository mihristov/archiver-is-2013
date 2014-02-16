#ifndef READ_STREAM_H
#define READ_STREAM_H

class ReadStream
{
public:
	virtual ~ReadStream() {};
	virtual bool ReadBit(char& bit) = 0;
	virtual bool ReadByte(char& byte) = 0;
	virtual bool ReadUnsignedInt32(unsigned int& value) = 0;
	virtual bool Reset() = 0;
	virtual unsigned int Bytes() = 0;
	virtual void RoundBitIndex() = 0;
};

#endif