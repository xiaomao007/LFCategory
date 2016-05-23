//
//  NSKeyedUnarchiver+LFAdd.m
//
//
//  Created by guoyaoyuan on 14-8-4.
//  Copyright (c) 2014 live Interactive. All rights reserved.
//

#import "LFNSKeyedUnarchiver+Add.h"
#import "LFCategoryMacro.h"


@implementation NSKeyedUnarchiver (LFNSKeyedUnarchiverAdditions)

+ (id)unarchiveObjectWithData:(NSData *)data exception:(__autoreleasing NSException **)exception {
    id object = nil;
    @try {
        object = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    }
    @catch (NSException *e)
    {
        if (exception) *exception = e;
    }
    @finally
    {
    }
    return object;
}

+ (id)unarchiveObjectWithFile:(NSString *)path exception:(__autoreleasing NSException **)exception {
    id object = nil;
    
    @try {
        object = [NSKeyedUnarchiver unarchiveObjectWithFile:path];
    }
    @catch (NSException *e)
    {
        if (exception) *exception = e;
    }
    @finally
    {
    }
    return object;
}

@end
