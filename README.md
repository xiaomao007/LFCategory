# LFCategory
 Laifeng的所有Category。  可以被引入全局的 pch 文件。  尽量避免有其他依赖。
 
LFCategory 说明文档：
LFCategory 与原工程中内容差异方法

1，UIView+LFAdd
删除如下四个方法：
//>显示转菊花
- (void)showChrysanthemumHUD:(BOOL)animated;

//>显示消息
- (void)showTimedHUD:(BOOL)animated message:(NSString *)message;
- (MBProgressHUD *)showTimedHUD:(BOOL)animated message:(NSString *)message andHideAfter:(NSTimeInterval)time;

//>删除
- (void)removeAllHUDViews:(BOOL)animated;

//>处理错误
- (void)dealWithError:(ExError*)error;

2，LFCategory.h
删除的引用
#import "NSObject+LFPersistence.h"
// Text
#import "NSAttributedString+LFText.h"
#import "NSParagraphStyle+LFText.h"
#import "LFRichTextRunDelegate.h"

