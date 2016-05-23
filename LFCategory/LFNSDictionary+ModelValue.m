//
//  NSDictionary+NSDictionaryExt.m
//  LaiFeng
//
//  Created by xinliu on 14-5-20.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import "LFNSDictionary+Add.h"
#import "LFCategory.h"


@implementation NSDictionary (LFModelValueAdditions)

-(NSTimeInterval)timeIntervalForKey:(NSString *)key withDefault:(NSTimeInterval)defVal{
    @try {
        return [[self objectForKey:key] doubleValue];
    }
    @catch (NSException *exception) {
        return defVal;
    }
}

- (NSDate *)timestampDataForKey:(NSString *)key withDefault:(NSDate *)defVal {
    if (self[key]) {
        SInt64 timestamp = [self longLongForKey:key withDefault:0];
        if (timestamp == 0) return nil;
        return [NSDate dateWithTimeIntervalSince1970:timestamp / 1000.0];
    } else {
        return defVal;
    }
}


- (NSString*)queryString {
	NSMutableString* buffer = [[NSMutableString alloc] initWithCapacity:0];
	for (id key in self) {
		NSString* value = [NSString stringWithFormat:@"%@",[self objectForKey:key]];
		value = [value urlEncode2:NSUTF8StringEncoding];
		[buffer appendString:[NSString stringWithFormat:@"&%@=%@", key, value]];
	}
	NSString* ret = [buffer substringFromIndex:1];

	return ret;
}

- (id)lf_objectForKey:(NSString*)key class:(Class)aClass
{
    id obj = self[key];
    if ([obj isKindOfClass:aClass]) {
        return obj;
    }
    return nil;
}




#pragma mark - Dictionary Value Getter
///=============================================================================
/// @name Dictionary Value Getter
///=============================================================================

/// Get a number value from 'id'.
static NSNumber *NSNumberFromID(id value) {
    static NSCharacterSet *dot;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dot = [NSCharacterSet characterSetWithRange:NSMakeRange('.', 1)];
    });
    if (!value || value == [NSNull null]) return nil;
    if ([value isKindOfClass:[NSNumber class]]) return value;
    if ([value isKindOfClass:[NSString class]]) {
        NSString *lower = ((NSString *)value).lowercaseString;
        if ([lower isEqualToString:@"true"] || [lower isEqualToString:@"yes"]) return @(YES);
        if ([lower isEqualToString:@"false"] || [lower isEqualToString:@"no"]) return @(NO);
        if ([lower isEqualToString:@"nil"] || [lower isEqualToString:@"null"]) return nil;
        if ([lower isEqualToString:@"<nil>"] || [lower isEqualToString:@"<null>"]) return nil;
        if ([(NSString *)value rangeOfCharacterFromSet:dot].location != NSNotFound) {
            return @(((NSString *)value).doubleValue);
        } else {
            return @(((NSString *)value).longLongValue);
        }
    }
    return nil;
}

#define RETURN_VALUE(_type_)                          \
    if (!key) return def;                             \
    id value = self[key];                             \
    if (!value || value == [NSNull null]) return def; \
    if ([value isKindOfClass:[NSNumber class]])       \
        return ((NSNumber *)value)._type_;            \
    if ([value isKindOfClass:[NSString class]]) {     \
        NSNumber *num = NSNumberFromID(value);        \
        if (!num) return def;                         \
        return num._type_;                            \
    }                                                 \
    return def;

- (BOOL)boolForKey:(NSString *)key withDefault:(BOOL)def {
    RETURN_VALUE(boolValue);
}

- (char)charForKey:(NSString *)key withDefault:(char)def {
    RETURN_VALUE(charValue);
}

- (unsigned char)unsignedCharForKey:(NSString *)key withDefault:(unsigned char)def {
    RETURN_VALUE(unsignedCharValue);
}

- (short)shortForKey:(NSString *)key withDefault:(short)def {
    RETURN_VALUE(shortValue);
}

- (unsigned short)unsignedShortForKey:(NSString *)key withDefault:(unsigned short)def {
    RETURN_VALUE(unsignedShortValue);
}

- (int)intForKey:(NSString *)key withDefault:(int)def {
    RETURN_VALUE(intValue);
}

- (unsigned int)unsignedIntForKey:(NSString *)key withDefault:(unsigned int)def {
    RETURN_VALUE(unsignedIntValue);
}

- (long)longForKey:(NSString *)key withDefault:(long)def {
    RETURN_VALUE(longValue);
}

- (unsigned long)unsignedLongForKey:(NSString *)key withDefault:(unsigned long)def {
    RETURN_VALUE(unsignedLongValue);
}

- (long long)longLongForKey:(NSString *)key withDefault:(long long)def {
    RETURN_VALUE(longLongValue);
}

- (unsigned long long)unsignedLongLongForKey:(NSString *)key withDefault:(unsigned long long)def {
    RETURN_VALUE(unsignedLongLongValue);
}

- (float)floatForKey:(NSString *)key withDefault:(float)def {
    RETURN_VALUE(floatValue);
}

- (double)doubleForKey:(NSString *)key withDefault:(double)def {
    RETURN_VALUE(doubleValue);
}

- (NSInteger)integerForKey:(NSString *)key withDefault:(NSInteger)def {
    RETURN_VALUE(integerValue);
}

- (NSUInteger)unsignedIntegerForKey:(NSString *)key withDefault:(NSUInteger)def {
    RETURN_VALUE(unsignedIntegerValue);
}

- (NSNumber *)numberForKey:(NSString *)key withDefault:(NSNumber *)def {
    if (!key) return def;
    id value = self[key];
    if (!value || value == [NSNull null]) return def;
    if ([value isKindOfClass:[NSNumber class]]) return value;
    if ([value isKindOfClass:[NSString class]]) {
        NSNumber *num = NSNumberFromID(value);
        if (!num) num = def;
        return num;
    }
    return def;
}

- (NSString *)stringForKey:(NSString *)key withDefault:(NSString *)def {
    if (!key) return def;
    id value = self[key];
    if (!value || value == [NSNull null]) return def;
    if ([value isKindOfClass:[NSString class]]) return value;
    if ([value isKindOfClass:[NSNumber class]]) return ((NSNumber *)value).description;
    if ([value isKindOfClass:[NSURL class]]) return ((NSURL *)value).absoluteString;
    return def;
}

- (BOOL)boolForKey:(NSString *)key; {return [self boolForKey:key withDefault:NO];}
- (char)charForKey:(NSString *)key; {return [self charForKey:key withDefault:NO];}
- (unsigned char)unsignedCharForKey:(NSString *)key; {return [self unsignedCharForKey:key withDefault:0];}
- (short)shortForKey:(NSString *)key; {return [self shortForKey:key withDefault:0];}
- (unsigned short)unsignedShortForKey:(NSString *)key; {return [self unsignedShortForKey:key withDefault:0];}
- (int)intForKey:(NSString *)key; {return [self intForKey:key withDefault:0];}
- (unsigned int)unsignedIntForKey:(NSString *)key; {return [self unsignedIntForKey:key withDefault:0];}
- (long)longForKey:(NSString *)key; {return [self longForKey:key withDefault:0];}
- (unsigned long)unsignedLongForKey:(NSString *)key; {return [self unsignedLongForKey:key withDefault:0];}
- (long long)longLongForKey:(NSString *)key; {return [self longLongForKey:key withDefault:0];}
- (unsigned long long)unsignedLongLongForKey:(NSString *)key; {return [self unsignedLongLongForKey:key withDefault:0];}
- (float)floatForKey:(NSString *)key; {return [self floatForKey:key withDefault:0];}
- (double)doubleForKey:(NSString *)key; {return [self doubleForKey:key withDefault:0];}
- (NSInteger)integerForKey:(NSString *)key; {return [self integerForKey:key withDefault:0];}
- (NSUInteger)unsignedIntegerForKey:(NSString *)key; {return [self unsignedIntegerForKey:key withDefault:0];}
- (NSNumber *)numberForKey:(NSString *)key; {return [self numberForKey:key withDefault:nil];}
- (NSString *)stringForKey:(NSString *)key; {return [self stringForKey:key withDefault:nil];}

@end
