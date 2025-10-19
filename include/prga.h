#ifndef PRGA_H
#define PRGA_H

#include "rc4_utils.h"
#include <vector>

/**
 * PRGA - Pseudo-Random Generation Algorithm
 * Thuật toán sinh keystream từ S-box
 * 
 * Các bước:
 * 1. Khởi tạo i = 0, j = 0
 * 2. Với mỗi byte cần mã hóa:
 *    - i = (i + 1) % 256
 *    - j = (j + S[i]) % 256
 *    - Swap S[i] và S[j]
 *    - t = (S[i] + S[j]) % 256
 *    - K = S[t] (keystream byte)
 * 
 * @param S: Mảng S-box đã được khởi tạo bởi KSA
 * @param length: Độ dài keystream cần sinh
 * @return Vector chứa keystream
 */
std::vector<unsigned char> PRGA(unsigned char S[256], int length) {
    std::vector<unsigned char> keystream;
    keystream.reserve(length);
    
    int i = 0;
    int j = 0;
    
    for (int n = 0; n < length; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(&S[i], &S[j]);
        
        int t = (S[i] + S[j]) % 256;
        keystream.push_back(S[t]);
    }
    
    return keystream;
}

/**
 * PRGA với verbose mode để hiển thị quá trình
 * @param S: Mảng S-box đã được khởi tạo bởi KSA
 * @param length: Độ dài keystream cần sinh
 * @param verbose: Có hiển thị chi tiết quá trình hay không
 * @return Vector chứa keystream
 */
std::vector<unsigned char> PRGA_verbose(unsigned char S[256], int length, bool verbose = false) {
    std::vector<unsigned char> keystream;
    keystream.reserve(length);
    
    if (verbose) {
        std::cout << "\n=== PRGA - Pseudo-Random Generation Algorithm ===\n";
        std::cout << "Generating keystream of length: " << length << " bytes\n";
    }
    
    int i = 0;
    int j = 0;
    
    // Hiển thị vài bước đầu tiên nếu verbose
    for (int n = 0; n < length; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(&S[i], &S[j]);
        
        int t = (S[i] + S[j]) % 256;
        unsigned char K = S[t];
        keystream.push_back(K);
        
        if (verbose && n < 5) {
            std::cout << "Step " << n + 1 << ": i=" << i 
                      << ", j=" << j 
                      << ", t=" << t 
                      << ", K=" << std::hex << std::setw(2) << std::setfill('0') << (int)K 
                      << std::dec << "\n";
        }
    }
    
    if (verbose && length > 5) {
        std::cout << "... (omitted " << length - 5 << " steps)\n";
    }
    
    return keystream;
}

#endif // PRGA_H
