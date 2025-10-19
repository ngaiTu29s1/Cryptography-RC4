# RC4 Stream Cipher

Đồ án môn Mật mã học - Implementation thuật toán RC4 bằng C++

## Giới thiệu

RC4 là thuật toán mã hóa dòng (stream cipher), nhanh và đơn giản nhưng đã deprecated vì lỗ hổng bảo mật. Project này chỉ để học thôi nhé!

## Kiến trúc project

```
Cryptography-RC4/
├── include/
│   ├── rc4_utils.h          # Hàm tiện ích: swap, print, init S-box
│   ├── ksa.h                # Key Scheduling Algorithm
│   ├── prga.h               # Pseudo-Random Generation Algorithm
│   ├── rc4.h                # Encrypt/Decrypt
│   └── test_vector_parser.h # Parser file test
├── src/
│   └── main.cpp             # Main - chỉ gọi hàm
├── test_vectors/
│   └── test_vector.txt      # 10 test cases
└── README.md
```

**Các header:**
- `rc4_utils.h` - Swap, print, khởi tạo S-box
- `ksa.h` - Trộn S-box dựa trên key
- `prga.h` - Sinh keystream từ S-box
- `rc4.h` - Mã hóa/giải mã (XOR plaintext với keystream)
- `test_vector_parser.h` - Đọc và parse file test

## Cách chạy

### 1. Clone về

```bash
git clone https://github.com/ngaiTu29s1/Cryptography-RC4.git
cd Cryptography-RC4
```

### 2. Compile

```bash
# Windows
g++ -std=c++11 -I. src/main.cpp -o rc4.exe

# Linux/Mac
g++ -std=c++11 -I. src/main.cpp -o rc4
```

### 3. Chạy

```bash
# Windows
.\rc4.exe

# Linux/Mac
./rc4
```

Kết quả:
```
Found 10 test case(s)
...
Total tests: 10, Passed: 10, Failed: 0
ALL TEST CASES PASSED!
```

## Thay đổi input

### Cách 1: Sửa file test_vectors/test_vector.txt

Thêm test case mới:

```
plaintext=Your message here
key=YourKey123
keystream=<hex values>
expected_ciphertext=<hex values>
expected_recovered=Your message here
---
```

### Cách 2: Dùng file test khác

```bash
.\rc4.exe test_vectors/my_test.txt
```

### Cách 3: Sửa code trong main.cpp

```cpp
// Thay vì đọc từ file, test trực tiếp:
std::string plaintext = "Hello World";
std::string key = "SecretKey";

std::vector<unsigned char> ciphertext;
std::vector<unsigned char> keystream;
RC4_encrypt(plaintext, key, ciphertext, keystream);
```

## Test case đề bài

Test #1 trong file `test_vectors/test_vector.txt`:

- **Plaintext:** Hanoi University of Science and Technology
- **Key:** HUST2024
- **Ciphertext (hex):** 5F 7B D7 AC 6B 4D FD DA 31 FD 52 BE E9 CA 94 D1 26 F0 67 D8 58 6B 40 FC D0 B4 C7 14 FD AC FF 2E D9 A0 DB D5 2D 7B D8 15 D0 1E

## Yêu cầu

- C++ compiler hỗ trợ C++11 (g++, clang++, MSVC)

## Lưu ý

⚠️ RC4 đã deprecated - chỉ dùng để học!

---

**GitHub:** https://github.com/ngaiTu29s1/Cryptography-RC4
