NAME ?= HOLLOWCE
ICON ?= icon.png
DESCRIPTION ?= "Hollow CE"
COMPRESSED ?= NO
ARCHIVED ?= YES

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
