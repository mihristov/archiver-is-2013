#include "FileDispatcher.h"

bool FileDispatcher::IsDirectory(string& directory)
{
	DWORD attribute = GetFileAttributes((LPCWSTR)directory.c_str());
	return attribute & FILE_ATTRIBUTE_DIRECTORY;
}

bool FileDispatcher::IsFile(string& file)
{
	DWORD attribute = GetFileAttributes((LPCWSTR)file.c_str());
	return !(attribute & FILE_ATTRIBUTE_DIRECTORY);
}

vector<string> FileDispatcher::TraverseDirectory(string& const basepath)
{
	vector<string> filepaths;
	string path = basepath + "\\*";
	WIN32_FIND_DATAA find_data;
	HANDLE find_data_handle = FindFirstFileA(path.c_str(), &find_data);

	if (find_data_handle == INVALID_HANDLE_VALUE) {
		return filepaths;
	}

	while (true) {
		if (string(find_data.cFileName) != "." &&
			string(find_data.cFileName) != "..") {
			filepaths.push_back(find_data.cFileName);
		}
		if (!FindNextFileA(find_data_handle, &find_data)) break;
	}

	FindClose(find_data_handle);
	return filepaths;
}

void FileDispatcher::TraverseDirectoryRecursively(vector<string>& filepaths, string& const basepath)
{
	filepaths.push_back(basepath);
	if (IsDirectory(basepath))
	{
		vector<string> filepathsFlat = TraverseDirectory(basepath);
		for (int i = 0; i < filepathsFlat.size(); i++)
		{
			string name = filepathsFlat[i];
			TraverseDirectoryRecursively(filepaths, basepath + "\\" + name);
		}
	}
}