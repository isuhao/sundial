# Copyright (c) 2014 The Sundial Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file. See the AUTHORS file for names of contributors.
###############################################################################

include ../build_config.mk

EXE= libsundial.$(PLATFORM_STATIC_EXT)

SRC_c= \
	adlist.c \
	ae.c \
	arc4random.c \
	crc64.c \
	daemon.c \
	dict.c \
	endianconv.c \
	http-parser.c \
	intset.c \
	jenkins_hash.c \
	linenoise.c \
	lzf_c.c \
	lzf_d.c \
	murmur3_hash.c \
	rand.c \
	rbtree.c \
	regex.c \
	sds.c \
	splaytree.c \
	util.c \
	uuid.c \
	ziplist.c \
	zipmap.c \
	zmalloc.c

SUNDIAL_HEADER_DIR= ../include

MY_COMMON_FLAGS=-std=c99 -I $(SUNDIAL_HEADER_DIR)
MY_CCFLAGS=-DENDIAN_LITTLE=1

SUNDIAL_HEADERS= \
	$(SUNDIAL_HEADER_DIR)/sundial/adlist.h \
	$(SUNDIAL_HEADER_DIR)/sundial/ae.h \
	$(SUNDIAL_HEADER_DIR)/sundial/arc4random.h \
	$(SUNDIAL_HEADER_DIR)/sundial/config.h \
	$(SUNDIAL_HEADER_DIR)/sundial/crc64.h \
	$(SUNDIAL_HEADER_DIR)/sundial/daemon.h \
	$(SUNDIAL_HEADER_DIR)/sundial/dict.h \
	$(SUNDIAL_HEADER_DIR)/sundial/endianconv.h \
	$(SUNDIAL_HEADER_DIR)/sundial/fmacros.h \
	$(SUNDIAL_HEADER_DIR)/sundial/http-parser.h \
	$(SUNDIAL_HEADER_DIR)/sundial/internal \
	$(SUNDIAL_HEADER_DIR)/sundial/intset.h \
	$(SUNDIAL_HEADER_DIR)/sundial/jenkins_hash.h \
	$(SUNDIAL_HEADER_DIR)/sundial/linenoise.h \
	$(SUNDIAL_HEADER_DIR)/sundial/lzf.h \
	$(SUNDIAL_HEADER_DIR)/sundial/lzfP.h \
	$(SUNDIAL_HEADER_DIR)/sundial/murmur3_hash.h \
	$(SUNDIAL_HEADER_DIR)/sundial/rand.h \
	$(SUNDIAL_HEADER_DIR)/sundial/rbtree.h \
	$(SUNDIAL_HEADER_DIR)/sundial/regex.h \
	$(SUNDIAL_HEADER_DIR)/sundial/sds.h \
	$(SUNDIAL_HEADER_DIR)/sundial/splaytree.h \
	$(SUNDIAL_HEADER_DIR)/sundial/sundial.h \
	$(SUNDIAL_HEADER_DIR)/sundial/testhelp.h \
	$(SUNDIAL_HEADER_DIR)/sundial/util.h \
	$(SUNDIAL_HEADER_DIR)/sundial/uuid.h \
	$(SUNDIAL_HEADER_DIR)/sundial/ziplist.h \
	$(SUNDIAL_HEADER_DIR)/sundial/zipmap.h \
	$(SUNDIAL_HEADER_DIR)/sundial/zmalloc.h


SUNDIAL_INTERNAL_HADERS= \
	$(SUNDIAL_HEADER_DIR)/sundial/internal/regex_config.h \
	$(SUNDIAL_HEADER_DIR)/sundial/internal/regex_internal.h


all $(EXE): static_lib

test: $(EXE) ../tools/sundial_run.sh
	sh ../tools/sundial_run.sh ../tests

check: test

sample: $(EXE) ../tools/sundial_run.sh
	sh ../tools/sundial_run.sh ../samples


.PHONY: install uninstall

install: $(EXE) $(SUNDIAL_HEADERS) $(SUNDIAL_INTERNAL_HADERS)
	mkdir -p $(DESTDIR)/usr/local/include/sundial/internal
	mkdir -p $(DESTDIR)/usr/local/lib
	install -p $(INSTALL_FLAGS) -m 0644 -o root $(EXE) $(DESTDIR)/usr/local/lib
	install -p $(INSTALL_FLAGS) -m 0644 -o root $(SUNDIAL_INTERNAL_HADERS) $(DESTDIR)/usr/local/include/sundial/internal
	install -c -p $(INSTALL_FLAGS) -m 0644 -o root $(SUNDIAL_HEADERS) $(DESTDIR)/usr/local/include/sundial 2>/dev/null

uninstall:
	rm -rf $(DESTDIR)/usr/local/include/sundial
	rm -rf $(DESTDIR)/usr/local/lib/$(EXE)


include ./Makefile.inc

