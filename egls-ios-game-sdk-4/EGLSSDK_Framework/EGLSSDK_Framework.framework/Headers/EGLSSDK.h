#import "EGLSSDKDelegate.h"

static NSString * sdkVersion = @"4.1.2";


typedef NS_ENUM(NSInteger, PassportCountry) {  // 按游戏发行地区进行区分
    PassportCountry_sandbox,
    PassportCountry_cn,     // 大陆
    PassportCountry_tw,     // 台湾
    PassportCountry_kr,     // 韩国
    PassportCountry_jp,     // 日本
    PassportCountry_us,     // 美国
    PassportCountry_ru
};
// 工程里配置的地区（Localization native development region）很重要，设备的语言不重要
@interface EGLSSDK : NSObject
@property(assign, nonatomic) id mDelegate;

/**
 * @brief     单例
 * @return    无返回
 */
+ (EGLSSDK *)sharedInstance;

/**
 *	初始化
 *
 *	@param	appID	EGLS平台注册的appID
 *	@param	clientVersion	游戏版本号
 *	@param	passportCountry	游戏所在国家对应的我司passport标识，详见枚举PassportCountry
 *	@param	isDebug	是否打印详细log
 *	@param	delegate	回调用
 *	@param	appleAppID	苹果后台appID（重要！请询问运营。接入Appsflyer的话，需要传）
 *	@param	currencyCode	货币符号（统计用，台湾是@"TWD"，详见网站www.xe.com/iso4217.php）
 *	@param	launchOptions	didFinishLaunchingWithOptions参数launchOptions内容
 */
- (void)sdkInitWithAppID:(NSString *)appID
       withClientVersion:(NSString *)clientVersion
     withPassportCountry:(PassportCountry)passportCountry
             withIsDebug:(BOOL)isDebug
    withCallBackDelegate:(id<EGLSSDKDelegate>)delegate
          withAppleAppID:(NSString *)appleAppID
        withCurrencyCode:(NSString *)currencyCode;

/**
 * @brief     自动登录
 * @description
  若之前登录过，本地存了账号密码，那么会自动登录，不弹出sdk面板；
  若没登录过，弹出登录面板。
 * @return    无返回
 */
- (void)autoLogin;

/**
 * @brief     登录，必定会弹出登录界面
 * @description   可用于切换账号
 * @return    无返回
 */
- (void)showLogin;

/**
 * @brief     国内充值：包含、常用充值卡充值
 * @param     productID    在EGLS平台注册的产品ID
 * @param     amount    充值金额，主要用于不固定金额的充值
 * @param     productName    sdk内展示产品名称
 * @param     extraData    可传自定义参数
 * @return    无返回
 */
- (void)showChargeWithProductID:(NSString *)productID
                     withAmount:(NSString *)amount
                withProductName:(NSString *)productName
                  withExtraData:(NSString *)extraData;
/**
 *	国内充值：包含、常用充值卡充值(EGLS自研游戏用的)
 *
 *	@param	productID
 *	@param	amount
 *	@param	productName
 *	@param	extraData
 *	@param	subgame	游戏区编号
 *	@param	roleID	角色ID
 *	@param	level	角色等级
 *	@param	vipLevel	VIP等级
 */
- (void)showChargeWithProductID:(NSString *)productID
                     withAmount:(NSString *)amount
                withProductName:(NSString *)productName
                  withExtraData:(NSString *)extraData
                    withSubgame:(NSString *)subgame
                     withRoleID:(NSString *)roleID
                      withLevel:(NSString *)level
                   withVipLevel:(NSString *)vipLevel;
/**
 *	苹果充值(不统计数据)
 *
 *	@param	productID	苹果后台配置的productID
 *	@param	extraData	可额外传参，比如接入方的订单号orderID
 */
- (void)applePurchaseWithProductID:(NSString *)productID
                     withExtraData:(NSString *)extraData;

//weixin
//-(void)sendAuthRequest;
/**
 *	苹果充值(韩国统计数据用)
 *
 *	@param	productID	苹果后台配置的productID
 *	@param	extraData	订单号orderID
 *	@param	subgame	游戏区编号
 *	@param	roleID	角色ID
 *	@param	level	角色等级
 *	@param	vipLevel	VIP等级
            price : 商品单价
            productName : 商品名称
            discount : 打折，没有的话，就写 0
            quantity : 购买数量
            currency : 货币单位 KRW = 1,USD = 2,JPY = 3,EUR = 4,GBP = 5,CNY = 6,TWD = 7,HKD = 8
            category : 最多设置 5个阶段的商品分类，各阶段句号(.)隔开
 
 */
- (void)applePurchaseWithProductID:(NSString *)productID
                     withExtraData:(NSString *)extraData
                       withSubgame:(NSString *)subgame
                        withRoleID:(NSString *)roleID
                         withLevel:(NSString *)level
                      withVipLevel:(NSString *)vipLevel
                       productName:(NSString*)productName
                             price:(double)price
                          discount:(double)discount
                          quantity:(NSUInteger)quantity
                          currency:(NSInteger *)currency
                          category:(NSString *)categories
                     extraAttrsMap:(NSString *)extraAttrs;
/**
 *	facebook分享:只分享图片
 *
 */
- (void)facebookShareWithImage:(UIImage*)image;
/**
 *	facebook分享：分享url、图片（不能是本地图片，只能是网络图片）、标题、描述
 *
 */
- (void)facebookShareWithUrl:(NSURL*)url withImageUrl:(NSURL*)imageUrl withTitle:(NSString*)title withContentDescription:(NSString*)contentDescription;

/**
 *    facebook邀请好友
 *
 */
- (void)facebookInviteFriends;

/**
 *	share content to APP line
 *
 *	@return	if open the APP line. Can't ensure the content has been shared successfully.
 */
- (BOOL)lineShareImage:(UIImage*)img;
- (BOOL)lineShareText:(NSString*)str;

// 此接口和FacebookLogin,Live Operation (定向推送）有关
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)dictionary;

// 此接口和FacebookLogin、AppsFlyer有关
- (void)applicationDidBecomeActive:(UIApplication *)application;

 // 此接口和Facebookshare、Google登录有关
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

- (void)applicationWillTerminate:(UIApplication *)application;

#pragma mark optional
/**
 *	设置悬浮窗的透明度，初始化时候设置
 *
 *	@param	alpha	0到1之间，1表示不透明, 默认为0.5
 */
- (void)setFloatButton_alpha:(CGFloat)alpha;
/*
    用户在游戏中的活动
        活动     无空格的英文和数字的字符串
    例如：角色命名       CharacterName
         VIP达到1等级   VIP1
         角色达到8等级   level8
 */
-(void)InAppUserActivities:(NSString *)Activities;
/*
    新用户在游戏中的活动
 活动     无空格的英文和数字的字符串
 例如：角色命名       CharacterName
 VIP达到1等级   VIP1
 角色达到8等级   level8
 */
-(void)firstTime:(NSString *)Experience;
/*
  显示弹窗通知
 */
-(void)showPopupNoti;
/**
 *	设置悬浮窗的初始位置
 *
 *	@param	position	x, y的值为百分比
 x可以是0~100，0表示屏幕左边，100表示屏幕右边
 y可以是0~100,0表示屏幕上面，100表示屏幕下面
 默认为左中（0, 50）
 */
- (void)setFloatButton_position:(CGPoint)position;

/**
 *	弹出用户中心面板，但不是通过 点击悬浮窗上的“用户中心”选项 的方式
 */
- (void)showUserCenter;

/**
 *	登录界面的关闭按钮是否隐藏
 *
 *	@param	hidden	YES时隐藏
 */
- (void)setTheCloseButtonOnLogin_Hidden:(BOOL)hidden;

/**
 *    替换rootViewController
 *
 *    @param    rootVC    被替换的rootViewController
 */
+ (void)setEGLSRootViewController:(UIViewController *)rootVC;

+ (UIView *)getEGLSRootViewController;
@end
