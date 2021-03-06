###############################################################################
#
# $Id: GNUmakefile,v 1.7 2009/06/01 11:46:49 stuart_hc Exp $ $Name:  $
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
# The Initial Developer of the Original Code of this file and the
# licensor of the Advanced Media Workflow Association is
# Avid Technology.
# All rights reserved.
#
###############################################################################


PROGNAME = aafmeta2dot



PACKAGE = Utilities/aafmeta2dot

AAFBASE ?= ../../../../

ifeq ($(shell uname), IRIX)
# Warnings turned off:
# 1107 - signed bit field has length of 1 bit in various stl files
# 1682 - partial overide of AxPropertyValuePrtcl::process
MODULE_PLATFORM_CFLAGS = -LANG:std -woff 1107,1682
LIBCIO = -lCio
endif

# Common definitions
include $(AAFBASE)/build/common.mk

# Include directories
INCLUDES = -I$(AAFSDKINCLUDEDIR) \
		-I../../../../examples2/axLib \
		-I.

# AxLib lib directory
AXLIBPACKAGE = axExamples
AXLIBDIR = $(AAFBUILDDIR)/$(AXLIBPACKAGE)/$(AAFTARGETDIR)

BINTARGET = $(AAFSDKBINDIR)/$(PROGNAME)$(EXE)

LINK_AXLIB_APP = -L$(AXLIBDIR) -laxLib
ifeq ($(COMPILER),cl)
  LINK_AXLIB_APP = $(AXLIBDIR)/libaxLib$(LIBEXT)
endif

.PHONY : all
all : $(OBJDIR) $(BINTARGET)

$(BINTARGET) : $(CXXOBJS)
	$(LD) $(CXXOBJS) $(LINK_AXLIB_APP) $(LINK_AAF_APP)

.PHONY : clean
clean :
	@$(RM) $(CXXOBJS)
	@$(RM) $(DEPS)
	@$(RM) $(BINTARGET)


.PHONY : realclean
realclean : clean


include $(AAFBASE)/build/rules.mk
