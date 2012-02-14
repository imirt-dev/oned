//
//  Shader.fsh
//  oneD
//
//  Created by Taylor O'Brien on 2/13/12.
//  Copyright (c) 2012 T.M. O'Brien. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
