#pragma once
#include <iostream>

#define DEBUG 1
#if DEBUG
template<typename T>
void debug_out(T t) {
    std::cerr << t;
}

template<typename T, typename... Args>
void debug_out(T t, Args... args) {
    std::cerr << t << ", ";
    debug_out(args...);
}

// 核心宏定义
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__), std::cerr << std::endl
#else
#define debug(...)
#endif