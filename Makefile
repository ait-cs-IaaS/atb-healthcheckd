SUBDIRS := $(wildcard src)


all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

install: src/healthcheckd
	install -m 755 src/healthcheckd /usr/bin


clean:
	$(MAKE) -C src clean


.PHONY: all $(SUBDIRS)
