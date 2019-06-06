///*************************************************************************
///     @FileName: TestQuery.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-06 17:00:55
///*************************************************************************
#include "TestQuery.h"

TestQuery::TestQuery(string strArray[],vector<string>::size_type count)
{
    lines_of_text.assign(strArray,strArray+count);
}

set<TestQuery::line_no> TestQuery::run_query(const string &word)const
{
    set<line_no> ret_lines;
    for(int i=0;i<lines_of_text.size();i++)
    {
        string line=lines_of_text[i];
        if(line.find(word)!=string::npos)
        {
            ret_lines.insert(i);
        }
    }
    return ret_lines;
}

TestQuery::line_no TestQuery::size()const
{
    return lines_of_text.size();
}

