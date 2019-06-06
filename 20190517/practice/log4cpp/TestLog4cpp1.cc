///*************************************************************************
///     @FileName: TestLog4cpp1.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Wed 05 Jun 2019 08:08:07 PM CST
///*************************************************************************
#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <iostream>
using namespace std;

int main()
{
    using namespace log4cpp;
    Category &root=Category::getRoot();

    OstreamAppender *pOstreamAppender=new OstreamAppender("OstreamAppender",&cout);
    pOstreamAppender->setLayout(new BasicLayout());

    root.setAppender(pOstreamAppender);
    root.setPriority(Priority::DEBUG);

    root.debug("this a debug message");

    Category::shutdown();
    return 0;
}

