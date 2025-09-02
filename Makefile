CUR_DIR := .

INC_DIR := $(CUR_DIR)/inc

SRC_DIR := $(CUR_DIR)/src

BIN_DIR := $(CUR_DIR)/bin

OBJ_DIR := $(CUR_DIR)/obj
STA_OBJ_DIR := $(OBJ_DIR)/static
SHR_OBJ_DIR := $(OBJ_DIR)/shared

LIB_DIR := $(CUR_DIR)/lib

LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

PROGRAM1 := main_static
PROGRAM2 := main_shared
LIB_NAME := libstrutils

#create obj for main
created_main_obj:
	gcc -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)


#create a static library
create_obj_static: 
	gcc -c $(SRC_DIR)/bstrutils.c -o $(STA_OBJ_DIR)/bstrutils.o -I $(INC_DIR)

create_lib_static:
	ar rcs $(LIB_STATIC_DIR)/lib$(LIB_NAME).a $(STA_OBJ_DIR)/bstrutils.o

static: create_obj_static create_lib_static created_main_obj
	gcc $(OBJ_DIR)/main.o -L $(LIB_STATIC_DIR) -l $(LIB_NAME) -o $(BIN_DIR)/$(PROGRAM1)


#create a shared library
create_obj_shared:
	gcc -c -fPIC $(SRC_DIR)/bstrutils.c -o $(SHR_OBJ_DIR)/bstrutils.o -I $(INC_DIR)

create_lib_shared:
	gcc -shared $(SHR_OBJ_DIR)/bstrutils.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so

shared: create_obj_shared create_lib_shared created_main_obj
	gcc  $(OBJ_DIR)/main.o -L $(LIB_SHARED_DIR) -l $(LIB_NAME) -o $(BIN_DIR)/$(PROGRAM2)


#create static and shared library
all: static shared

#clean the object files, binary files, and library files
clean:
	rm -rf $(STA_OBJ_DIR)/*
	rm -rf $(SHR_OBJ_DIR)/*
	rm -rf $(LIB_SHARED_DIR)/*
	rm -rf $(LIB_STATIC_DIR)/*
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*.o