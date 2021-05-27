
#import "EGLSSDKStaticData.h"
//#import "EGLSSDKUtil.h"
///**
// 登陆方式
// 
// - MODE_LOGIN_COMMON: 普通登陆方式，对应原接口showLogin
// - MODE_LOGIN_AUTO: 自动登陆方式，对应原接口autoLogin
// - MODE_LOGIN_FAST: 快速登陆方式，在自动登陆基础上，如果玩家第一次登陆游戏，不会弹出sdk页面，直接以游客方式登陆游戏
// -MODE_LOGIN_LIGHTLY:轻量级登录
// */
//typedef NS_ENUM(NSInteger, CPLoginType) {
//    MODE_LOGIN_COMMON,
//    MODE_LOGIN_AUTO,
//    MODE_LOGIN_FAST,
//    MODE_LOGIN_LIGHTLY
//};
//
//
//typedef NS_ENUM(NSInteger, CPLoginMode) { //适配关闭先关闭登陆页的情况
//    LOGINMODE_COMMON,
//    LOGINMODE_COLSELOGINVIEW,
//};
//
//// @param channel 登录方式："0"表示游客，"1"表示EGLS，“2”表示google，“3”表示facebook, "4"表示微信登陆
//typedef NS_ENUM(NSInteger, CPLoginChannel) { //适配关闭先关闭登陆页的情况
//    CHANNEL_TOURIST, //游客
//    CHANNEL_EGLS, //egls
//    CHANNEL_GOOGLE, //google
//    CHANNEL_FACEBOOK,//fb
//    CHANNEL_WECHAT,
//    CHANNEL_GAMECENTER,
//    CHANNEL_CR,
//    CHANNEL_APPLE,
//};
//
//typedef NS_ENUM(NSInteger, ShouldJumpToViewType) {
//    ShouldJumpToViewType_UserInfo,
//    ShouldJumpToViewType_Charge,
//    ShouldJumpToViewType_AppleCharge,
//    ShouldJumpToViewType_LastUI,
//    ShouldJumpToViewType_CurrentUI
//};
#define  LOGIN_MODE_CR @"cr"
#define  LOGIN_MODE_LINE @"line"
#define  LOGIN_MODE_PHONE @"phone"
//#define  GOOGLE_USERDEFAULTS_KEY @"google_userdefaults_key"



@interface EGLSSDKLoginManager : NSObject

@property(assign, nonatomic) CPLoginMode mCPLoginMode;
@property(assign, nonatomic) BOOL mIsGameout;

+ (EGLSSDKLoginManager *)sharedInstance;

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

- (void)autoLoginForData:(NSString *) channle;

//快速登录
-(void)fastLogin;

-(BOOL)supportLoginMode:(NSString *) mode;
//-(void)loginForChannel:(CPLoginChannel) channel andBind:(BOOL)isBind andJumpToView: (ShouldJumpToViewType) viewType;
-(SUPPORTPHONENUM)supportPhoneNumberLoginState;

-(BOOL)supportPhoneNumberCommpare:(SUPPORTPHONENUM) state;
@end
