///*************************************************************************
///     @FileName: Query_base.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-06 19:39:34
///*************************************************************************
#include "Query_base.h"

WordQuery::WordQuery(const string &s)
    :query_word(s)
{

}

set<WordQuery::line_no> WordQuery::eval(const TestQuery &t)const
{
    return t.run_query(query_word);
}

ostream & WordQuery::display(ostream &os)const
{
    return os<<query_word;
}

NotQuery::NotQuery(Query q)
    :query(q)
{

}

set<NotQuery::line_no> NotQuery::eval(const TestQuery &file)const
{
    set<line_no> has_val=query.eval(file);
    set<line_no>ret_lines;

    for(TestQuery::line_no n=0;n!=file.size();++n)
    {
        if(has_val.find(n)==has_val.end())
        {
            ret_lines.insert(n);
        }
    }
    return ret_lines;
}

ostream &NotQuery::display(ostream &os)const
{
    return os<<"~("<<query<<")";
}

BinaryQuery::BinaryQuery(Query left,Query right,string op)
    :lhs(left)
    ,rhs(right)
{

}

ostream & BinaryQuery::display(ostream &os)const
{
    return os<<"("<<lhs<<" "<<oper<<" "<<rhs<<")";
}

AndQuery::AndQuery(Query left,Query right)
    :BinaryQuery(left,right,"&")
{

}

set<AndQuery::line_no> AndQuery::eval(const TestQuery &file)const
{
    set<line_no> left=lhs.eval(file),right=rhs.eval(file);
    set<line_no> ret_lines;
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(ret_lines,ret_lines.begin()));
    return ret_lines;
}

OrQuery::OrQuery(Query left,Query right)
    :BinaryQuery(left,right,"|")
{

}

set<OrQuery::line_no> OrQuery::eval(const TestQuery &file)const
{
    set<OrQuery::line_no> right=rhs.eval(file),ret_lines=lhs.eval(file);
    ret_lines.insert(right.begin(),right.end());
    return ret_lines;
}


