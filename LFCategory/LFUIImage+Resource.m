//
//  UIImage+Resource.m
//  LaiFeng
//
//  Created by xinliu on 14-4-24.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import "LFUIImage+Resource.h"
#import "LFUIImage+Add.h"
#import "LFNSBundle+Add.h"
#import "LFNSString+Add.h"




#define LFImagePath(name) [NSString stringWithFormat:@"skin_common.bundle/Images/%@",(name)]

#define LFEmotionPath(name) [NSString stringWithFormat:@"skin_common.bundle/Images/emotions/%@",(name)]

@implementation UIImage(LFResourceAdditions)

+(UIImage *)LFImageNamed:(NSString *)name
{
    //Debug OK
    return [[self class] imageForKey:name];
}

+ (UIImage *)LFEmotionWithName:(NSString *)name
{
    //Debug OK
    NSString* imagePath = LFEmotionPath(name);
    UIImage* emotion = [UIImage imageNamed:imagePath];
    return emotion;
}

//+(UIImage*)imageForKey:(NSString *)key
//{
//    if (key.length == 0) return nil;
//    UIImage* image = [ResourceManager shareInstance].resImagesCache[key];
//    if(!image) {
//        image = [UIImage imageForKey:key inBundle:[ResourceManager shareInstance].commonBundle];
//        image = [image imageByDecoded];
//        if(image) {
//            [[ResourceManager shareInstance].resImagesCache setObject:image forKey:key];
//        }
//    }
//    return image;
//}

+ (UIImage *)imageForKey:(id)key inBundle:(NSBundle *)bundle
{
    NSString *imagePath = [bundle pathForScaledResource:key ofType:@"png" inDirectory:@"Images"];
    if (!imagePath) imagePath = [bundle pathForScaledResource:key ofType:@"jpg" inDirectory:@"Images"];
    
    if (imagePath) {
        NSData *data = [NSData dataWithContentsOfFile:imagePath];
        return [UIImage imageWithData:data scale:imagePath.pathScale];
    } else
    {
        imagePath = [bundle pathForResource:key ofType:@"png" inDirectory:@"Images/emotions"];
        if(imagePath) {
            return [UIImage imageWithContentsOfFile:imagePath];
        }
    }
    imagePath = [bundle pathForResource:key ofType:@"jpg" inDirectory:@"Images"];
    if (imagePath) {
        return [UIImage imageWithContentsOfFile:imagePath];
    }
    
    if ( [key isKindOfClass:[NSString class]] ) {
        NSString *key2x = [key stringByAppendingString:@"@2x"];
        if ( [bundle pathForResource:key2x ofType:@"png"]
            || [bundle pathForResource:key2x ofType:@"jpg"] ) {
            NSLog(@"ERROR: No 1x image resource (low resolution) provided for key:%@, only have 2x image.",key);
        }
    }
    return nil;
}

@end
