/* ////////////////////////////////////////////////////////////

File Name: fsgui3dicon.cpp
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

#include "fsgui3dicon.h"

unsigned char FsGui3DIcon::AttitudeIndicator[331]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x06,0x00,0x00,0x01,0x68,0xf4,0xcf,
	0xf7,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x04,0x18,0x35,
	0x29,0x0e,0xeb,0xef,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0xda,0x49,0x44,0x41,
	0x54,0x78,0xda,0xad,0x52,0x89,0x11,0x02,
	0x21,0x0c,0x4c,0xae,0x07,0x9f,0xe6,0xb4,
	0x0d,0x2d,0x41,0xdb,0xd0,0xe6,0x7c,0x8a,
	0x88,0x2c,0x26,0x81,0xc0,0x71,0x73,0xce,
	0xb8,0x33,0xdc,0x41,0xc8,0x86,0xcd,0x43,
	0x22,0x42,0x09,0xc2,0xf8,0x5c,0x68,0x43,
	0xac,0x16,0xe2,0x74,0xca,0xbb,0x6c,0xe1,
	0xfb,0xf3,0x6b,0x36,0x83,0xe1,0xca,0x5b,
	0x21,0x8b,0x82,0x95,0xbd,0xe9,0xf6,0x28,
	0x2e,0xc7,0x7d,0x09,0x76,0x92,0x17,0x83,
	0xc2,0xea,0xca,0x21,0x28,0x33,0x4b,0xa2,
	0x52,0x40,0xa2,0xc3,0x31,0x33,0xba,0xcb,
	0x0a,0x9e,0x42,0x0b,0xbc,0x89,0xc8,0x25,
	0xb5,0x74,0x30,0xc7,0x33,0xbd,0xc9,0x74,
	0x04,0x07,0x63,0xff,0x4f,0xa4,0x1c,0x76,
	0x3c,0x2d,0x66,0x00,0x91,0x75,0xa5,0xbc,
	0xc0,0x0a,0x88,0x9d,0xea,0x32,0x76,0x4f,
	0x40,0x2c,0x44,0x22,0x0a,0xfe,0xf5,0xb2,
	0xee,0x74,0x06,0x7d,0xd2,0x09,0xa1,0xc1,
	0x5e,0x8f,0x91,0x70,0x4d,0x3d,0xf8,0x87,
	0x42,0xd6,0xc4,0xe4,0x1c,0xd0,0xdc,0x79,
	0x27,0x66,0xeb,0xd8,0x92,0x17,0x82,0x0c,
	0x87,0x61,0x0d,0x50,0xe6,0x6e,0x40,0x7f,
	0x81,0x4f,0x1b,0x36,0x08,0xd2,0xf6,0x6a,
	0xd4,0x3f,0x1b,0x55,0x70,0x26,0x6b,0x28,
	0x0c,0x90,0xb4,0x4a,0xb6,0x92,0x43,0x17,
	0xe6,0xe4,0xd5,0xe7,0x51,0x9a,0x1f,0x51,
	0x04,0xd6,0xcf,0x3d,0x01,0x76,0xad,0x00,
	0x00,0x00,0x00,0x49,0x45,0x4e,0x44,0xae,
	0x42,0x60,0x82
};
unsigned char FsGui3DIcon::CrossHair[229]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x17,0x08,0x12,
	0xd8,0xa6,0x51,0xfc,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x74,0x49,0x44,0x41,
	0x54,0x78,0xda,0x85,0x51,0x49,0x12,0xc0,
	0x20,0x08,0x0b,0xfc,0xff,0xcf,0x54,0x44,
	0x56,0x3b,0x63,0x0f,0x0e,0x59,0x1a,0x52,
	0x0b,0x01,0x84,0xb1,0x1e,0x5a,0x13,0xf6,
	0x04,0x81,0xb2,0x72,0x90,0x6b,0x08,0xdd,
	0x4c,0xe6,0x0a,0xa9,0x0c,0x42,0xc7,0x1b,
	0xdc,0xa6,0x59,0xed,0x25,0x80,0x4a,0xda,
	0xc8,0x40,0xdd,0x67,0xec,0xd1,0xac,0x99,
	0x56,0xcc,0x29,0xca,0xe8,0x79,0x85,0xbe,
	0x5f,0xb9,0xd6,0x36,0x22,0x41,0xb6,0x6f,
	0x37,0xb3,0xee,0x80,0xfc,0x74,0x33,0xa7,
	0x98,0x64,0xc5,0xf4,0xb3,0x76,0xd6,0xf6,
	0x7e,0x5e,0xbb,0x63,0xf6,0x4a,0x1e,0x3b,
	0xf1,0xf3,0x2b,0xee,0x7f,0x87,0x6e,0xfa,
	0x00,0x48,0xfd,0x64,0xdf,0x89,0x23,0x8a,
	0xba,0x00,0x00,0x00,0x00,0x49,0x45,0x4e,
	0x44,0xae,0x42,0x60,0x82
};
unsigned char FsGui3DIcon::Lock[257]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x06,0x00,0x00,0x01,0x68,0xf4,0xcf,
	0xf7,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x04,0x28,0x29,
	0xe2,0x49,0x81,0x53,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x90,0x49,0x44,0x41,
	0x54,0x78,0xda,0xa5,0x92,0x41,0x0e,0xc0,
	0x20,0x08,0x04,0xc1,0xf8,0xff,0x2f,0xd3,
	0x62,0xc0,0x02,0x0a,0xb6,0x29,0x17,0x89,
	0xac,0xec,0x40,0x04,0x22,0x82,0x3b,0xa8,
	0x81,0x04,0xca,0x0d,0x20,0x5f,0x8f,0x4c,
	0x35,0xab,0x16,0xd1,0x2b,0x54,0x35,0x9b,
	0x4c,0xe5,0x6c,0x26,0xd1,0x20,0xc4,0xe3,
	0x8b,0x9c,0x12,0xc6,0x7c,0x79,0x21,0xc6,
	0xa8,0x14,0xcd,0x21,0x05,0x44,0x3e,0xfb,
	0xae,0x90,0x32,0x58,0x8b,0x2d,0x35,0x17,
	0xac,0xbf,0x63,0xb0,0xaf,0xca,0xb9,0x17,
	0x86,0xb8,0xa9,0x68,0xb9,0x30,0x7c,0xb6,
	0x70,0x82,0x72,0x0f,0x95,0xa8,0xc2,0x70,
	0x0d,0xf4,0x71,0xb6,0x92,0x5d,0xfd,0x38,
	0xc3,0x71,0x8d,0xe3,0x1b,0x1e,0xb0,0xab,
	0x71,0x7e,0x13,0xf4,0xac,0x60,0xe7,0xac,
	0x08,0x53,0x02,0xfb,0xa7,0x2b,0x82,0x72,
	0x84,0x37,0xbb,0xb9,0x00,0x48,0xcd,0x6a,
	0x11,0x0f,0x7d,0xa5,0x11,0x00,0x00,0x00,
	0x00,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,
	0x82
};
unsigned char FsGui3DIcon::RollLeft[223]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x0b,0x15,0x05,
	0xb1,0x25,0xe2,0x33,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x6e,0x49,0x44,0x41,
	0x54,0x78,0xda,0x75,0x50,0x81,0x0d,0xc0,
	0x20,0x08,0x2b,0x86,0xff,0x5f,0x66,0x03,
	0x64,0x96,0x0c,0x1b,0xb3,0x00,0x6d,0xb1,
	0x53,0x0c,0xc0,0x82,0xc3,0xf2,0x18,0xc4,
	0x90,0x90,0x18,0x08,0x72,0x12,0x9f,0x54,
	0x5c,0x35,0x28,0xdd,0x3b,0xd2,0x6a,0x9c,
	0x75,0xa8,0xb7,0xd5,0xa0,0xee,0xfd,0x7c,
	0xbd,0xce,0x52,0xfb,0xca,0x3d,0xe0,0xa5,
	0x99,0x1d,0x67,0xed,0x1a,0x6f,0x61,0x44,
	0xe4,0x66,0xf1,0x92,0x2d,0x9c,0x69,0x1c,
	0xe8,0x9f,0x64,0x3f,0x09,0x26,0x92,0x52,
	0xdd,0xe8,0xf6,0x38,0x13,0x4d,0xff,0x35,
	0xd3,0x61,0x3e,0xb9,0x27,0xd1,0x66,0xfb,
	0x73,0x31,0x1e,0x50,0x4c,0x37,0x23,0xd2,
	0xe4,0xfd,0x55,0x00,0x00,0x00,0x00,0x49,
	0x45,0x4e,0x44,0xae,0x42,0x60,0x82
};
unsigned char FsGui3DIcon::RollRight[230]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x0b,0x18,0x29,
	0x36,0x53,0xf0,0x9d,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x75,0x49,0x44,0x41,
	0x54,0x78,0xda,0x6d,0x90,0x81,0x12,0xc0,
	0x30,0x04,0x43,0xa3,0xb7,0xff,0xff,0x65,
	0xa3,0xcc,0x52,0xe5,0xb6,0x1b,0xf1,0xaa,
	0x19,0x40,0x15,0xa2,0xf0,0xb0,0x0c,0xfb,
	0xd1,0xfd,0x29,0x5d,0x54,0xac,0x92,0x60,
	0xce,0x16,0xf0,0x04,0x11,0x6f,0xca,0xc1,
	0x16,0xe2,0xa9,0x4b,0xab,0x6a,0x23,0xbc,
	0x4b,0x42,0x72,0xa0,0xf3,0x1e,0xab,0x8f,
	0xaa,0x4c,0xd2,0x11,0xcd,0x88,0xde,0xfa,
	0xef,0xc8,0x19,0xfd,0x5a,0x9a,0xd1,0x88,
	0x38,0x62,0x14,0x7e,0xef,0xc7,0xac,0xcb,
	0x06,0x97,0x0c,0x35,0xe0,0x86,0xae,0x7f,
	0xef,0x6b,0x1b,0x80,0x13,0x19,0x01,0x76,
	0x31,0x78,0x60,0x31,0x96,0x31,0xc6,0xb7,
	0xdc,0x17,0x1b,0x1c,0x3f,0x0b,0x6a,0xf0,
	0x5e,0x82,0x00,0x00,0x00,0x00,0x49,0x45,
	0x4e,0x44,0xae,0x42,0x60,0x82
};
unsigned char FsGui3DIcon::Left90[227]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x17,0x11,0x24,
	0x8c,0x1c,0x6d,0x7d,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x72,0x49,0x44,0x41,
	0x54,0x78,0xda,0x75,0x8f,0x09,0x0e,0x80,
	0x30,0x08,0x04,0x59,0xd3,0xff,0x7f,0x19,
	0x0b,0xa5,0x9c,0x8a,0x09,0x12,0x18,0x70,
	0x04,0xd3,0x8e,0x9d,0x18,0x52,0x41,0x4a,
	0xad,0x24,0x9e,0x5b,0x79,0x47,0x49,0xa7,
	0x95,0x71,0xe2,0x3e,0x07,0xe0,0xb4,0x64,
	0x44,0x6b,0xd8,0xee,0xe9,0xe6,0xdc,0x89,
	0x3c,0x75,0x02,0x6a,0xe1,0x44,0x8a,0x30,
	0x30,0x8f,0x9d,0x50,0x4d,0x9a,0x18,0x05,
	0x7e,0xde,0xc3,0xa3,0xc7,0x33,0xef,0x85,
	0x9d,0xe4,0x55,0x8c,0x30,0x0f,0xae,0xd8,
	0x94,0xb1,0x18,0x56,0x08,0x6c,0xff,0x88,
	0xa6,0xef,0x00,0xfd,0x0c,0xc6,0x85,0x8f,
	0x01,0xb5,0x0f,0xde,0xb2,0xc2,0x2f,0xa2,
	0x27,0x4f,0xf7,0xa8,0xd7,0x01,0x90,0x00,
	0x00,0x00,0x00,0x49,0x45,0x4e,0x44,0xae,
	0x42,0x60,0x82
};
unsigned char FsGui3DIcon::Right90[229]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x17,0x11,0x14,
	0xaa,0xc5,0x5d,0xd1,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x74,0x49,0x44,0x41,
	0x54,0x78,0xda,0x85,0x50,0x09,0x12,0xc0,
	0x30,0x04,0xa4,0x93,0xff,0x7f,0x59,0xc9,
	0x76,0xc9,0xd5,0xd6,0x4c,0x10,0xec,0x3a,
	0xd4,0xc4,0xc5,0x95,0x69,0x7a,0x5d,0x85,
	0x56,0x37,0x1a,0x51,0xe4,0x5c,0x2e,0xfa,
	0x7b,0x2a,0x51,0xd0,0x86,0x8c,0x76,0x6a,
	0x14,0x54,0x29,0xbf,0xf6,0xf4,0x23,0x6c,
	0xa9,0xc8,0x7e,0x15,0x1f,0xfa,0xc2,0x5e,
	0x64,0x97,0x79,0x0e,0xbe,0x13,0xe9,0x1c,
	0xc9,0x39,0x86,0xc5,0x57,0xc8,0x2a,0x75,
	0x07,0x1b,0xbd,0x92,0x16,0x6b,0x7f,0xd1,
	0x34,0xae,0xb0,0x0d,0x23,0xb8,0xd8,0x0b,
	0x38,0x40,0x38,0xea,0xcf,0x90,0x6a,0x8d,
	0x84,0xdb,0x89,0xe4,0xc8,0xc0,0x6f,0x95,
	0xdf,0xe3,0x3e,0x5a,0xef,0x53,0x34,0x60,
	0xcc,0x00,0x00,0x00,0x00,0x49,0x45,0x4e,
	0x44,0xae,0x42,0x60,0x82
};
unsigned char FsGui3DIcon::OrthoPers[308]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xb9,0xd9,0xc5,
	0xb0,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x16,0x00,0x02,0x1e,
	0x98,0x9f,0x88,0x23,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0xc3,0x49,0x44,0x41,
	0x54,0x78,0xda,0x95,0x53,0x01,0x0e,0xc4,
	0x20,0x08,0x03,0xe3,0xff,0xbf,0xdc,0x9b,
	0x22,0x27,0x28,0xe2,0x46,0xe2,0xe2,0xb0,
	0xad,0x05,0x22,0x83,0x24,0x18,0x4c,0x78,
	0x96,0xc4,0x93,0x05,0xfa,0x97,0x15,0x20,
	0x69,0x68,0x1e,0x24,0x7b,0xcb,0xfa,0xc7,
	0x20,0xf1,0x38,0x92,0x5f,0x26,0xac,0x38,
	0x70,0x3f,0xe2,0x45,0xa2,0x2c,0x3a,0x62,
	0xcf,0x6a,0x72,0xb7,0x46,0x61,0x18,0x47,
	0x8c,0x13,0xc8,0x5d,0x63,0x3c,0xe2,0x0a,
	0x14,0xc5,0xb8,0x66,0x43,0xdf,0x1d,0x5a,
	0xed,0x51,0xb6,0x87,0x68,0x69,0xd3,0xbd,
	0x6b,0x9a,0x4d,0xef,0x6d,0xac,0xbb,0x52,
	0x4b,0xcb,0xb2,0xc4,0x42,0x41,0x44,0x6d,
	0xda,0xaa,0x8e,0x9b,0xe3,0x80,0x27,0x88,
	0x48,0x14,0xaf,0x97,0x8c,0x10,0x61,0xe2,
	0x36,0xf9,0x78,0xe0,0x8d,0x51,0x74,0xab,
	0xca,0x68,0x5b,0x8e,0xc4,0x26,0x26,0x3e,
	0x95,0x5c,0x51,0x47,0x7b,0xdb,0xbf,0x79,
	0xd3,0x5c,0x7d,0x4f,0xcc,0x2e,0x99,0x51,
	0x4e,0x07,0x56,0x2e,0x9b,0xd7,0x1a,0xf5,
	0x06,0xb0,0x4f,0xe8,0x8d,0xc7,0x7a,0x92,
	0x51,0xb2,0x7f,0x0e,0xf9,0xd5,0x7d,0x9c,
	0x14,0x96,0x93,0x0f,0x25,0x63,0xfc,0x00,
	0x35,0x4e,0x83,0x16,0x68,0x3a,0x60,0xd0,
	0x00,0x00,0x00,0x00,0x49,0x45,0x4e,0x44,
	0xae,0x42,0x60,0x82
};
unsigned char FsGui3DIcon::Up[200]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x0b,0x1b,0x2e,
	0x83,0x1a,0x36,0xfd,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x57,0x49,0x44,0x41,
	0x54,0x78,0xda,0xc5,0x4e,0x49,0x12,0xc0,
	0x30,0x08,0x52,0xff,0xff,0x67,0x1a,0x63,
	0xc8,0xde,0x71,0x7a,0xaa,0x87,0x44,0x04,
	0x11,0x85,0x94,0x2a,0x0f,0xd4,0x3b,0x13,
	0x42,0x01,0x1c,0x41,0x7d,0x50,0xb9,0x9d,
	0x0a,0xd2,0xc8,0x34,0x8d,0x82,0x4b,0x9d,
	0x61,0xe5,0x83,0xee,0x11,0x0e,0x4d,0xe1,
	0x53,0x26,0xb0,0xd1,0xc6,0x7f,0x5f,0xf9,
	0x76,0xf6,0x2d,0xc7,0x0c,0x68,0xbf,0x09,
	0x16,0xe5,0x24,0x4a,0x1d,0x8e,0x9b,0x69,
	0xa8,0x1f,0x04,0x0f,0x8f,0xb1,0x25,0x1b,
	0x4c,0x92,0x90,0x30,0x00,0x00,0x00,0x00,
	0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82

};
unsigned char FsGui3DIcon::Down[209]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x0b,0x1b,0x05,
	0x2f,0xa6,0xcf,0xbd,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x60,0x49,0x44,0x41,
	0x54,0x78,0xda,0xad,0x51,0xd1,0x12,0x80,
	0x20,0x08,0x1b,0xfd,0xff,0x3f,0x2f,0x01,
	0x41,0xd2,0xbc,0xba,0x2e,0x1e,0x10,0xb6,
	0x01,0xa2,0x20,0xc0,0x03,0xcd,0xa4,0x45,
	0xb0,0x08,0x84,0xa2,0xec,0x59,0x70,0x48,
	0xbe,0x06,0x26,0x55,0x71,0x6a,0x84,0x94,
	0xab,0x64,0xa9,0xd9,0x01,0xbd,0x87,0x1e,
	0x9f,0x7b,0xbc,0x04,0x7c,0x94,0x7b,0x03,
	0x7c,0xa0,0xfb,0xdc,0xa5,0x5e,0xcb,0xa9,
	0x4d,0xcf,0xc7,0xa1,0xff,0x0b,0xca,0x83,
	0xcf,0xd4,0xcd,0x16,0x23,0x19,0x7b,0x2c,
	0x85,0xf1,0x75,0x61,0x27,0x18,0xf7,0x22,
	0x1d,0x07,0x33,0x9c,0xba,0x00,0x00,0x00,
	0x00,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,
	0x82
};
unsigned char FsGui3DIcon::Left[200]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x0b,0x1b,0x20,
	0x64,0xa2,0x1b,0xfa,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x57,0x49,0x44,0x41,
	0x54,0x78,0xda,0xad,0x50,0x01,0x0a,0x00,
	0x21,0x08,0xdb,0xfa,0xff,0x9f,0x77,0x79,
	0x84,0x59,0x76,0x44,0x74,0x42,0x2a,0xba,
	0xe9,0x8c,0x02,0x40,0x54,0x4f,0xcf,0xec,
	0x49,0xd5,0x17,0x34,0x7b,0x7b,0x66,0xbd,
	0x02,0x4d,0x2d,0x4f,0xd0,0xb1,0x54,0xac,
	0x96,0x09,0x90,0x29,0xab,0x19,0xfb,0xc2,
	0xc8,0x72,0x65,0x61,0x28,0x25,0x9e,0x6c,
	0x49,0x88,0xad,0x8c,0x0f,0xc0,0xf8,0x01,
	0x49,0xd5,0xd5,0x8a,0x46,0xb7,0x10,0xaf,
	0xfb,0xf3,0x8a,0x07,0x49,0xdb,0x1f,0x15,
	0x8e,0xfd,0x11,0xf0,0x00,0x00,0x00,0x00,
	0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82

};
unsigned char FsGui3DIcon::Right[199]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x0b,0x28,0x27,
	0x0e,0xad,0xeb,0x69,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x56,0x49,0x44,0x41,
	0x54,0x78,0xda,0xad,0x4f,0x41,0x0e,0xc0,
	0x30,0x08,0x82,0xfe,0xff,0xcf,0x6c,0x66,
	0x6b,0x13,0xd1,0x35,0x5b,0x32,0x0f,0x2d,
	0x41,0x44,0xa4,0x00,0x10,0xe7,0xcb,0x8c,
	0xa2,0xc6,0xfd,0x77,0x0c,0x64,0xad,0x05,
	0xe0,0xda,0xd9,0x1d,0x26,0xa8,0x23,0x7b,
	0x0f,0x23,0x2e,0x71,0xd9,0xb2,0x92,0x35,
	0xa6,0x01,0xc5,0x34,0x22,0xbe,0xc9,0xb1,
	0x89,0xf1,0x49,0x40,0x4d,0xeb,0x12,0x33,
	0x97,0xa5,0xec,0xbd,0x1e,0xe9,0x38,0xea,
	0x8f,0x2b,0x0e,0x72,0xb9,0x1d,0x19,0xff,
	0x7c,0x4e,0xd3,0x00,0x00,0x00,0x00,0x49,
	0x45,0x4e,0x44,0xae,0x42,0x60,0x82
};
unsigned char FsGui3DIcon::Rotation[242]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x04,0x0b,0x24,
	0x22,0x51,0x8a,0x8f,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x81,0x49,0x44,0x41,
	0x54,0x78,0xda,0x75,0x51,0x01,0x12,0x00,
	0x21,0x04,0x5c,0xa6,0xff,0x7f,0xd9,0xe1,
	0x08,0x75,0xd7,0x94,0xc4,0xda,0x56,0x41,
	0x00,0x9b,0x02,0xd2,0x0d,0xac,0xeb,0xf5,
	0x6c,0xe3,0xed,0x3b,0x4a,0xcc,0x57,0x63,
	0x07,0x07,0x3a,0x0a,0x8e,0x10,0x22,0x49,
	0x30,0x22,0xe0,0x40,0xda,0xc0,0xac,0x79,
	0x51,0x6e,0xa5,0x88,0x9d,0xd7,0x83,0x14,
	0x84,0x81,0x9a,0xa4,0x8b,0x1a,0xa9,0xf9,
	0xdc,0xef,0x68,0xb7,0xd4,0xa8,0x2e,0x82,
	0x83,0xad,0xa0,0xa9,0xc0,0x28,0xa9,0x24,
	0x66,0x61,0xa9,0x42,0x17,0x7a,0x04,0x93,
	0x01,0x47,0x12,0x83,0x31,0x5e,0xe7,0x4e,
	0xff,0x88,0xfa,0x1a,0xbc,0x9f,0x48,0x57,
	0x17,0x4a,0xf5,0x23,0xbd,0x83,0x82,0xe7,
	0x69,0xdd,0x0d,0x4e,0x45,0x0f,0x07,0x16,
	0x4f,0x0b,0x57,0x9b,0x7e,0xbb,0x00,0x00,
	0x00,0x00,0x49,0x45,0x4e,0x44,0xae,0x42,
	0x60,0x82
};
unsigned char FsGui3DIcon::Scroll[224]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x04,0x0b,0x3b,
	0xaf,0x59,0x87,0x7a,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x6f,0x49,0x44,0x41,
	0x54,0x78,0xda,0x6d,0x50,0x09,0x0e,0x00,
	0x20,0x08,0xc2,0xfe,0xff,0x67,0x3b,0xcc,
	0x8b,0x6a,0x6b,0x43,0x44,0xa4,0x44,0x01,
	0x8c,0x75,0x21,0x1d,0xc1,0xab,0x3f,0x03,
	0xa8,0x62,0xb1,0x1a,0xad,0x0b,0xe4,0x90,
	0x17,0x89,0x1a,0xb4,0x32,0xa4,0xe8,0x6e,
	0xd9,0x09,0x0f,0x1f,0x8b,0x3c,0xae,0x38,
	0xc4,0xee,0x86,0xa2,0xba,0x6e,0x3c,0xc0,
	0x5b,0x32,0x83,0x8d,0xbd,0x0a,0x26,0x5a,
	0x52,0x2b,0xaa,0x09,0x4d,0xd4,0x38,0x4d,
	0xf0,0x3c,0xb8,0xf8,0x09,0xbe,0x4d,0x92,
	0xe5,0x4f,0xf4,0xaf,0x8c,0x67,0xf0,0xde,
	0x4c,0xd4,0xd6,0x27,0xac,0x03,0x94,0xaf,
	0xae,0xb0,0x33,0x01,0xd2,0xf5,0x35,0x1b,
	0xd3,0x68,0xe8,0x53,0x00,0x00,0x00,0x00,
	0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82

};
unsigned char FsGui3DIcon::Shift[221]=
{
	0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,
	0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
	0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,
	0x08,0x04,0x00,0x00,0x01,0xc2,0xfd,0x07,
	0x7c,0x00,0x00,0x00,0x07,0x74,0x49,0x4d,
	0x45,0x07,0xdd,0x03,0x14,0x04,0x0b,0x0e,
	0xf9,0xea,0x43,0x59,0x00,0x00,0x00,0x09,
	0x70,0x48,0x59,0x73,0x00,0x00,0x0e,0xc2,
	0x00,0x00,0x0e,0xc2,0x01,0x15,0x28,0x4a,
	0x80,0x00,0x00,0x00,0x04,0x67,0x41,0x4d,
	0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,
	0x05,0x00,0x00,0x00,0x6c,0x49,0x44,0x41,
	0x54,0x78,0xda,0x85,0x4f,0x09,0x0e,0xc0,
	0x20,0x08,0x6b,0x17,0xff,0xff,0xe5,0x6e,
	0xe8,0x44,0xc0,0xcc,0x91,0xa0,0x4d,0x69,
	0x39,0x28,0x00,0xd7,0x93,0xa0,0x21,0x40,
	0x9a,0xa8,0xf3,0x03,0x47,0x26,0x00,0xa3,
	0x9d,0x71,0x0d,0xaa,0x76,0xf3,0xcc,0x77,
	0x53,0xbc,0x3d,0x28,0x31,0x59,0x44,0xef,
	0xae,0xbe,0xa2,0xfc,0x27,0x5c,0x5c,0x94,
	0xe7,0x3d,0x8e,0x44,0xea,0x31,0x9a,0xae,
	0x21,0xc9,0x61,0x4a,0x2b,0x59,0x46,0xd7,
	0x15,0x8b,0x33,0xa2,0x88,0x50,0xa4,0xeb,
	0x5c,0xb1,0x4d,0x3a,0x1f,0xb4,0xc4,0xdb,
	0xd6,0xbf,0x67,0xd5,0x68,0x1f,0x17,0x7b,
	0xdc,0x2d,0x8d,0x33,0x1f,0xa6,0x14,0x90,
	0x16,0x00,0x00,0x00,0x00,0x49,0x45,0x4e,
	0x44,0xae,0x42,0x60,0x82
};
