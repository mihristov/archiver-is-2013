#include <iostream>
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

using namespace std;
const static int READ_MODE = ios::in | ios::binary;
const static int WRITE_MODE = ios::out | ios::binary;

int* ReadFile(const char* fileName);
void CreateHuffmanTree(int* charactersCount);

// A small driver program that demonstrates the Huffman encoding API.
int main(int argc, char* argv[]) {
	
	//string baseDirectory = argv[1];
	//vector<string> filesAndDirectories;
	//GetFilesAndDirectoriesRecursive(baseDirectory, filesAndDirectories);

	std::string inputMilen = "C:\\Users\\Milen\\Desktop\\Sample";
	std::string outputMilen = "C:\\Users\\Milen\\Desktop\\Archive\\Petyo.txt";
	std::string inputStefan = "C:\\Users\\Stefan\\Desktop\\Sample";
	std::string outputStefan = "C:\\Users\\Stefan\\Desktop\\Archive\\Petyo.txt";
	//TODO: Fix slashes at the end.
	ReadStream* read = new FileReadStream(inputMilen);
	WriteStream* write = new FileWriteStream(outputMilen);
	HuffmanCompressor* compressor = new HuffmanCompressor(read, write);

	std::string sampleOutput = "C:\\Users\\Milen\\Desktop\\SampleOutput";
	Serializator serialization(inputMilen, write, compressor);
	serialization.Serialize();

	Deserializator deserialization(outputMilen, sampleOutput);
	deserialization.Deserialize();
}