#ifndef FILE_DISPATCHER_H
#define FILE_DISPATCHER_H

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class FileDispatcher
{
public:
	bool static IsDirectory(const string& directory);
	bool static IsFile(const string& file);
	vector<string> static TraverseDirectory(string& const basepath);
	void static TraverseDirectoryRecursively(vector<string>& filepaths, string& const basepath);
	string static StripBasePath(const string& path, const string& base_path);
	string static StripLastPathComponent(const string& path);

private:

};

#endif