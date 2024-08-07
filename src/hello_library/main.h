#ifndef HELLO_LIB_H
#define HELLO_LIB_H

#include <random>
#include <chrono>

#include <fmt/core.h>

#ifdef _WIN32
#ifdef HELLO_LIB_H_EXPORTS
#define HELLO_LIB_H_API __declspec(dllexport)
#else
#define HELLO_LIB_H_API __declspec(dllimport)
#endif

#elif __APPLE__
#define HELLO_LIB_H_API

#elif __linux__
#define HELLO_LIB_H_API
#endif

extern "C" HELLO_LIB_H_API int hello();

#endif