# Quick Start Guide

## Biên dịch nhanh

### Windows (PowerShell/CMD):
```powershell
g++ -std=c++11 -I. src/main.cpp -o rc4.exe
./rc4.exe
```

### Linux/MacOS:
```bash
g++ -std=c++11 -I. src/main.cpp -o rc4
./rc4
```

## Cấu trúc Code

```
include/
├── rc4_utils.h  ← Hàm tiện ích (swap, print, init)
├── ksa.h        ← Key Scheduling Algorithm
├── prga.h       ← Pseudo-Random Generation Algorithm
└── rc4.h        ← Encrypt/Decrypt chính

src/
└── main.cpp     ← Demo program
```

## Sử dụng trong code của bạn

```cpp
#include "include/rc4.h"

int main() {
    std::string plaintext = "Your secret message";
    std::string key = "YourKey";
    
    // Mã hóa
    std::string ciphertext = RC4_encrypt(plaintext, key, false);
    
    // Giải mã
    std::string decrypted = RC4_decrypt(ciphertext, key, false);
    
    return 0;
}
```

## Test Vector

**Input:**
- Plaintext: "Hanoi University of Science and Technology"
- Key: "HUST2024"

**Output khi chạy:**
- S-box sau KSA (xem khi verbose=true)
- Keystream được sinh ra
- Ciphertext (hex format)
- Decrypted plaintext (verify)

## Lưu ý

- RC4 chỉ dùng cho học tập, KHÔNG sử dụng trong production
- Key và plaintext có thể là string bất kỳ
- Độ dài ciphertext = độ dài plaintext
