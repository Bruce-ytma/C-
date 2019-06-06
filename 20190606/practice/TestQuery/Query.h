///*************************************************************************
///     @FileName: Query.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-06 17:09:41
///*************************************************************************
//#pragma once

#ifndef __WD__Query__
#define __WD__Query__

#include "TestQuery.h"
#include <iostream>

class Query_base;

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &,const Query &);
    friend Query operator&(const Query &,const Query &);

public:
    Query(const string &);
    Query(const Query &);
    virtual ~Query();
    Query &operator=(const Query &);

    set<TestQuery::line_no> eval(const TestQuery &)const;
    ostream &display(ostream &)const;

private:
    Query(Query_base *);

    Query_base *q;
    size_t *use;
    void decr_use();

};

inline ostream & operator<<(ostream &os,const Query &q)
{
    return q.display(os);
}

#endif
