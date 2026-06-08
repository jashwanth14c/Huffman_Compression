



# Huffman File Compression (C++)

A lossless file compression and decompression system implemented using the Huffman Coding algorithm in C++.


## Overview

This project demonstrates how data compression works using Huffman Coding. It builds a binary tree based on character frequencies and assigns shorter binary codes to more frequent characters, reducing overall file size.



## Features

- Build Huffman Tree from input text
- Generate binary codes for each character
- Compress text into binary string
- Decompress binary back to original text
- Display Huffman codes for all characters



## Concepts Used

- Greedy Algorithm (Huffman Coding)
- Binary Tree
- Priority Queue (Min Heap)
- Hash Map (`unordered_map`)
- Recursion


## How to Run

1. Compile:
   g++ main.cpp huffman.cpp -o huffman

2. Run:
   ./huffman   (Linux/Mac)
   huffman.exe (Windows)




## How It Works

1. Count frequency of each character
2. Build a Min Heap using frequencies
3. Construct Huffman Tree
4. Generate binary codes for each character
5. Encode input text into binary string
6. Decode binary string back to original text


