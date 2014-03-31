#include <dlfcn.h>
#include <stdexcept>

struct dynamic_lib::impl {
    impl(const std::string& lib) {
        handle = dlopen(lib.data(), RTLD_LAZY);
        if (!handle) throw std::runtime_error{"no_such_file"};
    }

    ~impl() {
        if (handle) dlclose(handle);
    }

    void* get_symbol(const std::string& symbol_name) {
        if (auto symbol = dlsym(handle, symbol_name.data())) return symbol;
        throw std::runtime_error{"no_such_symbol"};
    }

    void* handle;
};