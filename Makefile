SUBDIRS := $(wildcard src)


all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean:
	$(MAKE) -C src clean


.PHONY: all $(SUBDIRS)
