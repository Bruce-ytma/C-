///*************************************************************************
///     @FileName: Query_base.h
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-06 19:20:24
///*************************************************************************
//#pragma once
#ifndef __WD__Query_base__
#define __WD__Query_base__

#include <iostream>
#include "TestQuery.h"
#include "Query.h"

class Query_base
{
    friend class  Query;
protected:
    typedef TestQuery::line_no line_no;
    virtual ~Query_base()
    {}

private:
    virtual set<line_no> eval(const TestQuery &)const=0;
    virtual ostream &display(ostream & = cout)const=0;
};

class WordQuery:Query_base
{
    friend class Query;
    WordQuery(const string &);
    set<line_no> eval(const TestQuery &)const;
    ostream & display(ostream & = cout)const;

    string query_word;
};

class NotQuery:public Query_base
{
    friend Query operator~(const Query &);

    NotQuery(Query);
    set<line_no> eval(const TestQuery &)const;
    ostream & display(ostream & =cout)const;
    const Query query;
};

class BinaryQuery:public Query_base
{
protected:
    BinaryQuery(Query left,Query right,string op);
    ostream & display(ostream & = cout)const;

    const Query lhs,rhs;
    const string oper;
};

class AndQuery:BinaryQuery
{
    friend Query operator&(const Query &,const Query &);
    AndQuery(Query left,Query right);
    set<line_no> eval(const TestQuery &)const;
};

class OrQuery:BinaryQuery
{
    friend Query operator|(const Query &,const Query &);
    OrQuery(Query left,Query riight);
    set<line_no> eval(const TestQuery &) const;
};

#endif
