#ifndef TEST_VECTOR_PARSER_H
#define TEST_VECTOR_PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

struct TestCase {
    std::string plaintext;
    std::string key;
    std::vector<unsigned char> keystream;
    std::vector<unsigned char> expected_ciphertext;
    std::string expected_recovered;
};

// Convert hex string to bytes
std::vector<unsigned char> hexStringToBytes(const std::string& hex) {
    std::vector<unsigned char> bytes;
    std::istringstream iss(hex);
    std::string byteStr;
    
    while (iss >> byteStr) {
        unsigned int byte;
        std::istringstream(byteStr) >> std::hex >> byte;
        bytes.push_back(static_cast<unsigned char>(byte));
    }
    
    return bytes;
}

// Convert string to bytes
std::vector<unsigned char> stringToBytes(const std::string& str) {
    return std::vector<unsigned char>(str.begin(), str.end());
}

// Compare two byte vectors
bool compareBytes(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Print bytes in hex format
void printBytesHex(const std::vector<unsigned char>& bytes) {
    for (size_t i = 0; i < bytes.size(); i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)bytes[i] << " ";
    }
    std::cout << std::dec;
}

// Parse test vectors from file
std::vector<TestCase> parseTestVectors(const std::string& filename) {
    std::vector<TestCase> testCases;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return testCases;
    }
    
    TestCase currentTest;
    std::string line;
    bool hasData = false;
    
    while (std::getline(file, line)) {
        // Skip comments and empty lines
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // Check for separator
        if (line.find("---") != std::string::npos) {
            if (hasData) {
                testCases.push_back(currentTest);
                currentTest = TestCase();
                hasData = false;
            }
            continue;
        }
        
        // Parse field=value
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string field = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            
            if (field == "plaintext") {
                currentTest.plaintext = value;
                hasData = true;
            } else if (field == "key") {
                currentTest.key = value;
            } else if (field == "keystream") {
                currentTest.keystream = hexStringToBytes(value);
            } else if (field == "expected_ciphertext") {
                currentTest.expected_ciphertext = hexStringToBytes(value);
            } else if (field == "expected_recovered") {
                currentTest.expected_recovered = value;
            }
        }
    }
    
    // Add last test case if exists
    if (hasData) {
        testCases.push_back(currentTest);
    }
    
    file.close();
    return testCases;
}

#endif // TEST_VECTOR_PARSER_H
