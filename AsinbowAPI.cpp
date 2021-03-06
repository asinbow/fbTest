/**********************************************************\

  Auto-generated AsinbowAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"
#include <boost/format.hpp>

#include "AsinbowAPI.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn FB::variant AsinbowAPI::echo(const FB::variant& msg)
///
/// @brief  Echos whatever is passed from Javascript.
///         Go ahead and change it. See what happens!
///////////////////////////////////////////////////////////////////////////////
FB::variant AsinbowAPI::echo(const FB::variant& msg)
{
    static int n(0);
    fire_echo("So far, you clicked this many times: ", n++);

    // return "foobar";
    return msg;
}

///////////////////////////////////////////////////////////////////////////////
/// @fn AsinbowPtr AsinbowAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
AsinbowPtr AsinbowAPI::getPlugin()
{
    AsinbowPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

// Read/Write property testString
std::string AsinbowAPI::get_testString()
{
    return m_testString;
}

void AsinbowAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string AsinbowAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}

void AsinbowAPI::testEvent()
{
    fire_test();
}

void AsinbowAPI::executeCommandWork(const std::string& command, const FB::JSObjectPtr& callback) {
    char buf[4096];
    FILE* pipe = popen(
#ifdef _WIN32
        utf8_to_ansi(command).c_str(),
#else
        command.c_str(),
#endif
        "r");
    if (!pipe) {
        callback->Invoke("", FB::variant_list_of(true)("popen failed!"));
        return;
    }
    std::string result;
    int c;
    while ((c = fgetc(pipe)) != EOF) {
        result += (char)c;
        if (c=='\n') {
#ifdef _WIN32
            result = ansi_to_utf8(result);
#endif
            callback->Invoke("", FB::variant_list_of(false)(result));
            result = "";
        }
    }
    pclose(pipe);
    callback->Invoke("", FB::variant_list_of(true));
}

void AsinbowAPI::executeCommand(const std::string& command, const FB::JSObjectPtr& callback) {
    boost::thread thread(boost::bind(&AsinbowAPI::executeCommandWork, this, command, callback));
}
