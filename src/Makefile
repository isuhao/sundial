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
MY_CFLAGS=-DENDIAN_LITTLE=1

SUNDIAL_HEADERS= \
	$(SUNDIAL_HEADER_DIR)/adlist.h \
	$(SUNDIAL_HEADER_DIR)/ae.h \
	$(SUNDIAL_HEADER_DIR)/arc4random.h \
	$(SUNDIAL_HEADER_DIR)/config.h \
	$(SUNDIAL_HEADER_DIR)/crc64.h \
	$(SUNDIAL_HEADER_DIR)/daemon.h \
	$(SUNDIAL_HEADER_DIR)/dict.h \
	$(SUNDIAL_HEADER_DIR)/endianconv.h \
	$(SUNDIAL_HEADER_DIR)/fmacros.h \
	$(SUNDIAL_HEADER_DIR)/http-parser.h \
	$(SUNDIAL_HEADER_DIR)/intset.h \
	$(SUNDIAL_HEADER_DIR)/jenkins_hash.h \
	$(SUNDIAL_HEADER_DIR)/linenoise.h \
	$(SUNDIAL_HEADER_DIR)/lzf.h \
	$(SUNDIAL_HEADER_DIR)/lzfP.h \
	$(SUNDIAL_HEADER_DIR)/murmur3_hash.h \
	$(SUNDIAL_HEADER_DIR)/rand.h \
	$(SUNDIAL_HEADER_DIR)/rbtree.h \
	$(SUNDIAL_HEADER_DIR)/sds.h \
	$(SUNDIAL_HEADER_DIR)/splaytree.h \
	$(SUNDIAL_HEADER_DIR)/testhelp.h \
	$(SUNDIAL_HEADER_DIR)/util.h \
	$(SUNDIAL_HEADER_DIR)/uuid.h

SUNDIAL_INTERNAL_HADERS= \
	$(SUNDIAL_HEADER_DIR)/internal/regex_config.h \
	$(SUNDIAL_HEADER_DIR)/internal/regex_internal.h


all $(EXE): static_lib

test: $(EXE) ../tools/sundial_run.sh
	sh ../tools/sundial_run.sh ../tests

check: test

sample: $(EXE) ../tools/sundial_run.sh
	sh ../tools/sundial_run.sh ../samples


.PHONY: install uninstall

install: $(EXE) $(SUNDIAL_HEADERS) $(SUNDIAL_INTERNAL_HADERS)
	mkdir -p $(DESTDIR)/usr/local/include/sundail
	mkdir -p $(DESTDIR)/usr/local/include/sundail/internal
	install -p $(INSTALL_FLAGS) -m 0644 -o root $(SUNDIAL_HEADERS) $(DESTDIR)/usr/local/include/sundail
	install -p $(INSTALL_FLAGS) -m 0644 -o root $(SUNDIAL_INTERNAL_HADERS) $(DESTDIR)/usr/local/include/sundail/internal
	install -p $(INSTALL_FLAGS) -m 0644 -o root $(EXE) $(DESTDIR)/usr/local/lib

uninstall:
	rm -rf $(DESTDIR)/usr/local/include/sundail
	rm -rf $(DESTDIR)/usr/local/lib/$(EXE)


include ./Makefile.inc

