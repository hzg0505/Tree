# aux_source_directory(. DIR_LIB_SRCS)

aux_source_directory(./ SRCS)

add_library(btree SHARED ${SRCS}) 