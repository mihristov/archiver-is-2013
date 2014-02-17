// A small driver program that demonstrates the Huffman encoding API.#include <iostream>

#include <fstream>
#include <string>
#include "FileDispatcher.h"
#include "HuffmanEncoder.h"
#include "HuffmanCompressor.h"
#include "FileReadStream.h"
#include "FileWriteStream.h"
#include "Serializator.h"
#include "Deserializator.h"
#include "HuffmanDecompressor.h"
#include <map>

int main(int argc, char* argv[]) {
	
	// Verification for correct given absolute or relative directory to the program
	std::string err_message = "Please enter a valid directory!";

	if (argc != 3)
	{
		std::cerr << err_message << std::endl;
		return 1;
	}

	if (!FileDispatcher::IsValid(argv[2]) && !FileDispatcher::IsValid(argv[3]))
	{
		std::cerr << err_message << std::endl;
		return 1;
	}

	std::string firstParam = argv[1];
	if (firstParam == "compress")
	{
		ReadStream* read = new FileReadStream(argv[2]);
		WriteStream* write = new FileWriteStream(argv[3]);
		HuffmanCompressor* compressor = new HuffmanCompressor(read, write);
		Serializator serialization(argv[2], write, compressor);
		serialization.Serialize();
	}
	else if (firstParam == "decompress")
	{
		Deserializator deserialization(argv[2], argv[3]);
		deserialization.Deserialize();
	}


	//std::string inputMilen = "C:\\Users\\Milen\\Desktop\\Sample";
	//std::string outputMilen = "C:\\Users\\Milen\\Desktop\\Archive\\Petyo.txt";
	//std::string inputStefan = "C:\\Users\\Stefan\\Desktop\\Sample";
	//std::string outputStefan = "C:\\Users\\Stefan\\Desktop\\Archive\\Petyo.txt";
	////TODO: Fix slashes at the end.
	//ReadStream* read = new FileReadStream(inputMilen);
	//WriteStream* write = new FileWriteStream(outputMilen);
	//HuffmanCompressor* compressor = new HuffmanCompressor(read, write);
	//	
	//std::string sampleOutput = "C:\\Users\\Milen\\Desktop\\SampleOutput";
	//Serializator serialization(inputMilen, write, compressor);
	//serialization.Serialize();

	//Deserializator deserialization(outputMilen, sampleOutput);
	//deserialization.Deserialize();
}