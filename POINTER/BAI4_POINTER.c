/*
BÀI 4: CON TRỎ (POINTER)
    Trong ngôn ngữ lập trình C, con trỏ (pointer) là biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm)
    Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn
    
    * Pointer
    int test;           Address: 0x01   //Cấp phát Address 0x01 cho biến test địa chỉ được lấy trên RAM
                        Value:   0      //Tại Address 0x01 sẽ khởi tạo giá trị là 5

    int *ptr = &test;   Address: 0xf1   // &: lấy địa chỉ của biến, Cấp phát Address 0xf1 cho biến ptr
                        Value:   0x01   // con trỏ ptr chứa địa chỉ của biến test */
////VÍ DỤ:
// #include <stdio.h>

// int main()
// {
//     int test = 5;
//     int *ptr = &test;

//     printf("Adress test = %p\n", &test);
//     printf("Gia tri cua ptr = %p\n", ptr);
//     printf("Gia tri cua bien test = %d\n", *ptr);
//     return 0;
// }

/**Cách khai báo:
    int *ptr;         // con trỏ đến kiểu int
    char *ptr_char;   // con trỏ đến kiểu char
    float *ptr_float; // con trỏ đến kiểu float

*Lấy địa chỉ của một biến và truy cập giá trị
    int x = 10;         
    int *ptr_x = &x;    //ptr_x chứa địa chỉ của x
    int y = *ptr_x;     //y sẽ bằng giá trị của x (dereference: toán tử giải tham chiếu)*/
////VÍ DỤ:
// #include <stdio.h>
// #include <stdint.h>
// #include <stdbool.h>
// int main()
// {
//     printf("%d bytes\n", sizeof(int *));
//     printf("%d bytes\n", sizeof(uint8_t *));
//     printf("%d bytes\n", sizeof(int16_t *));
//     printf("%d bytes\n", sizeof(char *));
//     printf("%d bytes\n", sizeof(float *));
//     printf("%d bytes\n", sizeof(double *));
//     printf("%d bytes\n", sizeof(long *));
//     printf("%d bytes\n", sizeof(short *));
//     printf("%d bytes\n", sizeof(long long *));
//     printf("%d bytes\n", sizeof(bool *));
// return 0;
// }

/*Tất cả đều là 8bytes, Do kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc kiến trúc vi xử lý.

0x01             0x02        0x03        0x04
00000101(LSB)    00000000    00000000    00000000(MSB)

float = sign(1 bit) + exponent( 8 bits) + mantissa(23 bits)
float = sign(1 bit) + exponent( 11 bits) + mantissa(52 bits)
*/

// #include <stdio.h>

// void swap(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void swap_point(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main()
// {
//     int a = 10, b = 20;
//     swap(a, b); // hàm hoán đổi swap không sử dụng point
//     printf("Value a la: %d\n", a);
//     printf("Value b la: %d\n", b);
//     swap_point(&a, &b); // hàm hoán đổi swap có sử dụng point
//     printf("Value a point la: %d\n", a);
//     printf("Value b point la: %d\n", b);
//     return 0;
// }
// Hàm swap không sử dụng con trỏ khi gọi ra giá trị của a,b vẫn giữ nguyên còn hàm swap sử dụng con trỏ thì giá trị của a và b được hoán đổi
// Lý do swap không sử dụng con trỏ thì copy giá trị của a và b vào hàm swap để được hiện swap
// nên giá trị của a và b vẫn giữ nguyên
//còn swap có sử dụng point thì copy địa chỉ của a và b vào hàm swap
// nên hàm swap thay đổi thì a và b vẫn thay đổi giá trị

/*
Những con trỏ đặt biệt
1. void pointer 
    Thường dùng để trỏ tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó
    Cú pháp:
    void *ptr_void;   */
// #include <stdio.h>

// int main()
// {
//     //khai báo con trỏ kiểu void để trỏ được đến các kiểu dữ liệu khác
//     void *ptr_void;

//     int var_int  = 5;
//     ptr_void = &var_int;

//     printf("value to var: %d", *(int*)ptr_void); // con trỏ đang ở kiểu void muốn in giá trị int phải ép kiểu con trỏ thành con trỏ int
//     // con trỏ kiểu void công dụng để giảm tốn bộ nhớ
    
//     double var_double = 3.14;

//     char var_char[] = "hello";
//     //mảng con trỏ void
//     void *ptr [] = {&var_int, &var_double, var_char};
//     printf("\nMang void:\n");
//     printf("Mang void 1: %d\n", *(int*)ptr[0]);
//     printf("Mang void 2: %.2f\n", *(double*)ptr[1]);
//     printf("Mang void 3: ");
//     for (int i = 0; i < (sizeof(var_char)/ sizeof(var_char[0])); i++)
//     {
//         printf("%c", *(char*)(ptr[2]+ i));
//     }
// return 0;
// }

/* 
2. function pointer
Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình
Trong ngôn ngữ C, con trỏ hàm cho phép bạn truyền 1 hàm như là một đối số của 1 hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác
<return_type> (*func_pointer)(<data_type_1>, <data_type_2>);
ví dụ:
void sum(int a, int b);
void (*func_ptr) (int, int);

int test(double a, char b, chort c);
int (*func_ptr1)( double, char, short);
Ví Dụ:*/
// #include <stdio.h>

// void tong(int a, int b)
// {
//     printf("a + b = %d\n", a + b);
// }

// void hieu(int a, int b)
// {
//     printf("a - b = %d\n", a - b);
// }

// void tich(int a, int b)
// {
//     printf("a * b = %d\n", a * b);
// }

// void thuong(int a, int b)
// {
//     printf("a / b = %f\n", (float)a / (float)b);
// }

// void tinhtoan(void (*pheptoan)(int, int), int a, int b)
// {
//     pheptoan(a,b);
// }

// int main()
// {
//     int a = 5, b = 6;
//     ////cách 1: xử dung con trỏ hàm để gọi các phép toán
//     void (*ptr)(int, int);
//     // ptr = tong;
//     // ptr(a, b);

//     // ptr = hieu;
//     // ptr(a, b);

//     // ptr = tich;
//     // ptr(a, b);

//     // ptr = thuong;
//     // ptr(a,b);
//     ////cách 2: Gọi các phép toán thông qua hàm tinhtoan  
//     tinhtoan(tong, a, b);
//     ////cách 3: sử dụng mảng con trỏ hàm để gọi các phép toán
//     void (*calculate[])(int,int) = {tong, hieu, tich, thuong};
//     calculate[2](a, b);
// return 0;
// }
/*
    Gọi trực tiếp và gián tiếp qua con trỏ hàm có ưu và nhược điểm:
    Chương trình qua 2 quá trình:
    - Compiler - time: Gọi trực tiếp hàm sẽ ở compiler - time và nó cố định lun nên không thể thay đổi hàm trong quá trình chạy
    - Run - time: Gọi hàm qua con trỏ hàm xảy ra ở quá trình Run -  time linh hoạt hơn, có thể thay đổi trong quá trình chạy
*/

/*3. pointer to constant
    *Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng gía trị tại địa chỉ đó có thể thay đổi
    *Cú Pháp:
    const int *ptr_const;
ví dụ:*/
// #include <stdio.h>
// int value = 10;
// const int *ptr_const = &value;

// int main()
// {
//     printf("Value: %d\n ", *ptr_const);
//     int value_1 = 15;
//     ptr_const = &value_1;
//     printf("value 1: %d\n", *ptr_const);
// return 0;    
// }
/*4. constant to pointer 
    -Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ đến địa chỉ khác
    -Cú Pháp:
        int *const const_ptr = &value;
    
    -Ứng dụng để quản lý thanh ghi
5. NULL
    NULL Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cự thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể gán giá trị NULL để biểu diễn trạng thái null, C++ (NULL, nullptr)
    Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh derederencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình
    *2 trường hợp cần biểu diễn
        - Khi thay báo con trỏ nhưng chưa sử dụng thì để con trỏ = Null
        Tránh trường hợp con trỏ trỏ đến địa chỉ rác có thể vô trình làm mất dữ liệu ở địa chỉ này
        - Gán Null khi sử dụng xong con trỏ, tránh con trỏ trỏ đến địa chỉ rác
6. pointer to pointer
    -Con trỏ đến con trỏ (Pointer to pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của môt con trỏ. 
    -Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc.
    -Cấp bậc này có thể hữu ích trong nhiều tình huống, đặt biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
    
    *Pointer
    int test = 5;
    int *ptr = &test;
    int **ptp = &ptr; //Con trỏ cấp 1
    int ***ptn = &ptp; //Con trỏ cấp 2
Ví dụ:*/
// #include <stdio.h>

// int main()
// {
//     int test = 5;
//     int *ptr = &test;
//     int **ptp = &ptr;
//     printf("Value con tro cap 2: %d\n", **ptp);
// return 0;
// }