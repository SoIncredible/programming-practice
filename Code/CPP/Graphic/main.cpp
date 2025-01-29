#include <iostream>
#include <string>

// 定义一个简单的类
class Person
{
private:
    std::string name;
    int age;

public:
    // 构造函数，用于初始化对象
    Person(const std::string &n, int a) : name(n), age(a) {}

    // 成员函数，用于显示对象信息
    void displayInfo()
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // 析构函数，在对象销毁时自动调用
    ~Person()
    {
        std::cout << "Destroying person: " << name << std::endl;
    }
};

int main()
{
    // 在堆上创建 Person 类的对象
    Person *person = new Person("Alice", 25);

    // 调用对象的成员函数
    person->displayInfo();

    // 当 main 函数执行结束，person 对象会自动销毁
    delete person;
    return 0;
}