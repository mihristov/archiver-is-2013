#include <iostream>
#include <fstream>
#include <string>
#include "FileDispatcher.h"
#include "HuffmanEncoder.h"
#include "HuffmanCompressor.h"
#include "FileReadStream.h"
#include "FileWriteStream.h"
#include <map>

using namespace std;
const static int READ_MODE = ios::in | ios::binary;
const static int WRITE_MODE = ios::out | ios::binary;

int* ReadFile(const char* fileName);
void CreateHuffmanTree(int* charactersCount);

// A small driver program that demonstrates the Huffman encoding API.
int main(int argc, char* argv[]) {
	/*string file = "C:\\Users\\Milen\\Desktop\\Sample";
	vector<string> vec;
	FileDispatcher::TraverseDirectoryRecursively(vec, file);*/

	//string baseDirectory = argv[1];
	//vector<string> filesAndDirectories;
	//GetFilesAndDirectoriesRecursive(baseDirectory, filesAndDirectories);


	//for (vector<string>::iterator it = filesAndDirectories.begin(); it != filesAndDirectories.end(); it++)
	//{
	//	// cout << *it << endl;
	//}
	//int* charactersCount = ReadFile("input.txt");

	// Test Binary Heap
	/*HuffmanBinaryHeap heap(3);
	HuffmanNode* node1 = new HuffmanNode(4, 'a');
	HuffmanNode* node2 = new HuffmanNode(3, 'b');
	HuffmanNode* node3 = new HuffmanNode(2, 'c');
	heap.Add(node1);
	heap.Add(node2);
	heap.Add(node3);
	heap.Print();
	HuffmanNode* minNode;
	while (!heap.IsEmpty())
	{
		minNode = heap.RemoveMin();
		minNode->PrintNode();
		heap.Print();
	}*/
	ReadStream *read = new FileReadStream("C:\\Users\\Milen\\Desktop\\Sample\\Milen.txt");
	WriteStream *write = new FileWriteStream("C:\\Users\\Milen\\Desktop\\Sample\\Miuen.txt");
	HuffmanCompressor cmpr(read, write);
	cmpr.CompressFile();
}