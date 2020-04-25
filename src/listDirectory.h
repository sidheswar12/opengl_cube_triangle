#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void listFiles(string directoryName, vector<string>*fileList)
{
        DIR *directory = opendir(directoryName.c_str()); 
        struct dirent *entry;   
        if(directory == NULL) 
        {
                cout << "Error(" << errno << ") opening " << directory << endl;
                return;
        }       
        while ((entry = readdir(directory)) != NULL)
        {
                string str = string(entry->d_name);
                if(str.substr(str.find_last_of(".") + 1) == "jpg")                
                {
                        fileList->push_back(str);
                }
        }
        sort(fileList->begin(), fileList->end());
        closedir(directory);
}