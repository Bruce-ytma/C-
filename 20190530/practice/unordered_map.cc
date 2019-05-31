/*************************************************************************
  @FileName: unordered_map.cc
  @Author:   ytma
  @Email:    1539447319@qq.com
  @Time:   Thu 30 May 2019 10:32:53 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Example
{
public:
    Example()
    {
        cout<<"Example()"<<endl;
    }

    bool insert(int val)
    {
        if(num2pos.count(val))
            return false;
        nums.push_back(val);
        num2pos[val]=nums.size()-1;

        return true;
    }

    bool remove(int val)
    {
        if(!num2pos.count(val))
            return false;
        int last=nums.back();
        num2pos[last]=num2pos[val];
        nums[num2pos[val]]=last;
        num2pos.erase(val);//删除key=val
        return true;
    }

    int getRandom()
    {
        return nums[rand()%nums.size()];
    }
private:
    vector<int>nums;
    unordered_map<int,int>num2pos;
};

int main()
{
    Example obj;
    bool para_1=obj.insert(1);
    bool para_2=obj.insert(1);
    bool para_4=obj.insert(2);
    int para_3=obj.getRandom();
    cout<<para_3<<endl;

    return 0;
}

