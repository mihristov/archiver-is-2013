#ifndef WRITE_STREAM_H
#define WRITE_STREAM_H

class WriteStream {
public:
	virtual ~WriteStream() {}
	virtual bool WriteBit(char bit) = 0;
	virtual bool WriteByte(char byte) = 0;
	virtual bool WriteUnsignedInt32(unsigned int value) = 0;
	virtual bool Flush() = 0;
};

#endif