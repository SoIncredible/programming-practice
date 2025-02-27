// 对C++中 宏和断言的测试
#include <iostream>
#include <assert.h>

// 命令行构建使用 g++ main.cpp -D DEFINE_MACROS

int main(){
    int i = 101;
    assert(i > 100);

    std ::cout << "执行到断言方法之后了" << std ::endl;
#if DEFINE_MACROS
    std::cout << "找到宏的定义了!" << std::endl;
#endif
    return 0;
}