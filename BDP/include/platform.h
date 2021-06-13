#ifndef BDP_PLATFORM_H
#define BDP_PLATFORM_H
    #if defined(_WIN32) || defined(_WIN64)
        #define ISWINDOWS 1
    #elif defined(unix) || defined(__unix) || defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
        #define ISUNIX 1
    #endif
#endif