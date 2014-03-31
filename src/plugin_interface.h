#ifndef plugin_interface_h
#define plugin_interface_h
#include <string>

class plugin_interface {
public:
    virtual std::string name() const = 0;
};

using plugin_entry_fn = plugin_interface*(*)();

#endif /* plugin_interface_h */
