///*************************************************************************
///     @FileName: Noncopyanle.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-13 21:32:34
///*************************************************************************
#pragma once
namespace wd
{

class Noncopyanle
{
public:
    Noncopyanle() {}
    ~Noncopyanle() {}
    Noncopyanle(const Noncopyanle &)=delete;
    Noncopyanle &operator=(const Noncopyanle &)=delete;

};
}//end of namespace wd
