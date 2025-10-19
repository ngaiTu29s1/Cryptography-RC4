#include "include/rc4.h"
#include "include/test_vector_parser.h"
#include <iostream>
#include <iomanip>

void runTestCase(int testNum, const TestCase& test) {
    std::cout << "\n================================================\n";
    std::cout << "TEST CASE #" << testNum << "\n";
    std::cout << "================================================\n";
    std::cout << "Plaintext: " << test.plaintext << "\n";
    std::cout << "Key:       " << test.key << "\n";
    std::cout << "Length:    " << test.plaintext.length() << " bytes\n";
    
    // Ma hoa
    std::string ciphertext = RC4_encrypt(test.plaintext, test.key, false);
    std::vector<unsigned char> actual_ciphertext = stringToBytes(ciphertext);
    
    // Kiem tra ciphertext
    std::cout << "\n[1] Ciphertext Check:\n";
    std::cout << "    Expected: ";
    printBytesHex(test.expected_ciphertext);
    std::cout << "\n    Actual:   ";
    printBytesHex(actual_ciphertext);
    
    bool ciphertextMatch = compareBytes(actual_ciphertext, test.expected_ciphertext);
    std::cout << "\n    Result:   " << (ciphertextMatch ? "[PASS]" : "[FAIL]") << "\n";
    
    // Giai ma
    std::string decrypted = RC4_decrypt(ciphertext, test.key, false);
    
    // Kiem tra decryption
    std::cout << "\n[2] Decryption Check:\n";
    std::cout << "    Expected: " << test.expected_recovered << "\n";
    std::cout << "    Actual:   " << decrypted << "\n";
    
    bool decryptionMatch = (decrypted == test.expected_recovered);
    std::cout << "    Result:   " << (decryptionMatch ? "[PASS]" : "[FAIL]") << "\n";
    
    // Kiem tra plaintext goc
    bool plaintextMatch = (decrypted == test.plaintext);
    std::cout << "\n[3] Original Match:  " << (plaintextMatch ? "[PASS]" : "[FAIL]") << "\n";
    
    // Tong ket
    if (ciphertextMatch && decryptionMatch && plaintextMatch) {
        std::cout << "\n>>> TEST CASE #" << testNum << ": PASSED <<<\n";
    } else {
        std::cout << "\n>>> TEST CASE #" << testNum << ": FAILED <<<\n";
    }
}

int main(int argc, char* argv[]) {
    std::string testVectorFile = "test_vectors/test_vector.txt";
    
    // Cho phep truyen file path qua argument
    if (argc > 1) {
        testVectorFile = argv[1];
    }
    
    std::cout << "================================================\n";
    std::cout << "   RC4 STREAM CIPHER - TEST RUNNER\n";
    std::cout << "================================================\n";
    std::cout << "Loading test vectors from: " << testVectorFile << "\n";
    
    // Doc test vectors tu file
    std::vector<TestCase> testCases = parseTestVectors(testVectorFile);
    
    if (testCases.empty()) {
        std::cerr << "\n[ERROR] No test cases found or file cannot be read!\n";
        return 1;
    }
    
    std::cout << "Found " << testCases.size() << " test case(s)\n";
    
    // Chay tat ca test cases
    int passedCount = 0;
    int failedCount = 0;
    
    for (size_t i = 0; i < testCases.size(); i++) {
        runTestCase(i + 1, testCases[i]);
        
        // Kiem tra ket qua
        std::string ciphertext = RC4_encrypt(testCases[i].plaintext, testCases[i].key, false);
        std::vector<unsigned char> actual = stringToBytes(ciphertext);
        std::string decrypted = RC4_decrypt(ciphertext, testCases[i].key, false);
        
        if (compareBytes(actual, testCases[i].expected_ciphertext) && 
            decrypted == testCases[i].expected_recovered &&
            decrypted == testCases[i].plaintext) {
            passedCount++;
        } else {
            failedCount++;
        }
    }
    
    // Tong ket
    std::cout << "\n================================================\n";
    std::cout << "   FINAL SUMMARY\n";
    std::cout << "================================================\n";
    std::cout << "Total tests:  " << testCases.size() << "\n";
    std::cout << "Passed:       " << passedCount << "\n";
    std::cout << "Failed:       " << failedCount << "\n";
    std::cout << "Success rate: " << std::fixed << std::setprecision(1) 
              << (100.0 * passedCount / testCases.size()) << "%\n";
    std::cout << "================================================\n";
    
    if (failedCount == 0) {
        std::cout << "\nALL TEST CASES PASSED!\n\n";
        return 0;
    } else {
        std::cout << "\nSOME TEST CASES FAILED!\n\n";
        return 1;
    }
}
