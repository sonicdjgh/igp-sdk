    # [EGLS SDK for iOS](https://gitlab.com/NsLonger/egls-iOS-SDK.git) &middot;  [![Status](https://img.shields.io/badge/状态-已发布-brightgreen.svg)](https://gitlab.com/NsLonger/egls-iOS-SDK.git) ![Status](https://img.shields.io/badge/版本-4.6.0-lightgrey.svg) 


EGLS SDK for iOS是艾格拉斯公司为游戏设计的集成登陆，支付，分享，统计，反馈的软件，可以为iOS原生项目或者Unity与各种第三方引擎框架下各种游戏提供上述功能。

- [更新日志](#更新日志)
- [开发环境](#开发环境)
- [发行区域](#发行区域)
- [参数配置](#参数配置)
- [Xcode编译](#xcode编译)
- [功能代码](#功能代码)

---
## 更新日志

### [4.8.1] - 2020-11-24
#### Security
-  新增了line登录
-  大陆以外地区开放了电话登录

## 开发环境

EGLS SDK for iOS 现有版本需要Xcode 10.0以上，iOS版本为9.0以上，支持适配iPhone，iPad，支持所有方向游戏。

### [4.8.0] - 2020-02-21
#### Security
-  新增了轻量级sdk

## 开发环境

EGLS SDK for iOS 现有版本需要Xcode 10.0以上，iOS版本为9.0以上，支持适配iPhone，iPad，支持所有方向游戏。

## 发行区域

目前SDK按`发行区域`分为四个版本  
**大陆版**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/大陆))  
发行区域为中国大陆，不包括港澳台  
**港澳台欧美俄版本**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/港澳台欧美俄))  
发行区域包括中国港澳台地区，东南亚地区（不包括新加坡），欧美地区，俄罗斯地区  
**韩国版**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/韩国))  
发行区域为韩国  
**新加坡版**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/新加坡))  
发行区域为新加坡，基本内容与`港澳台欧美俄`版本相同，英文环境适配变为简体中文

## 参数配置
所需具体参数请参见我方运营配置表，这里列出所有参数在各版本中的填写必要性，请根据运营地区选择填入
#### 项目plist直接配置参数
|SDK国家版本/PlistKey|大陆版本| 港澳台欧美俄（新加坡）|韩国版本|
|:--:|:--:|:--:|:--:|
|EGLSAppleID（ItunsConnect AppleID string类型）|**需要**|**需要**|**需要**|
|EGLSCurrencyCode（货币代号 string类型）|**需要**|**需要**|**需要**|
|EGLSDevelopmentTeamID（APPLE DEVELOPMENT_TEAM ID string类型）|**需要**|**需要**|**需要**|
|EGLSAFDevKey（AppsFlyer开发者Key string类型）|如接入独立AF账号则需要|如接入独立AF账号则需要|如接入独立AF账号则需要|
|WechatAppID（微信开发者ID string类型）|**需要**|不需要|不需要|
|FacebookAppID（Facebook开发者ID string类型）|不需要|**需要**|**需要**|
|GoogleAppID（Google开发者ID string类型）|不需要|**需要**|**需要**|
|NaverLoginClientId（Naver开发者ID NaverLoginClientIdCafeId string类型）|不需要|不需要|**需要**|
|NaverLoginClientSecret（Naver开发者Secret NaverLoginClientSecret string类型 ）|不需要|不需要|**需要**|
|CafeId（NaverCafe开发者ID string类型）|不需要|不需要|**需要**|
|LineSDKConfig（line登录开ID string类型）|不需要|**需要**|不需要|
|LSApplicationQueriesSchemes（白名单功能参数见下方 Array）|**需要**|**需要**|**需要**|
|FaceBookPermissions（fb额外权限  无特殊要求可忽略  Array类型  ）|不需要|**需要**|**需要**|
|IsNeedFirebase（是否启用推送 ）|不需要|**需要**|**需要**|
|SupportedChannels（额外渠道登录 (cr[目前只有美国],line,phone[只有大陆和台湾才有此登录]) Array类型）|不需要|**需要**|**需要**|


#### 项目plist的scheme中需要添加的参数
这里的参数是在plist中打开URL Types选项卡以后需要点击“+”号添加的每一组参数，其中每组需要添加的参数包括了Identifier和URL Schemes（Schemes）2项，如果没有对identifier做说明则不需要填入任何参数，如有疑问也请善用搜索或者直接联系EGLS帮助  
line3rdp.$(PRODUCT_BUNDLE_IDENTIFIER)
|SDK国家版本/参数说明|大陆版本| 港澳台欧美俄（新加坡）|韩国版本|
|:--:|:--:|:--:|:--:|
|Schemes:WechatAppID值|**需要**|不需要|不需要|
|Schemes:"FB"+FacebookAppID值|不需要|**需要**|**需要**|
|Identifier:项目bundleID值 Schemes:项目bundleID值|不需要|**需要**|**需要**|
|Schemes:lien(line3rdp.$(PRODUCT_BUNDLE_IDENTIFIER))|不需要|**需要**|**需要**|  
|Schemes:GoogleAppID按“.”分割反序排列值*|不需要|**需要**|**需要**|  
*：[Google对填写scheme的说明](https://developers.google.com/identity/sign-in/ios/start-integrating)




#### 项目plist中LSApplicationQueriesSchemes数组中需要添加的参数（暂无）
|LSApplicationQueriesSchemes|参数|
|:--:|:--:|
|line|lineauth2,line|
|faceboob|fbapi,fb-messenger-share-api,fbauth2,fbshareextension|
|cafa|naversearchthirdlogin,naversearchapp,navercafe|

## Xcode编译

按步骤设置你的Xcode工程来保证编译成功

- **加入SDK库文件**  
分别在Xcode工程里拖入3rdlib（通用），EGLSSDK_Framework.framework，EGLSSDK_Framework.bundle（分发行地区选择导入）  
- **Capabilities设置**  
1--打开 Keychain Sharing 权限
- **Build Settings设置**  
1--在Other Linker Flags 选项中追加-ObjC  
2--SDK不支持bitcode 在Enable Bitcode选项中关闭它  
3--Search Paths 在Framework Search Paths、Header Search Paths、Library Search Paths中加入3rdLib文件夹路径，并在路径右侧的参数值选择里选择recursive，使路径遍历搜索  
4--在Framework Search Paths中加入EGLSSDK_Framework.framework路径  
- **Build Phases设置**  
1--如果工程整体设置了ARC则不需要再对具体文件设置ARC，否则请将SDK导入可编译的文件在Compile Sources选项卡中单独加入-fobjc-arc选项设置  
2--增加SDK所需系统库，列表如下，如已有不需重复添加  
  
> libxml2.tbd  
> libsqlite3.tbd  
> libz.tbd  
> libsqlite3.0.tbd  
> Photos.framework  
> UserNotifications.framework  
> CoreTelephony.framework  
> CFNetwork.framework  
> GameKit.framework  
> Social.framework  
> iAd.framework  
> AVKit.framework  
> WebKit.framework  
> QuartzCore.framework  
> ImageIO.framework  
> ReplayKit.framework  
> CoreGraphics.framework  
> Foundation.framework  
> Security.framework  
> UIKit.framework  
> AVFoundation.framework  
> AssetsLibrary.framework  
> MediaPlayer.framework  
> CoreMedia.framework  
> SystemConfiguration.framework  
> MobileCoreServices.framework  
> AddressBook.framework  
> SafariServices.framework  
> StoreKit.framework  
> AdSupport.framework  
> CoreGraphics.framework  
> Foundation.framework  
> MessageUI.framework  
> Accelerate.framework 

## 功能代码
### 初始化
 - （必选）SDK初始化
```
- (void)sdkInitWithAppID:(NSString *)appID
      withClientVersion:(NSString *)clientVersion
    withPassportCountry:(PassportCountry)passportCountry
            withIsDebug:(BOOL)isDebug
   withCallBackDelegate:(id<EGLSSDKDelegate>)delegate;
```
[EGLSSDK.h L:50](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L50)

- （可选）初始化回调
```
- (void)eglsSdkInitCallBack;
```

[EGLSSDKDelegate.h L:12](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L12)

### iOS通知接口
 - （必选）SDK iOS代理接口
```

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)dictionary;
 
- (void)applicationDidBecomeActive:(UIApplication *)application;
 
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
 
- (void)applicationWillTerminate:(UIApplication *)application;
 
- (BOOL)application:(UIApplication*)app openURL:(NSURL *)url options:(NSDictionary *)options;
 
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
 
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;
 
- (void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification *)notification;

```
[EGLSSDKDelegate.h L:198](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L198)


### 设置绘制层
- （必选）设置程序最上层用于显示的Controller,如果在游戏运行中rootViewController有变化也请在调用SDK方法之前调用这个方法
```
+ (void)setEGLSRootViewController:(UIViewController *)rootVC;
```

[EGLSSDK.h L:281](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L281)

### 一般模式(带ui的SDK方法)
#### 注册登陆
- （必选）登陆功能
```
- (void)eglsLogin:(CPLoginType)type;
```

[EGLSSDK.h L:89](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L74)

- （必选）登陆回调成功
```
- (void)loginSuccessCallBackWithUid:(NSString *)uid
                           andToken:(NSString *)token 
                         andChannel:(NSString *)channel
                        andNickname:(NSString *)nick;
```
[EGLSSDKDelegate.h L:22](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L22)


- （必选）登陆回调失败
```
- (void)loginFailCallBackWithChannel:(NSString *)channel;
```
[EGLSSDKDelegate.h L:115](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L115)


- （可选）注册回调
```
- (void)registerSuccessCallBackWithUid:(NSString *)uid;
```
[EGLSSDKDelegate.h L:52](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L52)

- （可选）关闭登陆页面回调
```
- (void)loginCancel;
```
[EGLSSDKDelegate.h L:38](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L38)


- （可选）悬浮框登出按钮回调
```
//目前回调参数不可用
- (void)eglsLogOut:(int)state andMessage:(NSString *) messge;
```

- （可选）悬浮框登出按钮显示隐藏
```
//YES为隐藏
+ (void)setLoginOutOnFloatButon:(BOOL)showEnable
```

- （可选）主动调用游客绑定
```
- (void)eglsGuestBind;
```
[EGLSSDK.h L:82](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L82)

- （可选）设置登陆后Banner是否隐藏更换账号按钮
```
- (void)setBannerSwitchHidden;
```
[EGLSSDK.h L:305](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L305)

#### 充值
- （必选）苹果充值 (CP可根据需求选择相应的充值接口)
```
// 玩家信息提交接口,一般自研游戏需要在充值前调用
-(void)updateRoleData:(NSString * )subgame
               roleID:(NSString *)roleID
               level:(NSString *)level
               vipLevel:(NSString *)vipLevel;
               
               
//公共充值接口            
#define  FLAG_PURCHASE_DEFAULT    0    //默认渠道支付
#define  FLAG_PURCHASE_WEB_MYCARD    1    //Mycard网页支付
#define  FLAG_PURCHASE_WEB_EC    2    //绿界网页支付
#define  FLAG_PURCHASE_WEB_EB  3     //蓝新网页支付


- (void)applePurchaseCommunal:(int)payType 
                     productID:(NSString *)productID
                     orderID:(NSString *)extraData
                     productName:(NSString*)productName
                     price:(double)price

                    
```
- （必选）充值回调
```
- (void)applePurchaseSuccessCallBackWithOrderID:(NSString *)orderID 
                                       andMoney:(NSString *)money;
```
[EGLSSDKDelegate.h L:59](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L59)
#### 分享
- （可选）通过第三方SDK实现游戏内容分享
```
- (void)shareWithType:(int)type 
            withTitle:(NSString *)title 
             withText:(NSString *)text 
            withImage:(NSString *)image 
             withLink:(NSString *)link 
           isTimeLine:(BOOL)isTL;
```
[EGLSSDK.h L:311](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L311)

- （可选）分享回调
```
- (void)shareCallBack:(int)typeCode 
           withResult:(int)result 
          withMessage:(NSString *)message;
```
[EGLSSDKDelegate.h L:68](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L68)


#### 第三方信息获取(目前只有faceBook)

##### 获取接口
```
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
```
##### 回掉接口
```
-(void)FBloginSuccessCallBackWithUid:(NSString *)uid name:(NSString *)name picture:(NSString *)picture
{
     NSLog(@"EGLS Login Success Call Back!\n uid is : %@\n name is : %@ picture:%@", uid, name,picture);
}
-(void)FBloginSuccessCallBackWithFields:(NSArray *)fields
{
    NSLog(@"field is:%@",fields);
}
```
#### 运营活动
- （可选）运营活动页面，接入需与我方运营人员确认
```

- (void)ratingActivity;

- (void)facebookActivity:(BOOL)enableJoinfans withEnableShare:(BOOL)enableShare;

- (void)linePromotionActivity;
```
[EGLSSDK.h L:311](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L317)
- （可选）运营回调
```
- (void)activityCallBack:(int)typeCode isSuccess:(BOOL)isSuc;
```
[EGLSSDKDelegate.h L77](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDKDelegate.h#L77)


### 轻量级SDK(不带UI)
#### 登录
```
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

```
#### 登录回调
```
/**
登录回掉(最新)
@param state SDK登录完成后返回的状态码，0为成功，1为取消，2为失败
@param uid 用户ID
@param token 校验用TOKEN
@param channel 登录方式："0"表示游客，"1"表示EGLS，“2”表示google，“3”表示facebook, "4"表示微信登陆
@param nick 用于显示的账号名称
@param message SDK登录完成后返回的平台消息
*/
-(void)loginCallback:(int)state andToken:(NSString *)token anduid: (NSString *)uid accountType:(NSString *)channel andNickname:(NSString *)nick andMassage:(NSString *) massage;
```

#### 绑定
```
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
```

#### 绑定回调
```
/**
 用户绑定回调

 @param accountType 绑定对应账户类型 1:EGLS 2:Google 3:Facebook 4:Wechat
 @param nickName 用户昵称
 */
- (void)channelBindCallBack:(NSString *)accountType withNickName:(NSString *)nickName withBindState: (int) state withMessage:(NSString*)massage;

/**
用户绑定验证

@param state  0为成功，1为取消，2为失败
@param message 服务器返回的消息
*/
- (void)verifyCallbackFromBind:(int)state andMessage:(NSString*)message;
```
#### 注册
```
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
```
#### 注册回调 
```
/**
用户注册验证回调

@param state SDK“手机号/邮箱注册验证”接口调用后返回的状态码：0为成功，1为取消，2为失败
@param message SDK“手机号/邮箱注册验证”接口调用后返回的平台消息
*/
- (void)verifyCallbackFromRegister:(int)state andMessage:(NSString*)message;

/**
登录回掉(最新) 注册成功后会直接登录 因此会走登录回调接口 
@param state SDK登录完成后返回的状态码，0为成功，1为取消，2为失败
@param uid 用户ID
@param token 校验用TOKEN
@param channel 登录方式："0"表示游客，"1"表示EGLS，“2”表示google，“3”表示facebook, "4"表示微信登陆
@param nick 用于显示的账号名称
@param message SDK登录完成后返回的平台消息
*/
-(void)loginCallback:(int)state andToken:(NSString *)token anduid: (NSString *)uid accountType:(NSString *)channel andNickname:(NSString *)nick andMassage:(NSString *) massage;


```

#### 密码相关服务
```
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
密码重置请求
@param userAccount  账号（手机号/邮箱）
 @param captcha  鉴权码
*/
-(void)pwdResetRequestLightly:(NSString*)userAccount captcha:(NSString*) captcha;
```

#### 密码服务回调
```
/**
鉴权回调接口

@param state SDK“密码重置鉴权”接口调用后返回的状态码：0为成功，1为取消，2为失败
@param message SDK“密码重置鉴权”接口调用后返回的平台消息
*/
- (void)captchaCallbackFromPassWord:(int)state andMessage:(NSString*)message;

/**
密码重置

@param state SDK“密码重置请求”接口调用后返回的状态码：0为成功，1为取消，2为失败
@param message SDK“密码重置鉴权”接口调用后返回的平台消息
*/
- (void)requestCallbackFromResetPassWord:(int)state andMessage:(NSString*)message;


/**
密码修改

@param state SDK“密码重置请求”接口调用后返回的状态码：0为成功，1为取消，2为失败
@param message SDK“密码重置鉴权”接口调用后返回的平台消息
*/
- (void)requestCallbackFromChangePassWord:(int)state andMessage:(NSString*)message;
```

#### 支付
```
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
                    
```

#### 支付回调
```
/**
 *    苹果充值成功回调
 *    @param     state          0为成功，1为取消，2为失败
 *    @param    orderID         EGLS平台订单号
 *    @param    otherMessage    额外信息, 目前充值成功为 充值金额 后续可能为json
 *
 */
- (void)applePurchaseCallBackWithOrderID:(int)state andOrderId:(NSString *)orderID andOtherMessage:(NSString *)otherMessage;


```


### 数据统计系统
```

需要在info.plst中添加 CollectionServer 数组
#define SERVER_TYPE_ADJUST @"Adjust"
#define SERVER_TYPE_APPSFLYER @"AppsFlyer"
#define SERVER_TYPE_TALKINGDATA @"TalkingData"
添加集中一个数据收集服务 talkingdate 暂时没有

韩国
1 闪屏动画首次启动事件追踪（必接） EVENT_ONE_SPLASH_IMAGE
2 新手任务开始事件追踪（必接）EVENT_TUTORIAL_START;
3 新手任务完成事件追踪（必接）EVENT_TUTORIAL_COMPLETE;
4 创建新角色事件追踪（必接）EVENT_NEW_CHARACTER;
5 角色等级变化事件追踪（必接） EVENT_LEVEL + roleLevel;
6 vip等级变化事件追踪（必接） EVENT_VIP + vipLevel;
7 打开游戏内购商店事件追踪()（EVENT_VISIT_SHOP
8 自定义事件追踪()（根据需求接入）
// 有时候运营会针对具体的数据分析增加特定的事件统计，那么请调用该接口，传入特定的事件名称

其他

1 闪屏动画首次启动事件追踪（必接） EVENT_ONE_SPLASH_IMAGE
2 新手任务开始事件追踪（必接）EVENT_TUTORIAL_START;
3 新手任务完成事件追踪（必接）EVENT_TUTORIAL_COMPLETE;
4 创建新角色事件追踪（必接）EVENT_NEW_CHARACTER;
5 游戏资源首次更新开始事件追踪（必接）EVENT_ONE_UPDATE_START;
6 游戏资源首次更新完成事件追踪（必接）EVENT_ONE_UPDATE_COMPLETE;
7 游戏资源首次加载开始事件追踪（必接）EVENT_ONE_LOAD_START;
8 游戏资源首次加载完成事件追踪（必接）EVENT_ONE_LOAD_COMPLETE;
9 自定义事件追踪()（根据需求接入）
// 有时候运营会针对具体的数据分析增加特定的事件统计，那么请调用该接口，传入特定的事件名称


默认事件名称
#define EVENT_ONE_SPLASH_IMAGE @"event_one_splash_image"//闪屏
#define EVENT_ONE_UPDATE_START @"event_one_update_start" //统计首次游戏更新开始
#define EVENT_ONE_UPDATE_COMPLETE @"event_one_update_complete" //统计首次游戏更新完毕
#define EVENT_ONE_LOAD_START @"event_one_load_start" //统计首次游戏加载开始
#define EVENT_ONE_LOAD_COMPLETE @"event_one_load_complete" //统计首次游戏加载完毕
#define EVENT_ONE_CALL_LOGIN @"event_one_call_login" //统计首次打开SDK登录页
#define EVENT_NEW_CHARACTER @"event_new_character" //统计角色创建成功
#define EVENT_TUTORIAL_START @"event_tutorial_start" //统计新手教学开始
#define EVENT_TUTORIAL_COMPLETE @"event_tutorial_complete" //统计新手教学完毕
#define EVENT_TERMS_AGREE @"event_terms_agree" //统计玩家点击同意协议状况
#define EVENT_LEVEL @"event_level_num" //统计玩家角色等级变化
#define EVENT_VIP @"event_vip_num" //统计玩家VIP等级变化
#define EVENT_VISIT_SHOP @"event_visit_shop" //统计玩家打开游戏内商店次数
#define EVENT_VISIT_FANSITE @"event_visit_fansite" //统计玩家打开论坛的次数

data 无参数可为nil

方法名称 (dataKey 事件名称 除默认外可根据要求自定义 data 为josn可是的字符串)
+(void)collectionServerEvent:(NSString *)dataKey andVaule:(NSString *)data;

此方法目前还不需要使用(暂时不用管)
+ (void)collectionServerData:(NSString *)dataKey andVaule:(NSString *)data;
```
[EGLSSDK.h L:461](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L469)

