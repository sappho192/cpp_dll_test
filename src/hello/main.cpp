// main.cpp
#include <iostream>
#include <string>
using std::string;
#include <fmt/core.h>

#include "co/co.h"
using co::chan;
#include "co/cout.h"

void pinger(chan<string>& ch)
{
    for (size_t i = 0; i < 5; i++)
    {
        ch << "ping";
    }
}

void ponger(chan<string>& ch)
{
    for (size_t i = 0; i < 5; i++)
    {
        ch << "pong";
    }
}

void printer(chan<string>& ch)
{
    for (size_t i = 0; i < 10; i++)
    {
        string str;
        ch >> str;
        std::cout << str << std::endl;
    }
}

// main function!
int main()
{
    fmt::print("Hello, world!\n");

    // WLOG << "hello" << 23;

    co::wait_group wg;
    wg.add(2);

    go([wg]()
       {
        std::cout << "hello world" << std::endl;
        wg.done(); });

    go([wg]()
       {
        std::cout << "hello again" << std::endl;
        wg.done(); });

    wg.wait();

    co::wait_group wg2;
    wg2.add(3);

    chan<string> ch;

    go([wg2, &ch]()
    {
        pinger(ch);
        wg2.done();
    });

    go([wg2, &ch]()
    {
        ponger(ch);
        wg2.done();
    });

    go([wg2, &ch]()
    {
        printer(ch);
        wg2.done();
    });

    wg2.wait();

    return 0;
}