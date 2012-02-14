//
//  Level.m
//  oneD
//
//  Created by Taylor O'Brien on 2/13/12.
//  Copyright (c) 2012 T.M. O'Brien. All rights reserved.
//

#import "Level.h"

@implementation Level

- (Level*) init {
    if ( self = [super init] ) {
        _maze = new Maze(5,5);
    }
    
    return self;
}

- (Level*) initWithRows:(uint)rows Columns:(uint)cols {
    if ( self = [super init] ) {
        _maze = new Maze(rows, cols);
    }
    
    return self;
}

- (void) dealloc {
    delete _maze;
}

- (Spot) getSpotAtRow:(int)row Column:(int)col {
    return _maze->get(row,col);
}

- (uint) width {
    return _maze->width();
}

- (uint) height {
    return _maze->height();
}

@end
