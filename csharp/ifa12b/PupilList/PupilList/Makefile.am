
EXTRA_DIST =  

# Warning: This is an automatically generated file, do not edit!

if ENABLE_DEBUG_X86
ASSEMBLY_COMPILER_COMMAND = dmcs
ASSEMBLY_COMPILER_FLAGS =  -noconfig -codepage:utf8 -warn:4 -optimize- -debug "-define:DEBUG"
ASSEMBLY = bin/Debug/PupilList.exe
ASSEMBLY_MDB = $(ASSEMBLY).mdb
COMPILE_TARGET = exe
PROJECT_REFERENCES = 
BUILD_DIR = bin/Debug

PUPILLIST_EXE_MDB_SOURCE=bin/Debug/PupilList.exe.mdb
PUPILLIST_EXE_MDB=$(BUILD_DIR)/PupilList.exe.mdb

endif

if ENABLE_RELEASE_X86
ASSEMBLY_COMPILER_COMMAND = dmcs
ASSEMBLY_COMPILER_FLAGS =  -noconfig -codepage:utf8 -warn:4 -optimize+
ASSEMBLY = bin/Release/PupilList.exe
ASSEMBLY_MDB = 
COMPILE_TARGET = exe
PROJECT_REFERENCES = 
BUILD_DIR = bin/Release

PUPILLIST_EXE_MDB=

endif

AL=al
SATELLITE_ASSEMBLY_NAME=$(notdir $(basename $(ASSEMBLY))).resources.dll

PROGRAMFILES = \
	$(PUPILLIST_EXE_MDB)  

BINARIES = \
	$(PUPILLIST)  


RESGEN=resgen2
	
all: $(ASSEMBLY) $(PROGRAMFILES) $(BINARIES) 

FILES = \
	Program.cs \
	Properties/AssemblyInfo.cs \
	Pupils.cs 

DATA_FILES = 

RESOURCES = 

EXTRAS = \
	pupillist.in 

REFERENCES =  \
	System

DLL_REFERENCES = 

CLEANFILES = $(PROGRAMFILES) $(BINARIES) 

include $(top_srcdir)/Makefile.include

PUPILLIST = $(BUILD_DIR)/pupillist

$(eval $(call emit-deploy-wrapper,PUPILLIST,pupillist,x))


$(eval $(call emit_resgen_targets))
$(build_xamlg_list): %.xaml.g.cs: %.xaml
	xamlg '$<'

$(ASSEMBLY_MDB): $(ASSEMBLY)

$(ASSEMBLY): $(build_sources) $(build_resources) $(build_datafiles) $(DLL_REFERENCES) $(PROJECT_REFERENCES) $(build_xamlg_list) $(build_satellite_assembly_list)
	mkdir -p $(shell dirname $(ASSEMBLY))
	$(ASSEMBLY_COMPILER_COMMAND) $(ASSEMBLY_COMPILER_FLAGS) -out:$(ASSEMBLY) -target:$(COMPILE_TARGET) $(build_sources_embed) $(build_resources_embed) $(build_references_ref)
