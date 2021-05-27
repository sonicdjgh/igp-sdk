
## 发行区域
**港澳台欧美俄版本**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/港澳台欧美俄))  
发行区域包括中国港澳台地区，东南亚地区（不包括新加坡），欧美地区，俄罗斯地区  
**韩国版**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/韩国))  
发行区域为韩国  
**新加坡版**([Git地址](https://gitlab.com/NsLonger/egls-iOS-SDK/tree/master/新加坡))  
发行区域为新加坡，基本内容与`港澳台欧美俄`版本相同，英文环境适配变为简体中文

#### 项目plist的scheme中需要添加的参数

## 功能代码
#### 初始化
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

#### iOS通知接口
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
#### 注册登陆

- （必选）设置程序最上层用于显示的Controller,如果在游戏运行中rootViewController有变化也请在调用SDK方法之前调用这个方法
```
+ (void)setEGLSRootViewController:(UIViewController *)rootVC;
```

[EGLSSDK.h L:281](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L281)

- （必选）登陆功能
```
- (void)eglsLogin:(CPLoginType)type;
```
[EGLSSDK.h L:89](https://gitlab.com/NsLonger/egls-iOS-SDK/blob/master/EGLSSDK_Framework/EGLSSDK_Framework.framework/Headers/EGLSSDK.h#L89)
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
- (void)applePurchaseCommunal:(PayType)payType 
                     productID:(NSString *)productID
                     orderID:(NSString *)extraData
                     productName:(NSString*)productName
                     price:(double)price
                     isSandBox:(BOOL) isSandBox
                     extra:(NSString*) extra;
                    
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

#### 数据统计

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

