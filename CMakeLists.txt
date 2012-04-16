cmake_minimum_required (VERSION 2.6)
project (libtai)

include_directories("${PROJECT_BINARY_DIR}" "${CMAKE_SOURCE_DIR}/include")

#Libtai
set (TIME_SRC caldate_fmjd.c caldate_fmt.c caldate_mjd.c caldate_norm.c caldate_scan.c caldate_ster.c caltime_fmt.c
	caltime_scan.c caltime_tai.c caltime_utc.c leapsecs_add.c leapsecs_init.c 
	leapsecs_read.c leapsecs_sub.c tai_add.c tai_now.c tai_pack.c tai_sub.c tai_unpack.c)

add_library(libtai ${TIME_SRC})

#Libtaia
#TODO

#add_executable(nowutc nowutc.c)
#target_link_libraries(nowutc libtai)

add_executable(leapsecs leapsecs.c)
target_link_libraries(leapsecs libtai)

add_executable(yearcal yearcal.c)
target_link_libraries(yearcal libtai)

add_executable(check check.c)
target_link_libraries(check libtai)

add_executable(easter easter.c)
target_link_libraries(easter libtai)


