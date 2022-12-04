/**
 * @file singleton_test.cc
 * @author cuishanyao (shanyao_work@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "singleton.h"

#include <iostream>
#include <thread>

using namespace LANG;

class Test final {
public:
    Test() { Init(); }
    Test(int number) : t_(number) {}
    ~Test() = default;

    int GetNumber() const {
        return t_;
    }

    void SetNumber(int number) {
        t_ = number;
    }

private:
    void Init() {
        t_ = 0;
    }

private:
    int t_;
    std::mutex mutex_;  // protect t
};


static Test* GTestPtr() {
    return Singleton<Test>::get();
}


int main(int argc, char** argv) {

    if (GTestPtr() != nullptr) {
        std::cout << "Init: " << GTestPtr()->GetNumber() << std::endl;
        GTestPtr()->SetNumber(1000);
        std::cout << "After: " << GTestPtr()->GetNumber() << std::endl;
    }

    return 0;
}