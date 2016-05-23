//
//  UINavigationController+LFAdd.h
//  LaiFeng
//
//  Created by limingchen on 15/3/2.
//  Copyright (c) 2015年 youku&tudou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationController (LFAdditions)

- (void)pushViewController: (UIViewController*)controller
    animatedWithTransition: (UIViewAnimationTransition)transition;
- (UIViewController*)popViewControllerAnimatedWithTransition:(UIViewAnimationTransition)transition;

@end
