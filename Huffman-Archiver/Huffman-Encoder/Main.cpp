#include <iostream>
#include <fstream>
#include <string>
#include "FileDispatcher.h"
#include <map>

using namespace std;
const static int READ_MODE = ios::in | ios::binary;
const static int WRITE_MODE = ios::out | ios::binary;

int* ReadFile(const char* fileName);
void CreateHuffmanTree(int* charactersCount);

// A small driver program that demonstrates the Huffman encoding API.
int main(int argc, char* argv[]) {
	string file = "C:\\Users\\Milen\\Desktop\\Sample";
	vector<string> vec;
	FileDispatcher::TraverseDirectoryRecursively(vec, file);

	std::map<char, unsigned int> freq;
	for (std::map<char, unsigned int>::iterator it = freq.begin(); it != freq.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << '\n';
	}

	//string baseDirectory = argv[1];
	//vector<string> filesAndDirectories;
	//GetFilesAndDirectoriesRecursive(baseDirectory, filesAndDirectories);


	//for (vector<string>::iterator it = filesAndDirectories.begin(); it != filesAndDirectories.end(); it++)
	//{
	//	// cout << *it << endl;
	//}
	//int* charactersCount = ReadFile("input.txt");

	// Test Binary Heap
	/*HuffmanBinaryHeap heap(5);
	HuffmanNode* node1 = new HuffmanNode(1, 2);
	HuffmanNode* node2 = new HuffmanNode(2, 2);
	HuffmanNode* node3 = new HuffmanNode(3, 2);
	HuffmanNode* node4 = new HuffmanNode(4, 2);
	heap.Add(node1);
	heap.Add(node2);
	heap.Add(node3);
	heap.Add(node4);
	HuffmanNode* node5 = new HuffmanNode(0, 2);
	heap.Add(node5);
	heap.Print();
	HuffmanNode* minNode;
	while (!heap.IsEmpty())
	{
		minNode = heap.RemoveMin();
		minNode->PrintNode();
		heap.Print();
	}*/
}



int* ReadFile(const char* fileName)
{
	fstream reader;
	reader.open(fileName, ios::in | ios::binary);

	size_t numberOfCharacters = 256;
	int* charactersCount = new int[numberOfCharacters];
	for (size_t i = 0; i < numberOfCharacters; i++)
	{
		charactersCount[i] = 0;
	}

	char letter;
	int position = 0;

	if (reader.is_open())
	{
		while (true)
		{
			reader.read(&letter, sizeof(char));
			if (reader.eof())
			{
				break;
			}
			position = (int) letter;
			charactersCount[position] += 1;
			// cout << letter << endl;
		}
		reader.close();
	}
	else
	{
		printf("Unable to open file\n");
	}

	/*for (size_t i = 0; i < numberOfCharacters; i++)
	{
		cout << (char) i << " --> " << charactersCount[i] << "\n";
	}*/

	return charactersCount;
}