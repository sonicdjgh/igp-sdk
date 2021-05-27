 /**登陆方式

 - MODE_LOGIN_COMMON: 普通登陆方式，对应原接口showLogin
 - MODE_LOGIN_AUTO: 自动登陆方式，对应原接口autoLogin
 - MODE_LOGIN_FAST: 快速登陆方式，在自动登陆基础上，如果玩家第一次登陆游戏，不会弹出sdk页面，直接以游客方式登陆游戏
 -MODE_LOGIN_LIGHTLY:轻量级登录
 */
typedef NS_ENUM(NSInteger, CPLoginType) {
    MODE_LOGIN_COMMON,
    MODE_LOGIN_AUTO,
    MODE_LOGIN_FAST,
    MODE_LOGIN_LIGHTLY
};


typedef NS_ENUM(NSInteger, CPLoginMode) { //适配关闭先关闭登陆页的情况
    LOGINMODE_COMMON,
    LOGINMODE_COLSELOGINVIEW,
};

// @param channel 登录方式："0"表示游客，"1"表示EGLS，“2”表示google，“3”表示facebook, "4"表示微信登陆
typedef NS_ENUM(NSInteger, CPLoginChannel) { //适配关闭先关闭登陆页的情况
    CHANNEL_TOURIST, //游客
    CHANNEL_EGLS, //egls
    CHANNEL_GOOGLE, //google
    CHANNEL_FACEBOOK,//fb
    CHANNEL_WECHAT,
    CHANNEL_GAMECENTER,
    CHANNEL_CR,
    CHANNEL_APPLE,
};

typedef NS_ENUM(NSInteger, ShouldJumpToViewType) {
    ShouldJumpToViewType_UserInfo,
    ShouldJumpToViewType_Charge,
    ShouldJumpToViewType_AppleCharge,
    ShouldJumpToViewType_LastUI,
    ShouldJumpToViewType_CurrentUI
};

typedef NS_ENUM(NSInteger, PassportCountry) {  // 按游戏发行地区进行区分
    PassportCountry_sandbox,
    PassportCountry_cn,     // 大陆
    PassportCountry_tw,     // 台湾
    PassportCountry_kr,     // 韩国
    PassportCountry_jp,     // 日本
    PassportCountry_us,     // 美国
    PassportCountry_ru,
    PassportCountry_th,
    PassportCountry_vn,
    PassportCountry_id, //占位
    //PassportCountry_tw_in99,
};


typedef NS_ENUM(NSInteger, GamePolicy) {  // 按游戏发行地区进行区分
    GamePolicy_sandbox,
    GamePolicy_cn,     // 大陆
    GamePolicy_tw,     // 台湾
    GamePolicy_kr,     // 韩国
    GamePolicy_jp,     // 日本
    GamePolicy_us,     // 美国
    GamePolicy_ru,
    GamePolicy_th,
    GamePolicy_vn,
    GamePolicy_id, //占位
    GamePolicy_tw_in99,
};

//typedef NS_ENUM(NSInteger, PayType) {
//    PAYTYPE_COMMON, //一般充值接口
//    PAYTYPE_CN, //国内
//    PAYTYPE_MC, //myCard
//    PAYTYPE_EC, //绿戒
//    PAYTYPE_EB //蓝心
//};

typedef NS_ENUM(NSInteger, NSUserDefaultsType) {
    NSUserDefaultsType_save,
    NSUserDefaultsType_update,
    NSUserDefaultsType_load,
    NSUserDefaultsType_remove,
};

typedef NS_ENUM(NSInteger, NSObjectType) {
    ObjectType_id,

};


typedef NS_ENUM(NSInteger, LoginType) {
    LoginType_None,
    LoginType_QuickLogin,
    LoginType_EGLS,
    LoginType_Facebook,
    LoginType_Google,
    LoginType_WeChat,
    LoginType_GameCenter,
    LoginType_CR,
    LoginType_Apple,
    LoginType_Line,
};

typedef NS_ENUM(NSUInteger, Locale) {
    Locale_zh_CN,
    Locale_zh_TW,
    Locale_en_US,
    Locale_ja_JP,
    Locale_ko_KR,
    Locale_vi_VN,
    Locale_id_ID,
    Locale_ar_IQ,
    Locale_ar_AE,
    Locale_th_TH,
    Locale_ru_RU,
};


typedef NS_ENUM(NSInteger, EGLSSDKMODE) {
    EGLSSDK_MODEN_COMMON, //默认的正常模式
    EGLSSDK_MODE_LIGHTLY, //轻量级模式 不显示任何弹框
};

typedef NS_ENUM(NSInteger, EGLSSDKBINDMODE) {
    EGLSSDK_BIND_COMMON, //默认的正常模式
    EGLSSDK_BIND_MULTIPLE, //多重绑定
};

typedef NS_ENUM(NSInteger, SUPPORTPHONENUM) {
    NOT, //不支持
    NOT_AEARNUM,//支持不带区号
    AEARNUM, //支持带区号
   
};

typedef NS_ENUM(NSInteger, EGLSSDKBINDFORPAY) {
    BINDFORPAY_NONE,    //不需要提示
    BINDFORPAY_BEFOR,  //支付之前需要绑定
    BINDFORPAY_AFTER,  //支付之后需要提示绑定
    BINDFORPAY_SUBSCRUBE,  //订阅需要绑定
   
};


typedef NS_ENUM(NSInteger, EGLSSDKPAYTYPE) {
    PAYTYPE_COMMON,    //一般支付类型
    PAYTYPE_SUBSCRIBE,  //订阅
};
#define  FLAG_PURCHASE_DEFAULT    0    //默认渠道支付
#define  FLAG_PURCHASE_WEB_MYCARD    1    //Mycard网页支付
#define  FLAG_PURCHASE_WEB_EC    2    //绿界网页支付
#define  FLAG_PURCHASE_WEB_EB  3     //蓝新网页支付


#define  TYPE_USER_ACCOUNT_GUEST    @"0"    //游客
#define  TYPE_USER_ACCOUNT_GOOGLE   @"2"    //Google
#define  TYPE_USER_ACCOUNT_FACEBOOK    @"3"    //Facebook
#define  TYPE_USER_ACCOUNT_WECHAT  @"4"     //微信
#define  TYPE_USER_ACCOUNT_QQ  @"5"     //QQ
#define  TYPE_USER_ACCOUNT_CR  @"6"     //Crunchyroll
#define  TYPE_USER_ACCOUNT_APPLE  @"7"     //苹果
#define  TYPE_USER_ACCOUNT_LINE  @"8"     //line登录


#define  TYPE_USER_BIND_MAIL    0   //邮箱
#define  TYPE_USER_BIND_MOBILE    1   //电话
#define  TYPE_USER_BIND_GOOGLE   2    //Google
#define  TYPE_USER_BIND_FACEBOOK   3    //Facebook
#define  TYPE_USER_BIND_WECHAT  4     //微信
#define  TYPE_USER_BIND_QQ  5     //QQ
#define  TYPE_USER_BIND_CR  6     //Crunchyroll
#define  TYPE_USER_BIND_APPLE  7     //苹果
#define  TYPE_USER_BIND_LINE  8     //line登录
#define  TYPE_USER_BIND_END  9     //bind登录结尾

#define  PLAYERINFO_KEY_IDENTITYNUMBER  @"identityNumber"
#define  PLAYERINFO_KEY_FIREBASE_TOKEN  @"fireBaseToken"

//#define MYBUNDLE_QUOTENAME @"EGLSSDKRES.bundle"
//#define MYBUNDLE_PATH [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:MYBUNDLE_QUOTENAME]
//#define MYBUNDLE [NSBundle bundleWithPath: MYBUNDLE_PATH]
//#define LS(str, nil) NSLocalizedStringFromTableInBundle(str, nil, MYBUNDLE, nil)
