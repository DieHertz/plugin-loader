#include "plugin_interface.h"
#include "scope_exit.h"
#include "dynamic_lib.h"
#include <iostream>

void print_plugin_name(const std::string& plugin_filename) {
    try {
        dynamic_lib plugin_lib{plugin_filename};

        auto plugin_entry = plugin_lib.get_symbol<plugin_entry_fn>("get_plugin");
        auto plugin = plugin_entry();
        std::cout << plugin->name() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "error loading plugin '" << plugin_filename << "': " << e.what() << std::endl;
    }
}

int main(int argc, char** argv) {
    for (auto i = 1; i < argc; ++i) print_plugin_name(argv[i]);
}
