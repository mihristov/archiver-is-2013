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
void Deserializator::Deserialize()
{
	//Deserialize directories

	/* Deleting all files in the directory in quiet mode.
	The 2>null means to redirect all errors produced by this command 
	to /dev/null, that is discard them, and don't display them to the screen */
	string command = "rmdir /S /Q \"" + input_ + "\" 2>null";
	system(command.c_str());

	command = "mkdir \"" + input_ + "\"";
	system(command.c_str());

	unsigned int n;
	output_->ReadUnsignedInt32(n);
	for (int i = 0; i < (int)n; i++)
	{
		unsigned int length;
		output_->ReadUnsignedInt32(length);
		string directory_name = "";
		for (int i = 0; i < (int)length; i++) {
			char byte;
			output_->ReadByte(byte);
			directory_name += byte;
		}

		directory_name = input_ + "\\" + directory_name;
		string command = "mkdir \"" + directory_name + "\"";
		system(command.c_str()); //TODO: if or try-catch
	}

	//Deserialize files
	output_->ReadUnsignedInt32(n);
	for (int i = 0; i < (int)n; i++)
	{
		unsigned int length;
		output_->ReadUnsignedInt32(length);
		string filename = "";
		for (int i = 0; i < (int)length; i++)
		{
			char byte;
			output_->ReadByte(byte);
			filename += byte;
		}
		filename = input_ + "\\" + filename;

		unsigned int bytes;
		output_->ReadUnsignedInt32(bytes);
		FileWriteStream write_stream(filename);
		while (bytes > 0) {
			char byte;
			output_->ReadByte(byte);
			write_stream.WriteByte(byte);
			bytes--;
		}
		write_stream.Flush();
	}
}