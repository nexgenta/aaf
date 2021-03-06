###############################################################################
#
# $Id: GNUmakefile,v 1.10 2009/06/01 11:46:49 stuart_hc Exp $ $Name:  $
#
# The contents of this file are subject to the AAF SDK Public Source
# License Agreement Version 2.0 (the "License"); You may not use this
# file except in compliance with the License.  The License is available
# in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
# Advanced Media Workflow Association, Inc., or its successor.
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
# the License for the specific language governing rights and limitations
# under the License.  Refer to Section 3.3 of the License for proper use
# of this Exhibit.
#
# WARNING:  Please contact the Advanced Media Workflow Association,
# Inc., for more information about any additional licenses to
# intellectual property covering the AAF Standard that may be required
# to create and distribute AAF compliant products.
# (http://www.amwa.tv/policies).
#
# Copyright Notices:
# The Original Code of this file is Copyright 1998-2009, licensor of the
# Advanced Media Workflow Association.  All rights reserved.
#
###############################################################################

# This make file is normally called from the top level makefile
# (../GNUmakefile) using the "dist" target.

# Windows Notes:
#
# The top level make target does not currently work under Win2K.
# Instead, run the following from this directory:
#
#    make AAFPLATFORM=Win AAFSDK=../AAFWinSDK release-dist
#    make AAFPLATFORM=Win AAFSDK=../AAFWinSDK sdk-dist
#
# It was tested using Cygwin.

# Note, as of V102 the SDK no longer supports OS9.  The name of the OS X
# target is PPCDarwin.

AAFBASE ?= ..

#
# Common definitions
#
include $(AAFBASE)/build/common.mk

ifeq ($(AAFPLATFORM),Win)
RELEASE_FILES_SRC = ./release-files.win
SDK_FILES_SRC = ./sdk-files.win
else
ifeq ($(AAFPLATFORM),PPCDarwin)
RELEASE_FILES_SRC = ./release-files.darwin
SDK_FILES_SRC = ./sdk-files.darwin
else
ifeq ($(AAFPLATFORM),i386Darwin)
RELEASE_FILES_SRC = ./release-files.darwin
SDK_FILES_SRC = ./sdk-files.darwin
else
ifeq ($(AAFPLATFORM),UniversalDarwin)
RELEASE_FILES_SRC = ./release-files.darwin
SDK_FILES_SRC = ./sdk-files.darwin
else
RELEASE_FILES_SRC = ./release-files.unix
SDK_FILES_SRC = ./sdk-files.unix
endif
endif
endif
endif

DST_DIR = $(AAFSDK)/Dist
RELEASE_FILES_DST = $(DST_DIR)/release-files
SDK_FILES_DST = $(DST_DIR)/sdk-files

AAFSDKBUILD_H = $(AAFBASE)/ref-impl/include/AAFSDKBuild.h

.PHONY : release-files
release-files :
	$(MKDIR) $(AAFSDK)/Dist
	$(CP) $(RELEASE_FILES_SRC) $(RELEASE_FILES_DST)

.PHONY : sdk-files
sdk-files :
	$(MKDIR) $(AAFSDK)/Dist
	$(CP) $(SDK_FILES_SRC) $(SDK_FILES_DST)

.PHONY : release-dist
release-dist : release-files
	./CreateDistribution.bash release Dist/release-files Dist/AAF-runtime-libs $(AAFSDK) $(AAFPLATFORM) $(AAFSDKBUILD_H)

.PHONY : sdk-dist
sdk-dist : sdk-files
	./CreateDistribution.bash sdk Dist/sdk-files Dist/AAF-devel-libs $(AAFSDK) $(AAFPLATFORM) $(AAFSDKBUILD_H)


.PHONY : clean
clean : realclean

.PHONY : realclean
realclean :
	$(RMDIR) $(DST_DIR)
