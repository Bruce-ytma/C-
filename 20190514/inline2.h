#ifdef __WD_INLINE2_H__
#define __WD_INLINE2_H__
//#pragma once

//inline函数不能分成头文件和实现文件
inline
int max(int x,int y)
{
    return x>y?x:y;
}

#endif
