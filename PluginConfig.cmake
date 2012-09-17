#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Asinbow
#
#\**********************************************************/

set(PLUGIN_NAME "Asinbow")
set(PLUGIN_PREFIX "ASI")
set(COMPANY_NAME "SaybotInc")

# ActiveX constants:
set(FBTYPELIB_NAME AsinbowLib)
set(FBTYPELIB_DESC "Asinbow 1.0 Type Library")
set(IFBControl_DESC "Asinbow Control Interface")
set(FBControl_DESC "Asinbow Control Class")
set(IFBComJavascriptObject_DESC "Asinbow IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "Asinbow ComJavascriptObject Class")
set(IFBComEventSource_DESC "Asinbow IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 195c31ee-7b20-5222-802b-886e2ed53e2b)
set(IFBControl_GUID ea0534e3-c82d-5a05-a9fc-05dbcce7e6a7)
set(FBControl_GUID efc66802-5327-5e6a-bd12-4443f3ff0528)
set(IFBComJavascriptObject_GUID adcc2e5f-cc22-5b41-b354-9f4fee511906)
set(FBComJavascriptObject_GUID facccab0-4df0-577f-977f-6fddf0a86861)
set(IFBComEventSource_GUID a8293fbd-b405-5394-afb9-09984c55ab2b)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "SaybotInc.Asinbow")
set(MOZILLA_PLUGINID "saybot.com/Asinbow")

# strings
set(FBSTRING_CompanyName "Saybot.Inc")
set(FBSTRING_PluginDescription "Hello ASINBOW!")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 Saybot.Inc")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Asinbow")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "Asinbow")
set(FBSTRING_MIMEType "application/x-asinbow")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
