//
//  YLColorEditActionView.h
//  YLSipColor
//
//  Created by lumin on 2018/1/14.
//  Copyright © 2018年 https://github.com/lqcjdx. All rights reserved.
//  颜色编辑

#import <UIKit/UIKit.h>
@class YLPalette;
@class YLColorEditActionView;

static CGFloat const kActionSmallHeight = 60.f;
static CGFloat const kActionBigHeight = 410.f;

typedef NS_ENUM(NSInteger, YLActionType) {
    YLActionTypeBeginEdit,
    YLActionTypeEndEdit,
    YLActionTypeClose,
    YLActionTypeRedo,
    YLActionTypeAdd,
    YLActionTypeDone,
    YLActionTypeSlider,
};

@protocol YLColorEditActionViewDelegate <NSObject>
- (void)actionView:(YLColorEditActionView *)actionView actionType:(YLActionType)type oldColor:(UIColor *)oldColor newColor:(UIColor *)newColor;
- (void)actionView:(YLColorEditActionView *)actionView scrollToPoint:(CGPoint)point;
@end

@interface YLColorEditActionView : UIView
@property (nonatomic, assign) BOOL isBig;
@property (nonatomic, weak) id <YLColorEditActionViewDelegate> delegate;

- (void)refreshWithPalette:(YLPalette *)palette;
- (void)scrolToPoint:(CGPoint)point;

@end
