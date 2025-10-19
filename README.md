# RC4 Stream Cipher Implementation

Dự án này là một triển khai hoàn chỉnh của thuật toán mã hóa dòng RC4 (Rivest Cipher 4) bằng C++.

## 📋 Mô tả

RC4 là một thuật toán mã hóa dòng (stream cipher) được thiết kế bởi Ron Rivest vào năm 1987. Thuật toán này sử dụng một S-box 256 byte và hai con trỏ để sinh ra một chuỗi keystream giả ngẫu nhiên, sau đó XOR với plaintext để tạo ra ciphertext.

### Đặc điểm của RC4:
- Thuật toán đối xứng (symmetric cipher)
- Mã hóa và giải mã sử dụng cùng một quá trình
- Tốc độ nhanh và hiệu quả
- Độ dài key linh hoạt (thường 40-2048 bits)

## 🏗️ Cấu trúc dự án

```
Cryptography-RC4/
├── include/
│   ├── rc4_utils.h          # Các hàm tiện ích (swap, print, init S-box)
│   ├── ksa.h                # Key Scheduling Algorithm
│   ├── prga.h               # Pseudo-Random Generation Algorithm
│   ├── rc4.h                # Hàm encrypt/decrypt chính
│   └── test_vector_parser.h # Parser cho file test vectors
├── src/
│   ├── main.cpp                  # Demo chương trình chính
│   ├── test_runner.cpp           # Chạy test tự động từ file
│   ├── generate_test_vectors.cpp # Tool tạo test vectors
│   └── simple_test.cpp           # Test đơn giản
├── test_vectors/
│   └── test_vector.txt      # File chứa 10 test cases
├── README.md                # File này
├── QUICKSTART.md            # Hướng dẫn nhanh
└── .gitignore              # Git ignore file
```

## 🔧 Cách biên dịch và chạy

### Yêu cầu hệ thống:
- C++ compiler hỗ trợ C++11 trở lên (g++, clang++, MSVC)
- Windows/Linux/MacOS

### Biên dịch trên Windows (PowerShell):

```powershell
# Demo chương trình chính (verbose mode)
g++ -std=c++11 -I. src/main.cpp -o rc4.exe
./rc4.exe

# Chạy test runner với test vectors
g++ -std=c++11 -I. src/test_runner.cpp -o test_runner.exe
./test_runner.exe

# Test đơn giản (compact output)
g++ -std=c++11 -I. src/simple_test.cpp -o simple_test.exe
./simple_test.exe

# Generate test vectors mới
g++ -std=c++11 -I. src/generate_test_vectors.cpp -o generate_test_vectors.exe
./generate_test_vectors.exe
```

### Biên dịch trên Linux/MacOS:

```bash
# Demo chương trình chính
g++ -std=c++11 -I. src/main.cpp -o rc4
./rc4

# Test runner
g++ -std=c++11 -I. src/test_runner.cpp -o test_runner
./test_runner

# Simple test
g++ -std=c++11 -I. src/simple_test.cpp -o simple_test
./simple_test
```

### Biên dịch với MSVC (Visual Studio):

```cmd
cl /EHsc /I. src\main.cpp /Fe:rc4.exe
rc4.exe
```

## 🧪 Test Vectors

Dự án sử dụng file test vectors để kiểm tra tính đúng đắn của implementation.

### Format file test vectors

File `test_vectors/test_vector.txt` chứa các test cases với format:

```
plaintext=<văn bản gốc>
key=<khóa>
keystream=<keystream dạng hex>
expected_ciphertext=<ciphertext mong đợi dạng hex>
expected_recovered=<plaintext sau khi giải mã>
---
```

### Chạy test tự động

```bash
# Biên dịch test runner
g++ -std=c++11 -I. src/test_runner.cpp -o test_runner
# hoặc trên Windows:
g++ -std=c++11 -I. src/test_runner.cpp -o test_runner.exe

# Chạy tất cả test cases
./test_runner        # Linux/MacOS
./test_runner.exe    # Windows
```

Kết quả mong đợi:
```
Found 10 test case(s)
...
Total tests:  10
Passed:       10 ✓
Failed:       0 ✗
Success rate: 100.0%

🎉 ALL TEST CASES PASSED! 🎉
```

### Tạo test vectors mới

Nếu bạn muốn tạo test vectors mới từ implementation:

```bash
g++ -std=c++11 -I. src/generate_test_vectors.cpp -o generate_test_vectors
./generate_test_vectors
```

Tool này sẽ:
1. Chạy RC4 với các plaintext và key khác nhau
2. Sinh keystream và ciphertext
3. Lưu vào file `test_vectors/test_vector.txt`

## 📊 Ví dụ Test Vector

### Test Case #1 - Đề bài yêu cầu:
- **Plaintext**: `Hanoi University of Science and Technology`
- **Key**: `HUST2024`
- **Keystream** (hex): `17 1A B9 C3 02 6D A8 B4 58 8B 37 CC 9A A3 E0 A8 06 9F 01 F8 0B 08 29 99 BE D7 A2 34 9C C2 9B 0E 8D C5 B8 BD 43 14 B4 7A B7 67`
- **Ciphertext** (hex): `5F 7B D7 AC 6B 4D FD DA 31 FD 52 BE E9 CA 94 D1 26 F0 67 D8 58 6B 40 FC D0 B4 C7 14 FD AC FF 2E D9 A0 DB D5 2D 7B D8 15 D0 1E`

### Các bước thuật toán:

#### 1. KSA (Key Scheduling Algorithm)

**S-box ban đầu** (identity permutation):
```
00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f
... (tiếp tục đến ff)
```

**Sau KSA** với key "HUST2024", S-box được hoán vị dựa trên công thức:
```
j = (j + S[i] + key[i % keylen]) % 256
swap(S[i], S[j])
```

S-box sau KSA sẽ là một hoán vị ngẫu nhiên của 256 byte.

#### 2. PRGA (Pseudo-Random Generation Algorithm)

Thuật toán sinh keystream:
```
i = (i + 1) % 256
j = (j + S[i]) % 256
swap(S[i], S[j])
t = (S[i] + S[j]) % 256
K = S[t]  // keystream byte
```

**Keystream** (43 bytes đầu tiên được sinh ra từ PRGA):
```
Sẽ được hiển thị khi chạy chương trình với verbose mode
```

#### 3. Encryption/Decryption

**Mã hóa**:
```
Ciphertext[i] = Plaintext[i] XOR Keystream[i]
```

**Giải mã** (quá trình giống hệt mã hóa):
```
Plaintext[i] = Ciphertext[i] XOR Keystream[i]
```

### Kết quả mẫu:

Khi chạy chương trình, bạn sẽ thấy output tương tự:

```
=============================================
RC4 STREAM CIPHER IMPLEMENTATION
=============================================

========================================
RC4 ENCRYPTION
========================================
Plaintext: Hanoi University of Science and Technology
Plaintext length: 43 bytes

=== KSA - Key Scheduling Algorithm ===
Key: HUST2024
Key length: 8 bytes

[S-box details...]

=== PRGA - Pseudo-Random Generation Algorithm ===
Generating keystream of length: 43 bytes

[Keystream details...]

=== XOR Operation ===
[XOR operation details...]

Ciphertext (hex): [hex values...]
========================================

[Decryption process...]

=============================================
VERIFICATION
=============================================
Original plaintext:  Hanoi University of Science and Technology
Decrypted plaintext: Hanoi University of Science and Technology

✓ SUCCESS: Decryption matches original plaintext!
=============================================
```

## 🧪 Test Cases bổ sung

Bạn có thể test với các input khác bằng cách sửa file `main.cpp`:

### Test 1: Key ngắn
```cpp
std::string plaintext = "Hello World";
std::string key = "Key";
```

### Test 2: Key dài
```cpp
std::string plaintext = "Secret Message";
std::string key = "ThisIsAVeryLongSecretKey123456";
```

### Test 3: Ký tự đặc biệt
```cpp
std::string plaintext = "Hello @#$% World!";
std::string key = "MyKey";
```

## 📚 Giải thích thuật toán

### KSA (Key Scheduling Algorithm)
- **Mục đích**: Khởi tạo S-box dựa trên key
- **Input**: Key có độ dài bất kỳ
- **Output**: S-box đã được hoán vị (permutation của 0-255)
- **Độ phức tạp**: O(256)

### PRGA (Pseudo-Random Generation Algorithm)
- **Mục đích**: Sinh keystream từ S-box
- **Input**: S-box đã khởi tạo, độ dài cần sinh
- **Output**: Keystream có độ dài bằng plaintext
- **Độ phức tạp**: O(n) với n là độ dài plaintext

### Encryption/Decryption
- **Mục đích**: Mã hóa/giải mã dữ liệu
- **Phương pháp**: XOR plaintext với keystream
- **Đặc điểm**: Mã hóa và giải mã dùng cùng một hàm

## ⚠️ Lưu ý bảo mật

RC4 hiện nay **KHÔNG được khuyến khích sử dụng** trong các ứng dụng thực tế do các lý do:
- Có nhiều điểm yếu về mặt mật mã học
- Keystream có thể bị dự đoán trong một số trường hợp
- Đã bị thay thế bởi các thuật toán an toàn hơn (AES, ChaCha20)

Dự án này chỉ dành cho **mục đích học tập và nghiên cứu**.

## 👨‍💻 Tác giả

- Dự án được tạo cho môn học Mật mã học
- Ngôn ngữ: C++11
- Năm: 2024

## 📄 License

Dự án này được tạo cho mục đích học tập và nghiên cứu.

## 🔗 Tài liệu tham khảo

- [RC4 on Wikipedia](https://en.wikipedia.org/wiki/RC4)
- [RFC 4345 - Improved Arcfour Modes for the SSH Transport Layer Protocol](https://tools.ietf.org/html/rfc4345)
- Applied Cryptography by Bruce Schneier