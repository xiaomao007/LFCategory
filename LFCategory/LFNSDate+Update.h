//
//  NSDate+Update.h
//  LFCategory
//
//  Created by WangZhiWei on 16/5/19.
//  Copyright © 2016年 youku. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (LFUpdateAdditions)

#pragma mark - 日期修改
///=============================================================================
/// @name 日期修改
///=============================================================================


- (NSDate *)dateByAddingYears:(NSInteger)years; /// 从这个日期加上N年
- (NSDate *)dateByAddingMonths:(NSInteger)months; /// 从这个日期加上N月
- (NSDate *)dateByAddingWeeks:(NSInteger)weeks; /// 从这个日期加上N日
- (NSDate *)dateByAddingDays:(NSInteger)days; /// 从这个日期加上N天
- (NSDate *)dateByAddingHours:(NSInteger)hours; /// 从这个日期加上N小时
- (NSDate *)dateByAddingMinutes:(NSInteger)minutes; /// 从这个日期加上N分钟
- (NSDate *)dateByAddingSeconds:(NSInteger)seconds; /// 从这个日期加上N秒


@end
