///*************************************************************************
///     @FileName: Noncopyable.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-10 17:09:33
///*************************************************************************
#pragma once

namespace wd
{
class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}

    Noncopyable(const Noncopyable &)=delete;
    Noncopyable &operator=(const Noncopyable &)=delete;

};
}//end of namespace wd

