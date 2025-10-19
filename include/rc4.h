#ifndef RC4_H
#define RC4_H

#include "ksa.h"
#include "prga.h"
#include <string>

/**
 * RC4 Encryption
 * Mã hóa plaintext sử dụng thuật toán RC4
 * 
 * @param plaintext: Văn bản gốc cần mã hóa
 * @param key: Khóa mã hóa
 * @param verbose: Có hiển thị chi tiết quá trình hay không
 * @return Ciphertext (văn bản đã mã hóa)
 */
std::string RC4_encrypt(const std::string& plaintext, const std::string& key, bool verbose = false) {
    unsigned char S[256];
    
    if (verbose) {
        std::cout << "\n========================================\n";
        std::cout << "RC4 ENCRYPTION\n";
        std::cout << "========================================\n";
        std::cout << "Plaintext: " << plaintext << "\n";
        std::cout << "Plaintext length: " << plaintext.length() << " bytes\n";
    }
    
    // Bước 1: KSA - Khởi tạo S-box
    if (verbose) {
        KSA_verbose(S, (const unsigned char*)key.c_str(), key.length(), true);
    } else {
        KSA(S, (const unsigned char*)key.c_str(), key.length());
    }
    
    // Tạo bản sao S-box để PRGA
    unsigned char S_copy[256];
    copySBox(S_copy, S);
    
    // Bước 2: PRGA - Sinh keystream
    std::vector<unsigned char> keystream;
    if (verbose) {
        keystream = PRGA_verbose(S_copy, plaintext.length(), true);
        printKeystream(keystream, "\nKeystream");
    } else {
        keystream = PRGA(S_copy, plaintext.length());
    }
    
    // Bước 3: XOR plaintext với keystream để tạo ciphertext
    std::string ciphertext;
    ciphertext.reserve(plaintext.length());
    
    if (verbose) {
        std::cout << "\n=== XOR Operation ===\n";
    }
    
    for (size_t i = 0; i < plaintext.length(); i++) {
        unsigned char encrypted_byte = plaintext[i] ^ keystream[i];
        ciphertext += encrypted_byte;
        
        if (verbose && i < 5) {
            std::cout << "Byte " << i << ": " 
                      << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)plaintext[i]
                      << " XOR " 
                      << std::hex << std::setw(2) << std::setfill('0') << (int)keystream[i]
                      << " = "
                      << std::hex << std::setw(2) << std::setfill('0') << (int)encrypted_byte
                      << std::dec << "\n";
        }
    }
    
    if (verbose && plaintext.length() > 5) {
        std::cout << "... (omitted " << plaintext.length() - 5 << " bytes)\n";
    }
    
    if (verbose) {
        printHex(ciphertext, "\nCiphertext (hex)");
        std::cout << "========================================\n";
    }
    
    return ciphertext;
}

/**
 * RC4 Decryption
 * Giải mã ciphertext sử dụng thuật toán RC4
 * 
 * Lưu ý: RC4 là thuật toán đối xứng, quá trình giải mã giống hệt mã hóa
 * 
 * @param ciphertext: Văn bản đã mã hóa
 * @param key: Khóa giải mã (phải giống khóa mã hóa)
 * @param verbose: Có hiển thị chi tiết quá trình hay không
 * @return Plaintext (văn bản gốc)
 */
std::string RC4_decrypt(const std::string& ciphertext, const std::string& key, bool verbose = false) {
    unsigned char S[256];
    
    if (verbose) {
        std::cout << "\n========================================\n";
        std::cout << "RC4 DECRYPTION\n";
        std::cout << "========================================\n";
        printHex(ciphertext, "Ciphertext (hex)");
        std::cout << "Ciphertext length: " << ciphertext.length() << " bytes\n";
    }
    
    // Bước 1: KSA - Khởi tạo S-box (giống như mã hóa)
    if (verbose) {
        KSA_verbose(S, (const unsigned char*)key.c_str(), key.length(), true);
    } else {
        KSA(S, (const unsigned char*)key.c_str(), key.length());
    }
    
    // Tạo bản sao S-box để PRGA
    unsigned char S_copy[256];
    copySBox(S_copy, S);
    
    // Bước 2: PRGA - Sinh keystream (giống như mã hóa)
    std::vector<unsigned char> keystream;
    if (verbose) {
        keystream = PRGA_verbose(S_copy, ciphertext.length(), true);
        printKeystream(keystream, "\nKeystream");
    } else {
        keystream = PRGA(S_copy, ciphertext.length());
    }
    
    // Bước 3: XOR ciphertext với keystream để tạo plaintext
    std::string plaintext;
    plaintext.reserve(ciphertext.length());
    
    if (verbose) {
        std::cout << "\n=== XOR Operation ===\n";
    }
    
    for (size_t i = 0; i < ciphertext.length(); i++) {
        unsigned char decrypted_byte = ciphertext[i] ^ keystream[i];
        plaintext += decrypted_byte;
        
        if (verbose && i < 5) {
            std::cout << "Byte " << i << ": " 
                      << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)ciphertext[i]
                      << " XOR " 
                      << std::hex << std::setw(2) << std::setfill('0') << (int)keystream[i]
                      << " = "
                      << std::hex << std::setw(2) << std::setfill('0') << (int)decrypted_byte
                      << " ('" << (char)decrypted_byte << "')"
                      << std::dec << "\n";
        }
    }
    
    if (verbose && ciphertext.length() > 5) {
        std::cout << "... (omitted " << ciphertext.length() - 5 << " bytes)\n";
    }
    
    if (verbose) {
        std::cout << "\nPlaintext: " << plaintext << "\n";
        std::cout << "========================================\n";
    }
    
    return plaintext;
}

#endif // RC4_H
