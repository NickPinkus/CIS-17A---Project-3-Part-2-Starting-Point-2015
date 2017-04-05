#include "Folder.h"
#include <iostream>
using namespace std;

Folder::Folder(std::string name) : _name(name)
{
}

Folder::Folder(){}

Folder::~Folder()
{
}

std::vector<std::string> Folder::ListFiles()
{
	std::vector<std::string> list;
	for (auto file : _files) {
		list.push_back(file->getName());
	}
	return list;
}

std::string Folder::ListContents()
{
	std::string output = "\n";
	for (auto folder : _folders) {
		output += "\\" + folder->getName() + "\n";
	}
	for (auto file : _files) {
		output += file->getName() + "\n";		
	}
	return output;
}

void Folder::AddFile(std::shared_ptr<File> newFile)
{
	_files.push_back(newFile);
}

void Folder::AddFolder(std::shared_ptr<Folder> newFolder)
{
	_folders.push_back(newFolder);
}

std::shared_ptr<Folder> Folder::FindFolder(std::string name)
{
	for(auto folder : _folders)
	{
		if (folder->getName() == name) {
			return folder;
		}
	}
	return nullptr;
}

std::shared_ptr<File> Folder::FindFile(std::string name)
{
	//Loop/Iterate this folder's files
	//If you find a file with the passed in name, return it
	//Loop/Iterate this folder's folders
	//Search(each folder in the loop)
	//Otherwise, return nullptr

	for (auto file : _files)
	{
		if (file->getName() == name) {
			cout << "File Found: " << name << endl
				 << "Located in Folder: " << getName() << endl;
			return file;
		}
	}

	for (auto folder : _folders)
	{
		auto file = folder->FindFile(name);
		if (file != nullptr) {
			return file;
		}
	}
	cout << "File Not Found" << endl;
	return nullptr;
}
