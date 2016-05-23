//
//  NSCharacterSet+LFAdd.m
//
//
//  Created by guoyaoyuan on 14-10-28.
//  Copyright (c) 2014 live Interactive. All rights reserved.
//

#import "LFNSCharacterSet+Add.h"
#import "LFNSString+Add.h"
#import "LFCategoryMacro.h"


@implementation NSCharacterSet (LFNSCharacterSetAdditions)

+ (NSCharacterSet *)emojiCharacterSet {
    static NSCharacterSet *set = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        set = [NSCharacterSet characterSetWithCharactersInString:[NSString allEmoji]];
    });
    return set;
}

@end


@implementation NSMutableCharacterSet (LFAdd)

+ (NSMutableCharacterSet *)emojiCharacterSet {
    static NSMutableCharacterSet *set = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        set = [NSCharacterSet emojiCharacterSet].mutableCopy;
    });
    return set;
}

@end
