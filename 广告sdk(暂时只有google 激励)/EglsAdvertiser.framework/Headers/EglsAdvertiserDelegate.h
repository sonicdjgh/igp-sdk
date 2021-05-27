//
//  EglsAdvertiser.h
//  EglsAdvertiser
//
//  Created by EGLS-Macmini on 2019/11/26.
//  Copyright © 2019 EGLS. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol EglsAdvertiserDelegate

@optional

-(void)eglsAdvertiserEvent:(NSString*)event andValue:(NSString*)jsonValue;
@end

@protocol EglsAdvertiserDelegatePadding
@end


