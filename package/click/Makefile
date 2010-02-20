include $(TOPDIR)/rules.mk

PKG_NAME:=click
PKG_VERSION:=olan-alt
PKG_REV:=31fff627720711ba45de256769c33365c4daf62b

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=git://github.com/olanb7/final-proj.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

CLICK_CONF_FILE:=test.click

include $(INCLUDE_DIR)/package.mk

define Package/click
  SECTION:=net
  CATEGORY:=Network
  DEPENDS:=
  MENU:=1
  TITLE:=The Click Modular Router for OpenWRT
  URL:=http://www.read.cs.ucla.edu/click/
endef

define Package/click/description
Click Modular Router for OpenWRT
endef


BUILDOPTS = \
		BUILD_CXX="g++ -I $(PKG_BUILD_DIR)/include-host" \
		BUILD_DL_LIBS="-ldl"


define Build/Configure
	(cd $(PKG_BUILD_DIR); \
		rm -rf config.{cache,status} ; \
		CONFIG_SITE= \
		./configure; \
		rm -rf include-host; \
		$(CP) include include-host; \
		rm -rf config.{cache,status} ; \
		$(TARGET_CONFIGURE_OPTS) \
		CXXFLAGS="-static -Os -MD" \
		CFLAGS="-static -MD" \
		CPPFLAGS="-I$(STAGING_DIR)/usr/include" \
		LDFLAGS="-L$(STAGING_DIR)/usr/lib" \
		$(BUILDOPTS) \
		./configure \
		  --prefix=/usr \
		  --target=$(GNU_TARGET_NAME) \
		  --host=$(GNU_TARGET_NAME) \
		  --build=$(GNU_HOST_NAME) \
		  --enable-wifi \
		  --disable-linuxmodule \
		  --enable-tools=mixed \
		  --enable-local \
		  --disable-dynamic-linking \
	)
endef

define Build/Compile
	rm -rf $(PKG_INSTALL_DIR);
	mkdir -p $(PKG_INSTALL_DIR);
	$(CP) ./files/$(CLICK_CONF_FILE) $(PKG_BUILD_DIR)/conf/
	$(CONF_OPTS) \
	$(MAKE) -C $(PKG_BUILD_DIR) \
		$(BUILDOPTS) \
		tools elementmap.xml;
	(cd $(PKG_BUILD_DIR)/userlevel; \
		../tools/click-mkmindriver/click-mkmindriver -p olan-driver -C ../ \
			-u -A -d../userlevel \
			-f $(PKG_BUILD_DIR)/conf/$(CLICK_CONF_FILE); \
		$(MAKE) -C $(PKG_BUILD_DIR) \
			$(BUILDOPTS) \
		 	MINDRIVER=olan-driver \
		)
endef

define Package/click/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_BUILD_DIR)/userlevel/olan-driverclick $(1)/usr/bin/click 
	$(CP) $(PKG_BUILD_DIR)/tools/click-align/click-align $(1)/usr/bin/click-align
	mkdir -p $(1)/usr/share/click
	$(CP) $(PKG_BUILD_DIR)/elementmap.xml $(1)/usr/share/click/elementmap.xml
	$(CP) ./files/$(CLICK_CONF_FILE) $(1)/usr/share/click/$(CLICK_CONF_FILE)
endef

$(eval $(call BuildPackage,click))

