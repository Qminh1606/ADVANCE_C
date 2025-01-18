/*BÀI 3: BITMASK
int: 4bytes =  32 bit
int8_t, uint8_t:1 bytes = 8 bit
int16_t, uint16_t: 2bytes = 16 bit
Để sử dụng int8_t ..v.v... sử dụng thư viên
#include <stdint.h>

Ví dụ:
*USER
    gender: Nam = 0/ Nữ = 1
    status: 0/1
    xemay: 0/1
    oto: 0/1
    maybay:0/1

Ta có thể khai báo
    int gender;
    int status;
    int xemay;
    int oto;
    int maybay;

-> Nó sẽ tốn bộ nhớ hết 20 bytes
-> Ta có thể giảm tốn bộ nhớ từ 20 bytes -> 5 bytes
    int8_t gender;
    int8_t status;
    int8_t xemay;
    int8_t oto;
    int8_t maybay;

Như vậy bộ nhớ sẽ tốn 5 bytes
Nhưng như vậy cũng chưa tối ưu

int8_t user; //0b xxxxxxxx
//bit 0: gender
//bit 1: status
//bit 2: xemay
//bit 3: oto
//bit 4: maybay
Như vây, bộ nhớ chỉ tốn 1 bytes = 8 bit và sẽ thao tác từng bit
20bytes -> 5bytes -> 1 bytes

1. BITMASK là gì?
    -BITMASK là kĩ thuật thao tác trên từng bit
    -Có thể sử dụng BITMASK để đặt, xóa và kiểm tra trạng thái của các bit
    -BITMASK thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên 1 cụm bit và quản lý các trạng thái, quyền truy cập hoặc các thuộc tính khác của 1 đối tượng

2. Các toán tử bitwise
2.1 NOT bitwise
- NOT bitwise là phép đảo bit
- Dùng để thực hiện phép NOT bitwise trên từng bit của 1 số. Kết quả là bit đảo ngược của số đó
bit 0: 1 ~ 0 // bit 0 = 1 NOT bitwise (~) thì 1 đảo thành 0
       0 ~ 1 // bit 0 = 0 NOT bitwise (~) thì 0 đảo thành 1
int  result = ~ num
A | Y
0 | 1
1 | 0

2.2 AND bitwise
- Dùng để thực hiện phép AND bitwise giữa từng cặp bit của 2 số.
- Kết quả là 1 nếu cả 2 bit tương ứng đều là 1, ngược lại là 0
A B | Y = A.B 
0 0 | 0
0 1 | 0
1 0 | 0
1 1 | 1
int result = num1 & num2;

2.3 OR bitwise
- Dùng để thực hiện phép OR bitwise giữa từng cặp bit của 2 số. Kết quả là 1 nếu có hơn 1 bit tương ứng là 1
A B | Y = A + B
0 0 | 0
0 1 | 1
1 0 | 1
1 1 | 1
int result =  num1 | num2;

2.4 XOR bitwise
- Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của 2 số
- Kết quả là 1 nếu chỉ 1 bit tương ứng là 1
A B | Y = (~A).B + A.(~B)
0 0 | 0
0 1 | 1
1 0 | 1
1 1 | 0
int result = num1 ^ num2;

2.5 shift left và shift right bitwise
Dùng để di chuyển bit sang trái hoặc sang phải
- Trong trường hợp << (shift left), các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0
- Trong trường hợp >> (shift right), các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất(bit dấu)
int resultLeftShift = num << shiftAmount;
int resultRightShift = num >> shiftAmount;
VÍ DỤ:*/
// 
////VÍ DỤ 2:
// #include <stdio.h>
// #include <stdint.h>
//                                                 //  0     1
// #define GENDER      1 << 0 // bit 0: giới tính    nữ    nam     0b00000001
// #define SHIRT       1 << 1 // bit 1: áo thun      không có      0b00000010
// #define HAT         1 << 2 // bit 2: nón          không có      0b00000100
// #define SHOES       1 << 3 // bit 3: giày         không có      0b00001000
// #define FEATURE1    1 << 4 // bit 4: tính năng 1                0b00010000
// #define FEATURE2    1 << 5 // bit 5: tính năng 2                0b00100000
// #define FEATURE3    1 << 6 // bit 6: tính năng 3                0b01000000
// #define FEATURE4    1 << 7 // bit 7: tính năng 4                0b10000000

// //enable bit (0 ->1)
// void enableFeature(uint8_t *options, uint8_t feature)
// {
//     *options |= feature;
// }

// //disable bit (1 -> 0)
// void disableFeature(uint8_t *options, uint8_t feature)
// {
//     *options = *options & (~feature);
// }

// //check bit
// int8_t isFeatureEnable(uint8_t options, uint8_t feature)
// {
//     return ((options & feature) != 0);
// }

// //liệt kê các tính năng đang bật
// void listSelectedFeatures(uint8_t options)
// {
//     printf("Selected Features: \n");

//     const char* featureName[] = 
//     {
//         "Gender",
//         "Shirt",
//         "Hat",
//         "Shoes",
//         "Feature 1",
//         "Feature 2",
//         "Feature 3",
//         "Feature 4"
//     };
//     for (int i = 0; i < 8; i++)
//     {
//         if ((options >> i) & 1)
//         {
//             printf("%s\n",featureName[i]);
//         }
//     }
// }

// int main()
// {
//    uint8_t options = 0;

//    //thêm tính năng
//    enableFeature(&options, GENDER | HAT |SHOES);

//    //loại bỏ tính năng
//    disableFeature(&options, HAT | SHOES);
   
//    //liệt kê các tính năng đã chọn
//    listSelectedFeatures(options);

//    return 0;
// }

