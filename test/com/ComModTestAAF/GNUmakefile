###############################################################################
#
# $Id: GNUmakefile,v 1.18 2009/06/01 11:47:11 stuart_hc Exp $ $Name:  $
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

PACKAGE = ComModAAF

AAFBASE ?= ../../..


# Common definitions
include $(AAFBASE)/build/common.mk


# Include directories
# NOTE: Client code would never include implementation headers.
# However, to ensure that all classes are tested, a macro from
# ref-impl/src/com-api/AAFObjectTable.h is used by ComModAAF.
# Also, utf8.h is temporarily included from ref-impl.
INCLUDES = -I$(AAFSDKINCLUDEDIR) \
			-I../../../ref-impl/src/com-api \
			-I../../../ref-impl/include


# CXXFILES2 is declared just to get the list of object files
# from ModuleTests directory. These object files are created 
# when building target ModuleTests
CXXFILES_TMP = $(wildcard ModuleTests/*.$(CPP_EXTENSION)) $(wildcard ModuleTests/*.c)
CXXFILES2 = $(CXXFILES_TMP:ModuleTests/%=%)


.PHONY : all
all : ModuleTests $(AAFSDKBINDIR)/ComModAAF$(EXE)

$(AAFSDKBINDIR)/ComModAAF$(EXE) : $(CXXOBJS) $(CXXOBJS2)
	$(LD) $(CXXOBJS) $(CXXOBJS2) $(LINK_AAF_APP)

.PHONY : ModuleTests
ModuleTests :
	@echo "\nBuilding ModuleTests\n"
	cd ModuleTests && $(MAKE)


.PHONY : clean
clean :
	cd ModuleTests && $(MAKE) GENDEPS=0 $@
	@$(RM) $(CXXOBJS)
	@$(RM) $(DEPS)
	@$(RM) $(AAFSDKBINDIR)/ComModAAF$(EXE)
	@$(RMDIR) $(OBJDIR)/ii_files


.PHONY : realclean
realclean : clean
	cd ModuleTests && $(MAKE) GENDEPS=0 $@


.PHONY : check
check : all
	$(APP_RUN_ENV) $(AAFSDKBINDIR)/ComModAAF$(EXE)

.PHONY : valgrind-check
valgrind-check : all
	$(APP_RUN_ENV) $(VALGRIND_CMD) $(AAFSDKBINDIR)/ComModAAF$(EXE)

include $(AAFBASE)/build/rules.mk
