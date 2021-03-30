#pragma once

#ifdef _DEBUG_
#define LOG(format, ...) printf(##format, __VA_ARGS__)
#define INFO(format, ...) printf("[ INFO ] "); printf(##format, __VA_ARGS__)
#else
#define LOG(format, ...)
#define INFO(format, ...)
#endif// _IMPROC_LOG_LEVEL > 0
