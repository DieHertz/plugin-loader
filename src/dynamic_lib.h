#ifndef dynamic_lib_h
#define dynamic_lib_h
#include <memory>
#include <string>

class dynamic_lib {
    struct impl;
    std::unique_ptr<impl> pimpl;

public:
    dynamic_lib(const std::string& lib);
    ~dynamic_lib();

    dynamic_lib(const dynamic_lib&) = delete;
    dynamic_lib& operator=(const dynamic_lib&) = delete;

    template<class S> S get_symbol(const std::string& symbol_name) {
        return reinterpret_cast<S>(get_symbol(symbol_name));
    }

private:
    void* get_symbol(const std::string& symbol_name);
};

#endif /* dynamic_lib_h */
