///*************************************************************************
///     @FileName: TestLog4cpp1.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:   Wed 05 Jun 2019 08:08:07 PM CST
///*************************************************************************
#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <iostream>
using namespace std;
using namespace log4cpp;

int main()
{
    PatternLayout *patternLayout=new PatternLayout();
    patternLayout->setConversionPattern("%d [%p] %m%n");

    OstreamAppender *ostreamAppender=new OstreamAppender("ostreamAppender",&cout);
    ostreamAppender->setLayout(patternLayout);

    Category &myRecord=Category::getRoot().getInstance("mycategory");
    myRecord.setAppender(ostreamAppender);

    myRecord.setPriority(Priority::ERROR);//通过配置文件修改

    //只有当日志的优先级大于等于日志记录器的优先级时，该条日志才会被记录
    myRecord.emerg("this is an emerg message");//方法本身代表的就是这一条日志级别的
    myRecord.fatal("this is a fatal message");
    myRecord.alert("this is an alert message");
    myRecord.crit("this is a crit message");
    myRecord.warn("this is a warn message");
    myRecord.error("this is an error message");
    myRecord.notice("this is a notice message");
    myRecord.info("this is an info message");
    myRecord.debug("this is a debug message");

    Category::shutdown();//回收各种堆空间的内存
    return 0;
}

