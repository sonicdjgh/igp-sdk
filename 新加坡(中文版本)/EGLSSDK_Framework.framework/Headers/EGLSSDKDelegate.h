
#import <UIKit/UIKit.h>


@protocol EGLSSDKDelegate

@optional

/**
 SDK初始化后的返回 //0 成功  2 失败 
 */
- (void)eglsSdkInitCallBack:(NSString *) state andJsonVaule:(NSString *) json;

/**
登录回掉(最新)
@param state SDK登录完成后返回的状态码，0为成功，1为取消，2为失败
@param uid 用户ID
@param token 校验用TOKEN
@param channel 登录方式："0"表示游客，"1"表示EGLS，“2”表示google，“3”表示facebook, "4"表示微信登陆  "6"  cr  "7 " apple  "8" line
@param nick 用于显示的账号名称
@param message SDK登录完成后返回的平台消息
*/
-(void)loginCallback:(int)state andToken:(NSString *)token anduid: (NSString *)uid accountType:(NSString *)channel andNickname:(NSString *)nick andMassage:(NSString *) massage;
/**
 * @brief     fb登录回调
 * @param     uid    fb用户ID
 * @param     name    用户昵称
 picture 用户头像
 */
- (void)FBloginSuccessCallBackWithUid:(NSString *)uid name:(NSString *)name picture:(NSString *)picture;
/*
 FB登录回调
 fields 好友列表
*/
- (void)FBloginSuccessCallBackWithFields:(NSArray *)fields;

/*
 FB好友邀请回调
 friends 好友列表
 */
- (void)FBloginInviteCallBackWithFriends:(NSArray *)friends;


/**
 *    关掉登录面板的回调
 */
- (void)loginCancel;
/**
 * @brief     注册回调(免注册绑定，不算注册)
 * @param     uid    用户ID
 */
- (void)registerSuccessCallBackWithUid:(NSString *)uid;
/**
 *    苹果充值成功回调
 *
 *    @param    orderID               EGLS平台订单号
 *    @param    otherMessage    额外信息, 目前充值成功为 充值金额 后续可能为json
 *
 */
- (void)applePurchaseCallBackWithOrderID:(int)state andOrderId:(NSString *)orderID andOtherMessage:(NSString *)otherMessage;
///**
// *    苹果充值失败回调
// *
// *    @param    orderID    EGLS平台订单号
// *    @param    money    充值金额
// */
//- (void)applePurchaseFailCallBack:(NSString *)failState;


@optional
/**
 *    若接入Facebook分享，需实现以下delegate。——获取分享的结果。
 *
 */
- (void)facebookShare_DidCompleteWithResults:(NSDictionary *)results;

- (void)facebookShare_DidFailWithError:(NSError *)error;

- (void)facebookShare_DidCancel;

/**
 * 分享回调接口
 *
 */
- (void)shareCallBack:(int)typeCode withResult:(int)result withMessage:(NSString*)message;

/**
 运营活动回调接口

 @param typeCode type 0 = 五星好评 1 = facebook加入粉丝团 2 = facebook每日分享 3 = line分享
 @param isSuc 是否成功
 */
- (void)activityCallBack:(int)typeCode isSuccess:(BOOL)isSuc;

/**
 *    若需要登出功能，则实现此回调,第三方账号会直接登出，egls账号不变，弹出账号输入界面
 *
 */
- (void)eglsLogOut:(int)state andMessage:(NSString *) messge;


/**
 用户绑定回调

 @param accountType 绑定对应账户类型 1:EGLS 2:Google 3:Facebook 4:Wechat "6"  cr  "7 " apple  "8" line
 @param nickName 用户昵称
 */
- (void)channelBindCallBack:(NSString *)accountType withNickName:(NSString *)nickName withBindState: (int) state withMessage:(NSString*)massage;

/**
用户绑定验证

@param state  0为成功，1为取消，2为失败
@param message 服务器返回的消息
*/
- (void)verifyCallbackFromBind:(int)state andMessage:(NSString*)message;


/**
用户注册回调

@param state SDK“手机号/邮箱注册验证”接口调用后返回的状态码：0为成功，1为取消，2为失败
@param message SDK“手机号/邮箱注册验证”接口调用后返回的平台消息
*/
- (void)verifyCallbackFromRegister:(int)state andMessage:(NSString*)message;


/**
玩家信息回调

@param state  请求状态 0为成功，1为取消，2为失败
@param message 成功时为josn 失败为失败信息
*/
- (void)requestCallbackPlayerInfo:(int)state andMessage:(NSString*) josn;
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


/**
 点击协议协议回调函数

 @param state 点击状态 0:点击取消 1:点击同意
 */
-(void)touchAgreementCallBack:(BOOL)state;

- (void)eglsResponseError:(int ) responseCode andMessage:(NSString *) message;
@end

@protocol EGLSSDKDelegatePadding
@end
