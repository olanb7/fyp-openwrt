# 
# Copyright (C) 2006 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=hostap-driver
PKG_VERSION:=0.4.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://hostap.epitest.fi/releases/
PKG_MD5SUM:=c7534dc040ab90218257a78488ecd378

include $(INCLUDE_DIR)/package.mk
ifeq ($(DUMP),)
  -include $(LINUX_DIR)/.config
endif

define KernelPackage/hostap/Default/2.4
  VERSION:=$(LINUX_VERSION)+$(PKG_VERSION)-$(BOARD)-$(PKG_RELEASE)
endef

define KernelPackage/hostap/Default/2.6
  VERSION:=$(LINUX_VERSION)-$(BOARD)-$(PKG_RELEASE)
endef

define KernelPackage/hostap/Default
$(call KernelPackage/hostap/Default/$(KERNEL))
  SUBMENU:=Wireless Drivers
  URL:=http://hostap.epitest.fi/
endef

define KernelPackage/hostap/Default/description
 Host AP is a driver for 802.11b wireless cards based on Intersil 
 Prism2/2.5/3 chipset. It supports so called Host AP mode that allows the 
 card to act as an IEEE 802.11 access point.
endef


define KernelPackage/hostap
$(call KernelPackage/hostap/Default)
  TITLE:=Host AP support for Prism2/2.5/3
  DEPENDS:=@PCI_SUPPORT||PCMCIA_SUPPORT +!(LINUX_2_6_30||LINUX_2_6_31):kmod-ieee80211 +LINUX_2_6_30||LINUX_2_6_31:kmod-lib80211 +wireless-tools
  KCONFIG:=CONFIG_HOSTAP CONFIG_HOSTAP_FIRMWARE=y CONFIG_HOSTAP_FIRMWARE_NVRAM=y
  PROVIDES:=kmod-hostap
endef

define KernelPackage/hostap/2.4
# NOTE: needed to remove the dependency on kmod-ieee80211 in the final ipkg
  DEPENDS:=
# NOTE: needed to build the standalone version on 2.4
  KCONFIG:=
  FILES:= \
	$(PKG_BUILD_DIR)/driver/modules/hostap.$(LINUX_KMOD_SUFFIX) \
	$(PKG_BUILD_DIR)/driver/modules/hostap_crypt_ccmp.$(LINUX_KMOD_SUFFIX) \
	$(PKG_BUILD_DIR)/driver/modules/hostap_crypt_tkip.$(LINUX_KMOD_SUFFIX) \
	$(PKG_BUILD_DIR)/driver/modules/hostap_crypt_wep.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoLoad,60,hostap hostap_crypt_wep hostap_crypt_tkip hostap_crypt_ccmp)
endef

define KernelPackage/hostap/2.6
  FILES:= \
	$(LINUX_DIR)/drivers/net/wireless/hostap/hostap.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoLoad,60,hostap)
endef

define KernelPackage/hostap/description
$(call KernelPackage/hostap/Default/description)
 This package contains the base Host AP driver code that is shared by 
 different hardware models. You will also need to enable support for 
 PLX/PCI/CS version of the driver to actually use the driver.
endef


define KernelPackage/hostap-cs
$(call KernelPackage/hostap/Default)
  TITLE:=Host AP driver for PCMCIA adaptors
  DEPENDS:=@PCMCIA_SUPPORT kmod-hostap +kmod-pcmcia-core
  KCONFIG:=CONFIG_HOSTAP_CS
  AUTOLOAD:=$(call AutoLoad,60,hostap_cs)
endef
define KernelPackage/hostap-cs/2.4
# NOTE: needed to build the standalone version on 2.4
  KCONFIG:=
  FILES:= \
	$(PKG_BUILD_DIR)/driver/modules/hostap_cs.$(LINUX_KMOD_SUFFIX)
endef
define KernelPackage/hostap-cs/2.6
  FILES:= \
	$(LINUX_DIR)/drivers/net/wireless/hostap/hostap_cs.$(LINUX_KMOD_SUFFIX)
endef

define KernelPackage/hostap-cs/description
$(call KernelPackage/hostap/Default/description)
 This package contains the Host AP driver for Prism2/2.5/3 PC cards.
endef


define KernelPackage/hostap-pci
$(call KernelPackage/hostap/Default)
  TITLE:=Host AP driver for PCI adaptors
  DEPENDS:=@PCI_SUPPORT kmod-hostap
  KCONFIG:=CONFIG_HOSTAP_PCI
  AUTOLOAD:=$(call AutoLoad,60,hostap_pci)
endef

define KernelPackage/hostap-pci/2.4
# NOTE: needed to build the standalone version on 2.4
  KCONFIG:=
  FILES:= \
	$(PKG_BUILD_DIR)/driver/modules/hostap_pci.$(LINUX_KMOD_SUFFIX)
endef

define KernelPackage/hostap-pci/2.6
  FILES:= \
	$(LINUX_DIR)/drivers/net/wireless/hostap/hostap_pci.$(LINUX_KMOD_SUFFIX)
endef

define KernelPackage/hostap-pci/description
$(call KernelPackage/hostap/Default/description)
 This package contains the Host AP driver for Prism2.5 PCI adaptors.
endef


define KernelPackage/hostap-plx
$(call KernelPackage/hostap/Default)
  TITLE:=Host AP driver for PLX9052 based PCI adaptors
  DEPENDS:=@PCI_SUPPORT kmod-hostap
  KCONFIG:=CONFIG_HOSTAP_PLX
  AUTOLOAD:=$(call AutoLoad,60,hostap_plx)
endef

define KernelPackage/hostap-plx/2.4
# NOTE: needed to build the standalone version on 2.4
  KCONFIG:=
  FILES:= \
	$(PKG_BUILD_DIR)/driver/modules/hostap_plx.$(LINUX_KMOD_SUFFIX)
endef

define KernelPackage/hostap-plx/2.6
  FILES:= \
	$(LINUX_DIR)/drivers/net/wireless/hostap/hostap_plx.$(LINUX_KMOD_SUFFIX)
endef

define KernelPackage/hostap-plx/description
$(call KernelPackage/hostap/Default/description)
 This package contains the Host AP driver for Prism2/2.5/3 in PLX9052 
 based PCI adaptors.
endef


ifeq ($(KERNEL),2.4)
  define Build/Compile
	$(MAKE) -C $(LINUX_DIR)/ \
		ARCH="$(LINUX_KARCH)" \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		SUBDIRS="$(PKG_BUILD_DIR)/driver/modules" \
		modules
  endef
else
  define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
  endef
  
  define Build/Configure
  endef
  
  define Build/Compile
  endef
endif

define KernelPackage/hostap/install
	$(INSTALL_DIR) $(1)/lib/wifi
	$(INSTALL_DATA) ./files/lib/wifi/hostap.sh $(1)/lib/wifi
endef

$(eval $(call KernelPackage,hostap))
$(eval $(call KernelPackage,hostap-cs))
$(eval $(call KernelPackage,hostap-pci))
$(eval $(call KernelPackage,hostap-plx))
