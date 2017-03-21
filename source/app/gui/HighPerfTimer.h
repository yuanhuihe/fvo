#pragma once

#include <stdint.h>
#include <time.h>

#ifdef __OS_XUN__
#include <sys/time.h>
#else
#include <Windows.h>   // LARGE_INTEGER, QueryPerformanceFrequency
#endif

/*
* 此模块获取1970到现在的时间，精度为us
* 平台： windows， unix， mac
*/

class HighPerfTimer
{
#ifdef __OS_XUN__
    struct timeval StartingTime, EndingTime, ElapsedTime;
#else
    LARGE_INTEGER __cpuFreq;
    LARGE_INTEGER StartingTime, EndingTime, ElapsedTime;
#endif // WIN32

    // 记录调用此函数时到1970年的微秒数
    uint64_t _1970usec;

public:
	HighPerfTimer(void);
	~HighPerfTimer(void);

    // sleep, sleep_us:微秒数
    void Sleep(double usecond);    

    // 返回从1970年到调用此函数时的微秒数
    uint64_t GetTime();
};

