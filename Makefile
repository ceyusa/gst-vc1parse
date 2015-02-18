CFLAGS := -O2 -ggdb -Wall -Wextra -Wno-unused-parameter -Wmissing-prototypes -ansi
LDFLAGS :=  -Wl,--no-undefined -Wl,--as-needed

override CFLAGS += -std=c99 -DGST_DISABLE_DEPRECATED

GST_CFLAGS := $(shell pkg-config --cflags gstreamer-1.0 gstreamer-base-1.0 gstreamer-pbutils-1.0 gstreamer-codecparsers-1.0)
GST_LIBS := $(shell pkg-config --libs gstreamer-1.0 gstreamer-base-1.0 gstreamer-pbutils-1.0 gstreamer-codecparsers-1.0)

all:

prefix ?= /usr

plugin := libgstvaapivc1parser.so
$(plugin): plugin.o gstvc1parse.o
$(plugin): override CFLAGS += -fPIC $(GST_CFLAGS)
$(plugin): override LIBS += $(GST_LIBS)

all: $(plugin)

# pretty print
ifndef V
QUIET_CC    = @echo '   CC         '$@;
QUIET_LINK  = @echo '   LINK       '$@;
QUIET_CLEAN = @echo '   CLEAN      '$@;
endif

install: $(plugin)
	install -m 755 -D $(plugin) $(prefix)/lib/gstreamer-1.0/$(plugin)

%.o:: %.c
	$(QUIET_CC)$(CC) $(CFLAGS) -MMD -o $@ -c $<

%.so::
	$(QUIET_LINK)$(CC) $(LDFLAGS)  -shared -o $@ $^ $(LIBS)

clean:
	$(QUIET_CLEAN)$(RM) -v $(targets) *.o *.d

-include *.d
