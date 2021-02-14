cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(UnityLoader)

include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Unity Loader")

set(VITA_TITLEID "UNITYLOAD")

set(VITA_VERSION "01.00")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-q -Wall -g -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-psabi -Wunused-variable -Wwrite-strings -fpermissive -std=c++17 -Wimplicit-fallthrough")
set(VITA_MAKE_FSELF_FLAGS "${VITA_MAKE_FSELF_FLAGS} -a 0x2808000000000000")

include_directories()

link_directories(
${CMAKE_CURRENT_BINARY_DIR}
)

FUNCTION(ADD_RESOURCES out_var)
	SET(result)
	FOREACH (in_f ${ARGN})
		SET(out_f "${CMAKE_CURRENT_BINARY_DIR}/${in_f}.o")
		GET_FILENAME_COMPONENT(out_dir ${out_f} DIRECTORY)
		ADD_CUSTOM_COMMAND(OUTPUT ${out_f}
				COMMAND ${CMAKE_COMMAND} -E make_directory ${out_dir}
				COMMAND ${CMAKE_LINKER} -r -b binary -o ${out_f} ${in_f}
				DEPENDS ${in_f}
				WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
				COMMENT "Building resource ${out_f}"
				VERBATIM
				)
		LIST(APPEND result ${out_f})
	ENDFOREACH ()
	SET(${out_var} "${result}" PARENT_SCOPE)
ENDFUNCTION()

file(GLOB_RECURSE res_files RELATIVE ${CMAKE_SOURCE_DIR}
	assets/head.bin
)

add_resources(PROJECT_RESOURCES ${res_files})

file(GLOB minizip
	"src/utils/minizip/*.c"
	"src/utils/minizip/*.h"
)

add_executable(${PROJECT_NAME}
  ${minizip}
  ${PROJECT_RESOURCES}
  src/main.cpp
  src/usb.c
  src/usb.h
	src/utils/filesystem.cpp
	src/utils/vitaPackage.cpp
	src/utils/zip.cpp
	src/utils/sha1.c
  /usr/local/vitasdk/arm-vita-eabi/include/common/debugScreen.c
)

target_link_libraries(${PROJECT_NAME}
  SceLibKernel_stub 
  SceDisplay_stub   
  taihen_stub
  SceSysmodule_stub
  SceMtpIfDriver_stub
  SceUsbstorVStorDriver_stub
  SceAppMgr_stub
  SceAppUtil_stub
  ftpvita
  vorbisfile
  vorbis
  ogg
  m
  c
  quirc
  onigmo
  archive
  bz2
  lzma
  crypto
  expat
  taihen_stub
  SceAppMgr_stub
  SceAppUtil_stub
  SceAudio_stub
  SceAudiodec_stub
  SceCamera_stub
  SceCommonDialog_stub
  SceCtrl_stub
  SceDisplay_stub
  SceFios2_stub
  SceGxm_stub
  SceIme_stub
  SceHttp_stub
  SceLibKernel_stub
  SceMtpIfDriver_stub
  SceMusicExport_stub
  SceNet_stub
  SceNetCtl_stub
  SceNpDrm_stub
  SceRegistryMgr_stub
  SceShellSvc_stub
  SceSqlite_stub
  SceSsl_stub
  z
  SceSysmodule_stub
  ScePgf_stub
  ScePower_stub
  ScePromoterUtil_stub
  SceUsbstorVStorDriver_stub
  SceVshBridge_stub
  SceVshBridge_stub
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})

vita_create_vpk("${PROJECT_NAME}.vpk" "${VITA_TITLEID}" "${PROJECT_NAME}.self"
  VERSION "${VITA_VERSION}"
  NAME "${VITA_APP_NAME}"
  FILE sce_sys sce_sys
)
