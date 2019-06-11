///*************************************************************************
///     @FileName: warcraft.cc
///     @Author:   ytma
///     @Email:    1539447319@qq.com
///     @Time:     2019-06-08 15:12:29
///*************************************************************************
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;

//对于颜色、武士类型，设计成枚举类型，方便以后的说明
enum Color
{
    RED,
    BLUE,
    NOTSET
};

enum WarriorType
{
    DRAGON_TYPE,
    NINJA_TYPE,
    ICEMAN_TYPE,
    LION_TYPE,
    WOLF_TYPE
};

//为了通过某种颜色或者武士类型，得到字符串，所以实现了以下inline函数。
inline string toString(Color color)
{
    return (color==RED)?string("red"):string("blue");
}

inline string toString(WarriorType type)
{
    switch(type)
    {
    case DRAGON_TYPE:return "dragon";
    case NINJA_TYPE:return "ninja";
    case ICEMAN_TYPE:return "iceman";
    case LION_TYPE:return "lion";
    case WOLF_TYPE:return "wolf";
    default:
        return string();
    }
}

namespace warcraft
{
//设计游戏配置类(单例)
class GameConfig
{
public:
    static GameConfig *getInstance();
    static void destory();

    void readFromConsole();//从控制台终端获取测试数据
    void readFromFile(const string &filename);//从配置文件中获取测试数据
    void nextGroupId()
    {
        ++_currentGroupId;
    }

    size_t groups()const
    {
        return _groups.size();
    }

    size_t currentGrouId()const
    {
        return _currentGroupId;
    }

    size_t cityCount()const;
    size_t headquartersInitialElements()const;
    size_t warriorInitialLife(WarriorType key)const;
    size_t warriorInitialAttack(WarriorType key)const;

private:
    GameConfig()
        :_currentGroupId(0)
    {
        cout<<"GameConfig()"<<endl;
    }
    ~GameConfig()
    {
        cout<<"~GameConfig()"<<endl;
    }

    void readFromStream(istream &is);

    struct InitData
    {
        size_t _initElements;
        size_t _cityCount;
        size_t _minutes;
        map<WarriorType,size_t> _initLifes;
        map<WarriorType,size_t> _initAttacks;
    };
private:
    static GameConfig *_pInstance;

    vector<InitData> _groups;//N组数据
    size_t _currentGroupId;//当前正在测试的数据
    vector<WarriorType> _initWarriorOrder;//输入时武士的生命值和攻击力设置顺序

};

//设置游戏时间类(单例)
class GameTime
{
public:
    static GameTime *getInstance();
    static void destory();

    void showTime()const;//打印时间
    void updateTime();//更新时间
    void reset()
    {
        _hour=0;
        _minute=0;
    }

private:
    GameTime *_pInstance;
    size_t _hour;
    size_t _minute;
};

//设计武士继承体系(Model)
class Warrior:public std::enable_shared_from_this<Warrior>
{
public:
    Warrior(Color color,const string &name,size_t id,size_t hp,size_t forces,WarriorType type)
        :_color(color)
        ,_name(name)
        ,_id(id)
        ,_hp(hp)
        ,_forces(forces)
        ,_type(type)
    {

    }

    virtual ~Warrior()
    {

    }

    virtual void march();//行军
    virtual void attack(WarriorPtr warrior);//攻击另一个武士
    virtual void defense(WarriorPtr warrior);//反击另一个武士

    void beWinner();//成为胜利者
    void beRewarded();//被奖励
    void sentElementsToHeadquarters(size_t elements);//为司令部获取生命元

    void setHp(size_t hp)
    {
        _hp=hp;
    }

    void setCity(size_t id)
    {
        _cityId=id;
    }

    void setHeadquarters(Headquarters *headquarters)
    {
        _headquarters=headquarters;
    }

    Color getColor()const
    {
        return _color;
    }

    string getName()
    {
        return _name;
    }

    size_t getId()const
    {
        return _id;
    }

    size_t getHp()const
    {
        return _hp;
    }

    size_t getCityId()const
    {
        return _cityId;
    }

    size_t getElements()const
    {
        return _hp;
    }

    size_t getEarnElements()const
    {
        return _earnElements;
    }

    size_t getForces()const
    {
        return _forces;
    }

    WarriorType getType()const
    {
        return _type;
    }

protected:
    Color _color;
    string _name;
    size_t _id;//编号
    size_t _hp;//生命值
    size_t _forces;//攻击力
    size_t _cityId;//位于某个城市
    size_t _earnElements;//从某个城市中获取生命元
    WarriorType _type;
    Headquarters *_headquarters;
};

class Dragon:public Warrior
{
public:
    Dragon(Color color,size_t id,size_t hp,size_t forces,float morale)
        :Warrior(color,"dragon",id,hp,forces,DRAGON_TYPE)
        ,_morale(morale)
    {

    }

    virtual float getMorale()const
    {
        return _morale;
    }

private:
    float _morale;
};

class Ninja:public Warrior
{
public:
    Ninja(Color color,size_t id,size_t hp,size_t forces)
        :Warrior(color,"ninja",id,hp,forces,NINJA_TYPE)
    {

    }

    //ninja挨打了也从不反击敌人，需覆盖
    virtual void defense(WarriorPtr warrior)override;
};

class Iceman:public Warrior
{
public:
    Iceman(Color color,size_t id,size_t hp,size_t forces)
        :Warrior(color,"iceman",id,hp,forces,ICEMAN_TYPE)
        ,_steps(0)
    {

    }

    //iceman每前进两步，在第二步完成的时候，生命值会减少9，攻击力会增加20.
    //但是若生命值jian9后会小于等于0，则生命值不减9，而是变为1.即iceman不会因走多了而死。
    //需覆盖
    virtual void march()override;

private:
    size_t _steps;//前进的步数
};

class Lion:public Warrior
{
public:
    Lion(Color color,size_t id,size_t hp,size_t forces,size_t loyalty)
        :Warrior(color,"lion",id,hp,forces,LION_TYPE)
        ,_loyalty(loyalty)
    {

    }

    virtual size_t getLoyalty()const override
    {
        return _loyalty;
    }

private:
    size_t _loyalty;
};

class Wolf:public Warrior
{
public:
    Wolf(Color color,size_t id,size_t hp,size_t forces)
        :Warrior(color,"wolf",id,hp,forces,WOLF_TYPE)
        ,_killTimes(0)
    {

    }

    /*在一个wolf通过主动攻击杀死敌人的次数达到偶数的时刻(次数从1开始算)，在战斗完
     * 成后，该wolf生命值和攻击力都增加1倍。如果其死的敌人是lion，则攻击力和生命值
     * 先加倍，然后才吸取lion的生命值。获取总部的生命元奖励，发生在加倍之后。只有在
     * 主动攻击敌人时才能有加倍的事情，反击杀死敌人则不会发生加倍。*/

    //需覆盖
    virtual void attack(WarriorPtr warrior)override;

private:
    int _killTimes;//击杀次数
        
};

//设计城市类(Model)
class City
{
public:
    City(size_t id,size_t elements=0)
        :_flag(Color::NOTSET)
        ,_id(id)
        ,_elements(elements)
        ,redWinCount(0)
        ,_blueWinCount(0)
    {

    }

    void produceElements();//城市生产生命元
    void attach(WarriorPtr);//某武士进入该城市
    void detach(WarriorPtr);//某武士离开该城市
    void startBattle();//开始战斗
    void takenBy(WarriorPtr warrior);//生命元被某武士取走

    size_t getId()const
    {
        return _id;
    }

    Color getFlag()const
    {
        return _flag;
    }

    size_t getWarriorAmount()const
    {
        return _redWarriors.size()+_blueWarriors.size();
    }

    vector<WarriorPtr> &getRedWarriors()
    {
        return _redWarriors;
    }

    vector<WarriorPtr> &getBlueWarriors()
    {
        return _blueWarriors;
    }

private:
    void battle(WarriorPtr warrior1,WarriorPtr warrior2);//2名武士的具体战斗情况
    bool isChangingFlag(WarriorPtr warrior);//是否更换旗子

private:
    Color _flag;//城市旗子的颜色
    size_t _id;//城市编号
    size_t _elements;//城市生命元
    size_t _redWinCount;//红魔军连续胜利次数
    size_t _blueWinCount;//蓝魔军连续胜利次数
    vector<WarriorPtr> _redWarriors;
    vector<WarriorPtr> _blueWarriors;
    
};

//设计司令部类(Model)
class Headquarters
{
public:
    Headquarters(Color color,size_t elements)
        :_color(color)
        ,_elements(elements)
        ,_earnElements(0)
        ,_nextWarriorIndex(0)
    {

    }
    
    virtual ~Headquarters()
    {

    }

    //创建武士
    WarriorPtr creat();

    //添加胜利者
    void addWinner(WarriorPtr warrior);

    //奖励胜利者
    void reward();

    //统计从城市获取生命元
    void increaseElements(size_t elements)
    {
        _earnElements+=elements;
    }

    //设置所剩生命元的数量
    void setElements(size_t elements)
    {
        _elements=elements;
    }

    template<typename Iterator>
    void setWarriorCreatingOrder(Iterator beg,Iterator end)
    {
        //设置武士生产顺序
        for(;beg!=end;++beg)
        {
            _warriorCreatingOrder.push_back(*beg);
        }
    }

    size_t getId()const
    {
        return _id;
    }

    void setId(size_t id)
    {
        _id=id;
    }

    Color getColor()const
    {
        return _color;
    }

    size_t getElements()const
    {
        return _elements;
    }

    vector<WarriorPtr> &getWarriors()
    {
        return _warriors;
    }

private:
    //生产各种武士
    WarriorPtr createIceman(size_t id,size_t hp,size_t forces);
    WarriorPtr createLion(size_t id,size_t hp,size_t forces);
    WarriorPtr createWolf(size_t id,size_t hp,size_t forces);
    warriorPtr createNinja(size_t id,size_t hp,size_t forces);
    WarriorPtr createDragon(size_t id,size_t hp,size_t forces);

    void nextWarriorType();

    WarriorType getNextWarriorType()
    {
        return _warriorCreatingOrder[_nextWarriorIndex];
    }

protected:
    Color _color;//红或者蓝
    size_t _id;//编号，0代表红色司令部，N+1代表蓝色司令部
    size_t _elements;//当前司令部所剩的生命元
    size_t _earnElements;//一次战斗结束后，所有武士获取的生命元
    size_t _nextWarriorIndex;//下次生产的武士下标
    vector<WarriorType> _warriorCreatingOrder;//武士生产顺序

    //一次战斗时间结束后，胜利的所有武士
    priority_queue<WarriorPtr,vector<WarriorPtr>,WarriorComparator> _winners;
    vector<WarriorPtr> _warriors;//生产的所有武士

    //各种类型武士的数量
    unordered_map<WarriorType,size_t> _warriorTypeAmounts;
};

class RedHeadquarters:public Headquarters
{
public:
    RedHeadquarters(size_t elements)
        :Headquarters(RED,elements)
    {

    }
};

class BlueHeadquarters:public Headquartes
{
public:
    BlueHeadquarters(size_t elements)
        :Headquarters(BLUE,elements)
    {

    }
};

//设计魔兽世界类(Controller)
class WarcraftWorld
{
public:
    explicit WarcraftWorld()
        :_redHeadquarters(nullptr)
        ,_blueHeadquarters(nullptr)
    {
        init();
    }

    void start()//游戏开始
    {
        while(1)
        {
            createWarrior();
            if(!warriorMarch())
            {
                break;
            }
            cityProduceElements();
            takeCityElements();
            battle();
            headquartersReportElements();
        }
    }

    template<typename Iterator>
        void setRedWarriorCreatingOrder(Iterator beg,Iterator end);

    template<typename Iterator>
        void setBlueWarriorCreatingOrder(Iterator beg,Iterator end);

    ~WarcraftWorld()
    {
        if(_redHeadquarters)
            delete _redHeadquarters;
        if(_blueHeadquarters)
            delete _blueHeadquarters;
    }

private:
    void init();

    //-----------时间begin-----------
    void createWarrior();//整点：创建武士
    bool warriorMarch();//第10分：武士行军
    void cityProduceElements();//第20分：城市生产生命元
    void takeCityElements();//第30分：武士取走城市中的生命元
    void battle();//第40分：战斗
    void headquartersReportElements();//第50分：司令部报告情况
    //-------------事件--------------
    
    bool createWarrior(Headquarters *);//某个司令部开始创建武士
    void warriorMarch(Headquartes *headquarters);//某个司令部中的武士行军

    bool checkRedHeadquartersBetaken();//判断红司令部是否被占领
    bool checkBlueHeadquartersBetaken();//判断蓝司令部是否被占领

private:
    Headquarters *_redHeadquarters;//红色司令部
    Headquarters *_blueHeadquarters;//蓝色司令部
    vector<City> _cities;//所有的城市，其中0号代表红色司令部，size-1代表蓝色司令部

};

    template<typename Iterator>
    void WarcraftWorld::setBlueWarriorCreatingOrder(Iterator beg,Iterator end)
    {
        _blueHeadquarters->setWarriorCreatingOrder(beg,end);
    }


//设计信息显示视图(View)
//武士视图类
class WarriorView
{
public:
    WarriorView(WarriorPtr warrior)
        :_warrior(warrior)
    {

    }

    void showBorn()const;//武士出生时
    void showMarch()const;//武士行军时
    void showEarnElements()const;//武士取走生命元时
    void showReachDestination()const;//武士到达敌方司令部时
protected:
    void showName()const;
    void showToCity()const;
    void showInCity()const;
    void showDeath()const;
    void showElementsAndForces()const;

protected:
    WarriorPtr _warrior;
};

//dragon欢呼视图类
class DragonView:public WarriorView
{
public:
    DragonView(WarriorPtr warrior)
        :WarriorView(warrior)
    {

    }

    //dragon再一次在它主动进攻的战斗结束后，如果还没有战死，就会欢呼
    void showYell()const;
};

//战斗视图类
class BattleView
{
public:
    BattleView(WarriorPtr warrior1,WarriorPtr warrior2)
        :_warrior1(warrior1)
        ,_warrior2(warrior2)
    {

    }

    //武士主动攻击时
    void showBattle()const;
    //武士反击时
    void showDefense()const;
private:
    WarriorPtr _warrior1;
    WarriorPtr _warrior2;
};

//司令部视图类
class HeadquartesView
{
public:
    HeadquartesView(Headquartes *Headquartes)
        :_headquarters(Headquartes)
    {

    }

    //司令部报告情况时
    void showLeftElements()const;

    //司令部被占领时
    void showBeTaken()const;
private:
    Headquartes *_headquarters;
};

//城市视图类
class CityView
{
public:
    CityView(City *city)
        :_city(city)
    {

    }

    //城市更换旗子时
    void showFlag()const;
private:
    City *_city;
};

}//end of namespce warcraftworld

int test0()
{
    //武士生命值设置时的顺序
    vector<WarriorType> types1={
        DRAGON_TYPE,
        NINJA_TYPE,
        ICEMAN_TYPE,
        LION_TYPE,
        WOLF_TYPE,
    };

    //Red武士制造的顺序
    vector<WarriorType> types2={
        ICEMAN_TYPE,
        LION_TYPE,
        WOLF_TYPE,
        NINJA_TYPE,
        DRAGON_TYPE,
    };

    //Blue武士制造的顺序
    vector<WarriorType> types3={
        LION_TYPE,
        DRAGON_TYPE,
        NINJA_TYPE,
        ICEMAN_TYPE,
        WOLF_TYPE
    };

    //先测试游戏配置类
    GameConfig::getInstance()->setWarriorOrder(types1.begin(),types1.end());
    GameConfig::getInstance()->readFromFile("warcraft.conf");
    //GameConfig::getInstance()->readFromFile(argv[1]);
    //GameConfig::getInstance()->readFromConsole();
    GameConfig::getInstance()->debug();

#if 0
    //在测试游戏时间类
    for(int idx=0;idx!=100;++idx)
    {
        GameTime::getInstance()->showTime();
        GameTime::getInstance()->updateTime();
    }
#endif

#if 1
    //然后在测试魔兽世界类
    //测试数据时，先测一组。当一组的数据没有问题之后，在测下一组
    size_t groups=GameConfig::getInstance()->groups();
    for(size_t groupId=0;groupId1=groups;++groupId)
    {
        printf("Case:%lu\n",groupId+1);
        WarcraftWorld wow;
        wow.setRedWarriorCreatingOrder(types2.begin(),types2.end());
        wow.setBlueWarriorCreatingOrder(types3.begin(),types3.end());
        wow.start();

        GameConfig::getInstance()->nextGroupId();
        GameTime::getInstance()->reset();
    }
#endif

    GameConfig::destroy();
    wd::Mylogger::destroy();

    return 0;
}

int main()
{
    test0();
    return 0;
}

