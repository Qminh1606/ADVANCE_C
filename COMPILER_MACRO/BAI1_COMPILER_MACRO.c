/*bài 1: Compiler và macro
1. IDE cung cấp editor(trình soạn thảo) và compiler(trình biên dịch)
2. Compiler là trình biên dịch
-Nhiệm vụ: chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy
-Mỗi IDE có trình biên dịch(compiler) khác nhau
3. Quá trình biên dịch compiler
gồm có 4 bước:
    -Tiền xử lý (Preprocessor)
    -Compiler
    -Assembler
    -Linker
3.1. Tiền xử lý (Preprocessor): từ những file .h và .c qua quá trình tiền xử lý tạo ra file .i
{
- Cú pháp: 
        gcc -E main.c -o main.i
- Nhiệm vụ:
        -copy toàn bộ mã nguồn của những file đưa vào
        -xóa bỏ chú thích và comment
        -những định nghĩa define cũng sẽ được thay thế
        -còn lại tất cả giữ nguyên
- MACRO 
{
- MACRO là những từ mà chỉ thông tin được xử lý ở quá trình tiền xử lý
- Những loại macro:
    1. #include là chỉ thị bao hàm tệp
        -#include được dùng để in vào những thư viện hoặc những file .ngoài file main
        -khi quá trình tiền xử lý xảy ra #include sẽ copy toàn bộ code những file vaò file .in
    Có 2 dạng 
        - khi #include < > thì compiler tìm tên file nào có tên giống và tìm trong file thư mục cài đặt
        - khi #include " " thì tìm kiếm trong thư mục hiện tại compiler copy toàn bộ code vào trong file .i
    VÍ DỤ:*/
    // #include <stdio.h>
    // #include "test.c"
    // int main()
    // {
    //     output();
    //     return 0;
    // }
    /*2. #define, hủy định nghĩa macro
        2.1. #define được gọi là chỉ thị định nghĩa
        - các toán tử trong macro
            + ## (gọi là toán tử macro) dùng để nối chuổi lại với nhau
                #define CREATE_VAR(name)    \
                int int_##name;             \
                double double_##name;       
                VÍ DỤ:*/
                // #include <stdio.h>
                // #define CREATE_VAR(name)    \
                // int int_##name;             \
                // double double_##name

                // int main()
                // {
                //     CREATE_VAR(abc);
                //     int_abc =1;
                //     double_abc =2.5;
                //     printf("%d %f\n", int_abc, double_abc);
                //     return 0;
                // }
        /*  + # chuẩn hóa lên chuổi
                #define CREATE_STRING( cmd) printf(#cmd);
                VÍ DỤ*/
                // #include <stdio.h>
                // #define CREATE_STRING(cmd) printf(#cmd);
                
                // int main()
                // {
                //     CREATE_STRING(abcxyz);
                //     return 0;
                // }
         /* + macro variadic: cho phép 1 hàm nhận 1 số lượng tham số truyền vào không xác định được
                #define sum (...)               \
                int arr[] = {__VA_AGRS__, 0};   \
                int tong  = 0;                  \
                int i = 0;                      \
                while (arr[i] != 0)             \
                {                               \
                    tong += arr[i];             \
                    i++;                        \
                }                               \
                printf("Tong = %d\n", tong);

                VÍ DỤ:*/
                // #include <stdio.h>
                
                // #define sum(...)                                        \
                // int arr[] = {__VA_ARGS__, 0};                           \
                // int tong = 0;                                           \
                // for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)    \
                // {                                                       \
                //     tong += arr[i];                                     \
                // }                                                       \
                // printf("sum  = %d\n", tong);                              
                
                // int main()                                              
                // {                                   
                //     sum(1,2,3,4,5,6);
                //     return 0;
                // }



     /* 2.2. Hủy định nghĩa macro
        - Chỉ thị #undef dùng để hủy định nghĩa của 1 macro đã được định nghĩa trước đó bằng #define
        - Cú pháp: #undef data
        VÍ DỤ:*/
        // #include <stdio.h>
        // #define SENSOR_DATA 30
        // int main()
        // {
        //     printf("Value of SENSOR_DATA %d\n", SENSOR_DATA);
        //     #undef SENSOR_DATA
        //     #define SENSOR_DATA 20
        //     printf("Value of SENSOR_DATA %d", SENSOR_DATA);
        // return 0;
        // }

    /*3. #ifndef #ifdef #else #if #elif :những chỉ thị biên dịch có điều kiện
        -#ifdef : kiểm tra macro có được định nghĩa hay chưa, nêú chưa thì sử dụng #ifndef
        -#ifndef kiểm tra macro có được định nghĩa hay chưa, nếu chưa định nghĩa thì bắt đầu định nghĩa phía dưới còn định nghĩa rồi thì thực thi câu lệnh
        thường sử dụng để thiết kế thư viên
    #define size 30

    #ifdef size
    int array[size];
    #endif
    VÍ DỤ:*/
    // #include <stdio.h>
    // #include "test.h"
    // #define size 5

    // #ifdef size
    // int arr[size];
    // #endif

    // int main()
    // {
    //     for (int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++)
    //     {
    //         arr[i] = i;
    //     }
    //     for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    //     {
    //         printf("%d ", arr[i]);
    //     }
    //     output();
    //     return 0;
    // }


/*}
4. Quá trình compiler
    -main.i -> main.s 
    -main.s là file asemly file hợp ngữ
    -gcc -S main.i -o main.s

5. Assembler
    -file main.s -> main.o được gọi là quá trình assembler
    -gcc -c main.s -o main.o
6. Linker
    -file main.o -> main.exe được gọi là linker
    -liên kết các file .o để tạo ra file .exe
    -gcc main.o test.o -o main*/