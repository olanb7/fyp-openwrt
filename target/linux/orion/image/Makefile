#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/image.mk

define Image/Prepare
	cp $(LINUX_DIR)/arch/arm/boot/uImage $(KDIR)/uImage
endef

define Image/BuildKernel
# WRT350N v2: mach id 1633 (0x661)
	echo -en "\x06\x1c\xa0\xe3\x61\x10\x81\xe3" > $(KDIR)/wrt350nv2-zImage
	cat $(LINUX_DIR)/arch/arm/boot/zImage >> $(KDIR)/wrt350nv2-zImage
	$(STAGING_DIR_HOST)/bin/mkimage -A arm -O linux -T kernel \
	-C none -a 0x00008000 -e 0x00008000 -n 'Linux-$(LINUX_VERSION)' \
	-d $(KDIR)/wrt350nv2-zImage $(KDIR)/wrt350nv2-uImage
	cp $(KDIR)/wrt350nv2-uImage $(BIN_DIR)/openwrt-wrt350nv2-uImage
# WNR854T: mach id 1801 (0x709)
	echo -en "\x07\x1c\xa0\xe3\x09\x10\x81\xe3" > $(KDIR)/wnr854t-zImage
	cat $(LINUX_DIR)/arch/arm/boot/zImage >> $(KDIR)/wnr854t-zImage
	$(STAGING_DIR_HOST)/bin/mkimage -A arm -O linux -T kernel \
	-C none -a 0x00008000 -e 0x00008000 -n 'Linux-$(LINUX_VERSION)' \
	-d $(KDIR)/wnr854t-zImage $(KDIR)/wnr854t-uImage
	cp $(KDIR)/wnr854t-uImage $(BIN_DIR)/openwrt-wnr854t-uImage
# DT2: mach id 1514 (0x5EA)
	echo -en "\x05\x1c\xa0\xe3\xea\x10\x81\xe3" > $(KDIR)/dt2-zImage
	cat $(LINUX_DIR)/arch/arm/boot/zImage >> $(KDIR)/dt2-zImage
	$(STAGING_DIR_HOST)/bin/mkimage -A arm -O linux -T kernel \
	-C none -a 0x00008000 -e 0x00008000 -n 'Linux-$(LINUX_VERSION)' \
	-d $(KDIR)/dt2-zImage $(KDIR)/dt2-uImage
	cp $(KDIR)/dt2-uImage $(BIN_DIR)/openwrt-dt2-uImage
endef

define Image/Build/Netgear
	mkdir $(KDIR)/netgear_image
	cp $(KDIR)/wnr854t-uImage $(KDIR)/netgear_image/uImage
	$(STAGING_DIR_HOST)/bin/mkfs.jffs2 -m none -p -l -q -e 128KiB -o $(KDIR)/wnr854t-uImage.jffs2 -d $(KDIR)/netgear_image
	rm -rf $(KDIR)/netgear_image
	( \
		dd if=$(KDIR)/wnr854t-uImage.jffs2 bs=1024k conv=sync; \
		dd if=$(KDIR)/root.$(1) bs=128k conv=sync; \
	) > $(BIN_DIR)/openwrt-$(2)-$(1).img
	$(STAGING_DIR_HOST)/bin/add_header $(3) $(BIN_DIR)/openwrt-$(2)-$(1).img $(BIN_DIR)/openwrt-$(2)-$(1)-webupgrade.img
endef

define Image/Build/Linksys
# placeholder for the WRT350N v2
endef

define Image/Build/Freecom
	$(INSTALL_DIR) $(TARGET_DIR)/boot
	# TODO: Add special CMDLINE shim for webupgrade image here
	$(CP) $(KDIR)/dt2-uImage $(TARGET_DIR)/boot/uImage
	rm -rf $(TARGET_DIR)/{var,jffs,rom}
	$(INSTALL_DIR) $(TARGET_DIR)/var
	$(TAR) cfj $(BIN_DIR)/openwrt-$(2)-$(1).img --numeric-owner --owner=0 --group=0 -C $(TARGET_DIR)/ .
	$(STAGING_DIR_HOST)/bin/encode_crc $(BIN_DIR)/openwrt-$(2)-$(1).img $(BIN_DIR)/openwrt-$(2)-$(1)-webupgrade.img $(3)
endef

define Image/Build
	$(call Image/Build/$(1),$(1))
	$(call Image/Build/Netgear,$(1),wnr854t,NG_WNR854T,$(1))
	$(call Image/Build/Linksys,$(1),wrt350nv2,WNR350Nv2,$(1))
	$(call Image/Build/Freecom,$(1),dt2,DT,$(1))
endef

define Image/Build/squashfs
	$(call prepare_generic_squashfs,$(KDIR)/root.squashfs)
	( \
		dd if=$(KDIR)/uImage bs=1024k conv=sync; \
		dd if=$(KDIR)/root.$(1) bs=128k conv=sync; \
	) > $(BIN_DIR)/openwrt-$(BOARD)-$(1).img
endef

$(eval $(call BuildImage))
