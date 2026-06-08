



#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>

using namespace std;

class Huffman {

public:

    struct Node {
        char ch;
        int freq;
        Node *left;
        Node *right;

        Node(char c, int f) {
            ch = c;
            freq = f;
            left = right = nullptr;
        }
    };


    void build(const string &text);
    string encode(const string &text);
    string decode(const string &binary);
    void printCodes();

private:
    Node* root;

    unordered_map<char, string> codes;
    unordered_map<string, char> reverseCodes;


    void buildTree(const string &text);
    void generateCodes(Node* node, string str);
};

#endif