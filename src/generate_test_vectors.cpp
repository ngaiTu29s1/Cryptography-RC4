#include "include/rc4.h"
#include "include/test_vector_parser.h"
#include <fstream>

/**
 * Test Vector Generator - Tạo file test vectors từ RC4 implementation
 */

void generateTestVector(std::ofstream& outFile, const std::string& plaintext, const std::string& key) {
    // Encrypt
    std::string ciphertext = RC4_encrypt(plaintext, key, false);
    std::vector<unsigned char> ciphertext_bytes = stringToBytes(ciphertext);
    
    // Sinh keystream bằng cách chạy RC4 lại
    unsigned char S[256];
    KSA(S, (const unsigned char*)key.c_str(), key.length());
    unsigned char S_copy[256];
    copySBox(S_copy, S);
    std::vector<unsigned char> keystream = PRGA(S_copy, plaintext.length());
    
    // Decrypt để verify
    std::string decrypted = RC4_decrypt(ciphertext, key, false);
    
    // Ghi vào file
    outFile << "plaintext=" << plaintext << "\n";
    outFile << "key=" << key << "\n";
    outFile << "keystream=";
    for (size_t i = 0; i < keystream.size(); i++) {
        outFile << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (int)keystream[i];
        if (i < keystream.size() - 1) outFile << " ";
    }
    outFile << "\n";
    
    outFile << "expected_ciphertext=";
    for (size_t i = 0; i < ciphertext_bytes.size(); i++) {
        outFile << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << (int)ciphertext_bytes[i];
        if (i < ciphertext_bytes.size() - 1) outFile << " ";
    }
    outFile << std::dec << "\n";
    
    outFile << "expected_recovered=" << decrypted << "\n";
    outFile << "---\n";
}

int main() {
    std::ofstream outFile("test_vectors/test_vector.txt");
    
    if (!outFile.is_open()) {
        std::cerr << "ERROR: Cannot create output file!\n";
        return 1;
    }
    
    // Header
    outFile << "# Test vectors for RC4 implementation\n";
    outFile << "# Format: field=value, separated by --- for each test case\n";
    outFile << "# RC4 only uses key (no IV needed like Sosemanuk)\n";
    outFile << "# Generated automatically from RC4 implementation\n\n";
    
    std::cout << "Generating RC4 test vectors...\n\n";
    
    // Test case 1: Đề bài
    std::cout << "[1] Hanoi University of Science and Technology\n";
    generateTestVector(outFile, "Hanoi University of Science and Technology", "HUST2024");
    
    // Test case 2: Hello World
    std::cout << "[2] Hello World\n";
    generateTestVector(outFile, "Hello World", "Key");
    
    // Test case 3: Test RC4
    std::cout << "[3] Test RC4\n";
    generateTestVector(outFile, "Test RC4", "SecretKey");
    
    // Test case 4: Cryptography
    std::cout << "[4] Cryptography\n";
    generateTestVector(outFile, "Cryptography", "Pass123");
    
    // Test case 5: Short
    std::cout << "[5] Short\n";
    generateTestVector(outFile, "Short", "ABC");
    
    // Test case 6: Simple Test Message
    std::cout << "[6] Simple Test Message\n";
    generateTestVector(outFile, "Simple Test Message", "MyKey");
    
    // Test case 7: RC4 Stream Cipher
    std::cout << "[7] RC4 Stream Cipher\n";
    generateTestVector(outFile, "RC4 Stream Cipher", "TestKey2024");
    
    // Test case 8: Long message
    std::cout << "[8] Long message for testing RC4 encryption and decryption\n";
    generateTestVector(outFile, "Long message for testing RC4 encryption and decryption", "LongSecretKey123");
    
    // Test case 9: Alphabet
    std::cout << "[9] ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    generateTestVector(outFile, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "Alphabet");
    
    // Test case 10: Numbers
    std::cout << "[10] 12345\n";
    generateTestVector(outFile, "12345", "Num");
    
    outFile.close();
    
    std::cout << "\n✓ Test vectors generated successfully!\n";
    std::cout << "File: test_vectors/test_vector.txt\n";
    
    return 0;
}
