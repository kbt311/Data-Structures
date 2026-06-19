#include "add.h"
#include <iostream>
#include <stdexcept> 

int main() {
    std::cout << "=== 高精度抽象大类测试启动 ===" << std::endl;
    try {
        std::string num1 = "";
        std::string num2 = "";
        std::cin >> num1 >> num2;
        SeqBigInt a(num1);
        ListBigInt b(num2);
        //b.add(a);
        //b.print();
        a.add(b);
        a.print();
    }
    catch (const std::exception& e) {
        std::cerr << "\n[致命错误] 程序崩溃被成功拦截！原因: " << e.what() << std::endl;
    }
    std::cout << "=== 测试结束，对象自动析构释放内存 ===" << std::endl;
    return 0;
}