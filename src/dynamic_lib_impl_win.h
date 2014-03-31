#include <windows.h>
#include <stdexcept>

struct dynamic_lib::impl {
    impl(const std::string& lib) {
        handle = LoadLibrary(lib.data());
        if (!handle) throw std::runtime_error{"no_such_file"};
    }

    ~impl() {
        if (handle) FreeLibrary(handle);
    }

    void* get_symbol(const std::string& symbol_name) {
        if (auto symbol = GetProcAddress(handle, symbol_name.data())) {
            return reinterpret_cast<void*>(symbol);
        }
        throw std::runtime_error{"no_such_symbol"};
    }

    HMODULE handle;
};