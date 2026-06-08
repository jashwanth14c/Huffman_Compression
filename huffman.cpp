

#include "huffman.h"
#include <queue>
#include <iostream>

using namespace std;

struct Compare {
    bool operator()(Huffman::Node* a, Huffman::Node* b) {
        return a->freq > b->freq;
    }
};

void Huffman::build(const string &text) {
    buildTree(text);
    codes.clear();
    reverseCodes.clear();
    generateCodes(root, "");
}

void Huffman::buildTree(const string &text) {

    unordered_map<char, int> freq;

    for (char c : text) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto &p : freq) {
        pq.push(new Node(p.first, p.second));
    }



    while (pq.size() > 1) {

        Node* left = pq.top(); pq.pop();

        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);

        newNode->left = left;


        newNode->right = right;

        pq.push(newNode);
    }

    root = pq.top();
}

void Huffman::generateCodes(Node* node, string str) {

    if (!node) return;

    if (!node->left && !node->right) {
        codes[node->ch] = str;
        reverseCodes[str] = node->ch;
    }

    generateCodes(node->left, str + "0");


    generateCodes(node->right, str + "1");
}


string Huffman::encode(const string &text) {

    string result = "";

    for (char c : text) {
        result += codes[c];
    }

    return result;
}




string Huffman::decode(const string &binary) {

    string result = "";
    string temp = "";

    for (char bit : binary) {
        temp += bit;

        if (reverseCodes.count(temp)) {
            result += reverseCodes[temp];
            temp = "";
        }
    }

    return result;
}



void Huffman::printCodes() {
    cout << "\nHuffman Codes:\n";
    for (auto &p : codes) {
        cout << p.first << " : " << p.second << endl;
    }
}