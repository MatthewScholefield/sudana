#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/Instrument.o \
	${OBJECTDIR}/source/Notes/Note.o \
	${OBJECTDIR}/source/Notes/SawNote.o \
	${OBJECTDIR}/source/Notes/SinNote.o \
	${OBJECTDIR}/source/Notes/TriNote.o \
	${OBJECTDIR}/source/Sample.o \
	${OBJECTDIR}/source/SongPlayer.o \
	${OBJECTDIR}/source/SoundSystem.o \
	${OBJECTDIR}/source/SoundWorld.o \
	${OBJECTDIR}/source/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall
CXXFLAGS=-Wall

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lportaudio

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sunada

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sunada: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sunada ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/source/Instrument.o: source/Instrument.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Instrument.o source/Instrument.cpp

${OBJECTDIR}/source/Notes/Note.o: source/Notes/Note.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Notes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Notes/Note.o source/Notes/Note.cpp

${OBJECTDIR}/source/Notes/SawNote.o: source/Notes/SawNote.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Notes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Notes/SawNote.o source/Notes/SawNote.cpp

${OBJECTDIR}/source/Notes/SinNote.o: source/Notes/SinNote.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Notes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Notes/SinNote.o source/Notes/SinNote.cpp

${OBJECTDIR}/source/Notes/TriNote.o: source/Notes/TriNote.cpp 
	${MKDIR} -p ${OBJECTDIR}/source/Notes
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Notes/TriNote.o source/Notes/TriNote.cpp

${OBJECTDIR}/source/Sample.o: source/Sample.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Sample.o source/Sample.cpp

${OBJECTDIR}/source/SongPlayer.o: source/SongPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SongPlayer.o source/SongPlayer.cpp

${OBJECTDIR}/source/SoundSystem.o: source/SoundSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SoundSystem.o source/SoundSystem.cpp

${OBJECTDIR}/source/SoundWorld.o: source/SoundWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SoundWorld.o source/SoundWorld.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sunada

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
