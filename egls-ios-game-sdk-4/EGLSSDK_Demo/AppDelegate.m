#import "AppDelegate.h"
#import <LiveOps/LiveOps.h>
//#import <Bugly/Bugly.h>
#define MYBUNDLE_QUOTENAME @"EGLSSDKRES.bundle"
#define MYBUNDLE_PATH [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:MYBUNDLE_QUOTENAME]
#define MYBUNDLE [NSBundle bundleWithPath: MYBUNDLE_PATH]
#define LS(str, nil) NSLocalizedStringFromTableInBundle(str, nil, MYBUNDLE, nil)
@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor grayColor];
    [self.window makeKeyAndVisible];
    
    UIViewController * vc = [[UIViewController alloc] init];
    _vc000 = vc;
    self.window.rootViewController = vc;
//    [Bugly startWithAppId:@"ee092f177b"];
//    [Bugly startWithAppId:@"28dbffb447"];
    
    CGFloat screenHeight = [UIScreen mainScreen].bounds.size.height;
    CGFloat screenWidth = [UIScreen mainScreen].bounds.size.width;
    if (screenWidth < screenHeight) {
        CGFloat tmp = screenWidth;
        screenWidth = screenHeight;
        screenHeight = tmp;
    }
    CGFloat size = screenHeight * 0.0006;
    
    CGFloat x_btn = 100 * size;
    CGFloat y = 0;
    //    CGFloat h_btn = 40 * size;
    CGFloat h_btn = 0.1 * screenHeight;
    //    CGFloat w_btn = 400 * size;
    CGFloat w_btn = h_btn * 4;
    
    //    CGFloat y_alpha = 20 * size;
    CGFloat y_alpha = (screenHeight - h_btn * 6) / 7;
    CGFloat x_alpha = 100 * size;
    //===========================================================
    y = y_alpha;
    
    
    
    NSString * bundlePath = [[ NSBundle mainBundle] pathForResource:@"EGLSSDKRES" ofType :@"bundle"];
    
    NSBundle * resourceBundle = [NSBundle bundleWithPath:bundlePath];
    
    UIImage * imageBack = [UIImage imageNamed:@"EGLSSDKRES.bundle/kr_06.png"];
    imageBack = [imageBack stretchableImageWithLeftCapWidth:4 topCapHeight:4];
    
    UIButton * autoLoginButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    //    autoLoginButton.frame = CGRectMake(20, 20, 100, 20);
    autoLoginButton.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [autoLoginButton setTitle:LS(@"AutoLoin", nil) forState:UIControlStateNormal];
    [autoLoginButton setTintColor:[UIColor whiteColor]];  //LS(@"AutoLoin", nil)
    [autoLoginButton setBackgroundImage:imageBack forState:UIControlStateNormal];
    [autoLoginButton addTarget:self action:@selector(autoLoginClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:autoLoginButton];
    
    //===========================================================
    y += (h_btn + y_alpha);
    UIButton * showLoginButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    //    showLoginButton.frame = CGRectMake(20, 20, 100, 20);
    showLoginButton.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [showLoginButton setTitle:LS(@"LOGIN", nil) forState:UIControlStateNormal];
    [showLoginButton setTintColor:[UIColor whiteColor]];  //LS(@"LOGIN", nil)
    [showLoginButton setBackgroundImage:imageBack forState:UIControlStateNormal];
    [showLoginButton addTarget:self action:@selector(showLoginClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:showLoginButton];
    
    //===========================================================
    y += (h_btn + y_alpha);
    UIButton * chargeButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    //    chargeButton.frame = CGRectMake(20, 50, 100, 20);
    chargeButton.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [chargeButton setTitle:LS(@"MainlandPurchase", nil) forState:UIControlStateNormal];
    [chargeButton setTintColor:[UIColor whiteColor]];
    [chargeButton setBackgroundImage:imageBack forState:UIControlStateNormal];
    [chargeButton addTarget:self action:@selector(chargeClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:chargeButton];
    
    //===========================================================
    y += (h_btn + y_alpha);
    UIButton * applePurchaseBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    //    chargeButton.frame = CGRectMake(20, 50, 100, 20);
    applePurchaseBtn.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [applePurchaseBtn setTitle:LS(@"ApplePurchase", nil) forState:UIControlStateNormal];
    [applePurchaseBtn setTintColor:[UIColor whiteColor]];
    [applePurchaseBtn setBackgroundImage:imageBack forState:UIControlStateNormal];
    [applePurchaseBtn addTarget:self action:@selector(applePurchaseClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:applePurchaseBtn];
    
    //    //===========================================================
    //    y += (h_btn + y_alpha);
    //    UIButton * logoutBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    //    logoutBtn.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    //    [logoutBtn setTitle:LS(@"LOGOUT", nil) forState:UIControlStateNormal];
    //    [logoutBtn setTintColor:[UIColor whiteColor]];
    //    [logoutBtn setBackgroundImage:imageBack forState:UIControlStateNormal];
    //    [logoutBtn addTarget:self action:@selector(logoutClick) forControlEvents:UIControlEventTouchUpInside];
    //    [vc.view addSubview:logoutBtn];
    
    //    //===========================================================
    y += (h_btn + y_alpha);
    UIButton * fbShareImgBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    fbShareImgBtn.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [fbShareImgBtn setTitle:LS(@"FacebookSharePictureOnly", nil) forState:UIControlStateNormal];
    [fbShareImgBtn setTintColor:[UIColor whiteColor]];
    [fbShareImgBtn setBackgroundImage:imageBack forState:UIControlStateNormal];
    [fbShareImgBtn addTarget:self action:@selector(fbShareImgClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:fbShareImgBtn];
    
    
    //    //===========================================================
    x_btn += (w_btn + x_alpha);   // 换列
    y = y_alpha;
    UIButton * fbShareUrlAndSoOnBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    fbShareUrlAndSoOnBtn.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [fbShareUrlAndSoOnBtn setTitle:LS(@"FacebookShareUrlAndSoON", nil) forState:UIControlStateNormal];
    [fbShareUrlAndSoOnBtn setTintColor:[UIColor whiteColor]];
    [fbShareUrlAndSoOnBtn setBackgroundImage:imageBack forState:UIControlStateNormal];
    [fbShareUrlAndSoOnBtn addTarget:self action:@selector(fbShareUrlAndSoOnClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:fbShareUrlAndSoOnBtn];
    
    //    //===========================================================
    y += (h_btn + y_alpha);
    UIButton * lineShareImgBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    lineShareImgBtn.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [lineShareImgBtn setTitle:LS(@"LineShareImg", nil) forState:UIControlStateNormal];
    [lineShareImgBtn setTintColor:[UIColor whiteColor]];
    [lineShareImgBtn setBackgroundImage:imageBack forState:UIControlStateNormal];
    [lineShareImgBtn addTarget:self action:@selector(lineShareImgClick) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:lineShareImgBtn];
    
    
    //    //===========================================================
    y += (h_btn + y_alpha);
    UIButton * lineShareTextBtn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    lineShareTextBtn.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [lineShareTextBtn setTitle:LS(@"LineShareText2", nil) forState:UIControlStateNormal];
    [lineShareTextBtn setTintColor:[UIColor whiteColor]];
    [lineShareTextBtn setBackgroundImage:imageBack forState:UIControlStateNormal];
    [lineShareTextBtn addTarget:self action:@selector(lineShareTextClick2) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:lineShareTextBtn];
    
    y += (h_btn + y_alpha);
    UIButton * fbInvite = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    fbInvite.frame = CGRectMake(x_btn, y, w_btn, h_btn);
    [fbInvite setTitle:@"facebook邀请好友" forState:UIControlStateNormal];
    [fbInvite setTintColor:[UIColor whiteColor]];
    [fbInvite setBackgroundImage:imageBack forState:UIControlStateNormal];
    [fbInvite addTarget:self action:@selector(fbInviteFriends) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:fbInvite];
    
    // 测试用的view   //===========================================================
    y += (h_btn + y_alpha);
    CGFloat w_eventView = screenWidth - x_btn;
    CGFloat h_eventView = screenHeight - y;
    UIView * eventView = [[UIView alloc]initWithFrame:CGRectMake(x_btn, y, w_eventView, h_eventView)];
    eventView.backgroundColor = [UIColor brownColor];
    eventView.userInteractionEnabled = YES;
    UITapGestureRecognizer * gesture_my = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(alert)];
    gesture_my.numberOfTapsRequired = 1;
    [eventView addGestureRecognizer:gesture_my];
    //    [vc.view addSubview:eventView];
    
    
    [[EGLSSDK sharedInstance] application:application didFinishLaunchingWithOptions:launchOptions];
    //接入需添加的初始化代码
    [[EGLSSDK sharedInstance] sdkInitWithAppID:@"8803"
                             withClientVersion:@"1.01.01"
                           withPassportCountry:PassportCountry_tw
                                   withIsDebug:YES
                          withCallBackDelegate:self
                                withAppleAppID:@"1121470622"
                              withCurrencyCode:@"TWD"];
    
    [self performSelector:@selector(delayMethod) withObject:nil/*可传任意类型参数*/ afterDelay:2.0];
    
    return YES;
}

- (void)delayMethod{
    
}
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    NSLog(@"str=%@",[[[[deviceToken description] stringByReplacingOccurrencesOfString: @"<" withString: @""]
                      stringByReplacingOccurrencesOfString: @">" withString: @""]
                     stringByReplacingOccurrencesOfString: @" " withString: @""]);
    
    NSLog(@"deviceToken1=%@",deviceToken);
    
    [LiveOpsPush setDeviceToken:deviceToken];
}
- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    //Device Token 登录失败 Log 确认
    NSLog(@"Device Token Register Failed: %@", error);
}
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_7_0
#warning "Remote push open tracking is counted only when user touches notification center under iOS SDK 7.0"

- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    [LiveOpsPush handleRemoteNotification:userInfo fetchHandler:nil];
}
#else
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    
    [LiveOpsPush handleRemoteNotification:userInfo fetchHandler:completionHandler];
}
#endif

- (void) alert{
    UIAlertView * alert = [[UIAlertView alloc] initWithTitle:nil
                                                     message:@"透传了"
                                                    delegate:self
                                           cancelButtonTitle:@"OK"
                                           otherButtonTitles:nil];
    [alert show];
    [alert release];
    
}


- (void)autoLoginClick {
    [[EGLSSDK sharedInstance] autoLogin];
    UIWindow *p = [[[UIApplication sharedApplication] delegate] window];
    UIView *t = [[[UIApplication sharedApplication] delegate] window].rootViewController.view;
    NSLog(@"获取window的值 = %@\n 获取view的值 = %@",p,t);
}

- (void)showLoginClick {
    [[EGLSSDK sharedInstance] showLogin];
}

- (void)chargeClick {
    [[EGLSSDK sharedInstance] showChargeWithProductID:@"com.eglsgame.paltform.lib.test" withAmount:@"10" withProductName:LS(@"OneBagOfDiamonds", nil) withExtraData:@"handsome" withSubgame:@"100005" withRoleID:@"149680001" withLevel:@"2" withVipLevel:@"0"];
}

- (void)applePurchaseClick {
    
    [[EGLSSDK sharedInstance] applePurchaseWithProductID:@"com.linkedfun.macau.tw.chippack1" withExtraData:nil];
}

- (void)loginSuccessCallBackWithUid:(NSString *)uid andToken:(NSString *)token andChannel:(NSString *)channel; {
    NSLog(@"EGLS Login Success Call Back!\n uid is : %@\n token is : %@", uid, token);
}

- (void)loginCancel {
    NSLog(@"EGLS loginCancel");
}

- (void)applePurchaseSuccessCallBackWithOrderID:(NSString *)orderID andMoney:(NSString *)money{
    NSLog(@"applePurchaseSuccessCallBack!\n orderID is : %@\n money is : %@", orderID, money);
}

#pragma mark fb
- (void)fbShareImgClick {
    UIImage * image = [UIImage imageNamed:@"EGLSSDKRES.bundle/EGLS.png"];
    [[EGLSSDK sharedInstance] facebookShareWithImage:image];
}

- (void)fbShareUrlAndSoOnClick {
    NSURL * url = [NSURL URLWithString:@"http://www.g2us.com"];
    NSURL * imgUrl = [NSURL URLWithString:@"https://res.oasgames.com/platform/uploader/1394777516.jpg"];
    NSString * title = LS(@"EGLS", nil);
    NSString * contentDescription = LS(@"GoodProduct", nil);
    [[EGLSSDK sharedInstance] facebookShareWithUrl:url withImageUrl:imgUrl withTitle:title withContentDescription:contentDescription];
}

- (void)facebookShare_DidCompleteWithResults:(NSDictionary *)results {
    NSLog(@"didCompleteWithResults:results ==%@", results);
}

- (void)facebookShare_DidFailWithError:(NSError *)error{
    NSLog(@"didFailWithError:error == %@", error);
}

- (void)facebookShare_DidCancel{
    NSLog(@"sharerDidCancel");
}

- (void)lineShareImgClick {
    UIImage * image = [UIImage imageNamed:@"EGLSSDKRES.bundle/EGLS.png"];
    if ([[EGLSSDK sharedInstance] lineShareImage:image]) {
        NSLog(LS(@"LineIsOpened", nil));
    } else {
        NSLog(LS(@"LineCanNotBeOpened", nil));
    }
}

- (void)lineShareTextClick {
    NSString * text = @"EGLS is great!";
    if ([[EGLSSDK sharedInstance] lineShareText:text]) {
        NSLog(LS(@"LineIsOpened", nil));
    } else {
        NSLog(LS(@"LineCanNotBeOpened", nil));
    }
}

- (void)fbInviteFriends {
    [[EGLSSDK sharedInstance] facebookInviteFriends];
}

- (void)applicationDidBecomeActive:(UIApplication *)application{
    [[EGLSSDK sharedInstance] applicationDidBecomeActive:application];
}


- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return [[EGLSSDK sharedInstance]application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    [[EGLSSDK sharedInstance] applicationWillTerminate:application];
}

- (void)FBloginInviteCallBackWithFriends:(NSArray *)friends
{
    NSLog(@"%@",friends);
}

@end
