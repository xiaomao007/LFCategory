# LFCategory
 Laifeng的所有Category。  可以被引入全局的 pch 文件。  尽量避免有其他依赖。
 
说明文档：

LFCategory 与原工程中内容差异方法

1，LFUIView+LFAdd
删除如下个方法：
//>处理错误
- (void)dealWithError:(ExError*)error;

2，删除LFUIImage+Resource.h .m 文件

+ (UIImage*)LFImageNamed:(NSString*)name;
+ (UIImage*)LFEmotionWithName:(NSString*)name;

3，LFUIBarButtonItem+Image.h 
//>删除方法
- (void)setToolBarWithImageKey:(NSString *)imageKey;

4，LFUIImage+Scale.h
//>删除方法
+ (UIImage*)middleStretchableImageWithKey:(NSString*)key;

5，LFCategory.h 

删除的引用
#import "NSObject+LFPersistence.h"
#import "LFUIImage+Resource.h"
// Text
#import "NSAttributedString+LFText.h"
#import "NSParagraphStyle+LFText.h"
#import "LFRichTextRunDelegate.h"



