#import "EGLSSDKDelegate.h"
#import "EGLSSDKLoginManager.h"
#import "EGLSSDKStaticData.h"


static NSString * sdkVersion = @"4.8.3";



@interface EGLSSDK : NSObject
@property(assign, nonatomic) id mDelegate;

/**
 * @brief     单例
 * @return    无返回
 */
+ (EGLSSDK *)sharedInstance;

/**
 *    初始化
 *
 *    @param    appID    EGLS平台注册的appID
 *    @param    clientVersion    游戏版本号
 *    @param    passportCountry    游戏所在国家对应的我司passport标识，详见枚举PassportCountry
 *    @param    isDebug    是否打印详细log
 *    @param    delegate    回调用对象
 */
- (void)sdkInitWithAppID:(NSString *)appID
       withClientVersion:(NSString *)clientVersion
     withPassportCountry:(PassportCountry)passportCountry
             withIsDebug:(BOOL)isDebug
    withCallBackDelegate:(id<EGLSSDKDelegate>)delegate;





/**
 轻量级登录

 @param accountType 登录类型
 */
-(void)channelLoginLightly:(NSString*)accountType;


/**
手机号 登录

@param mobile 手机号
@param passWord 密码
*/
-(void)mobileLoginLightly:(NSString*)mobile passWord:(NSString *) password;
/**
 邮箱 登录
@param mail 电子邮箱
@param passWord 密码
*/
-(void)mailLoginLightly:(NSString*)mail passWord:(NSString *) password;


/**
 轻量级绑定

 @param accountType accountType 绑定类型
 */
-(void)channelBindLightly:(NSString*)accountType;



/**
  手机号绑定验证

 @param mobile  手机号码
 */
-(void)mobileBindVerifyLightly:(NSString*)mobile;

/**
邮箱绑定验证

 @param mail  邮箱验证
 */
-(void)mailBindVerifyLightly:(NSString*)mail;


/**
 手机号绑定请求

 @param mobile  手机号
 @param verificationCode  验证码
 @param password  密码
 */
-(void)mobileBindRequestLightly:(NSString*)mobile verificationCode:(NSString*)verificationCode passWord:(NSString*)password;


/**
 邮箱绑定请求

 @param mail  邮箱号
 @param verificationCode  验证码
 @param password  密码
 */
-(void)mailBindRequestLightLy:(NSString*)mail verificationCode:(NSString*)verificationCode passWord:(NSString*)password;

/**
手机号注册验证
@param mobile  手机号
*/

-(void)mobileRegisterVerifyLightly:(NSString*) mobile;

/**
邮箱注册验证
@param mobile  手机号
*/

-(void)mailRegisterVerifyLightly:(NSString*) mail;


/**
手机注册请求
@param mobile  手机号
@param verificationCode  验证码
@param passWord  密码
*/

-(void)mobileRegisterRequestLightly:(NSString*) mobile verificationCode:(NSString*)verificationCode passWord:(NSString*)password;

/**
邮箱注册请求
@param mail  邮箱
@param verificationCode  验证码
@param passWord  密码
*/

-(void)mailRegisterRequestLightly:(NSString*) mail verificationCode:(NSString*)verificationCode passWord:(NSString*)password;

/**
密码修改
@param passWord  密码
*/
-(void)pwdModifyLightly:(NSString*)password;

/**
密码重置鉴权
@param userAccount  账号（手机号/邮箱）
*/
-(void)pwdResetCaptchaLightly:(NSString*)userAccount;


/**
密码重置鉴权
@param type 0 邮箱 1 手机号
@param userAccount  账号（手机号/邮箱）
*/

-(void)pwdResetCaptchaLightly:(int)type andUser:(NSString*)userAccount;
/**
密码重置请求
@param userAccount  账号（手机号/邮箱）
 @param captcha  鉴权码
*/
-(void)pwdResetRequestLightly:(NSString*)userAccount captcha:(NSString*) captcha;


/**
 轻量级支付
 @param amount  金额（手机号/邮箱）
 @param productId  档位编号
 @param productName  档位名称
 @param orderInfo  订单信息
 @param flag  支付标识
                    PAYTYPE_COMMON, //一般充值接口
                    PAYTYPE_MC, //myCard
                    PAYTYPE_EC, //绿戒
                    PAYTYPE_EB //蓝心
                    
*/
-(void)channelPurchaseLightly:(NSString *)amount productId:(NSString*)productId productName:(NSString*)productName
                    orderInfo:(NSString*)orderInfo flag:(int)falg;
/**
 切换账号
 */
- (void)eglsSwitch;

/**
 账号登出 
 */
- (void)eglsLogOut;
/**
 主动调用游客绑定
 */
- (void)eglsGuestBind;

/**
 新的登陆接口，集成了以往2种登陆方式autoLogin与showLogin

 @param type 登陆方式，参见 NS_ENUM(NSInteger, CPLoginType)
 */
- (void)eglsLogin:(CPLoginType)type;

/**
 
 根据sdk存档进行登录,无存档调用common显示ui
 @param channle  渠道号
 */

- (void)eglsLoginForData:(NSString*)channle;

/**
 玩家信息提交接口,一般自研游戏需要在充值前调用
*    @param    subgame    游戏区编号
*    @param    roleID    角色ID
*    @param    level    角色等级
*    @param    vipLevel    VIP等级
*/
-(void)updateRoleData:(NSString * )subgame
              roleID:(NSString *)roleID
              level:(NSString *)level
              vipLevel:(NSString *)vipLevel;

/**
*    公共充值接口
*    @param    payType   FLAG_PURCHASE_DEFAULT, //一般充值接口
                  FLAG_PURCHASE_WEB_MYCARD, //myCard
                  FLAG_PURCHASE_WEB_EC //绿戒
                  FLAG_PURCHASE_WEB_EB  3     //蓝新网页支付
 
*    @param    productID    苹果后台配置的productID
*    @param    extraData    订单号orderID,不可含有"|","=","@"
*    @param    productName  商品名称
*    @param    price        商品单价
 */
- (void)applePurchaseCommunal:(int)payType //公共充值接口
                    productID:(NSString *)productID
                    orderID:(NSString *)extraData
                    productName:(NSString*)productName
                    price:(NSString*)price;



/**
*    公共充值接口
*    @param    payType   FLAG_PURCHASE_DEFAULT, //一般充值接口
                  FLAG_PURCHASE_WEB_MYCARD, //myCard
                  FLAG_PURCHASE_WEB_EC //绿戒
                  FLAG_PURCHASE_WEB_EB  3     //蓝新网页支付
 
*    @param    productID    苹果后台配置的productID
*    @param    extraData    订单号orderID,不可含有"|","=","@"
*    @param    productName  商品名称
*    @param    price        商品单价
 */
- (void)applePurchaseSubscribe:(int)payType //公共充值接口
                    productID:(NSString *)productID
                    orderID:(NSString *)extraData
                    productName:(NSString*)productName
                    price:(NSString*)price;

/**
*    恢复购买
*    @param    mode   0, SKReceiptRefreshRequest//刷新支付凭证 并不产生新订单
                1, restoreCompletedTransactions//把所用订单从新购买,但不产生付费
                2, restoreCompletedTransactionsWithApplicationUsername//把满足条件的订单从新购买,但不产生付费
            

*    @param    userName    只有在mode 为2时产生作用  个状态均可为nil
*/
-(void)resumePurchaseFormApple:(int) mode withUserName:(NSString*) userName;

/**
 *    facebook分享:只分享图片
 *
 */
- (void)facebookShareWithImage:(UIImage*)image;
/**
 *    facebook分享：分享url、图片（不能是本地图片，只能是网络图片）、标题、描述
 *
 */
- (void)facebookShareWithUrl:(NSURL*)url withImageUrl:(NSURL*)imageUrl withTitle:(NSString*)title withContentDescription:(NSString*)contentDescription;

/**
 *    facebook邀请好友
 *
 */
- (void)facebookInviteFriends;

/**
 *    玩家信息
 *
 */
- (void)facebookUserInfo;


/**
 *    玩家好友列表
 *
 */
- (void)facebookFriendList;

/**
 *    share content to APP line
 *
 *    @return    if open the APP line. Can't ensure the content has been shared successfully.
 */
- (BOOL)lineShareImage:(UIImage*)img;
- (BOOL)lineShareText:(NSString*)str;

// 此接口和FacebookLogin,Live Operation (定向推送）wechatLogin 有关
// 重要：此接口在4.4.6以后与获取网络权限有关，请接入否则SDK无法登录
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)dictionary;

// 此接口和FacebookLogin、AppsFlyer有关
- (void)applicationDidBecomeActive:(UIApplication *)application;

 // 此接口和Facebookshare、Google登录有关
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;


//- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

- (void)applicationWillTerminate:(UIApplication *)application;

#pragma mark optional
/**
 *    设置悬浮窗的透明度，初始化时候设置
 *
 *    @param    alpha    0到1之间，1表示不透明, 默认为0.5
 */
- (void)setFloatButton_alpha:(CGFloat)alpha;


/**
 设置悬浮窗是否显示

 @param showEnable YES:显示 NO:不显示
 */
+ (void)setFloatButton_show:(BOOL)showEnable;



/**
 设置登出按钮是否隐藏

 @param showEnable YES:隐藏 NO:显示
 */

+ (void)setLoginOutOnFloatButon:(BOOL)showEnable;
/**
 *    设置悬浮窗的初始位置
 *
 *    @param    position    x, y的值为百分比
 x可以是0~100，0表示屏幕左边，100表示屏幕右边
 y可以是0~100,0表示屏幕上面，100表示屏幕下面
 默认为左中（0, 50）
 */
- (void)setFloatButton_position:(CGPoint)position;

/**
 *    弹出用户中心面板，但不是通过 点击悬浮窗上的“用户中心”选项 的方式
 */
- (void)showUserCenter;

/**
 *    登录界面的关闭按钮是否隐藏
 *
 *    @param    hidden    YES时隐藏
 */
- (void)setTheCloseButtonOnLogin_Hidden:(BOOL)hidden;

/**
 *    替换rootViewController
 *
 *    @param    rootVC    被替换的rootViewController
 */
+ (void)setEGLSRootViewController:(UIViewController *)rootVC;



/**
 @return setEGLSRootViewController中设置的controller,如果没有设置默认为[[UIApplication sharedApplication] keyWindow].rootViewController
 */
+ (UIViewController *)getEGLSRootViewController;



/**
 @return setEGLSRootViewController中设置的controller.view,如果没有设置默认为[[UIApplication sharedApplication] keyWindow].rootViewController.view
 */
+ (UIView *)getEGLSRootViewControllerView;


/**
 设置登陆后Banner是否隐藏更换账号按钮
 更换账号按钮是玩家在任何登陆方式成功之后可以在banner显示时间内点击banner里的“switch”按钮来重新切换到登陆面板，是一种方便的切换登陆方式
 但是要注意如果玩家在短时间内第二次登陆成功，就又会有一个登陆回调产生，这时游戏要做好相应准备，防止崩溃和错误

 @param hide 默认为YES 隐藏切换按钮，不开启切换功能 NO:显示切换按钮，开启切换功能
 */
+ (void)setBannerSwitchHidden:(BOOL)hide;

/**
 *    显示韩国naver论坛页面
 */

+ (void)NaverControllerShow;

/**
 *    显示igaw积分墙
 */

+ (void)didClickOpenOfferwallBtn;

/**
 *    系统通知类，igaw相关
 *
 */

- (BOOL)application:(UIApplication*)app openURL:(NSURL *)url options:(NSDictionary *)options;
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;
- (void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification *)notification;
- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;
/**
 通过第三方分享

 @param type 1031 微信 1032 微博 1033 qq分享 1034 facebook 1035 line 1036 naver
 @param title 标题
 @param text 描述
 @param image 图片全路径
 @param link 链接
 @param isTL 微信是否分享到朋友圈
 */
- (void)shareWithType:(int)type withTitle:(NSString *)title withText:(NSString *)text withImage:(NSString *)image withLink:(NSString *)link isTimeLine:(BOOL)isTL;


/**
 五星好评运营活动接口
 */
- (void)ratingActivity;


/**
 facebook运营活动接口

 @param enableJoinfans 请求加入粉丝圈活动
 @param enableShare 请求每日分享活动
 */
- (void)facebookActivity:(BOOL)enableJoinfans withEnableShare:(BOOL)enableShare;


/**
 line分享运营活动
 */
- (void)linePromotionActivity;



/**
数据统计额外参数    目前继承的还不需要

@param dataKey 事件名字
@param data 事件内容，json格式
*/
+ (void)collectionServerData:(NSString *)dataKey andVaule:(NSString *)data;

/**
自定义统计事件    接入方按需求选接

@param dataKey 事件名字
@param data 事件内容，json格式
*/
+ (void)collectionServerEvent:(NSString *)dataKey andVaule:(NSString *)data;
/**
 设置是否需要游客登陆方式,默认不设置为开启游客登陆

 @param guestEnable YES:开启 NO:关闭
 */
+ (void)setGuestEnable:(BOOL)guestEnable;


/**
 设置是否显示SDK中的alert提示框，默认开启

 @param alertEnable YES:开启 NO:关闭
 */
+ (void)setAlertEnable:(BOOL)alertEnable;

/**
 设置是否显示SDK中的登录Banners,默认开启
 
 @param alertEnable YES:开启 NO:关闭
 */
+ (void)setBannersEnable:(BOOL)bannersEnable;

/**
 设置链接状态是否显示SDK中的alert提示框，默认开启
 
 @param alertEnable YES:开启 NO:关闭
 */
+ (void)setContentAlertEnable:(BOOL)alertEnable;


/**
 设置是否开始cr登录 默认关闭

 @param isOpen isOpen YES：开启 NO：关闭
 */
+(void)setCRLoginOpen:(BOOL)isOpen;

/**
 设置是否开始egls登录 默认开启

 @param isOpen isOpen YES：开启 NO：关闭
 */
+(void)setEGLSLoginOpen:(BOOL)isOpen;

+(void)setUnViewAgreement:(BOOL)isView;

+(void)setWXLoginOpen:(BOOL)isOpen;

+(void)setDebugOpen:(BOOL)isOpen;

+(void)setTakeNewMac:(BOOL)isNew;

+(void)setMacAddress;

+(NSString *)getMacAddress;

+(void)setCloseUIQuickly:(BOOL)isClose;

+(void)openWebView:(NSString*)url;

+(NSString*) getPlayerInfo:(NSString *) infoKey;

+(void)setUIModalPresentationStyle:(UIModalPresentationStyle)mode;

+(void)setPrisonBreak:(BOOL)prisonBreak; //是否为越狱包

+(void)setKeepLive:(BOOL)isOpen; //是否为越狱包

+(void)setSetPaymentCondition:(EGLSSDKBINDFORPAY)isBind;

+(void)setCPLoginMode:(CPLoginMode) mode;


- (void)setUsePurchaseSandbox:(BOOL) sandbox;

- (void)setGamePolicy:(GamePolicy) gamePolicy;

- (void)accountQuery;

-(void)setSdkMode:(EGLSSDKMODE) mode;

-(void)setSdkBindMode:(EGLSSDKBINDMODE) mode;

-(void)eglsSimpleAlert:(NSString * )message;

-(void)setLocalLanguages:(NSString * )message;

-(void)openRealNameAuthenticationTest;
@end

