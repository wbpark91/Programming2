#include <iostream>
#include <string>

class Student {
public:
    Student() {
        std::cout << "Default Constructor" << std::endl;
    }
    Student(std::string name, double height, double weight, int age)
    : name_(name), height_(height), weight_(weight), age_(age) {
        std::cout << "JH Lim" << std::endl;
    }
    Student(Student& stu_) {
        name_ = stu_.name_;
        height_ = stu_.height_;
        weight_ = stu_.weight_;
        age_ = stu_.age_;
        std::cout << "Copy constructor" << std::endl;
    }
private:
    std::string name_;
    double height_;
    double weight_;
    int age_;
};

int main() {
    Student park;
    Student lim("Lim", 180, 188.3, 29);
    Student kim(lim);
    
    return 0;
}
