//
//  NSString+Ex.m
//  LaiFeng
//
//  Created by xinliu on 14-5-16.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import "LFNSString+URLString.h"
#import <CommonCrypto/CommonDigest.h>
#import "LFCategory.h"

@implementation NSString(LFURLStringAdditions)

///////////////////////////////////////////////////////////////////////////////////////////////////
- (NSString*) lf_urlEncode2:(NSStringEncoding)stringEncoding
{
    
    NSArray *escapeChars = [NSArray arrayWithObjects:@";", @"/", @"?", @":",
                            @"@", @"&", @"=", @"+", @"$", @",", @"!",
                            @"'", @"(", @")", @"*", @"-", @"~", @"_", nil];
    
    NSArray *replaceChars = [NSArray arrayWithObjects:@"%3B", @"%2F", @"%3F", @"%3A",
                             @"%40", @"%26", @"%3D", @"%2B", @"%24", @"%2C", @"%21",
                             @"%27", @"%28", @"%29", @"%2A", @"%2D", @"%7E", @"%5F", nil];
    
    NSInteger len = [escapeChars count];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    NSString *tempStr = [self stringByAddingPercentEscapesUsingEncoding:stringEncoding];
    
    if (tempStr == nil) {
        return nil;
    }
 #pragma clang diagnostic pop   
    NSMutableString *temp = [tempStr mutableCopy];
    
    int i;
    for (i = 0; i < len; i++) {
        
        [temp replaceOccurrencesOfString:[escapeChars objectAtIndex:i]
                              withString:[replaceChars objectAtIndex:i]
                                 options:NSLiteralSearch
                                   range:NSMakeRange(0, [temp length])];
    }
    
    NSString *outStr = [NSString stringWithString: temp];
    
    return outStr;
}

// 判断字符串是否为空
+ (BOOL)lf_stringIsNull:(NSString *)string
{
    if (!string) {
        return YES;
    } else if ([string isEqualToString:@""] || [string isEqualToString:@"(null)"]){
        return YES;
    }
    NSCharacterSet *whitespace = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    string = [string stringByTrimmingCharactersInSet:whitespace];
    if (string && ![string isEqualToString:@""] && ![string isEqualToString:@"(null)"]) {
        return NO;
    } else {
        return YES;
    }
}

- (NSString*) lf_urlDecode:(NSStringEncoding)stringEncoding
{
    
    NSArray *escapeChars = [NSArray arrayWithObjects:@";", @"/", @"?", @":",
                            @"@", @"&", @"=", @"+", @"$", @",", @"!",
                            @"'", @"(", @")", @"*", @"-", @"~", @"_", nil];
    
    NSArray *replaceChars = [NSArray arrayWithObjects:@"%3B", @"%2F", @"%3F", @"%3A",
                             @"%40", @"%26", @"%3D", @"%2B", @"%24", @"%2C", @"%21",
                             @"%27", @"%28", @"%29", @"%2A", @"%2D", @"%7E", @"%5F", nil];
    
    NSInteger len = [escapeChars count];
    
    NSMutableString *temp = [self mutableCopy];
    
    if (temp == nil) {
        return nil;
    }
    
    int i;
    for (i = 0; i < len; i++) {
        
        [temp replaceOccurrencesOfString:[replaceChars objectAtIndex:i]
                              withString:[escapeChars objectAtIndex:i]
                                 options:NSLiteralSearch
                                   range:NSMakeRange(0, [temp length])];
    }
    NSString *outStr = [NSString stringWithString: temp];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    return [outStr stringByReplacingPercentEscapesUsingEncoding:stringEncoding];
#pragma clang diagnostic pop
}

- (NSDictionary*)lf_queryContentsDicUsingEncoding:(NSStringEncoding)encoding {
    NSCharacterSet* delimiterSet = [NSCharacterSet characterSetWithCharactersInString:@"&;"];
    NSMutableDictionary* pairs = [NSMutableDictionary dictionary];
    NSScanner* scanner = [[NSScanner alloc] initWithString:self];
    while (![scanner isAtEnd]) {
        NSString* pairString = nil;
        [scanner scanUpToCharactersFromSet:delimiterSet intoString:&pairString];
        [scanner scanCharactersFromSet:delimiterSet intoString:NULL];
        NSArray* kvPair = [pairString componentsSeparatedByString:@"="];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        if (kvPair.count == 2) {
            NSString* key = [[kvPair objectAtIndex:0]
                             stringByReplacingPercentEscapesUsingEncoding:encoding];
            NSString* value = [[kvPair objectAtIndex:1]
                               stringByReplacingPercentEscapesUsingEncoding:encoding];
            [pairs setObject:value forKey:key];
        }
    }
    return [NSDictionary dictionaryWithDictionary:pairs];
#pragma clang diagnostic pop
}


- (NSURL *)lf_toURL {
    if ([self lf_isNotBlank]) {
        return [NSURL URLWithString:self];
    }
    return nil;
}

@end
