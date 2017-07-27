
//
// c++ 11 size of player  
// 
//
 
#include <memory>
#include <string>
#include <iostream>
#include <unistd.h> 
#include <map>
using namespace std;


#include<time.h>
#include<string.h>
#include <stdint.h>

const int MAX_OPENID_LEN         = 128;
const int MAX_ROLENAME_LEN       = 32;
const int MAX_ROLEPIC_LEN        = 256;
const int MAX_GRID_NUM           = 320; // 320个背包格子,但300超过300个算满
const int MAX_KNIGHT_NUM         = 16;
const int MAX_PET_NUM            = 16;
const int MAX_FRIEND_NUM         = 128;
const int MAX_KNIGHT_EMBED_NUM   = 4;
const int MAX_KNIGHT_EMBED_LEVEL =10;
const int MAX_KNIGHT_EQUIP_NUM   = 5;
const int MAX_KNIGHT_EQUIP_COR   = 5;
const int MAX_LOTTERYS_NUM       = 4;
const int HALF_MAX_LOTTERYS_NUM  = (MAX_LOTTERYS_NUM /2);
const int MAX_TRADE_NUM          = 16;

const int MAX_SCENES           = 300;
const int MAX_CHATPERS         = 32;
const int MAX_GUID_COMPLETED   = 128;
const int MAX_PVPINFO          = 10;
const int MAX_DROP_RECORD      = 10;

const int MAX_MAIL_TITLE_LEN = 32;
const int MAX_MAIL_CONTENT_LEN = 512;
const int MAX_MAIL_ATTACH_NUM = 10;
const int MAX_SYSMAIL_NUM = 128;
const int MAX_ROLEMAIL_NUM = 150;
const int MAX_GROUP_MAIL_NUM = 200;
const int MAX_GROUP_MAIL_RECIEVER_NUM = 5000;

const int PVP_ARENAID_MAX = 4;
const int PVP_ARENAID[PVP_ARENAID_MAX] = {100501, 100502, 100503, 100504};
const int PVP_RESULT[3]  = {-1, 0, 1} ;  // 输 平 赢

const int MAX_HISTORYS = 25;

const int ZOOM_SCORE = 100000;

const int MAX_VIP_LEVEL = 10;  // 包含该值

typedef enum tagEItemType
{
    eCurrency   = 0,    // 货币，可以堆叠
    eKey        = 1,    // 钥匙，可以堆叠
    eKnight     = 2,    // 骑士，不能堆叠
    ePet        = 3,    // 宠物，不能堆叠
    eEquip      = 4,    // 装备，不能堆叠
    eGem        = 5,    // 宝石，可以堆叠
    eProp       = 6,    // 道具，可以堆叠
}EItemType;


//用户状态 0-初始状态 1-数据加载中 2-数据加载成功 3-用户已经登录 4-用户已经退出
typedef enum tagUserStatus
{
    USER_STATUS_INIT                = 0,
    USER_STATUS_LOADING             = 1,
    USER_STATUS_LOADED              = 2,
    USER_STATUS_KO_RSP              = 3,
    USER_STATUS_LOGIN               = 4,
    USER_STATUS_LOGOUT              = 5,
    USER_STATUS_INCONSISTENCY       = 6,
    USER_STATUS_NOEXIST             = 7,    //不存在该用户
}UserStatus;



/////////////////// VIP 配表 //////////////////////////
typedef struct tagVipJsonInfo
{
    int needDiamond;
    int keyCount;
    int coinCount;
    int wipeoutCardCount;
    int diamondWipeout;
    int maxKey;
    int lotteryFlag;
    int bagSpace;
    string strExtraSignReward;
    int equipCoinRatio;
    int dailyCoinLimit;
    int dailyChestLimit;
    int coolDownTime;
    string strVIPGift;
    string strVIPCost;
}VipJsonInfo;

/////////////////// 用户数据 //////////////////////////
//Tencet plat info
typedef struct tagTXPlatInfo
{
    char accessToken[256];
    char payToken[256];
    char pf[256];
    char pfKey[256];
    tagTXPlatInfo()
    {
        memset(this, 0x0, sizeof(tagTXPlatInfo));
    }
}TXPlatInfo;

// 玩家登录信息
typedef struct tagLoginInfo
{
    int      status;            //
    uint64_t last_update_time;  //最后一次更新时间
    uint64_t reg_time;          //注册时间
    uint64_t login_time;        //登录时间
    uint64_t allOnlineTime;     //总在线时长
    uint64_t todayOnlineTime;   //今天总在线时长
    uint64_t lastOnlineTime;    //最近一次在线时间
    TXPlatInfo TXPlat;
    unsigned int userIP;
    unsigned int uiClientPos;
    tagLoginInfo()
    {
        memset(this, 0x0, sizeof(tagLoginInfo));
    }
}LoginInfo;

// 玩家会话信息
typedef struct tagRoleSession
{
    uint64_t validTime;    // 过期时间
    char deviceID[64];     // 设备ID

    tagRoleSession()
    {
        memset(this, 0x0, sizeof(tagRoleSession));
    }
}RoleSession;


// 角色VIP信息
typedef struct tagRoleVip
{
    int firstPay;            // 未使用
    int totalPay;            // 总共充值金额
    int vipLevel;            // 当前VIP等级
    int getVipLv;            // 领取分配VIP奖励

    tagRoleVip()
    {
        memset(this, 0x0, sizeof(tagRoleVip));
    }
}RoleVip;

// 角色基础信息
typedef struct tagRoleBaseInfo
{
    int roleID;                         // 角色ID
    int platform;                       // 平台信息 0--游客; 1--微信; 2--手Q。
    char roleName[MAX_ROLENAME_LEN];    // 角色名称
    char openid[MAX_OPENID_LEN];        // OpenID
    int pic;                            // 头像
    int rename;                         // 重命名次数
    int curKey;                         // 当前钥匙
    int maxKey;                         // 钥匙上限
    int gold;                           // 金币
    int diamond;                        // 钻石
    int score;                          // 积分
    int selKnightID;                    // 当前选择骑士ID
    int selPetID;                       // 当前选择宠物ID,没有则为0
    int acceptKey;                      // 可以接受赠送
    int firstPay;                       // 0首充,1已充值,2已领取

    uint64_t activeTime;                // 创建时间
    uint64_t keyTime;                   // 钥匙上次更新时间
    uint64_t banTime;                   // 封号时间

    RoleVip vip;                        // 角色Vip信息

    int lastScoreTime;                  // 积分最近一交更新时间

    tagRoleBaseInfo()
    {
        memset(this, 0x0, sizeof(tagRoleBaseInfo));
    }
}RoleBaseInfo;

typedef struct tagKnightItem
{
    int    id;                              // 骑士id
    int    level;                           // 等级
    int    starLv;                          // 星级
    int    embed[MAX_KNIGHT_EMBED_NUM];     // 宝石ID
    int    equips[MAX_KNIGHT_EQUIP_NUM];    //默认值为-1, 装备索引 下标0-武器 1-盔甲 2-项链 3-戒指 4-马鞍
    uint64_t time;                          // 解锁时间

    tagKnightItem()
    {
        memset(this, 0x0, sizeof(tagKnightItem));
        for(int i = 0; i < MAX_KNIGHT_EMBED_NUM; i++)
        {
            embed[i] = -1;
        }

        for(int i = 0; i < MAX_KNIGHT_EQUIP_NUM; i++)
        {
            equips[i] = -1;
        }
    }
}KnightItem;

// 骑士信息，不能使用memset
typedef struct tagRoleKnight
{
    KnightItem knightList[MAX_KNIGHT_NUM];
}RoleKnight;

// 玩家宠物
typedef struct tagPetItem
{
    int    id;        // 宠物id
    int    level;     // 等级
    int    starLv;    // 星级
    uint64_t time;    // 解锁时间

    tagPetItem()
    {
        memset(this, 0x0, sizeof(tagPetItem));
    }
}PetItem;

typedef struct tagRolePet
{
    PetItem petList[MAX_PET_NUM];

    tagRolePet()
    {
        memset(this, 0x0, sizeof(tagRolePet));
    }
}RolePet;

// 掉落记录
typedef struct tagDropRecord
{
    int    ItemID;              // 掉落物品ID
    int winCount;            // 本轮赢的次数
    uint64_t lastTime;
}DropRecord;

// 场景数据
typedef struct tagSceneData
{
    int   id;
    int   star;        // 星级
    int   win;         // 胜利次数
    int   count;       // 总次数
    int   dayNum;      // 每日赢的次数定时清零
    uint64_t time;     // 最近战斗时间

    DropRecord records[MAX_DROP_RECORD];    // 掉落记录

    tagSceneData()
    {
        memset(this, 0x0, sizeof(tagSceneData));
    }
}SceneData;

typedef struct tagChapterData
{
    int id;
    int dayNum;       // 每日次数
    uint64_t time;    // 最近战斗时间
    int boxLv;        // 领取宝箱级别
}ChapterData;

// 角色战斗信息
typedef struct tagRoleBattle
{
    uint64_t      lastResetTime;          // 上次重置时间
    SceneData     scenes[MAX_SCENES];
    ChapterData   chapters[MAX_CHATPERS];

    tagRoleBattle()
    {
        memset(this, 0x0, sizeof(tagRoleBattle));
    }
}RoleBattle;


typedef struct tagTaskItem
{
    int id;
    int state;
    tagTaskItem()
    {
        id = 0;
        state = 0;
    }
}TaskItem;

typedef struct tagActivityItem
{
    int id;
    int state;
    tagActivityItem()
    {
        id = 0;
        state = 0;
    }
}ActivityItem;

// 角色任务
typedef struct tagRoleTask
{
     TaskItem taskList[480];  // 所有成就
}RoleTask;

typedef struct tagActivityReward
{
	int id;                       // ID
	int num;                      // 当前累计的数量 当为-1时 说明已经完成。
	int lasttime;                 // 活动最后时间， 如果过了这个时间，可以清除掉这结构
	tagActivityReward()
	{
		memset(this, 0x0, sizeof(tagActivityReward));
	}
    void Clear()
    {
    	memset(this, 0x0, sizeof(tagActivityReward));
    }
}ActivityReward;


// 角色每日活动
typedef struct tagRoleActivity
{
    ActivityItem   activityList[50];  // 所有成就
    ActivityReward actReward[50];
}RoleActivity;

// 角色签到
typedef struct tagRoleSign
{
    int year;     // 年
    int month;    // 月
    int day[31];  // 日

    tagRoleSign()
    {
        memset(this, 0x0, sizeof(tagRoleSign));
    }

    void Clear()
    {
        memset(this, 0x0, sizeof(tagRoleSign));
    }
}RoleSign;


// 玩家匹配信息
typedef struct tagRoleMatch
{

    int roleID;                     // 角色ID
    int arenaID;                    // 匹配的竞技场ID
    char name[MAX_ROLENAME_LEN];    // 角色昵称
    int pic;                        // 角色头象

    int selKinight;                 // 出战骑士
    int selPet;                     // 出战宠物
    int ability;                    // 能力值
    int beginTime;                  // 开始匹配时间

    tagRoleMatch()
    {
        memset(this, 0x0, sizeof(tagRoleMatch));
    }
}RoleMatch;



// pvp信息

typedef struct tagPvpInfo
{
    int win;              // 赢场次
    int lose;             // 输场次
    int draw;             // 平场次
    int escape;           // 逃跑次
    int last;             // 上次输赢
    int matchID;          // 当前匹配竞技场ID
    int atomic;           // 原子统计用来判断是否已经被别人修改过

    RoleMatch matchInfo;  // 最近的匹配信息

    tagPvpInfo()
    {
        memset(this, 0x0, sizeof(tagPvpInfo));
    }
}PvpInfo;

 // 角色PVP
typedef struct tagRolePvP
{
    PvpInfo  pvpInfo[MAX_PVPINFO];
    tagRolePvP()
    {
        memset(this, 0x0, sizeof(tagRolePvP));
    }
}RolePvP;

// 基本表格
typedef struct tagGrid
{
    int itemID;         // 物品ID
    int itemNum;        // 物品数量
    int pos;            // 背包位置
    int type;           // 物品类型
    uint64_t time;      // 时间

    int level;     // 等级
    int wear;      // 是否穿戴,不为0表示骑士ID
    int exp;       // 当前经验值

    tagGrid()
    {
        memset(this, 0x0, sizeof(tagGrid));
    }

    void Clear()
    {
        memset(this, 0x0, sizeof(tagGrid));
    }

}Grid;


// 用户背包
typedef struct tagRoleBag
{
    int openGridNum;            // 开启的格子数,无用字段
    int rdProp;                 // 无尽模式随机物品
    Grid grid[MAX_GRID_NUM];    // 物品

    tagRoleBag()
    {
        memset(this, 0x0, sizeof(tagRoleBag));
    }
}RoleBag;

// 宝箱信息
typedef struct tagLotteryInfo
{
    int       type;         // 保箱类型
    int       freeCount;    // 抽取次数
    uint64_t  lastTime;     // 宝箱上次抽取时间
    bool      isFree;       // 是否免费

    tagLotteryInfo()
    {
        memset(this, 0x0, sizeof(tagLotteryInfo));
    }
}LotteryInfo;


// 抽奖角色信息
typedef struct tagLotteryRole
{
    LotteryInfo lotterys[MAX_LOTTERYS_NUM];         // 抽奖类型
    int diamond[HALF_MAX_LOTTERYS_NUM];            // 累计钻石
    int priority[HALF_MAX_LOTTERYS_NUM];           // 当前优先级
    tagLotteryRole()
    {
        memset(this, 0x0, sizeof(tagLotteryRole));
    }

}LotteryRole;

typedef struct tagTradeItem
{
    int id;         // 交易ID
    int count;      // 当天交易次数
    int totalCount; // 总交易次数
    tagTradeItem()
    {
        memset(this, 0x0, sizeof(tagTradeItem));
    }

    void ClearDailyData()
    {
        count = 0;
    }
}TradeItem;

typedef struct tagTradeInfo
{
    TradeItem tradeList[MAX_TRADE_NUM];

    tagTradeInfo()
    {
        memset(this, 0x0, sizeof(tagTradeInfo));
    }
}TradeInfo;

// 角色新手引导
typedef struct tagRoleGuide
{
    char allGuid[MAX_GUID_COMPLETED]; // 所有新手引导
    tagRoleGuide()
    {
        memset(this, 0x0, sizeof(tagRoleGuide));
    }
}RoleGuide;

// 角色好友信息
typedef struct tagFriendData
{
    int commID;                         // openID hash
    int roleID;                         // 角色ID
    int index;                          // 客户端序号
    char name[MAX_ROLENAME_LEN];        // 昵称
    int pic;                            // 头像
    uint64_t keyTime;                   // 下次赠该好友钥匙时间
    bool acceptKey;                     // 是否接受钥匙
    int vipLevel;                       // 好友vip等级

    tagFriendData()
    {
        memset(this, 0x0, sizeof(tagFriendData));
    }

    void Clear()
    {
        memset(this, 0x0, sizeof(tagFriendData));
    }
}FriendData;

// 角色好友信息
typedef struct tagRoleFriend
{
    FriendData friendList[MAX_FRIEND_NUM];
    tagRoleFriend()
    {
        memset(this, 0x0, sizeof(tagRoleFriend));
    }
}RoleFriend;

// 用户统计基础数据
typedef struct tagBaseStaticField
{

    int KillBoss;         // 击杀Boss
    int RunDistance;      // 跑总公里数
    int RunScore;         // 跑的总积分
    int CollectCoin;      // 收集金币
    int CollectDiamond;   // 收集钻石
    int LotteryBox;       // 抽取宝箱
    int EndlessBox;       // 无尽模式掉落宝箱
    int PracticeBox;      // 试炼模式掉落宝箱
    int BattleBox;        // 战役模式掉落宝箱
    int BattleSweep;      // 战役扫荡

    void Clear()
    {
        memset(this, 0x0, sizeof(tagBaseStaticField));
    }

    tagBaseStaticField()
    {
        memset(this, 0x0, sizeof(tagBaseStaticField));
    }

}BaseStaticField;

// 历史最高数据统计
typedef struct tagStatisHighestField
{

    int FightValue;        // 战斗力最高
    int GemLevel;          // 获取i级宝石等级
    int PracticeSceneLv;   // 活动试练关卡
    int IDKnightLevel;     // 骑士最高等级
    int IDPetLevel;        // 宠物最高等级
    int IDKnightStarLv;    // 指定骑士最高星级
    int IDPetStarLv;       // 指定宠物最高星级
    int IDSceneLevel;      // 指定关卡过关难度等级
    int IDChapterLevel;    // 章节通关难度等级

    BaseStaticField baseStaticData;
    tagStatisHighestField()
    {
        memset(this, 0x0, sizeof(tagStatisHighestField));
    }
}StatisHighestField;

// 用户历史总数数据统计
typedef struct tagStatisTotalField
{

    int FullKnight;                         // 满级骑士总数
    int FullPet;                            // 满级宠物总数
    int GivingKey;                          // 赠送给别人钥匙总数
    int ReceiveKey;                         // 钥匙获取次数
    int EndlessModel;                        // 无尽模式次数
    int PosGemLv[MAX_KNIGHT_EMBED_NUM][MAX_KNIGHT_EMBED_LEVEL];   // 指定类型等级宝石的数量
    int PosEquipCor[MAX_KNIGHT_EQUIP_NUM][MAX_KNIGHT_EQUIP_COR];  // 指定类型颜色装备的数量
    int Lottery2Box;                        // 抽取黄金宝箱1抽次数
    int KaifuReward;                        // 开服领取奖励次数
    int InviteFriendTotal;                  // 邀请好友个数。 这个数据应该放每日数据中，现在弃用。 借用GM控制签到天数
    int BindAccountTotal;                   // 绑定帐号的次数

    BaseStaticField baseStaticData;
    tagStatisTotalField()
    {
        memset(this, 0x0, sizeof(tagStatisTotalField));
    }
}StatisTotalField;

// 用户每日数据统计
typedef struct tagStatisDailyField
{
    int NormalSceneCount;           // 完成普通难度
    int HeroSceneCount;             // 完成英雄难度
    int PracticeSceneCount;         // 活动试练关卡
    int ActivityCount;              // 完成xxxx活动
    int TimeFreekeyCount;           // 指定时间内领取钥匙
    int KnightUpLevelCount;         // 骑士升级
    int KnightUpStarCount;          // 骑士升星
    int PetUpLevelCount;            // 宠物升级
    int PetUpStarCount;             // 宠物升星
    int EndlessModelCount;          // 无尽模式次数
    int GivingKeyTimes;             // 赠送好友钥匙数量
    int ReceiveKeyTimes;            // 接收好友钥匙数量
    int EndlessDropCoin;            // 无尽模式掉落金币数量
    int EndlessDropChest;           // 无尽模式掉落宝箱数量
    int GivingKeyCount;             // 赠送好友钥匙
    int UpdateQuipdyCount;          // 当日升级级装备次数
    int FBGiveMailCount;            // 领取facebook好友送物品的邮件个数量
    int InviteFriendTotal;          // 邀请好友个数
    BaseStaticField baseStaticData;
    tagStatisDailyField()
    {
        memset(this, 0x0, sizeof(tagStatisDailyField));
    }
    void Clear()
    {
        memset(this, 0x0, sizeof(tagStatisDailyField));
    }
}StatisDailyField;

//TODO:
typedef struct tagStatisGlobalField
{
    uint64_t nextDailyResetTime;    // 下次基本数据重置时间
    uint64_t nextBattleResetTime;   // 下次副本数据重置时间
    uint64_t nextDailyIssueTime;    // 下次上线邮件重置时间,目前未使用
    uint64_t nextKaifuRewardTime;   // 下次开服奖励领取时间
    uint64_t nextSignInTime;        // 下次强制刷新签到时间

    tagStatisGlobalField()
    {
        memset(this, 0x0, sizeof(tagStatisGlobalField));
    }
}StatisGlobalField;

// 战斗临时数据
typedef struct tagBattleSnap
{

    int sceneID ;        // 关卡ID
    int resurrectNum;    // 复活次数
    uint64_t lastTime;   // 上次操作时间
    int state;
    tagBattleSnap()
    {
        memset(this, 0x0, sizeof(tagBattleSnap));
    }

    void Clear()
    {
        memset(this, 0x0, sizeof(tagBattleSnap));
        //this->sceneID =  INVALID_ID;
        state = 0;
        this->sceneID =  -1;
    }
}BattleSnap;

typedef struct tagExtractField
{
    uint64_t dirtyFlag;      //记录更新的数据块
    int      sequence;      //记录已更新次数

    tagExtractField()
    {
        memset(this, 0x0, sizeof(tagExtractField));
    }
}ExtractField;

//////////////////////////////////OSS 统计分析 beign //////////////////
typedef struct tagOssInfo
{
    int clientip;                   //客户端IP
    int channelid;                  //渠道号
    char version[10];               //客户端程序版本如 1.01
    char  imei[20] ;                //imei号,必填
    int  nettype;                   //设置网络类型 3G = 1；WIFI = 2;2G = 3; 4G = 4; OTHER = 100
    char mac[30] ;                  //mac 地址
    char  brand[20] ;               //品牌
    char language[10] ;             //语言
    char osversion[10] ;            //操作系统版本
    char  resolution[20] ;          //分辨率
    char operators ;                //运营商;0--其它 1--移动 2--联通 3--电信
    char province[128];             //省份
    char country[128];              //国家
    time_t login_time;              //登录时间
    int login_type;                 //登录类型     0- 登录 1-重登录 2-注册
 }OssInfo;
//////////////////////////////////end////////////////////////////////////

// 角色信息
typedef struct tagRoleInfo
{
    LoginInfo    login;
    RoleSession  session;                // 角色Session信息

    RoleBaseInfo base;                   // 基础信息
    RoleKnight   knight;                 // 骑士
    RolePet      pet;                    // 宠物
    RoleBattle   battle;                 // 关卡

    RoleTask     task;                   // 角色任务
    RoleActivity activity;               // 角色每日活动
    RoleSign     sign;                   // 角色签到

    RolePvP      pvp;                    // PVP
    RoleBag      bag;                    // 背包
    LotteryRole  lottery;                // 抽奖
    TradeInfo    tradeInfo;              // 交易信息
    RoleGuide    guide;                  // 角色新手引导
    RoleFriend   roleFriend;             // 好友

    StatisHighestField  highestField;   // 历史最高数据统计
    StatisTotalField    totalField;     // 用户历史总数数据统计
    StatisDailyField    dailyField;     // 用户每日数据统计
    StatisGlobalField   globalField;    // 刷新时间

    BattleSnap  battleSnap;             // 关卡快照，不回写数据库
    OssInfo Oss;                        //统计数据, 不回写数据库

    ExtractField extField;              // 额外数据

}RoleInfo;

///////////////////////////////////////////////////////////////
//邮件
//邮件附件
typedef struct tagEmailAttach
{
    int itemID;
    int itemNum;

    tagEmailAttach()
    {
        memset(this, 0x0, sizeof(tagEmailAttach));
    }
}EmailAttach;

//邮件数据结构
typedef struct tagMailInfo
{
    int emailID;                            // 邮件ID
    int type;                               // 0,公告  1,系统邮件  2,好友邮件
    int behavior;                           // 0,领取后立即删除  1,置顶  2,置底  3,保持原位
    int state;                              // 0,新邮件  1,已读邮件  2,已经领取  3,已经删除
    int senderID;                           // 发送者ID
    char senderName[MAX_ROLENAME_LEN];      // 发送者昵称
    char title[MAX_MAIL_TITLE_LEN];         // 标题
    char content[MAX_MAIL_CONTENT_LEN];     // 正文
    int beginTime;                          // 邮件发送时间
    int endTime;                            // 邮件到期时间
    EmailAttach attach[MAX_MAIL_ATTACH_NUM];// 附件

    tagMailInfo()
    {
        memset(this, 0x0, sizeof(tagMailInfo));
    }

    void Clear()
    {
        memset(this, 0x0, sizeof(tagMailInfo));
    }
}MailInfo;


typedef struct tagSysMailItem
{
    int emailID;    // 邮件ID
    int state;      // 0,新邮件  1,已读邮件  2,已经领取  3,已经删除

    tagSysMailItem()
    {
        memset(this, 0x0, sizeof(tagSysMailItem));
    }
}SysMailItem;

typedef struct tagRoleMail
{
    int roleID;
    int initID;
    int initTime;
    bool acceptKey;
    MailInfo info[MAX_ROLEMAIL_NUM];
    SysMailItem sysInfo[MAX_SYSMAIL_NUM];

    tagRoleMail()
    {
        memset(this, 0x0, sizeof(tagRoleMail));
    }
}RoleMail;


typedef struct tagSysMailInfo
{
    int emailID;                            // 邮件ID,目前是邮件发送时间戳
    int state;                              // 0有效 1删除
    char title[MAX_MAIL_TITLE_LEN];         // 标题
    char content[MAX_MAIL_CONTENT_LEN];     // 正文
    int beginTime;                          // 邮件发送时间
    int validTime;                          // 邮件有效时间
    int behavior;                           // 0,领取后立即删除  1,置顶  2,置底  3,保持原位
    int newRoleValid;                       // 0,表示新用户不生效  1,表示新用户也生效
    EmailAttach attach[MAX_MAIL_ATTACH_NUM];//附件

    tagSysMailInfo()
    {
        memset(this, 0x0, sizeof(tagSysMailInfo));
    }

    void Clear()
    {
        memset(this, 0x0, sizeof(tagSysMailInfo));
    }
}SysMailInfo;

typedef struct tagSysMail
{
    int initTime;                       // 避免ID冲突,记录最近一封邮件的时间戳
    SysMailInfo info[MAX_SYSMAIL_NUM];  // 系统邮件

    tagSysMail()
    {
        memset(this, 0x0, sizeof(tagSysMail));
    }
}SysMail;

typedef struct tagReciever
{
    int roleID;
    char state;
    int rank;

    tagReciever()
    {
        memset(this, 0x0, sizeof(tagReciever));
    }
}Reciever;

typedef struct tagGroupMail
{
    int emailID;                            // 邮件ID,目前是邮件发送时间戳
    char title[MAX_MAIL_TITLE_LEN];         // 标题
    char content[MAX_MAIL_CONTENT_LEN];     // 正文
    int beginTime;                          // 邮件发送时间
    int validTime;                          // 邮件有效时间
    int behavior;                           // 0,领取后立即删除  1,置顶  2,置底  3,保持原位

    EmailAttach attach[MAX_MAIL_ATTACH_NUM];        //附件

    int recieverNum;                                // 接收者人数
    Reciever reciever[MAX_GROUP_MAIL_RECIEVER_NUM]; // 接收者

    tagGroupMail()
    {
        memset(this, 0x0, sizeof(tagGroupMail));
    }
}GroupMail;


///////////////////////////////////////////////////////////////
// 竞技场记录

typedef struct tagFighterInfo
{
    int roleID;
    char name[MAX_ROLENAME_LEN];
    //char picUrl[MAX_ROLEPIC_LEN];
    int  pic;
    int ability;               // 当时能力值
    float scoreGain;             // 积分加成
    int selKnight;             // 当时参战的骑士
    int selPet;                // 当时参战的宠物
    int score;                 // 竞技积分
    int process;              // 进度 0未结束 1结束 2延迟 3结算 4超时 5掉线
    int result;                // 比赛结果 -1 失败 0 平局 1 胜利
    int reward;                // 奖励结果0未领取 1领取
    int deduct;                // 是否完成门票扣除
    int vipLevel;              // vipLevel
	tagFighterInfo()
    {
        memset(this, 0x0, sizeof(tagFighterInfo));
    }
}FighterInfo;

typedef struct tagPVPRecords
{
    int    matchID;           // 匹配ID
    int    areanID;           // 竞技场ID
    time_t beginTime;         // 开始时间
    time_t endTime;           // 结束时间
    time_t delayTime;         // 延迟结算时间
    int    matchType;         // 匹配类型  实时在线，对战离线，对战机器人

    FighterInfo fighters[2];   // 0-self 1-enemy
    tagPVPRecords()
    {
        memset(this, 0x0, sizeof(tagPVPRecords));
    }
    void Clear()
    {
        memset(this, 0x0, sizeof(tagPVPRecords));
    }

}PVPRecords;

typedef struct tagMatchInfo
{
    int  roleID;
    char name[MAX_ROLENAME_LEN];
    char picUrl[MAX_ROLEPIC_LEN];
    int  pic;
    int  ability;
    int  matchID;             // 匹配ID
    int  areanaID;            // 竞技场ID
    float  scoreGain;
    int  selKnightID;
    int  selPetID;
    int  grade;

    time_t beginTime;        // 开始时间
    int    state;
    int    busDestID;        // 大区ID
    int    sn;
    int    vipLevel;

    tagMatchInfo()
    {
        memset(this, 0x0, sizeof(tagMatchInfo));
    }
    void CopyFrom(const tagMatchInfo& one)
    {
        memcpy(this, &one, sizeof(tagMatchInfo));
    }
    void Clear()
    {
        memset(this, 0x0, sizeof(tagMatchInfo));
    }
}MatchInfo;

typedef struct tagPvPSnap
{
    int curProcess;        // 进度  0-未结束 1-结束 2-延迟 3-结算 4-超时 5-掉线
    int curMatchID;        // 当前匹配ID
    tagPvPSnap()
    {
        memset(this, 0x0, sizeof(tagPvPSnap));
    }
    void CopyFrom(const tagPvPSnap& one)
    {
        memcpy(this, &one, sizeof(tagPvPSnap));
    }
    void Clear()
    {
        memset(this, 0x0, sizeof(tagPvPSnap));
    }

}PvPSnap;

// 角色PVP
typedef struct tagDBRolePvP
{
    int roleID;
    char name[MAX_ROLENAME_LEN];
    //char picUrl[MAX_ROLEPIC_LEN];
    int pic;
    PvPSnap snap;
    int win;              // 赢场次数
    int lost;             // 输场次数
    int draw;             // 和场次数
    int escape;           // 逃跑次数
    int last;             // 上次输赢

    PVPRecords historys[MAX_HISTORYS];
    tagDBRolePvP()
    {
        memset(this, 0x0, sizeof(tagDBRolePvP));
    }
}DBRolePvP;

typedef map<int, MatchInfo> GRADE_ROLEID_MAP;  // <grade, roleid>  <段位, 匹配信息>
typedef map<string, GRADE_ROLEID_MAP>  MATCH_MAP;  // <arenaid_result, <grade, roleid> >  <竞技场ID_输赢结果，<段位, 角色ID> >


/////////////////////////////////////////////////////////////////////////////

int main ()
{
	int n = sizeof(RoleInfo);
	printf("n=%d\n", n/1024);
	return 0;
}
