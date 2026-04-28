#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=LcTLCD.c SIO2.c main.c TIMER2.c ADC2.c game.c SELECT_BUTTON.c DATA_TIME.c FARM.c PRODUCTS.c COMMANDS.c DO_COMMAND.c INITIALIZE.c TTL_MANUAL_RECIEVE.c TTL_MANUAL_SEND.c EEPROM.c LED2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/LcTLCD.p1 ${OBJECTDIR}/SIO2.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/TIMER2.p1 ${OBJECTDIR}/ADC2.p1 ${OBJECTDIR}/game.p1 ${OBJECTDIR}/SELECT_BUTTON.p1 ${OBJECTDIR}/DATA_TIME.p1 ${OBJECTDIR}/FARM.p1 ${OBJECTDIR}/PRODUCTS.p1 ${OBJECTDIR}/COMMANDS.p1 ${OBJECTDIR}/DO_COMMAND.p1 ${OBJECTDIR}/INITIALIZE.p1 ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1 ${OBJECTDIR}/TTL_MANUAL_SEND.p1 ${OBJECTDIR}/EEPROM.p1 ${OBJECTDIR}/LED2.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/LcTLCD.p1.d ${OBJECTDIR}/SIO2.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/TIMER2.p1.d ${OBJECTDIR}/ADC2.p1.d ${OBJECTDIR}/game.p1.d ${OBJECTDIR}/SELECT_BUTTON.p1.d ${OBJECTDIR}/DATA_TIME.p1.d ${OBJECTDIR}/FARM.p1.d ${OBJECTDIR}/PRODUCTS.p1.d ${OBJECTDIR}/COMMANDS.p1.d ${OBJECTDIR}/DO_COMMAND.p1.d ${OBJECTDIR}/INITIALIZE.p1.d ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d ${OBJECTDIR}/EEPROM.p1.d ${OBJECTDIR}/LED2.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/LcTLCD.p1 ${OBJECTDIR}/SIO2.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/TIMER2.p1 ${OBJECTDIR}/ADC2.p1 ${OBJECTDIR}/game.p1 ${OBJECTDIR}/SELECT_BUTTON.p1 ${OBJECTDIR}/DATA_TIME.p1 ${OBJECTDIR}/FARM.p1 ${OBJECTDIR}/PRODUCTS.p1 ${OBJECTDIR}/COMMANDS.p1 ${OBJECTDIR}/DO_COMMAND.p1 ${OBJECTDIR}/INITIALIZE.p1 ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1 ${OBJECTDIR}/TTL_MANUAL_SEND.p1 ${OBJECTDIR}/EEPROM.p1 ${OBJECTDIR}/LED2.p1

# Source Files
SOURCEFILES=LcTLCD.c SIO2.c main.c TIMER2.c ADC2.c game.c SELECT_BUTTON.c DATA_TIME.c FARM.c PRODUCTS.c COMMANDS.c DO_COMMAND.c INITIALIZE.c TTL_MANUAL_RECIEVE.c TTL_MANUAL_SEND.c EEPROM.c LED2.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4321
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/LcTLCD.p1: LcTLCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LcTLCD.p1.d 
	@${RM} ${OBJECTDIR}/LcTLCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/LcTLCD.p1 LcTLCD.c 
	@-${MV} ${OBJECTDIR}/LcTLCD.d ${OBJECTDIR}/LcTLCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LcTLCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SIO2.p1: SIO2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SIO2.p1.d 
	@${RM} ${OBJECTDIR}/SIO2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/SIO2.p1 SIO2.c 
	@-${MV} ${OBJECTDIR}/SIO2.d ${OBJECTDIR}/SIO2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SIO2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TIMER2.p1: TIMER2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TIMER2.p1 TIMER2.c 
	@-${MV} ${OBJECTDIR}/TIMER2.d ${OBJECTDIR}/TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ADC2.p1: ADC2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC2.p1.d 
	@${RM} ${OBJECTDIR}/ADC2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ADC2.p1 ADC2.c 
	@-${MV} ${OBJECTDIR}/ADC2.d ${OBJECTDIR}/ADC2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ADC2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/game.p1: game.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/game.p1.d 
	@${RM} ${OBJECTDIR}/game.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/game.p1 game.c 
	@-${MV} ${OBJECTDIR}/game.d ${OBJECTDIR}/game.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/game.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SELECT_BUTTON.p1: SELECT_BUTTON.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SELECT_BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/SELECT_BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/SELECT_BUTTON.p1 SELECT_BUTTON.c 
	@-${MV} ${OBJECTDIR}/SELECT_BUTTON.d ${OBJECTDIR}/SELECT_BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SELECT_BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/DATA_TIME.p1: DATA_TIME.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DATA_TIME.p1.d 
	@${RM} ${OBJECTDIR}/DATA_TIME.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/DATA_TIME.p1 DATA_TIME.c 
	@-${MV} ${OBJECTDIR}/DATA_TIME.d ${OBJECTDIR}/DATA_TIME.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DATA_TIME.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FARM.p1: FARM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FARM.p1.d 
	@${RM} ${OBJECTDIR}/FARM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FARM.p1 FARM.c 
	@-${MV} ${OBJECTDIR}/FARM.d ${OBJECTDIR}/FARM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FARM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/PRODUCTS.p1: PRODUCTS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRODUCTS.p1.d 
	@${RM} ${OBJECTDIR}/PRODUCTS.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/PRODUCTS.p1 PRODUCTS.c 
	@-${MV} ${OBJECTDIR}/PRODUCTS.d ${OBJECTDIR}/PRODUCTS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/PRODUCTS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/COMMANDS.p1: COMMANDS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/COMMANDS.p1.d 
	@${RM} ${OBJECTDIR}/COMMANDS.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/COMMANDS.p1 COMMANDS.c 
	@-${MV} ${OBJECTDIR}/COMMANDS.d ${OBJECTDIR}/COMMANDS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/COMMANDS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/DO_COMMAND.p1: DO_COMMAND.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DO_COMMAND.p1.d 
	@${RM} ${OBJECTDIR}/DO_COMMAND.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/DO_COMMAND.p1 DO_COMMAND.c 
	@-${MV} ${OBJECTDIR}/DO_COMMAND.d ${OBJECTDIR}/DO_COMMAND.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DO_COMMAND.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/INITIALIZE.p1: INITIALIZE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/INITIALIZE.p1.d 
	@${RM} ${OBJECTDIR}/INITIALIZE.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/INITIALIZE.p1 INITIALIZE.c 
	@-${MV} ${OBJECTDIR}/INITIALIZE.d ${OBJECTDIR}/INITIALIZE.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/INITIALIZE.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1: TTL_MANUAL_RECIEVE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1 TTL_MANUAL_RECIEVE.c 
	@-${MV} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.d ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TTL_MANUAL_SEND.p1: TTL_MANUAL_SEND.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_SEND.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTL_MANUAL_SEND.p1 TTL_MANUAL_SEND.c 
	@-${MV} ${OBJECTDIR}/TTL_MANUAL_SEND.d ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EEPROM.p1: EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EEPROM.p1 EEPROM.c 
	@-${MV} ${OBJECTDIR}/EEPROM.d ${OBJECTDIR}/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LED2.p1: LED2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LED2.p1.d 
	@${RM} ${OBJECTDIR}/LED2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/LED2.p1 LED2.c 
	@-${MV} ${OBJECTDIR}/LED2.d ${OBJECTDIR}/LED2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LED2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/LcTLCD.p1: LcTLCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LcTLCD.p1.d 
	@${RM} ${OBJECTDIR}/LcTLCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/LcTLCD.p1 LcTLCD.c 
	@-${MV} ${OBJECTDIR}/LcTLCD.d ${OBJECTDIR}/LcTLCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LcTLCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SIO2.p1: SIO2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SIO2.p1.d 
	@${RM} ${OBJECTDIR}/SIO2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/SIO2.p1 SIO2.c 
	@-${MV} ${OBJECTDIR}/SIO2.d ${OBJECTDIR}/SIO2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SIO2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TIMER2.p1: TIMER2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TIMER2.p1 TIMER2.c 
	@-${MV} ${OBJECTDIR}/TIMER2.d ${OBJECTDIR}/TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ADC2.p1: ADC2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC2.p1.d 
	@${RM} ${OBJECTDIR}/ADC2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ADC2.p1 ADC2.c 
	@-${MV} ${OBJECTDIR}/ADC2.d ${OBJECTDIR}/ADC2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ADC2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/game.p1: game.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/game.p1.d 
	@${RM} ${OBJECTDIR}/game.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/game.p1 game.c 
	@-${MV} ${OBJECTDIR}/game.d ${OBJECTDIR}/game.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/game.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/SELECT_BUTTON.p1: SELECT_BUTTON.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SELECT_BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/SELECT_BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/SELECT_BUTTON.p1 SELECT_BUTTON.c 
	@-${MV} ${OBJECTDIR}/SELECT_BUTTON.d ${OBJECTDIR}/SELECT_BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/SELECT_BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/DATA_TIME.p1: DATA_TIME.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DATA_TIME.p1.d 
	@${RM} ${OBJECTDIR}/DATA_TIME.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/DATA_TIME.p1 DATA_TIME.c 
	@-${MV} ${OBJECTDIR}/DATA_TIME.d ${OBJECTDIR}/DATA_TIME.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DATA_TIME.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FARM.p1: FARM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FARM.p1.d 
	@${RM} ${OBJECTDIR}/FARM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FARM.p1 FARM.c 
	@-${MV} ${OBJECTDIR}/FARM.d ${OBJECTDIR}/FARM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FARM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/PRODUCTS.p1: PRODUCTS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PRODUCTS.p1.d 
	@${RM} ${OBJECTDIR}/PRODUCTS.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/PRODUCTS.p1 PRODUCTS.c 
	@-${MV} ${OBJECTDIR}/PRODUCTS.d ${OBJECTDIR}/PRODUCTS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/PRODUCTS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/COMMANDS.p1: COMMANDS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/COMMANDS.p1.d 
	@${RM} ${OBJECTDIR}/COMMANDS.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/COMMANDS.p1 COMMANDS.c 
	@-${MV} ${OBJECTDIR}/COMMANDS.d ${OBJECTDIR}/COMMANDS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/COMMANDS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/DO_COMMAND.p1: DO_COMMAND.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DO_COMMAND.p1.d 
	@${RM} ${OBJECTDIR}/DO_COMMAND.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/DO_COMMAND.p1 DO_COMMAND.c 
	@-${MV} ${OBJECTDIR}/DO_COMMAND.d ${OBJECTDIR}/DO_COMMAND.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/DO_COMMAND.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/INITIALIZE.p1: INITIALIZE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/INITIALIZE.p1.d 
	@${RM} ${OBJECTDIR}/INITIALIZE.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/INITIALIZE.p1 INITIALIZE.c 
	@-${MV} ${OBJECTDIR}/INITIALIZE.d ${OBJECTDIR}/INITIALIZE.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/INITIALIZE.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1: TTL_MANUAL_RECIEVE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1 TTL_MANUAL_RECIEVE.c 
	@-${MV} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.d ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTL_MANUAL_RECIEVE.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/TTL_MANUAL_SEND.p1: TTL_MANUAL_SEND.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d 
	@${RM} ${OBJECTDIR}/TTL_MANUAL_SEND.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/TTL_MANUAL_SEND.p1 TTL_MANUAL_SEND.c 
	@-${MV} ${OBJECTDIR}/TTL_MANUAL_SEND.d ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/TTL_MANUAL_SEND.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EEPROM.p1: EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EEPROM.p1 EEPROM.c 
	@-${MV} ${OBJECTDIR}/EEPROM.d ${OBJECTDIR}/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/LED2.p1: LED2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LED2.p1.d 
	@${RM} ${OBJECTDIR}/LED2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/LED2.p1 LED2.c 
	@-${MV} ${OBJECTDIR}/LED2.d ${OBJECTDIR}/LED2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/LED2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-1dc0-1fff -mram=default,-1f4-1ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/faseB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
