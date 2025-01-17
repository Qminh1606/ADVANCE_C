/*Bài 2: Thư viên stdarg và thư viện assert
1. Thư viện stdarg
-Cung cấp những hàm, những macro để làm việc với các hàm có số lượng tham số truyền vào (input parameter) chưa xác định được
-Điển hình là hàm printf và scanf

1.2. Macro của thư viện stdarg
-Để thao tác được với thư viện stdarg: #include <stdarg.h>

1.2.1 Va_list
-Là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi
    typedef struct __va_list_tag va_list[1]
    //typedef char* va_list
    va_list: khai báo con trỏ kiểu char giống như mảng chứa kí tự hay chuổi

1.2.2 Va_start
    -Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên
        #define va_start(v, 1) __builtin_va_start(v, 1)

1.2.3 Va_arg
-Truy cập một số đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
    #define va_agr(v, 1) __builtin_va_arg(v, 1)

1.2.4 Va_end
-Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.
-Thu hồi hay kết khúc con trỏ va_list
1.2.5 Va_copy
-Copy dữ liệu của va_list này sang va_list khác
    va_list args;
    va_list check;
    va_copy(check,args); // copy dữ liệu args sang check


VÍ DỤ1*/
// #include <stdio.h>
// #include <stdarg.h>

// void test(int count, ...)
// {
//     va_list args;
//     //Typedef char* va_list
//     // va_list args: khai báo con trỏ kiểu char chứa chuổi
//     //va_list args = "int count, 1, 2, 3.14, Hello world"
//     va_start(args, count);
//     //va_start truyền vào 2 tham số: biến kiểu va_list và tên của biến
//     // tên của biến dùng để so sánh và tìm ra đâu là đối số đâu là danh sách bắt đầu của danh sách
//     //char *args = "1, 2, 3.14, hello World"
//     printf("value 1: %d\n", va_arg(args, int));
//     //va_arg gồm 2 thông số: 1 là biến kiểu va_list và kiểu dữ liệu
//     //va_arg mỗi lần gọi lấy được 1 đối số
//     //va_arg đọc theo thứ tự vùng nhớ và in ra 
//     //va_arg truyền vào kiểu dữ liệu hợp lý ví dụ biến int thì kiểu dữ kiệu int
//     printf("value 2: %d\n", va_arg(args, int));
//     printf("value 3: %f\n", va_arg(args, double));
//     printf("value 4: %s\n", va_arg(args, char*));
//     va_end(args);
//     //khi đã làm xong hết nhiệm vụ
//     //sử dụng va_end để kết thúc con trỏ
// }

// int main()
// {
//     test(4, 1, 2, 3.14, "Hello world");

//     return 0;
// }

////VÍ DỤ 2
// #include <stdio.h>
// #include <stdarg.h>

// int sum(int count, ...)
// {
//     int tong = 0;
//     va_list arr;
//     va_start(arr, count);
//     for (int i = 0; i < count; i++)
//     {
//         tong += va_arg(arr,int);
//     }
//     va_end(arr);
//     return tong;
// }

// int main()
// {
//     printf("%d\n",sum(4, 1, 2, 3, 4));
//     return 0;
// }
////vÍ DỤ 3

// #include <stdio.h>
// #include <stdarg.h>
// #define tong(...) sum(__VA_ARGS__, 'a')

// int sum(int count, ...)
// {
//     va_list args;
//     va_list check;

    

//     va_start(args, count);
//     va_copy(check, args);
//     int result = count;
//     while (va_arg(check, char*) != (char*)'a' )
//     {
//         result += va_arg(args,int);
//     } 
//     va_end(args);
//     va_end(check);
//     return result;
// }

// int main()
// {
//     printf("Tong = %d\n", tong(3,2,0,4,5,6));
//     return 0;
// }

/*2. Thư viện assert
    -Cung cấp macro assert
Chức năng:
    -Được sử dụng để debug chương trình và phát hiện lỗi
    -Nếu chương trình không có lỗi thì chạy bình thường
    -Còn phát hiện lỗi sẽ dừng ngay chương trình
Thư viện:
    #include <assert.h>
    assert(kiểm tra);
VÍ DỤ:*/

// #include <stdio.h>
// #include <assert.h>

// int main()
// {
//     int a = 5;
//     assert(a==5);
//     printf("%d\n", a);
//     return 0;
// }

/*
*ƯU ĐIỂM CỦA ASSERT:
    Phát hiện lỗi sẽ dừng chương trình ngay lập tức chỉ ra lỗi ở hàng nào, ở đau và lỗi gì
*NHƯỢC ĐIỂM CỦA ASSERT:
    Làm cho gián đoạn chương trình nếu gặp lỗi sẽ dừng ngay lập tức và không thực thi phía sau
*/