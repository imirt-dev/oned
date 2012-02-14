//
//  Level.h
//  oneD
//
//  Created by Taylor O'Brien on 2/13/12.
//  Copyright (c) 2012 T.M. O'Brien. All rights reserved.
//

#include "Maze.h"
#import <Foundation/Foundation.h>

@interface Level : NSObject {
    Maze* _maze;
}

- (Level*) init;
- (Level*) initWithRows:(uint)rows Columns:(uint)cols;
- (void) dealloc;

- (int) getSpotAtRow:(int)row Column:(int)col;
- (uint) width;
- (uint) height;

@end
