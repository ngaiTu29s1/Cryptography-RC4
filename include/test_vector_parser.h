#ifndef TEST_VECTOR_PARSER_H
#define TEST_VECTOR_PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * Cấu trúc lưu trữ một test case
 */
struct TestCase {
    std::string plaintext;
    std::string key;
    std::vector<unsigned char> keystream;
    std::vector<unsigned char> expected_ciphertext;
    std::string expected_recovered;
};

/**
 * Hàm chuyển đổi chuỗi hex thành vector bytes
 * Ví dụ: "48 65 6C 6C 6F" -> {0x48, 0x65, 0x6C, 0x6C, 0x6F}
 */
std::vector<unsigned char> hexStringToBytes(const std::string& hex) {
    std::vector<unsigned char> bytes;
    std::istringstream iss(hex);
    std::string byte_str;
    
    while (iss >> byte_str) {
        if (byte_str.length() == 2) {
            unsigned int byte_val;
            std::stringstream ss;
            ss << std::hex << byte_str;
            ss >> byte_val;
            bytes.push_back(static_cast<unsigned char>(byte_val));
        }
    }
    
    return bytes;
}

/**
 * Hàm trim khoảng trắng ở đầu và cuối string
 */
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

/**
 * Hàm đọc và parse file test vectors
 * @param filename: Đường dẫn tới file test vector
 * @return Vector chứa các test cases
 */
std::vector<TestCase> parseTestVectors(const std::string& filename) {
    std::vector<TestCase> testCases;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "ERROR: Cannot open file: " << filename << std::endl;
        return testCases;
    }
    
    TestCase currentTest;
    std::string line;
    bool hasData = false;
    
    while (std::getline(file, line)) {
        line = trim(line);
        
        // Bỏ qua dòng trống và comment
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // Phân cách giữa các test cases
        if (line == "---") {
            if (hasData) {
                testCases.push_back(currentTest);
                currentTest = TestCase(); // Reset
                hasData = false;
            }
            continue;
        }
        
        // Parse dòng có format "field=value"
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string field = trim(line.substr(0, pos));
            std::string value = trim(line.substr(pos + 1));
            
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
    
    // Thêm test case cuối cùng nếu có
    if (hasData) {
        testCases.push_back(currentTest);
    }
    
    file.close();
    return testCases;
}

/**
 * Hàm so sánh 2 vector bytes
 */
bool compareBytes(const std::vector<unsigned char>& a, const std::vector<unsigned char>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

/**
 * Hàm chuyển vector bytes thành string
 */
std::string bytesToString(const std::vector<unsigned char>& bytes) {
    return std::string(bytes.begin(), bytes.end());
}

/**
 * Hàm chuyển string thành vector bytes
 */
std::vector<unsigned char> stringToBytes(const std::string& str) {
    return std::vector<unsigned char>(str.begin(), str.end());
}

/**
 * Hàm in vector bytes dưới dạng hex
 */
void printBytesHex(const std::vector<unsigned char>& bytes) {
    for (size_t i = 0; i < bytes.size(); i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << (int)bytes[i];
        if (i < bytes.size() - 1) std::cout << " ";
    }
    std::cout << std::dec;
}

#endif // TEST_VECTOR_PARSER_H
