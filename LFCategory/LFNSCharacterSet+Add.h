//
//  NSCharacterSet+LFAdd.h
//
//
//  Created by guoyaoyuan on 14-10-28.
//  Copyright (c) 2014 live Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Provides extensions for `NSCharacterSet`.
 */
@interface NSCharacterSet (LFNSCharacterSetAdditions)

/**
 Returns a character set containing all Apple Emoji.
 */
+ (NSCharacterSet *)emojiCharacterSet;

@end



/**
 Provides extensions for `NSMutableCharacterSet`.
 */
@interface NSMutableCharacterSet (LFAdd)

/**
 Returns a character set containing all Apple Emoji.
 */
+ (NSMutableCharacterSet *)emojiCharacterSet;

@end
