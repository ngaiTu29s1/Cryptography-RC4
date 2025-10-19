#include "include/rc4.h"
#include <iostream>

int main() {
    // Khai báo plaintext và key
    std::string plaintext = "Hanoi University of Science and Technology";
    std::string key = "HUST2024";
    
    std::cout << "=============================================\n";
    std::cout << "RC4 STREAM CIPHER IMPLEMENTATION\n";
    std::cout << "=============================================\n";
    
    // Mã hóa với verbose mode
    std::string ciphertext = RC4_encrypt(plaintext, key, true);
    
    // Giải mã với verbose mode
    std::string decrypted = RC4_decrypt(ciphertext, key, true);
    
    // Kiểm tra kết quả
    std::cout << "\n=============================================\n";
    std::cout << "VERIFICATION\n";
    std::cout << "=============================================\n";
    std::cout << "Original plaintext:  " << plaintext << "\n";
    std::cout << "Decrypted plaintext: " << decrypted << "\n";
    
    if (plaintext == decrypted) {
        std::cout << "\n✓ SUCCESS: Decryption matches original plaintext!\n";
    } else {
        std::cout << "\n✗ ERROR: Decryption does not match original plaintext!\n";
    }
    
    std::cout << "=============================================\n";
    
    // Demo thêm với key khác để thấy sự khác biệt
    std::cout << "\n\n=============================================\n";
    std::cout << "DEMO WITH DIFFERENT KEY\n";
    std::cout << "=============================================\n";
    
    std::string wrong_key = "WRONG123";
    std::cout << "Trying to decrypt with wrong key: " << wrong_key << "\n";
    std::string wrong_decrypted = RC4_decrypt(ciphertext, wrong_key, false);
    std::cout << "Result: " << wrong_decrypted << "\n";
    std::cout << "(Shows garbled text because key is incorrect)\n";
    std::cout << "=============================================\n";
    
    return 0;
}
