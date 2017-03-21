#include "HighPerfTimer.h"

HighPerfTimer::HighPerfTimer(void)
{
    // 获取从1970年1月1日0时到此时的秒数
    time_t t = time(NULL);

    // 记录调用此函数时到1970年的微秒数
    _1970usec = t * 1000000;

#ifdef __OS_XUN__

    gettimeofday(&StartingTime, NULL);

#else

    // 获取本地时间
    SYSTEMTIME tm;
    ::GetLocalTime(&tm);

    // 只用其毫秒数值，以补充time()函数的精度不足的问题
    _1970usec += tm.wMilliseconds * 1000;

    QueryPerformanceFrequency(&__cpuFreq);
    QueryPerformanceCounter(&StartingTime);

#endif
}


HighPerfTimer::~HighPerfTimer(void)
{
}

void HighPerfTimer::Sleep(double usecond)
{
    if ( usecond <= 0 ) return;

#ifdef __OS_XUN__
    struct timeval tmpStartingTime, tmpEndingTime;
    double currEslipsedTime;
    gettimeofday(&tmpStartingTime, NULL);
    do
    {
        gettimeofday(&tmpEndingTime, NULL);
        currEslipsedTime = (tmpEndingTime.tv_sec - tmpStartingTime.tv_sec) * 1000000 + (tmpEndingTime.tv_usec - tmpStartingTime.tv_usec);
    } while (currEslipsedTime < usecond);
#else
    LARGE_INTEGER freq;      //CUP频率
    LARGE_INTEGER count_base;//开始计数值
    LARGE_INTEGER count_curr;//当前技术值
    double passed_time;          //从0开始,过来多长时间
    //获得时钟频率
    QueryPerformanceFrequency(&freq);
    //获取开始寄存器计数值
    QueryPerformanceCounter(&count_base);
    //计时等待
    do
    {
        QueryPerformanceCounter(&count_curr);
        passed_time = ((count_curr.QuadPart - count_base.QuadPart) * 1000000) / freq.QuadPart;
    } while (passed_time < usecond);
#endif
}

uint64_t HighPerfTimer::GetTime()
{
#ifdef __OS_XUN__

    gettimeofday(&EndingTime, NULL);

    ElapsedTime.tv_sec = EndingTime.tv_sec - StartingTime.tv_sec;
    ElapsedTime.tv_usec = EndingTime.tv_usec - StartingTime.tv_usec;

    return ElapsedTime.tv_sec * 1000000 + ElapsedTime.tv_usec;
#else

    QueryPerformanceCounter(&EndingTime);
    ElapsedTime.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

    // 为了避免损失精度，先转换成微秒再除以CPU的频率
    ElapsedTime.QuadPart *= 1000000;    // 微秒
    ElapsedTime.QuadPart /= __cpuFreq.QuadPart;

    return _1970usec + ElapsedTime.QuadPart;

#endif
}