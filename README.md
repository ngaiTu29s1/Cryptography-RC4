# RC4 Stream Cipher Implementation# RC4 Stream Cipher Implementation



Trien khai thuat toan ma hoa dong RC4 bang C++.Du an nay la mot trien khai hoan chinh cua thuat toan ma hoa dong RC4 (Rivest Cipher 4) bang C++.



## Cau truc du an## Mo ta



```RC4 la mot thuat toan ma hoa dong (stream cipher) duoc thiet ke boi Ron Rivest vao nam 1987. Thuat toan nay su dung mot S-box 256 byte va hai con tro de sinh ra mot chuoi keystream gia ngau nhien, sau do XOR voi plaintext de tao ra ciphertext.

Cryptography-RC4/

├── include/### Dac diem cua RC4:

│   ├── rc4_utils.h          # Cac ham tien ich (swap, print, init S-box)- Thuat toan doi xung (symmetric cipher)

│   ├── ksa.h                # Key Scheduling Algorithm- Ma hoa va giai ma su dung cung mot qua trinh

│   ├── prga.h               # Pseudo-Random Generation Algorithm- Toc do nhanh va hieu qua

│   ├── rc4.h                # Ham encrypt/decrypt chinh- Do dai key linh hoat (thuong 40-2048 bits)

│   └── test_vector_parser.h # Doc file test vectors

├── src/## Cau truc du an

│   └── main.cpp             # Ham main - chi chua khai bao va goi ham

├── test_vectors/```

│   └── test_vector.txt      # File chua 10 test casesCryptography-RC4/

├── README.md├── include/

└── .gitignore│   ├── rc4_utils.h          # Các hàm tiện ích (swap, print, init S-box)

```│   ├── ksa.h                # Key Scheduling Algorithm

│   ├── prga.h               # Pseudo-Random Generation Algorithm

## Huong dan chay chuong trinh│   ├── rc4.h                # Hàm encrypt/decrypt chính

│   └── test_vector_parser.h # Parser cho file test vectors

### Bien dich:├── src/

│   ├── main.cpp                  # Demo chương trình chính

**Windows (PowerShell):**│   ├── test_runner.cpp           # Chạy test tự động từ file

```powershell│   ├── generate_test_vectors.cpp # Tool tạo test vectors

g++ -std=c++11 -I. src/main.cpp -o rc4.exe│   └── simple_test.cpp           # Test đơn giản

```├── test_vectors/

│   └── test_vector.txt      # File chứa 10 test cases

**Linux/MacOS:**├── README.md                # File này

```bash├── QUICKSTART.md            # Hướng dẫn nhanh

g++ -std=c++11 -I. src/main.cpp -o rc4└── .gitignore              # Git ignore file

``````



### Chay chuong trinh:## 🔧 Cách biên dịch và chạy



**Windows:**### Yêu cầu hệ thống:

```powershell- C++ compiler hỗ trợ C++11 trở lên (g++, clang++, MSVC)

.\rc4.exe- Windows/Linux/MacOS

```

### Biên dịch trên Windows (PowerShell):

**Linux/MacOS:**

```bash```powershell

./rc4# Demo chương trình chính (verbose mode)

```g++ -std=c++11 -I. src/main.cpp -o rc4.exe

./rc4.exe

### Chay voi file test vector khac:

# Chạy test runner với test vectors

```bashg++ -std=c++11 -I. src/test_runner.cpp -o test_runner.exe

.\rc4.exe test_vectors/custom_test.txt./test_runner.exe

```

# Test đơn giản (compact output)

## Bo test vectorg++ -std=c++11 -I. src/simple_test.cpp -o simple_test.exe

./simple_test.exe

### Format file test vector

# Generate test vectors mới

File `test_vectors/test_vector.txt` chua cac test cases voi format:g++ -std=c++11 -I. src/generate_test_vectors.cpp -o generate_test_vectors.exe

./generate_test_vectors.exe

``````

plaintext=<van ban goc>

key=<khoa>### Biên dịch trên Linux/MacOS:

keystream=<keystream dang hex, cach nhau boi space>

expected_ciphertext=<ciphertext mong doi dang hex>```bash

expected_recovered=<plaintext sau khi giai ma># Demo chương trình chính

---g++ -std=c++11 -I. src/main.cpp -o rc4

```./rc4



### Cac test case co san# Test runner

g++ -std=c++11 -I. src/test_runner.cpp -o test_runner

File `test_vectors/test_vector.txt` chua **10 test cases**:./test_runner



1. **Test case 1 - De bai yeu cau:**# Simple test

   - Plaintext: `Hanoi University of Science and Technology`g++ -std=c++11 -I. src/simple_test.cpp -o simple_test

   - Key: `HUST2024`./simple_test

   - Keystream: `17 1A B9 C3 02 6D A8 B4 58 8B 37 CC 9A A3 E0 A8 06 9F 01 F8 0B 08 29 99 BE D7 A2 34 9C C2 9B 0E 8D C5 B8 BD 43 14 B4 7A B7 67````

   - Ciphertext: `5F 7B D7 AC 6B 4D FD DA 31 FD 52 BE E9 CA 94 D1 26 F0 67 D8 58 6B 40 FC D0 B4 C7 14 FD AC FF 2E D9 A0 DB D5 2D 7B D8 15 D0 1E`

### Biên dịch với MSVC (Visual Studio):

2. **Test case 2:**

   - Plaintext: `Hello World````cmd

   - Key: `Key`cl /EHsc /I. src\main.cpp /Fe:rc4.exe

rc4.exe

3. **Test case 3:**```

   - Plaintext: `Test RC4`

   - Key: `SecretKey`## 🧪 Test Vectors



4. **Test case 4:**Dự án sử dụng file test vectors để kiểm tra tính đúng đắn của implementation.

   - Plaintext: `Cryptography`

   - Key: `Pass123`### Format file test vectors



5. **Test case 5:**File `test_vectors/test_vector.txt` chứa các test cases với format:

   - Plaintext: `Short`

   - Key: `ABC````

plaintext=<văn bản gốc>

6. **Test case 6:**key=<khóa>

   - Plaintext: `Simple Test Message`keystream=<keystream dạng hex>

   - Key: `MyKey`expected_ciphertext=<ciphertext mong đợi dạng hex>

expected_recovered=<plaintext sau khi giải mã>

7. **Test case 7:**---

   - Plaintext: `RC4 Stream Cipher````

   - Key: `TestKey2024`

### Chạy test tự động

8. **Test case 8:**

   - Plaintext: `Long message for testing RC4 encryption and decryption````bash

   - Key: `LongSecretKey123`# Biên dịch test runner

g++ -std=c++11 -I. src/test_runner.cpp -o test_runner

9. **Test case 9:**# hoặc trên Windows:

   - Plaintext: `ABCDEFGHIJKLMNOPQRSTUVWXYZ`g++ -std=c++11 -I. src/test_runner.cpp -o test_runner.exe

   - Key: `Alphabet`

# Chạy tất cả test cases

10. **Test case 10:**./test_runner        # Linux/MacOS

    - Plaintext: `12345`./test_runner.exe    # Windows

    - Key: `Num````



### Ket qua mong doiKết quả mong đợi:

```

Khi chay chuong trinh, ket qua se hien thi:Found 10 test case(s)

...

```Total tests:  10

================================================Passed:       10 ✓

   RC4 STREAM CIPHER - TEST RUNNERFailed:       0 ✗

================================================Success rate: 100.0%

Loading test vectors from: test_vectors/test_vector.txt

Found 10 test case(s)🎉 ALL TEST CASES PASSED! 🎉

```

================================================

TEST CASE #1### Tạo test vectors mới

================================================

Plaintext: Hanoi University of Science and TechnologyNếu bạn muốn tạo test vectors mới từ implementation:

Key:       HUST2024

Length:    42 bytes```bash

g++ -std=c++11 -I. src/generate_test_vectors.cpp -o generate_test_vectors

[1] Ciphertext Check:./generate_test_vectors

    Expected: 5f 7b d7 ac 6b 4d fd da 31 fd 52 be e9 ca 94 d1 26 f0 67 d8 58 6b 40 fc d0 b4 c7 14 fd ac ff 2e d9 a0 db d5 2d 7b d8 15 d0 1e```

    Actual:   5f 7b d7 ac 6b 4d fd da 31 fd 52 be e9 ca 94 d1 26 f0 67 d8 58 6b 40 fc d0 b4 c7 14 fd ac ff 2e d9 a0 db d5 2d 7b d8 15 d0 1e

    Result:   [PASS]Tool này sẽ:

1. Chạy RC4 với các plaintext và key khác nhau

[2] Decryption Check:2. Sinh keystream và ciphertext

    Expected: Hanoi University of Science and Technology3. Lưu vào file `test_vectors/test_vector.txt`

    Actual:   Hanoi University of Science and Technology

    Result:   [PASS]## 📊 Ví dụ Test Vector



[3] Original Match:  [PASS]### Test Case #1 - Đề bài yêu cầu:

- **Plaintext**: `Hanoi University of Science and Technology`

>>> TEST CASE #1: PASSED <<<- **Key**: `HUST2024`

- **Keystream** (hex): `17 1A B9 C3 02 6D A8 B4 58 8B 37 CC 9A A3 E0 A8 06 9F 01 F8 0B 08 29 99 BE D7 A2 34 9C C2 9B 0E 8D C5 B8 BD 43 14 B4 7A B7 67`

... (9 test cases con lai)- **Ciphertext** (hex): `5F 7B D7 AC 6B 4D FD DA 31 FD 52 BE E9 CA 94 D1 26 F0 67 D8 58 6B 40 FC D0 B4 C7 14 FD AC FF 2E D9 A0 DB D5 2D 7B D8 15 D0 1E`



================================================### Các bước thuật toán:

   FINAL SUMMARY

================================================#### 1. KSA (Key Scheduling Algorithm)

Total tests:  10

Passed:       10**S-box ban đầu** (identity permutation):

Failed:       0```

Success rate: 100.0%00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f

================================================10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f

... (tiếp tục đến ff)

ALL TEST CASES PASSED!```

```

**Sau KSA** với key "HUST2024", S-box được hoán vị dựa trên công thức:

## Giai thich thuat toan RC4```

j = (j + S[i] + key[i % keylen]) % 256

### 1. KSA - Key Scheduling Algorithmswap(S[i], S[j])

```

**Muc dich:** Khoi tao S-box dua tren key

S-box sau KSA sẽ là một hoán vị ngẫu nhiên của 256 byte.

**Cac buoc:**

```#### 2. PRGA (Pseudo-Random Generation Algorithm)

1. Khoi tao S-box voi cac gia tri 0-255

   S[i] = i (voi i tu 0 den 255)Thuật toán sinh keystream:

```

2. Hoan vi S-box dua tren key:i = (i + 1) % 256

   j = 0j = (j + S[i]) % 256

   for i = 0 to 255:swap(S[i], S[j])

       j = (j + S[i] + key[i mod keylength]) mod 256t = (S[i] + S[j]) % 256

       swap(S[i], S[j])K = S[t]  // keystream byte

``````



**File:** `include/ksa.h`**Keystream** (43 bytes đầu tiên được sinh ra từ PRGA):

```

### 2. PRGA - Pseudo-Random Generation AlgorithmSẽ được hiển thị khi chạy chương trình với verbose mode

```

**Muc dich:** Sinh keystream tu S-box

#### 3. Encryption/Decryption

**Cac buoc:**

```**Mã hóa**:

i = 0```

j = 0Ciphertext[i] = Plaintext[i] XOR Keystream[i]

for each byte can ma hoa:```

    i = (i + 1) mod 256

    j = (j + S[i]) mod 256**Giải mã** (quá trình giống hệt mã hóa):

    swap(S[i], S[j])```

    t = (S[i] + S[j]) mod 256Plaintext[i] = Ciphertext[i] XOR Keystream[i]

    keystream_byte = S[t]```

```

### Kết quả mẫu:

**File:** `include/prga.h`

Khi chạy chương trình, bạn sẽ thấy output tương tự:

### 3. Encryption (Ma hoa)

```

**Qua trinh:**=============================================

```RC4 STREAM CIPHER IMPLEMENTATION

1. Chay KSA de khoi tao S-box tu key=============================================

2. Chay PRGA de sinh keystream

3. Ciphertext[i] = Plaintext[i] XOR Keystream[i]========================================

```RC4 ENCRYPTION

========================================

**File:** `include/rc4.h` - ham `RC4_encrypt()`Plaintext: Hanoi University of Science and Technology

Plaintext length: 43 bytes

### 4. Decryption (Giai ma)

=== KSA - Key Scheduling Algorithm ===

**Qua trinh:** (Giong het ma hoa vi RC4 la thuat toan doi xung)Key: HUST2024

```Key length: 8 bytes

1. Chay KSA de khoi tao S-box tu key (phai giong key ma hoa)

2. Chay PRGA de sinh keystream (giong voi luc ma hoa)[S-box details...]

3. Plaintext[i] = Ciphertext[i] XOR Keystream[i]

```=== PRGA - Pseudo-Random Generation Algorithm ===

Generating keystream of length: 43 bytes

**File:** `include/rc4.h` - ham `RC4_decrypt()`

[Keystream details...]

## Cac file header (thu vien)

=== XOR Operation ===

### 1. rc4_utils.h[XOR operation details...]

Cac ham tien ich:

- `initializeSBox()`: Khoi tao S-box voi gia tri 0-255Ciphertext (hex): [hex values...]

- `swap()`: Hoan doi 2 phan tu========================================

- `printSBox()`: In S-box dang hex

- `printHex()`: In du lieu dang hex[Decryption process...]

- `printKeystream()`: In keystream

- `copySBox()`: Sao chep S-box=============================================

VERIFICATION

### 2. ksa.h=============================================

Thuat toan KSA:Original plaintext:  Hanoi University of Science and Technology

- `KSA()`: Khoi tao S-box dua tren keyDecrypted plaintext: Hanoi University of Science and Technology

- `KSA_verbose()`: KSA voi che do hien thi chi tiet

✓ SUCCESS: Decryption matches original plaintext!

### 3. prga.h=============================================

Thuat toan PRGA:```

- `PRGA()`: Sinh keystream tu S-box

- `PRGA_verbose()`: PRGA voi che do hien thi chi tiet## 🧪 Test Cases bổ sung



### 4. rc4.hBạn có thể test với các input khác bằng cách sửa file `main.cpp`:

Ham ma hoa/giai ma chinh:

- `RC4_encrypt()`: Ma hoa plaintext### Test 1: Key ngắn

- `RC4_decrypt()`: Giai ma ciphertext```cpp

std::string plaintext = "Hello World";

### 5. test_vector_parser.hstd::string key = "Key";

Doc va parse file test vector:```

- `parseTestVectors()`: Doc test cases tu file

- `hexStringToBytes()`: Chuyen hex string thanh bytes### Test 2: Key dài

- `compareBytes()`: So sanh 2 mang bytes```cpp

- `printBytesHex()`: In bytes dang hexstd::string plaintext = "Secret Message";

std::string key = "ThisIsAVeryLongSecretKey123456";

## Ham main```



File `src/main.cpp` **chi chua khai bao va goi ham** tu cac header:### Test 3: Ký tự đặc biệt

```cpp

```cppstd::string plaintext = "Hello @#$% World!";

#include "include/rc4.h"std::string key = "MyKey";

#include "include/test_vector_parser.h"```



int main(int argc, char* argv[]) {## 📚 Giải thích thuật toán

    // Khai bao

    std::string testVectorFile = "test_vectors/test_vector.txt";### KSA (Key Scheduling Algorithm)

    - **Mục đích**: Khởi tạo S-box dựa trên key

    // Goi ham doc test vectors- **Input**: Key có độ dài bất kỳ

    std::vector<TestCase> testCases = parseTestVectors(testVectorFile);- **Output**: S-box đã được hoán vị (permutation của 0-255)

    - **Độ phức tạp**: O(256)

    // Goi ham chay tung test case

    for (size_t i = 0; i < testCases.size(); i++) {### PRGA (Pseudo-Random Generation Algorithm)

        runTestCase(i + 1, testCases[i]);- **Mục đích**: Sinh keystream từ S-box

    }- **Input**: S-box đã khởi tạo, độ dài cần sinh

    - **Output**: Keystream có độ dài bằng plaintext

    return 0;- **Độ phức tạp**: O(n) với n là độ dài plaintext

}

```### Encryption/Decryption

- **Mục đích**: Mã hóa/giải mã dữ liệu

## Repository- **Phương pháp**: XOR plaintext với keystream

- **Đặc điểm**: Mã hóa và giải mã dùng cùng một hàm

**GitHub Repository:** https://github.com/ngaiTu29s1/Cryptography-RC4

## ⚠️ Lưu ý bảo mật

**Clone repository:**

```bashRC4 hiện nay **KHÔNG được khuyến khích sử dụng** trong các ứng dụng thực tế do các lý do:

git clone https://github.com/ngaiTu29s1/Cryptography-RC4.git- Có nhiều điểm yếu về mặt mật mã học

cd Cryptography-RC4- Keystream có thể bị dự đoán trong một số trường hợp

```- Đã bị thay thế bởi các thuật toán an toàn hơn (AES, ChaCha20)



## Yeu cau he thongDự án này chỉ dành cho **mục đích học tập và nghiên cứu**.



- C++ compiler ho tro C++11 tro len## 👨‍💻 Tác giả

- Windows: g++ (MinGW) hoac MSVC

- Linux/MacOS: g++ hoac clang++- Dự án được tạo cho môn học Mật mã học

- Ngôn ngữ: C++11

## Luu y- Năm: 2024



RC4 chi dung cho **muc dich hoc tap**. Khong su dung trong production vi:## 📄 License

- Co nhieu diem yeu ve mat ma hoc

- Da bi deprecated trong nhieu tieu chuanDự án này được tạo cho mục đích học tập và nghiên cứu.

- Duoc thay the boi cac thuat toan an toan hon (AES, ChaCha20)

## 🔗 Tài liệu tham khảo

## Tac gia

- [RC4 on Wikipedia](https://en.wikipedia.org/wiki/RC4)

- Du an duoc tao cho mon hoc Mat ma hoc- [RFC 4345 - Improved Arcfour Modes for the SSH Transport Layer Protocol](https://tools.ietf.org/html/rfc4345)

- Ngon ngu: C++11- Applied Cryptography by Bruce Schneier
- Nam: 2024
