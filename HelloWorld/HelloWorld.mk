##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=HelloWorld
ConfigurationName      :=Debug
WorkspacePath          := "/home/senthil/.codelite/Test"
ProjectPath            := "/home/senthil/.codelite/Test/HelloWorld"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Senthil
Date                   :=19/09/15
CodeLitePath           :="/home/senthil/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="HelloWorld.txt"
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Subject.cpp$(ObjectSuffix) $(IntermediateDirectory)/Store.cpp$(ObjectSuffix) $(IntermediateDirectory)/Product.cpp$(ObjectSuffix) $(IntermediateDirectory)/Observer.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/senthil/.codelite/Test/HelloWorld/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Subject.cpp$(ObjectSuffix): Subject.cpp $(IntermediateDirectory)/Subject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/senthil/.codelite/Test/HelloWorld/Subject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Subject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Subject.cpp$(DependSuffix): Subject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Subject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Subject.cpp$(DependSuffix) -MM "Subject.cpp"

$(IntermediateDirectory)/Subject.cpp$(PreprocessSuffix): Subject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Subject.cpp$(PreprocessSuffix) "Subject.cpp"

$(IntermediateDirectory)/Store.cpp$(ObjectSuffix): Store.cpp $(IntermediateDirectory)/Store.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/senthil/.codelite/Test/HelloWorld/Store.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Store.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Store.cpp$(DependSuffix): Store.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Store.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Store.cpp$(DependSuffix) -MM "Store.cpp"

$(IntermediateDirectory)/Store.cpp$(PreprocessSuffix): Store.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Store.cpp$(PreprocessSuffix) "Store.cpp"

$(IntermediateDirectory)/Product.cpp$(ObjectSuffix): Product.cpp $(IntermediateDirectory)/Product.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/senthil/.codelite/Test/HelloWorld/Product.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Product.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Product.cpp$(DependSuffix): Product.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Product.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Product.cpp$(DependSuffix) -MM "Product.cpp"

$(IntermediateDirectory)/Product.cpp$(PreprocessSuffix): Product.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Product.cpp$(PreprocessSuffix) "Product.cpp"

$(IntermediateDirectory)/Observer.cpp$(ObjectSuffix): Observer.cpp $(IntermediateDirectory)/Observer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/senthil/.codelite/Test/HelloWorld/Observer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Observer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Observer.cpp$(DependSuffix): Observer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Observer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Observer.cpp$(DependSuffix) -MM "Observer.cpp"

$(IntermediateDirectory)/Observer.cpp$(PreprocessSuffix): Observer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Observer.cpp$(PreprocessSuffix) "Observer.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


