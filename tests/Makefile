# Copyright (c) 2014 The Sundial Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file. See the AUTHORS file for names of contributors.
###############################################################################

include ../build_config.mk

EXE= ./rbtree_test

SRC_c= ./rbtree_test.c

MY_COMMON_FLAGS=

MY_CCFLAGS= -I ../include

MY_LDFLAGS=

MY_LIBS= -L ../src -l sundial


all: c_bin

test: all
	$(EXE)

include ../src/Makefile.inc

