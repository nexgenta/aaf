// Copyright 2003 BBC Technology

// $Id: AifVersions.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#ifndef __AifVersions_h__
#define __AifVersions_h__

#include <AAFSDKBuild.h>

#if   AAF_MAJOR_VERSION == 1  &&  AAF_MINOR_VERSION == 1  && AAF_MAINT_RELEASE == 0
#define AIF_V110
#elif AAF_MAJOR_VERSION == 1  &&  AAF_MINOR_VERSION == 0  && AAF_MAINT_RELEASE == 2
#define AIF_V102
#else
#error "unsupported AAF SDK version"
#endif

#endif