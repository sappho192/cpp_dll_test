// main.cpp
#include <iostream>
#include <fmt/core.h>

#include "co/log.h"
#include "co/co.h"

// main function!
int main()
{
    fmt::print("Hello, world!\n");

    WLOG << "hello" << 23;

    co::wait_group wg;
    wg.add(2);

    go([wg](){
        std::cout << "hello world" << std::endl;
        wg.done();
    });

    go([wg](){
        std::cout << "hello again" << std::endl;
        wg.done();
    });

    wg.wait();
    return 0;
}