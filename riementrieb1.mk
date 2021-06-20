##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=riementrieb1
ConfigurationName      :=Debug
WorkspacePath          :=/home/josef/Programmieren/TERMPROGS/METALL/riementrieb1
ProjectPath            :=/home/josef/Programmieren/TERMPROGS/METALL/riementrieb1/riementrieb1
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Josef Wismeth
Date                   :=26/08/20
CodeLitePath           :=/home/josef/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="riementrieb1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/winkelfunktionen.cpp$(ObjectSuffix) $(IntermediateDirectory)/riemen.cpp$(ObjectSuffix) $(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/winkelfunktionen.cpp$(ObjectSuffix): winkelfunktionen.cpp $(IntermediateDirectory)/winkelfunktionen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/TERMPROGS/METALL/riementrieb1/riementrieb1/winkelfunktionen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/winkelfunktionen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/winkelfunktionen.cpp$(DependSuffix): winkelfunktionen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/winkelfunktionen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/winkelfunktionen.cpp$(DependSuffix) -MM winkelfunktionen.cpp

$(IntermediateDirectory)/winkelfunktionen.cpp$(PreprocessSuffix): winkelfunktionen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/winkelfunktionen.cpp$(PreprocessSuffix) winkelfunktionen.cpp

$(IntermediateDirectory)/riemen.cpp$(ObjectSuffix): riemen.cpp $(IntermediateDirectory)/riemen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/TERMPROGS/METALL/riementrieb1/riementrieb1/riemen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/riemen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/riemen.cpp$(DependSuffix): riemen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/riemen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/riemen.cpp$(DependSuffix) -MM riemen.cpp

$(IntermediateDirectory)/riemen.cpp$(PreprocessSuffix): riemen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/riemen.cpp$(PreprocessSuffix) riemen.cpp

$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix): menuefrage.cpp $(IntermediateDirectory)/menuefrage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/TERMPROGS/METALL/riementrieb1/riementrieb1/menuefrage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menuefrage.cpp$(DependSuffix): menuefrage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/menuefrage.cpp$(DependSuffix) -MM menuefrage.cpp

$(IntermediateDirectory)/menuefrage.cpp$(PreprocessSuffix): menuefrage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menuefrage.cpp$(PreprocessSuffix) menuefrage.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/TERMPROGS/METALL/riementrieb1/riementrieb1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


