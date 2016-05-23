//
//  NSString+Ex.h
//  LaiFeng
//
//  Created by xinliu on 14-5-16.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString(LFURLStringAdditions)

- (NSString*) urlEncode2:(NSStringEncoding)stringEncoding;

+ (BOOL)stringIsNull:(NSString *)string;

- (NSString*) urlDecode:(NSStringEncoding)stringEncoding;
- (NSDictionary*)queryContentsDicUsingEncoding:(NSStringEncoding)encoding;

- (NSURL*)toURL;
@end
