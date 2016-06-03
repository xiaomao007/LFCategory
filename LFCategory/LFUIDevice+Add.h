//
//  UIDevice+Add.h
//
//
//  Created by guoyaoyuan on 13-4-3.
//  Copyright (c) 2013 live Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <mach/host_info.h>
/**
 Provides extensions for `UIDevice`.
 */

typedef void (^ cameraAuthorziedBlock) (void);

@interface UIDevice (LFAdditions)



#pragma mark - Device Information
///=============================================================================
/// @name Device Information
///=============================================================================

/// Whether the device is iPad/iPad mini.
@property (nonatomic, readonly) BOOL lf_isPad;

/// Whether the device is a simulator.
@property (nonatomic, readonly) BOOL lf_isSimulator;

/// Wherher the device can make phone calls.
@property (nonatomic, readonly) BOOL lf_canMakePhoneCalls;

/// The device's machine model.  e.g. "iPhone6,1" "iPad4,6"
/// @see http://theiphonewiki.com/wiki/Models
@property (nonatomic, readonly) NSString *lf_machineModel;

/// The device's machine model name. e.g. "iPhone 5s" "iPad mini 2"
/// @see http://theiphonewiki.com/wiki/Models
@property (nonatomic, readonly) NSString *lf_machineModelName;

/// 屏幕大小，高大于宽
+ (CGSize) lf_screenSize;

/// 系统版本，以float形式返回
- (CGFloat)lf_systemVersionByFloat;

/// 系统版本，以float形式返回
+ (CGFloat)lf_systemVersionByFloat;

#pragma mark - Disk Space
///=============================================================================
/// @name Disk Space
///=============================================================================

/// Total disk space in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_diskSpace;

/// Free disk space in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_diskSpaceFree;

/// Used disk space in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_diskSpaceUsed;


#pragma mark - Memory Information
///=============================================================================
/// @name Memory Information
///=============================================================================

/// Total physical memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryTotal;

/// Used (active + inactive + wired) memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryUsed;

/// Free memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryFree;

/// Acvite memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryActive;

/// Inactive memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryInactive;

/// Wired memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryWired;

/// Purgable memory in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryPurgable;

@property (nonatomic,copy ,readonly) NSString *lf_CPUType;
@property (nonatomic,copy ,readonly) NSString *lf_CPUSubtype;

#pragma mark - System version compare
///=============================================================================
/// @name System version compare
///=============================================================================

- (BOOL)lf_systemVersionLowerThan:(NSString*)version;
- (BOOL)lf_systemVersionNotHigherThan:(NSString *)version;
- (BOOL)lf_systemVersionHigherThan:(NSString*)version;
- (BOOL)lf_systemVersionNotLowerThan:(NSString *)version;

#pragma mark - Others
///=============================================================================
/// @name Others
///=============================================================================

/// 设备是否越狱
/// Whether the device is jailbroken.
@property (nonatomic, readonly) BOOL lf_isJailbroken;

//
+ (void)lf_cameraAuthorzied:(cameraAuthorziedBlock)authorizedBlock notAuthorized:(cameraAuthorziedBlock)notAuthorizedlock;
-(NSString*)lf_deviceID;

@end
