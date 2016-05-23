//
//  NSDate+NSDateExt.h
//  LaiFeng
//
//  Created by xinliu on 14-6-25.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface NSDate(NSDateExt)
- (NSString *)stringForTimeLaifeng;
- (NSString *)stringForDateline;
- (NSString *)stringForTimeToday;
- (NSString *)stringForTimeTomorrow;
- (NSString *)stringForTimeCommon;
- (NSString *)stringForHourLaifeng;
- (NSString *)stringForDayLaifeng;
- (NSAttributedString *)attributedStringForTimeToday;
- (NSAttributedString *)attributedStringForTimeTomorrow;
- (NSAttributedString *)attributedStringForCommon;

- (NSString *)stringForFeed;
- (BOOL)isToday;
- (BOOL)isYesterday;
- (BOOL)isTodayBirthday;
- (BOOL)isLast30Mins;
@end
