#include "include/rc4.h"
#include "include/test_vector_parser.h"
#include <iomanip>

/**
 * Test Runner - Chạy tất cả test cases từ file test_vectors.txt
 */

void printTestHeader(int testNum, const TestCase& test) {
    std::cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║  TEST CASE #" << std::setw(2) << testNum << std::setfill(' ') 
              << "                                                  ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n";
    std::cout << "Plaintext: " << test.plaintext << "\n";
    std::cout << "Key:       " << test.key << "\n";
}

void printTestResult(bool passed, const std::string& message = "") {
    if (passed) {
        std::cout << "✓ PASSED";
    } else {
        std::cout << "✗ FAILED";
    }
    if (!message.empty()) {
        std::cout << " - " << message;
    }
    std::cout << "\n";
}

bool runTestCase(int testNum, const TestCase& test, bool verbose = false) {
    printTestHeader(testNum, test);
    
    bool allPassed = true;
    
    // Bước 1: Mã hóa plaintext
    std::string ciphertext = RC4_encrypt(test.plaintext, test.key, false);
    std::vector<unsigned char> actual_ciphertext = stringToBytes(ciphertext);
    
    // Kiểm tra ciphertext
    std::cout << "\n[1] Ciphertext Check:\n";
    std::cout << "    Expected: ";
    printBytesHex(test.expected_ciphertext);
    std::cout << "\n    Actual:   ";
    printBytesHex(actual_ciphertext);
    std::cout << "\n    ";
    
    bool ciphertextMatch = compareBytes(actual_ciphertext, test.expected_ciphertext);
    printTestResult(ciphertextMatch, ciphertextMatch ? "Ciphertext matches" : "Ciphertext mismatch");
    allPassed &= ciphertextMatch;
    
    // Bước 2: Giải mã ciphertext
    std::string decrypted = RC4_decrypt(ciphertext, test.key, false);
    
    // Kiểm tra plaintext sau khi giải mã
    std::cout << "\n[2] Decryption Check:\n";
    std::cout << "    Expected: " << test.expected_recovered << "\n";
    std::cout << "    Actual:   " << decrypted << "\n";
    std::cout << "    ";
    
    bool decryptionMatch = (decrypted == test.expected_recovered);
    printTestResult(decryptionMatch, decryptionMatch ? "Decryption successful" : "Decryption failed");
    allPassed &= decryptionMatch;
    
    // Bước 3: Kiểm tra plaintext gốc
    std::cout << "\n[3] Original Plaintext Check:\n";
    std::cout << "    ";
    bool plaintextMatch = (decrypted == test.plaintext);
    printTestResult(plaintextMatch, plaintextMatch ? "Matches original" : "Does not match original");
    allPassed &= plaintextMatch;
    
    // Tổng kết test case
    std::cout << "\n" << std::string(68, '─') << "\n";
    std::cout << "Overall Result: ";
    if (allPassed) {
        std::cout << "✓ ALL CHECKS PASSED\n";
    } else {
        std::cout << "✗ SOME CHECKS FAILED\n";
    }
    std::cout << std::string(68, '─') << "\n";
    
    return allPassed;
}

int main(int argc, char* argv[]) {
    std::string testVectorFile = "test_vectors/test_vector.txt";
    
    // Cho phép truyền file path qua argument
    if (argc > 1) {
        testVectorFile = argv[1];
    }
    
    std::cout << "╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║           RC4 STREAM CIPHER - TEST VECTOR RUNNER              ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n";
    std::cout << "\nLoading test vectors from: " << testVectorFile << "\n";
    
    // Đọc test vectors từ file
    std::vector<TestCase> testCases = parseTestVectors(testVectorFile);
    
    if (testCases.empty()) {
        std::cerr << "\n✗ ERROR: No test cases found or file cannot be read!\n";
        return 1;
    }
    
    std::cout << "Found " << testCases.size() << " test case(s)\n";
    
    // Chạy tất cả test cases
    int passedCount = 0;
    int failedCount = 0;
    
    for (size_t i = 0; i < testCases.size(); i++) {
        bool passed = runTestCase(i + 1, testCases[i]);
        if (passed) {
            passedCount++;
        } else {
            failedCount++;
        }
    }
    
    // Tổng kết
    std::cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                      FINAL SUMMARY                             ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════╝\n";
    std::cout << "Total tests:  " << testCases.size() << "\n";
    std::cout << "Passed:       " << passedCount << " ✓\n";
    std::cout << "Failed:       " << failedCount << " ✗\n";
    std::cout << "Success rate: " << std::fixed << std::setprecision(1) 
              << (100.0 * passedCount / testCases.size()) << "%\n";
    std::cout << std::string(68, '═') << "\n";
    
    if (failedCount == 0) {
        std::cout << "\n🎉 ALL TEST CASES PASSED! 🎉\n\n";
        return 0;
    } else {
        std::cout << "\n⚠ SOME TEST CASES FAILED ⚠\n\n";
        return 1;
    }
}
