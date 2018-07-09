
#import <UIKit/UIKit.h>


@protocol EGLSSDKDelegate

@optional
/**
 * @brief     登录回调
 * @param     uid    用户ID
 * @param     token    校验用的
              channel   登录方式："0"表示游客，"1"表示EGLS，“2”表示google，“3”表示facebook
 */
- (void)loginSuccessCallBackWithUid:(NSString *)uid andToken:(NSString *)token andChannel:(NSString *)channel;
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
 *	关掉登录面板的回调
 */
- (void)loginCancel;
/**
 * @brief     注册回调(免注册绑定，不算注册)
 * @param     uid    用户ID
 */
- (void)registerSuccessCallBackWithUid:(NSString *)uid;
/**
 *	苹果充值回调
 *
 *	@param	orderID	EGLS平台订单号
 *	@param	money	充值金额
 */
- (void)applePurchaseSuccessCallBackWithOrderID:(NSString *)orderID andMoney:(NSString *)money;


@optional
/**
 *	若接入Facebook分享，需实现以下delegate。——获取分享的结果。
 *
 */
- (void)facebookShare_DidCompleteWithResults:(NSDictionary *)results;

- (void)facebookShare_DidFailWithError:(NSError *)error;

- (void)facebookShare_DidCancel;

@end
