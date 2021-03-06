/* ////////////////////////////////////////////////////////////

File Name: ysfileio.h
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

#ifndef YSFILEMISC_IS_INCLUDED
#define YSFILEMISC_IS_INCLUDED
/* { */

#include <cstddef>
#include <ysclass.h>
#include <stdio.h>


/*
  2016/01/08
  YsFileIO as C-File abstraction was totally my bad.  I added YsFileIO::File class for that purpose.
  Hope it doesn't affect too many users.  
*/

class YsFileIO
{
public:
	static const char *Getcwd(YsString &cwd);
	static const wchar_t *Getcwd(YsWString &cwd);
	static YsWString Getcwd(void);

	static YSRESULT ChDir(const char dirName[]);
	static YSRESULT ChDir(const wchar_t dirName[]);

	static YSRESULT MkDir(const char dirName[]);
	static YSRESULT MkDir(const wchar_t dirName[]);

	static FILE *Fopen(const wchar_t fn[],const char mode[]);
	static FILE *Fopen(const char fn[],const char mode[]);

	static YSRESULT Remove(const wchar_t fn[]);
	static YSRESULT Remove(const char fn[]);

	static YSBOOL CheckFileExist(const wchar_t fn[]);
	static YSBOOL CheckFileExist(const char fn[]);

	class File
	{
	private:
		FILE *fp;
	public:
		File();
		File(const wchar_t fn[],const char mode[]);
		File(const char fn[],const char mode[]);
		virtual ~File();

		inline operator FILE *() const
		{
			return fp;
		}
		inline YsTextFileInputStream InStream(void) const
		{
			return YsTextFileInputStream(fp);
		}
		inline YsTextFileOutputStream OutStream(void) const
		{
			return YsTextFileOutputStream(fp);
		}
		inline bool operator==(std::nullptr_t)
		{
			return (fp==nullptr);
		}
		inline bool operator!=(std::nullptr_t)
		{
			return (fp!=nullptr);
		}

		void Fclose(void);
		FILE *Fp(void) const;
	};
};

inline bool operator==(std::nullptr_t,const YsFileIO::File &fp)
{
	return (fp==nullptr);
}
inline bool operator!=(std::nullptr_t,const YsFileIO::File &fp)
{
	return (fp!=nullptr);
}

/* } */
#endif
