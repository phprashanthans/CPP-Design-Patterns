#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class FileSystem {
    public:
        virtual void ls() = 0;
};

class File : public FileSystem {
    private:
        string p_name;
    public:
        File(string name) : p_name(name){}
        void ls() override {
            cout << "File_name: " << p_name << endl;
        }
};

class Directory : public FileSystem {
    private:
        string d_name;
        vector<FileSystem*> file_list;
    public:
        Directory(string name) : d_name(name) {}
        void addFiles(FileSystem* f){
            file_list.push_back(f);
        }
        void ls() override {
            cout << "Directory_name: " << d_name << endl;
            for(auto it : file_list) {
                cout << "   ----";
                it->ls();
            }
        }
};

int main() {
    FileSystem* f1 = new File("Godde Godde Chaa");
    FileSystem* f2 = new File("Bambukaat");
    FileSystem* f3 = new File("Angrej");
    Directory* dir1 = new Directory("Punjabi Movies");
    Directory* dir2 = new Directory("Comedy Movies");
    dir1->addFiles(f1);
    dir1->addFiles(f2);
    dir2->addFiles(f3);
    dir1->addFiles(dir2);
    
    dir1->ls();
    dir2->ls();
}