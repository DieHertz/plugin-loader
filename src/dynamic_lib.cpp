#include "dynamic_lib.h"
#include "dynamic_lib_impl_ld.h"

dynamic_lib::dynamic_lib(const std::string& lib) : pimpl{new impl{lib}} {}
dynamic_lib::~dynamic_lib() = default;

void* dynamic_lib::get_symbol(const std::string& symbol_name) {
    return pimpl->get_symbol(symbol_name);
}
