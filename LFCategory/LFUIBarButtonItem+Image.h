//
//  UIBarButtonItem+Image.h
//  LaiFeng
//
//  Created by xinliu on 14-4-25.
//  Copyright (c) 2014年 live Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIBarButtonItem (LFCustomImageAdditions)

+ (UIBarButtonItem *)rsBarButtonItemWithTitle:(NSString *)title
                                       target:(id)target
                                       action:(SEL)selector;
// 可扩展
+ (UIBarButtonItem *)rsBarButtonItemWithTitle:(NSString *)title 
                                        image:(UIImage *)image
                             heightLightImage:(UIImage *)hlImage
                                 disableImage:(UIImage *)disImage
                                       target:(id)target
                                       action:(SEL)selector;

+ (UIBarButtonItem *)rsLeftBarButtonItemWithTitle:(NSString *)title
                                            image:(UIImage *)image
                                 heightLightImage:(UIImage *)hlImage
                                     disableImage:(UIImage *)disImage
                                           target:(id)target
                                           action:(SEL)selector;

+ (UIBarButtonItem *)rsBarButtonItemWithBellButton:(UIButton *)bellButton
                                             image:(UIImage *)image
                                  heightLightImage:(UIImage *)hlImage
                                      disableImage:(UIImage *)disImage
                                            target:(id)target
                                            action:(SEL)selector;

+ (UIButton*)rsCustomBarButtonWithTitle:(NSString*)title
                                  image:(UIImage *)image
                       heightLightImage:(UIImage *)hlImage
                           disableImage:(UIImage *)disImage
                                 target:(id)target
                                 action:(SEL)selector;

- (void)setButtonAttribute:(NSDictionary*)dic;

@end

@interface UIToolbar(UIToolbar_Image)

// 设置底边条背景图片
//- (void)setToolBarWithImageKey:(NSString *)imageKey;

- (void)setToolBarWithImage:(UIImage *)image;
// 清空底边条的背景图片，使恢复到系统默认状态
- (void)clearToolBarImage;


@end

