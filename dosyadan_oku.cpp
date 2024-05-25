#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "BinaryTree.h" 

using namespace std;

void loadFromFile(const std::string& filename, BinaryTree& tree) {
    ifstream dosya(filename);
    char ogrno[15], ad[30], soyad[30], satirAl[75];
    char *ptr;

    dosya.getline(satirAl, 75);
    while(dosya) {
        for(int i = 0; i < 75; i++) {
            if(satirAl[i] == '\r')
                satirAl[i] = '\0';
        }
        ptr = strtok(satirAl, "\t");
        int j = 0;
        while(ptr != NULL) {
            if(j == 0)
                strcpy(ogrno, ptr);
            if(j == 1)
                strcpy(ad, ptr);
            if(j == 2)
                strcpy(soyad, ptr);
            if(j == 3) {
                strcat(ad, " ");
                strcat(ad, soyad);
                strcpy(soyad, ptr);
            }
            ptr = strtok(NULL, " ");
            j++;
        }
        tree.insert(stoi(ogrno), ad, soyad);
        dosya.getline(satirAl, 75);
    }
    dosya.close();
}

int main() {
    BinaryTree tree1, tree2, tree3;

    loadFromFile("data1.txt", tree1);
    loadFromFile("data2.txt", tree2);
    loadFromFile("data3.txt", tree3);

    tree1.inorder();
    tree2.inorder();
    tree3.inorder();

    return 0;
}