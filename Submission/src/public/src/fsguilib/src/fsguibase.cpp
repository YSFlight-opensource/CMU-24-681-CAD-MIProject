/* ////////////////////////////////////////////////////////////

File Name: fsguibase.cpp
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

#include <fssimplewindow.h>

#include "fsguibase.h"
#include "fsguidialog.h"

FsGuiObject::SCHEME FsGuiObject::scheme=FsGuiObject::PLAIN;

int FsGuiObject::defBitmapWidthLimit=64;
int FsGuiObject::defBitmapHeightLimit=64;


FsGuiControlBase::FsGuiControlBase()
{
	parent=NULL;
	modalDlg=NULL;
}


/* virtual */ FsGuiControlBase::~FsGuiControlBase()
{
	PerformScheduledDeletion();
}


void FsGuiControlBase::SetParent(FsGuiControlBase *parent)
{
	this->parent=parent;
}


FsGuiControlBase *FsGuiControlBase::GetParent(void) const
{
	return parent;
}

void FsGuiControlBase::AttachModalDialog(class FsGuiDialog *modalDlg)
{
	this->modalDlg=modalDlg;
	if(NULL!=modalDlg)
	{
		modalDlg->SetParent(this);
		modalDlg->OnAttach();
	}
	SetNeedRedraw(YSTRUE);
}

void FsGuiControlBase::DetachModalDialog(void)
{
	if(NULL!=modalDlg)
	{
		auto toCall=modalDlg;
		AttachModalDialog(NULL);
		toCall->OnDetach();

		if(YSTRUE==toCall->IsSelfDestructiveDialog())
		{
			scheduledForDeletion.Append(toCall);
		}
	}
	else
	{
		AttachModalDialog(NULL);
	}
	SetNeedRedraw(YSTRUE);
}

class FsGuiDialog *FsGuiControlBase::GetModalDialog(void) const
{
	return modalDlg;
}

void FsGuiControlBase::Interval(void)
{
}

void FsGuiControlBase::OnModalDialogClosed(int,class FsGuiDialog *,int)
{
}

YSRESULT FsGuiControlBase::OnSaveView(const class FsGui3DViewControlDialog *dlg)
{
	return YSERR;
}

YSRESULT FsGuiControlBase::OnLoadView(class FsGui3DViewControlDialog *dlg)
{
	return YSERR;
}

////////////////////////////////////////////////////////////

YSBOOL FsGuiBitmapType::IsEmpty(void) const
{
	if(0==GetWidth() || 0==GetHeight())
	{
		return YSTRUE;
	}
	return YSFALSE;
}

YSBOOL FsGuiBitmapType::IsLoaded(void) const
{
	if(0==GetWidth() || 0==GetHeight())
	{
		return YSFALSE;
	}
	return YSTRUE;
}

int FsGuiBitmapType::GetWidth(void) const
{
	return GetTotalWidth();
}

int FsGuiBitmapType::GetHeight(void) const
{
	return GetTotalHeight();
}

void FsGuiBitmapType::MakeSmallEmptyBitmap(void)
{
	YsBitmap bmp;
	bmp.PrepareBitmap(8,8);
	SetAndBreakUp(bmp,8,8);
}

void FsGuiBitmapType::SetBitmap(const YsBitmap &bmpIn)
{
	SetAndBreakUp(bmpIn,FsGuiObject::defBitmapWidthLimit,FsGuiObject::defBitmapHeightLimit);
}

void FsGuiControlBase::PerformScheduledDeletion(void)
{
	for(auto ptr : scheduledForDeletion)
	{
		delete ptr;
	}
	if(0<scheduledForDeletion.GetN())
	{
		YsPrintf("Deleted %d dialogs scheduled for deletion.\n",(int)scheduledForDeletion.GetN());
	}
	scheduledForDeletion.CleanUp();
}
