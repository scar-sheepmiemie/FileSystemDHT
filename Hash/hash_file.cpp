#include "md5.h"
#include "dirent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define PATH "./sample_files"

using namespace std;

int IdCounter[32] = {};
string getHash(const string &filename) {
	ifstream  fd(filename.c_str());
	if (!fd) {
		cout << "failed to open file: " << filename << endl;
		return "";
	}
	stringstream buffer;
	buffer << fd.rdbuf();
	string content = buffer.str();
	return MD5(content).toString();
}

int hash2fileID(const string &hash) {
	int mask = 32, res, prefixValue;
	string hashPrefix = hash.substr(0, 6);
	sscanf(hashPrefix.c_str(), "%x", &prefixValue);
	res = prefixValue % mask;
	IdCounter[res]++;
	cout << "hash: " << hash << ", hashPrefix: " << hashPrefix << ", hex value: " << prefixValue << " ,id: " << res << endl;
	return res;
}
void dealAllFiles(const string& path) {
	DIR *dir = opendir(path.c_str());
	if (dir == NULL) {
		cout << "failed to open the directory: " << path << endl;
		return;
	}
	struct dirent *entry = readdir(dir);
	int count = 0;
	while (entry != NULL) {
		cout << "reading " << entry->d_name << endl;
		string temp = PATH;
		temp = temp + "/" + entry->d_name;
		//cout << temp << endl;
		string tempMD5 = getHash(temp);
		hash2fileID(tempMD5);
		entry = readdir(dir);
		count++;
	}
	cout << "total " << count << "files:" << endl;
	for (int i = 0; i < 32; i++) {
		cout << i + 1 << ": " << IdCounter[i] << endl;
	}
	closedir(dir);
}
int main(int argc, char** argv)
{
	dealAllFiles(PATH);
	return 0;
}

