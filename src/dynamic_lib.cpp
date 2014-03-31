#include "dynamic_lib.h"

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
#include "dynamic_lib_impl_win.h"
#else
#include "dynamic_lib_impl_ld.h"
#endif

dynamic_lib::dynamic_lib(const std::string& lib) : pimpl{new impl{lib}} {}
dynamic_lib::~dynamic_lib() = default;

void* dynamic_lib::get_symbol(const std::string& symbol_name) {
    return pimpl->get_symbol(symbol_name);
}
