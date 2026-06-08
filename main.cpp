


#include <iostream>
#include "huffman.h"

using namespace std;

int main() {

    Huffman h;

    string text;

    cout << "Enter text to compress: ";
    getline(cin, text);

    h.build(text);

    string encoded = h.encode(text);

    cout << "\nEncoded Binary:\n" << encoded << endl;

    h.printCodes();

    string decoded = h.decode(encoded);

    cout << "\nDecoded Text:\n" << decoded << endl;

    return 0;
}