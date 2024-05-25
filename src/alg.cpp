// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string> Tree;
    std::ifstream file(filename);
    if (!file) {
        throw std::string("An error!");
    }
    std::string str;
    while (!file.eof()) {
        file >> str;
        std::transform(str.begin(), str.end(), str.begin(), tolower);
        bool fl = true;
        for (int i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                fl = false;
                break;
            }
        }
        std::string strRes;
        std::string temp = ".,!?:;\"\'-)/]*";
        if (str[0] == '\"' || str[0] == '(' || str[0] == '[')
            str = str.substr(1, str.size());
        int pos = str.find_first_of(temp);
        strRes = str.substr(0, pos);
        if (fl) {
            Tree.join(strRes);
        }
    }
    file.close();
    return Tree;
}
