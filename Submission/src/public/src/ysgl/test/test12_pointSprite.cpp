/* ////////////////////////////////////////////////////////////

File Name: test12_pointSprite.cpp
Copyright (c) 2015 Soji Yamakawa.  All rights reserved.
http://www.ysflight.com

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//////////////////////////////////////////////////////////// */

/*
 *  testapp.cpp
 *  FsSimpleWindow
 *
 *  Created by Soji Yamakawa on 11/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <fssimplewindow.h>
#include <ysgl.h>


#if !defined(GL_PROGRAM_POINT_SIZE) && defined(GL_PROGRAM_POINT_SIZE_EXT)
#define GL_PROGRAM_POINT_SIZE GL_PROGRAM_POINT_SIZE_EXT
#endif


static GLuint texId=0;

static YsGLSL3DRenderer *pointSpriteRenderer;
static int pointSpriteMode=YSGLSL_POINTSPRITE_SIZE_IN_3DSPACE;

const unsigned char groundTileTexture[16*16]=
{
	247,235,252,241,238,246,232,247,244,240,245,238,236,230,239,248,
	249,255,237,241,239,239,248,248,237,245,237,239,236,248,237,238,
	233,237,254,236,237,239,245,238,248,236,243,248,251,233,241,251,
	238,240,240,235,250,234,253,238,236,246,251,234,236,238,233,240,
	231,244,240,240,244,253,237,244,234,244,247,244,255,246,242,254,
	237,252,230,235,230,233,242,240,232,242,246,255,232,241,240,251,
	245,254,237,233,251,231,248,246,239,245,232,246,238,254,243,243,
	246,249,247,242,246,252,245,250,254,246,252,242,238,243,236,231,
	255,238,236,244,240,249,232,241,245,253,252,246,249,249,249,241,
	249,237,241,245,231,244,230,249,255,242,239,230,252,255,234,232,
	241,255,253,247,240,248,242,246,241,231,243,253,251,232,250,238,
	250,232,231,231,235,247,238,230,237,233,250,241,255,233,244,240,
	255,246,248,242,232,247,247,237,241,233,254,237,241,241,238,244,
	237,232,232,233,237,239,234,244,251,239,253,255,252,238,232,244,
	231,242,241,246,244,250,253,231,236,254,236,233,251,247,250,240,
	242,252,244,243,234,240,232,244,255,243,234,252,251,245,237,249
};

GLuint MakeTextureTile(void)
{
	unsigned char rgba[16*16*4];
	for(int i=0; i<256; i++)
	{
		rgba[i*4  ]=groundTileTexture[i];
		rgba[i*4+1]=groundTileTexture[i];
		rgba[i*4+2]=groundTileTexture[i];
		rgba[i*4+3]=255;
	}
	
	GLuint ysScnGlMapTex;
	glGenTextures(1,&ysScnGlMapTex);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,ysScnGlMapTex);
	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	
	glTexImage2D
	(GL_TEXTURE_2D,
	 0,
	 GL_RGBA,
	 16,
	 16,
	 0,
	 GL_RGBA,
	 GL_UNSIGNED_BYTE,
	 rgba);
	
	return ysScnGlMapTex;
}


void FsSimpleWindowIntervalCallBack(void)
{
	int winWid,winHei;
	FsGetWindowSize(winWid,winHei);

	int lb,mb,rb,mx,my;
	FsGetMouseEvent(lb,mb,rb,mx,my);

	float r=1.0,g=0.0,b=0.0,a=1.0;

	
	if(0==texId)
	{
		texId=MakeTextureTile();
	}
	
	
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	

	GLfloat spriteVtx[]=
	{
		1,1,1,
		-1,1,1,
		1,-1,1,
		-1,-1,1,
		1,1,-1,
		-1,1,-1,
		1,-1,-1,
		-1,-1,-1,
	};
	GLfloat spriteColor[]=
	{
		0,0,1, 1,
		0,1,0, 1,
		1,0,0, 1,
		1,0,1, 1,
		1,1,0, 1,
		1,1,1, 1,
		0,0,1, 1,
		0,1,0, 1,
	};
	GLfloat spriteTexOrigin[]=
	{
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f
	};
	GLfloat spriteSizePixel[]=
	{
		10,
		20,
		30,
		40,
		50,
		60,
		70,
		80
	};
	GLfloat spriteSize3d[]=
	{
		1.0f,
		1.0f,
		1.0f,
		1.0f,
		1.0f,
		1.0f,
		1.0f,
		1.0f
	};
	const int nVtx=(sizeof(spriteVtx)/(3*sizeof(GLfloat)));
	
	struct YsGLSL3DRenderer *renderer=pointSpriteRenderer;


	glDisable(GL_DEPTH_TEST);

	glEnable(GL_PROGRAM_POINT_SIZE);  // Needed for enabling gl_PointSize in the vertex shader.
	glEnable(GL_POINT_SPRITE);        // Needed for enabling gl_PointCoord in the fragment shader.

	YsGLSLUsePlain2DRenderer(YsGLSLSharedPlain2DRenderer());
	YsGLSLUseWindowCoordinateInPlain2DDrawing(YsGLSLSharedPlain2DRenderer(),1);
	YsGLSLDrawPlain2DLinef(YsGLSLSharedPlain2DRenderer(),mx-10,my-10,mx+10,my+10,r,g,b,a);
	YsGLSLDrawPlain2DLinef(YsGLSLSharedPlain2DRenderer(),mx+10,my-10,mx-10,my+10,r,g,b,a);
	
	YsGLSLEndUsePlain2DRenderer(YsGLSLSharedPlain2DRenderer());

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	
	glEnable(GL_DEPTH_TEST);

	static double hdg=0.0;

	YsGLSLUse3DRenderer(renderer);

	YsGLSLSet3DRendererPointSpriteClippingType(renderer,YSGLSL_POINTSPRITE_CLIPPING_CIRCLE);

	GLfloat modelview[16],projection[16],tfm[16];
	YsGLMakeIdentityfv(modelview);
	YsGLMakeTranslationfv(tfm,0.0f,0.0f,-5.0f);
	YsGLMultMatrixfv(modelview,modelview,tfm);
	YsGLMakeXZRotationfv(tfm,(float)hdg);
	YsGLMultMatrixfv(modelview,modelview,tfm);
	YsGLSLSet3DRendererModelViewfv(renderer,modelview);
	
	YsGLMakePerspectivefv(projection,YSGLPI/6.0,(float)winWid/(float)winHei,1.0,50.0);
	YsGLSLSet3DRendererProjectionfv(renderer,projection);

	YsGLSLSet3DRendererViewportDimensionf(renderer,(float)winWid,(float)winHei);
	YsGLSLSet3DRendererPointSizeMode(renderer,pointSpriteMode);
	YsGLSLSet3DRendererTextureType(renderer,YSGLSL_TEX_TYPE_BILLBOARD);

	const GLfloat *spriteSize=(YSGLSL_POINTSPRITE_SIZE_IN_PIXEL==pointSpriteMode ? spriteSizePixel : spriteSize3d);
	YsGLSLDrawPrimitiveVtxTexCoordColPointSizefv(renderer,GL_POINTS,nVtx,spriteVtx,spriteTexOrigin,spriteColor,spriteSize);

	YsGLSLEndUse3DRenderer(renderer);

	hdg+=0.01;

	FsSwapBuffers();
}

int main(void)
{
	FsOpenWindow(16,16,800,600,1);

	double rot=0.0;
	int fogEnabled=0;

	YsGLSLCreateSharedRenderer();

	pointSpriteRenderer=YsGLSLCreateVariColorPointSprite3DRenderer();

	for(int key=FSKEY_NULL; FSKEY_ESC!=key; FsSleep(10))
	{
		FsPollDevice();
		key=FsInkey();
		FsSimpleWindowIntervalCallBack();

		if(FSKEY_F==key)
		{
			fogEnabled=1-fogEnabled;

			//YsGLSLUse3DRenderer(flatRenderer);
			//YsGLSLSet3DRendererUniformFogEnabled(flatRenderer,fogEnabled);
			//YsGLSLSet3DRendererUniformFogDensity(flatRenderer,.07);
			//YsGLSLEndUse3DRenderer(flatRenderer);

			//YsGLSLUse3DRenderer(variColRenderer);
			//YsGLSLSet3DRendererUniformFogEnabled(variColRenderer,fogEnabled);
			//YsGLSLSet3DRendererUniformFogDensity(variColRenderer,.08);
			//YsGLSLEndUse3DRenderer(variColRenderer);
		}
		else if(FSKEY_SPACE==key)
		{
			pointSpriteMode=1-pointSpriteMode;
		}
	}

	YsGLSLDeleteSharedRenderer();

	return 0;
}


