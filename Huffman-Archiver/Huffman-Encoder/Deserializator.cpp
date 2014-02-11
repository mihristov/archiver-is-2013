#include "Deserializator.h"
#include "FileWriteStream.h"
#include "FileReadStream.h"
#include "FileDispatcher.h"
#include <vector>
#include <string>

Deserializator::Deserializator(std::string input, ReadStream* output)
{
	this->input_ = input;
	this->output_ = output;
}

Deserializator::~Deserializator()
{
	delete output_;
}

bool Deserializator::DeserializeDirectory(const string& base_directory,
	ReadStream* read_stream)
{
	unsigned int length;
	if (!read_stream->ReadUnsignedInt32(length)) return false;
	string directory_name;
	for (int i = 0; i < (int)length; i++) {
		char byte;
		if (!read_stream->ReadByte(byte)) return false;
		directory_name += byte;
	}
	directory_name = base_directory + "\\" + directory_name;
	string command = "mkdir \"" + directory_name + "\"";
	if (system(command.c_str())) return false;

	return true;
}

bool Deserializator::DeserializeFile(const string& base_directory, ReadStream* read_stream) {
	unsigned int length;
	if (!read_stream->ReadUnsignedInt32(length)) return false;
	string filename;
	for (int i = 0; i < (int)length; i++) {
		char byte;
		if (!read_stream->ReadByte(byte)) return false;
		filename += byte;
	}
	filename = base_directory + "\\" + filename;

	unsigned int bytes;
	if (!read_stream->ReadUnsignedInt32(bytes)) return false;
	FileWriteStream write_stream(filename);
	while (bytes > 0) {
		char byte;
		if (!read_stream->ReadByte(byte)) return false;
		if (!write_stream.WriteByte(byte)) return false;
		bytes--;
	}
	write_stream.Flush();
	return true;
}

bool Deserializator::DeserializeDirectories(const string& base_directory,
	ReadStream* read_stream) {

	// Make sure that the target base directory is empty.

	// Delete the target base directory.
	string command = "rmdir /S /Q \"" + base_directory + "\" 2>null";
	system(command.c_str());

	// Create an empty target base directory.
	command = "mkdir \"" + base_directory + "\"";
	system(command.c_str());

	unsigned int n;
	if (!read_stream->ReadUnsignedInt32(n)) return false;
	for (int i = 0; i < (int)n; i++) {
		if (!DeserializeDirectory(base_directory, read_stream)) return false;
	}
	return true;
}

bool Deserializator::DeserializeFiles(const string& base_directory, ReadStream* read_stream) {
	unsigned int n;
	if (!read_stream->ReadUnsignedInt32(n)) return false;
	for (int i = 0; i < (int)n; i++) {
		if (!DeserializeFile(base_directory, read_stream)) return false;
	}
	return true;
}

bool Deserializator::Deserialize()
{
	if (!DeserializeDirectories(input_, output_)) return false;
	if (!DeserializeFiles(input_, output_)) return false;
	return true;

}