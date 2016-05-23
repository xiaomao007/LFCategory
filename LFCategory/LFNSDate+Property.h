//
//  NSDate+LFAdd.m
//
//
//  Created by guoyaoyuan on 13-4-11.
//  Copyright (c) 2013 live Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Provides extensions for `NSDate`.
 */
@interface NSDate (LFPropertyAdditions)


#pragma mark - 时间部分
///=============================================================================
/// @name 时间部分
///=============================================================================

@property (nonatomic, readonly) NSInteger year; ///< Year component
@property (nonatomic, readonly) NSInteger month; ///< Month component
@property (nonatomic, readonly) NSInteger day; ///< Day component
@property (nonatomic, readonly) NSInteger hour; ///< Hour component
@property (nonatomic, readonly) NSInteger minute; ///< Minute component
@property (nonatomic, readonly) NSInteger second; ///< Second component
@property (nonatomic, readonly) NSInteger nanosecond; ///< Nanosecond component
@property (nonatomic, readonly) NSInteger weekday; ///< Weekday component
@property (nonatomic, readonly) NSInteger weekdayOrdinal; ///< WeekdayOrdinal component
@property (nonatomic, readonly) NSInteger weekOfMonth; ///< WeekOfMonth component
@property (nonatomic, readonly) NSInteger weekOfYear; ///< WeekOfYear component
@property (nonatomic, readonly) NSInteger yearForWeekOfYear; ///< YearForWeekOfYear component
@property (nonatomic, readonly) NSInteger quarter; ///< Quarter component
@property (nonatomic, readonly) BOOL isLeapMonth; ///< 是否闰月
@property (nonatomic, readonly) BOOL isLeapYear; ///< 是否闰年

@end
