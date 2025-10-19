#include "include/rc4.h"
#include <iostream>

/**
 * Simple example - Ví dụ đơn giản không có verbose mode
 * Chạy file này để xem kết quả ngắn gọn
 */
int main() {
    // Test case 1: Chuỗi đề bài
    std::cout << "=== TEST CASE 1 ===\n";
    std::string plaintext1 = "Hanoi University of Science and Technology";
    std::string key1 = "HUST2024";
    
    std::string ciphertext1 = RC4_encrypt(plaintext1, key1, false);
    std::string decrypted1 = RC4_decrypt(ciphertext1, key1, false);
    
    std::cout << "Plaintext:  " << plaintext1 << "\n";
    std::cout << "Key:        " << key1 << "\n";
    printHex(ciphertext1, "Ciphertext");
    std::cout << "Decrypted:  " << decrypted1 << "\n";
    std::cout << "Match:      " << (plaintext1 == decrypted1 ? "YES ✓" : "NO ✗") << "\n\n";
    
    // Test case 2: Chuỗi ngắn
    std::cout << "=== TEST CASE 2 ===\n";
    std::string plaintext2 = "Hello World";
    std::string key2 = "Key";
    
    std::string ciphertext2 = RC4_encrypt(plaintext2, key2, false);
    std::string decrypted2 = RC4_decrypt(ciphertext2, key2, false);
    
    std::cout << "Plaintext:  " << plaintext2 << "\n";
    std::cout << "Key:        " << key2 << "\n";
    printHex(ciphertext2, "Ciphertext");
    std::cout << "Decrypted:  " << decrypted2 << "\n";
    std::cout << "Match:      " << (plaintext2 == decrypted2 ? "YES ✓" : "NO ✗") << "\n\n";
    
    // Test case 3: Key dài
    std::cout << "=== TEST CASE 3 ===\n";
    std::string plaintext3 = "Secret Message";
    std::string key3 = "ThisIsAVeryLongSecretKey123456";
    
    std::string ciphertext3 = RC4_encrypt(plaintext3, key3, false);
    std::string decrypted3 = RC4_decrypt(ciphertext3, key3, false);
    
    std::cout << "Plaintext:  " << plaintext3 << "\n";
    std::cout << "Key:        " << key3 << "\n";
    printHex(ciphertext3, "Ciphertext");
    std::cout << "Decrypted:  " << decrypted3 << "\n";
    std::cout << "Match:      " << (plaintext3 == decrypted3 ? "YES ✓" : "NO ✗") << "\n\n";
    
    return 0;
}
