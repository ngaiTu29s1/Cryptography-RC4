# Tóm tắt Dự án RC4 Stream Cipher

## ✅ Đã hoàn thành

### 1. Cấu trúc Code Modular
- ✅ `include/rc4_utils.h` - Các hàm tiện ích
- ✅ `include/ksa.h` - Key Scheduling Algorithm  
- ✅ `include/prga.h` - Pseudo-Random Generation Algorithm
- ✅ `include/rc4.h` - Hàm encrypt/decrypt chính

### 2. File chương trình
- ✅ `src/main.cpp` - Demo chi tiết với verbose mode
- ✅ `src/simple_test.cpp` - Test cases đơn giản

### 3. Documentation
- ✅ `README.md` - Hướng dẫn đầy đủ với test vectors
- ✅ `QUICKSTART.md` - Hướng dẫn nhanh
- ✅ `.gitignore` - Git ignore cho C++ project

### 4. Test Case
- ✅ Plaintext: "Hanoi University of Science and Technology"
- ✅ Key: "HUST2024"
- ✅ Mã hóa thành công
- ✅ Giải mã khớp với plaintext gốc

## 📊 Test Vectors (từ chương trình)

### Input:
```
Plaintext: Hanoi University of Science and Technology
Key: HUST2024
Length: 42 bytes
```

### Output:
```
Ciphertext (hex): 
5f 7b d7 ac 6b 4d fd da 31 fd 52 be e9 ca 94 d1 
26 f0 67 d8 58 6b 40 fc d0 b4 c7 14 fd ac ff 2e 
d9 a0 db d5 2d 7b d8 15 d0 1e
```

### Keystream (first 42 bytes):
```
17 1a b9 c3 02 6d a8 b4 58 8b 37 cc 9a a3 e0 a8
06 9f 01 f8 0b 08 29 99 be d7 a2 34 9c c2 9b 0e
8d c5 b8 bd 43 14 b4 7a b7 67
```

### S-box sau KSA (một phần):
```
48 a3 f3 4a 9a b5 19 77 78 d6 a2 3f d0 75 ec 90
4c 4f b3 53 66 ca 88 6b 6d 1f 6c a6 b1 69 84 a0
...
```

## 🔗 Repository Information

- **Repository URL**: https://github.com/ngaiTu29s1/Cryptography-RC4
- **Branch**: main
- **Owner**: ngaiTu29s1

## 📝 Commits

1. **feat**: Implement RC4 stream cipher with modular architecture
   - Tạo cấu trúc modular với các header riêng biệt
   - Implement KSA, PRGA, và các hàm tiện ích
   - Thêm verbose mode để hiển thị chi tiết
   
2. **docs**: Add quick start guide and simple test examples
   - Thêm QUICKSTART.md
   - Thêm simple_test.cpp với nhiều test cases

## 🚀 Cách sử dụng

### 1. Clone repository:
```bash
git clone https://github.com/ngaiTu29s1/Cryptography-RC4.git
cd Cryptography-RC4
```

### 2. Biên dịch và chạy:
```bash
# Demo đầy đủ với verbose
g++ -std=c++11 -I. src/main.cpp -o rc4.exe
./rc4.exe

# Test đơn giản
g++ -std=c++11 -I. src/simple_test.cpp -o simple_test.exe
./simple_test.exe
```

## 📚 Kiến thức đã áp dụng

1. **RC4 Algorithm**:
   - KSA (Key Scheduling Algorithm)
   - PRGA (Pseudo-Random Generation Algorithm)
   - Stream cipher encryption/decryption

2. **C++ Programming**:
   - Header files và modularity
   - Template và inline functions
   - STL (vector, string)
   - Namespace management

3. **Software Engineering**:
   - Modular design
   - Separation of concerns
   - Documentation
   - Version control (Git)

## ⚠️ Lưu ý

RC4 chỉ dùng cho **mục đích học tập**. Không sử dụng trong production vì:
- Có nhiều lỗ hổng bảo mật đã được phát hiện
- Đã bị deprecated trong nhiều tiêu chuẩn
- Được thay thế bởi các thuật toán an toàn hơn (AES, ChaCha20)

## 📧 Liên hệ

- Repository: https://github.com/ngaiTu29s1/Cryptography-RC4
- Issues: https://github.com/ngaiTu29s1/Cryptography-RC4/issues
