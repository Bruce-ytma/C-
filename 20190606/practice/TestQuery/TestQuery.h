///*************************************************************************
///     @FileName: TestQuery.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-06 14:31:34
///*************************************************************************
//#pragma once
#ifndef __WD__TestQuery__
#define __WD__TestQuery__

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class TestQuery
{
public:
    typedef vector<string>::size_type line_no;
    TestQuery(string[],vector<string>::size_type);
    set<line_no> run_query(const string &) const;
    line_no size()const;

private:
    vector<string> lines_of_text;

};

#endif
