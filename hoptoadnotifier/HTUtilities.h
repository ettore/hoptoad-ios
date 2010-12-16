//
//  HTUtilities.h
//  HoptoadNotifier
//
//  Created by Caleb Davenport on 10/13/10.
//  Copyright 2010 GUI Cocoa, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

/*
 The HTUtilities class contains a set of utility methods
 that perform various tasks that assist the notifier.
 */
@interface HTUtilities : NSObject {

}


/*
 returns a path for a notice given a name with the correct
 extension
 */
+ (NSString *)noticePathWithName:(NSString *)name;

/*
 substitute common variables into string
 */
+ (NSString *)stringByReplacingHoptoadVariablesInString:(NSString *)string;


/*
 returns the application version
 
 every app should have a CFBundleVersion some apps have a
 CFBundleShortVersionString if it has both, this method will
 return "CFBundleVersion (CFBundleShortVersionString)"
 */
+ (NSString *)applicationVersion;

/*
 returns a display name for the application
 
 this method will attempt to return the CFBundleDisplayName
 if that isn't set, it will return CFBundleIdentifier
 */
+ (NSString *)bundleDisplayName;

/*
 returns the current platform
 
 if the app is running in the simulator this simply returns
 "iPhone Simulator" otherwise, it first get the hardware
 model. ex. "iPhone1,2"
 
 if possible, this will be matched with a common string
 the returned result is often of the form
 "iPhone 4 (iPhone3,1)"
 */
+ (NSString *)platform;

#if TARGET_OS_IPHONE
/*
 return the class name of the on screen view controller.
 
 this does not indicate the controller where the crash
 occured, simply the one that has a view on screen
 
 if the HTNotifier delegate implements
 -rootViewControllerForNotice, the heirarchy of the returned
 controller will be inspected
 
 if not, the rootViewController of the key window will be
 inspected (if it exists)
 */
+ (NSString *)currentViewController;

/*
 return the name of the visible view controller given a
 starting view controller.
 
 this method makes assumptions about tab and nav controllers
 and will traverse the view heirarchy until an unknown
 controller is encountered - this is often the onscreen
 controller
 
 this method is called by +currentViewController
 */
+ (NSString *)visibleViewControllerWithViewController:(UIViewController *)controller;
#endif

@end
