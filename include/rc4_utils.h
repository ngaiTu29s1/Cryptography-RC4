#ifndef RC4_UTILS_H
#define RC4_UTILS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

/**
 * Hàm khởi tạo S-box với các giá trị từ 0-255
 * @param S: Mảng S-box cần khởi tạo
 */
void initializeSBox(unsigned char S[256]) {
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }
}

/**
 * Hàm hoán đổi 2 phần tử trong S-box
 * @param a: Con trỏ tới phần tử thứ nhất
 * @param b: Con trỏ tới phần tử thứ hai
 */
void swap(unsigned char* a, unsigned char* b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Hàm in S-box dưới dạng hex
 * @param S: Mảng S-box cần in
 * @param title: Tiêu đề mô tả
 */
void printSBox(unsigned char S[256], const std::string& title) {
    std::cout << "\n" << title << ":\n";
    for (int i = 0; i < 256; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)S[i] << " ";
        if ((i + 1) % 16 == 0) std::cout << "\n";
    }
    std::cout << std::dec << std::endl;
}

/**
 * Hàm in dữ liệu dưới dạng hex
 * @param data: Dữ liệu cần in
 * @param title: Tiêu đề mô tả
 */
void printHex(const std::string& data, const std::string& title) {
    std::cout << title << ": ";
    for (unsigned char c : data) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)(unsigned char)c << " ";
    }
    std::cout << std::dec << std::endl;
}

/**
 * Hàm in keystream
 * @param keystream: Vector chứa keystream
 * @param title: Tiêu đề mô tả
 */
void printKeystream(const std::vector<unsigned char>& keystream, const std::string& title) {
    std::cout << title << ": ";
    for (size_t i = 0; i < keystream.size(); i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)keystream[i] << " ";
        if ((i + 1) % 16 == 0 && i + 1 < keystream.size()) std::cout << "\n           ";
    }
    std::cout << std::dec << std::endl;
}

/**
 * Hàm sao chép S-box
 * @param dest: S-box đích
 * @param src: S-box nguồn
 */
void copySBox(unsigned char dest[256], unsigned char src[256]) {
    for (int i = 0; i < 256; i++) {
        dest[i] = src[i];
    }
}

#endif // RC4_UTILS_H
