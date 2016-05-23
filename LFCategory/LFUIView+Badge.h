//
//  UIView+Badge.h
//  LaiFeng
//
//  Created by limingchen on 15/8/11.
//  Copyright (c) 2015年 live Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark -- types definition
typedef NS_ENUM(NSUInteger, LFBadgeType)
{
    LFBadgeTypeRedDot = 0,          /* red dot type */
    LFBadgeTypeNumber,              /* badge with number */
    LFBadgeTypeNew                  /* badge with a fixed text "new" */
};

typedef NS_ENUM(NSUInteger, LFBadgeStyle)
{
    LFBadgeStyleNormal = 0,          /* badge style rectangle  */
    LFBadgeStyleCircle,              /* badge style circle */
};

typedef NS_ENUM(NSUInteger, LFBadgeSizeType) {
    LFBadgeSizeTypeNormal = 0,      /* badge size systom */
    LFBadgeSizeTypeCustom = 1       /* badge size custom */
};


#pragma mark -- badge apis

@interface UIView (LFBadgeAdditons)

@property (nonatomic, strong) UILabel *badge;
@property (nonatomic) CGFloat badgeOriginX;
@property (nonatomic) CGFloat badgeOriginY;
@property (nonatomic) BOOL showAllNumbers;//<展示完整的数字 (默认超过100展示99+)  等于0也展示

/**
 *  show badge with red dot style and WBadgeAnimTypeNone by default.
 */
- (void)showRedDotBadge;
- (void)showRedDotBadgeBySizeType:(LFBadgeSizeType)sizeType;
- (void)showRedDotBadgeByStyle:(LFBadgeStyle)style;
- (void)showRedDotBadgeByStyle:(LFBadgeStyle)style sizeType:(LFBadgeSizeType)sizeType;

/**
 * show badge with WBadgeStyleNumber style
 */
- (void)showNewBadge;
- (void)showNewBadgeBySizeType:(LFBadgeSizeType)sizeType;
- (void)showNewBadgeByStyle:(LFBadgeStyle)style;
- (void)showNewBadgeByStyle:(LFBadgeStyle)style sizeType:(LFBadgeSizeType)sizeType;

/**
 * show badge with showNumberBadgeWithValue style
 */
- (void)showNumberBadge:(NSInteger)value;
- (void)showNumberBadge:(NSInteger)value sizeType:(LFBadgeSizeType)sizeType;
- (void)showNumberBadge:(NSInteger)value style:(LFBadgeStyle)style;
- (void)showNumberBadge:(NSInteger)value style:(LFBadgeStyle)style sizeType:(LFBadgeSizeType)sizeType;

/**
 *  clear badge
 */
- (void)clearBadge;

/**
 *  get current badgeType
 */
- (LFBadgeType)getBadgeType;

/**
 *  get bage show
 *
 */

- (BOOL)isShowBage;

@end
