#include "plugin_interface.h"

class test_plugin : public plugin_interface {
    virtual std::string name() const override { return "test-plugin-v1"; }  
};

extern "C" plugin_interface* get_plugin() {
    static auto plugin = new test_plugin{};
    return plugin;
}
