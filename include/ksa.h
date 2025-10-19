#ifndef KSA_H
#define KSA_H

#include "rc4_utils.h"

/**
 * KSA - Key Scheduling Algorithm
 * Thuật toán khởi tạo S-box dựa trên key
 * 
 * Các bước:
 * 1. Khởi tạo S-box với giá trị từ 0-255
 * 2. Sử dụng key để hoán vị S-box
 * 
 * @param S: Mảng S-box sẽ được khởi tạo
 * @param key: Khóa được sử dụng
 * @param keyLength: Độ dài của khóa
 */
void KSA(unsigned char S[256], const unsigned char* key, int keyLength) {
    // Bước 1: Khởi tạo S-box
    initializeSBox(S);
    
    // Bước 2: Hoán vị S-box dựa trên key
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keyLength]) % 256;
        swap(&S[i], &S[j]);
    }
}

/**
 * Hàm KSA với verbose mode để hiển thị quá trình
 * @param S: Mảng S-box sẽ được khởi tạo
 * @param key: Khóa được sử dụng
 * @param keyLength: Độ dài của khóa
 * @param verbose: Có hiển thị chi tiết quá trình hay không
 */
void KSA_verbose(unsigned char S[256], const unsigned char* key, int keyLength, bool verbose = false) {
    // Bước 1: Khởi tạo S-box
    initializeSBox(S);
    
    if (verbose) {
        std::cout << "\n=== KSA - Key Scheduling Algorithm ===\n";
        std::cout << "Key: ";
        for (int i = 0; i < keyLength; i++) {
            std::cout << key[i];
        }
        std::cout << "\nKey length: " << keyLength << " bytes\n";
        printSBox(S, "S-box ban đầu (identity permutation)");
    }
    
    // Bước 2: Hoán vị S-box dựa trên key
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keyLength]) % 256;
        swap(&S[i], &S[j]);
    }
    
    if (verbose) {
        printSBox(S, "S-box sau KSA");
    }
}

#endif // KSA_H
