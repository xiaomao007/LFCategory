//
//  UIApplication+LFAdd.h
//
//
//  Created by guoyaoyuan on 13-4-4.
//  Copyright (c) 2013 live Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

/// Returns "Documents" folder in this app's sandbox.
NSString *NSDocumentsPath(void);

/// Returns "Library" folder in this app's sandbox.
NSString *NSLibraryPath(void);

/// Returns "Caches" folder in this app's sandbox.
NSString *NSCachesPath(void);


/**
 Provides extensions for `UIApplication`.
 */
@interface UIApplication (LFAdditions)

/// "Documents" folder in this app's sandbox.
@property (nonatomic, readonly) NSURL *lf_documentsURL;

/// "Caches" folder in this app's sandbox.
@property (nonatomic, readonly) NSURL *lf_cachesURL;

/// "Library" folder in this app's sandbox.
@property (nonatomic, readonly) NSURL *lf_libraryURL;

/// Application's Bundle Name (show in SpringBoard).
@property (nonatomic, readonly) NSString *lf_appBundleName;

/// Application's Bundle ID.  e.g. "com.live Interactive.MyApp"
@property (nonatomic, readonly) NSString *lf_appBundleID;

/// Application's Version.  e.g. "1.2.0"
@property (nonatomic, readonly) NSString *lf_appVersion;

/// Application's Build number. e.g. "123"
@property (nonatomic, readonly) NSString *lf_appBuildVersion;

/// Current thread real memory used in byte. (-1 when error occurs)
@property (nonatomic, readonly) int64_t lf_memoryUsage;

/// Current thread CPU usage, 1.0 means 100%. (-1 when error occurs)
@property (nonatomic, readonly) float lf_cpuUsage;


/// App是否被破解了
/// Whether this app is priated (not from appstore).
@property (nonatomic, readonly) BOOL lf_isPirated;

/// App是否正在被调试
/// Whether this app is being debugged (debugger attached).
@property (nonatomic, readonly) BOOL lf_isBeingDebugged;

@end
