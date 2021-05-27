//
//  EglsAdvertiser.h
//  EglsAdvertiser
//
//  Created by EGLS-Macmini on 2019/11/26.
//  Copyright © 2019 EGLS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EglsAdvertiserDelegate.h"

#define ADSERVER_TYPE_GOOGLE @"adGoogle"

#define ADSERVER_ACTION_PLAY @"playAdvertiser"

#define ADSERVER_BACK_SUCCESS @"adserver_back_success"
#define ADSERVER_BACK_PLAYING @"adserver_back_playing"
#define ADSERVER_BACK_COMPLETED @"adserver_back_completed"
#define ADSERVER_BACK_OPEN @"adserver_back_open"
#define ADSERVER_BACK_RECEIVED @"adserver_back_received"
#define ADSERVER_BACK_LEAVE @"adserver_back_leave"
#define ADSERVER_BACK_SKIP @"adserver_back_skip"
#define ADSERVER_BACK_CLOSE @"adserver_back_close"
#define ADSERVER_BACK_ERROR @"adserver_back_error"

static NSString * adVersion = @"1.0.0";

@interface EglsAdvertiser : NSObject<EglsAdvertiserDelegatePadding>
@property(assign, nonatomic) id mAdDelegate;
+ (EglsAdvertiser *)sharedInstance;
+(void)setRootViewController:(UIViewController *) viewController;
+ (UIViewController *)getRootViewController;

+(NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;
+(NSString*)dictionaryToJson:(NSDictionary *)dic;

-(void)adServerEvent:(NSString *) eventName andValue:(NSString *) value;
-(void)adServerData:(NSString *)dataKey andVaule:(NSString *)data;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)dictionary;
-(void) setDelegate:(id<EglsAdvertiserDelegate>)delegate;
@end
