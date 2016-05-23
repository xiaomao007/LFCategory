//
//  NSDictionary+NSDictionaryExt.h
//  LaiFeng
//
//  Created by xinliu on 14-5-20.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSDictionary (LFModelValueAdditions)

/*
 返回指定key的timeInterval值
 没有指定key的值，返回默认值
 */
-(NSTimeInterval)timeIntervalForKey:(NSString *)key withDefault:(NSTimeInterval)defVal;

/// 源字符串是 timestamp 毫秒数
- (NSDate *)timestampDataForKey:(NSString *)key withDefault:(NSDate *)defVal;

- (NSString*)queryString;


- (id)lf_objectForKey:(NSString*)key class:(Class)aClass;




#pragma mark - Dictionary Value Getter
///=============================================================================
/// @name Dictionary Value Getter
///=============================================================================

- (BOOL)boolForKey:(NSString *)key withDefault:(BOOL)def;
- (char)charForKey:(NSString *)key withDefault:(char)def;
- (unsigned char)unsignedCharForKey:(NSString *)key withDefault:(unsigned char)def;
- (short)shortForKey:(NSString *)key withDefault:(short)def;
- (unsigned short)unsignedShortForKey:(NSString *)key withDefault:(unsigned short)def;
- (int)intForKey:(NSString *)key withDefault:(int)def;
- (unsigned int)unsignedIntForKey:(NSString *)key withDefault:(unsigned int)def;
- (long)longForKey:(NSString *)key withDefault:(long)def;
- (unsigned long)unsignedLongForKey:(NSString *)key withDefault:(unsigned long)def;
- (long long)longLongForKey:(NSString *)key withDefault:(long long)def;
- (unsigned long long)unsignedLongLongForKey:(NSString *)key withDefault:(unsigned long long)def;
- (float)floatForKey:(NSString *)key withDefault:(float)def;
- (double)doubleForKey:(NSString *)key withDefault:(double)def;
- (NSInteger)integerForKey:(NSString *)key withDefault:(NSInteger)def;
- (NSUInteger)unsignedIntegerForKey:(NSString *)key withDefault:(NSUInteger)def;
- (NSNumber *)numberForKey:(NSString *)key withDefault:(NSNumber *)def;
- (NSString *)stringForKey:(NSString *)key withDefault:(NSString *)def;

- (BOOL)boolForKey:(NSString *)key;
- (char)charForKey:(NSString *)key;
- (unsigned char)unsignedCharForKey:(NSString *)key;
- (short)shortForKey:(NSString *)key;
- (unsigned short)unsignedShortForKey:(NSString *)key;
- (int)intForKey:(NSString *)key;
- (unsigned int)unsignedIntForKey:(NSString *)key;
- (long)longForKey:(NSString *)key;
- (unsigned long)unsignedLongForKey:(NSString *)key;
- (long long)longLongForKey:(NSString *)key;
- (unsigned long long)unsignedLongLongForKey:(NSString *)key;
- (float)floatForKey:(NSString *)key;
- (double)doubleForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (NSUInteger)unsignedIntegerForKey:(NSString *)key;
- (NSNumber *)numberForKey:(NSString *)key;
- (NSString *)stringForKey:(NSString *)key;

@end
