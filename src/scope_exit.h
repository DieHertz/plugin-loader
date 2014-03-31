#ifndef scope_exit_h
#define scope_exit_h
#include <utility>

template<class Function> class scope_exit_impl {
    Function f;

public:
    scope_exit_impl(Function f) : f{f} {}
    ~scope_exit_impl() { f(); }
};

template<class Function> scope_exit_impl<Function> scope_exit_forwarder(Function&& f) {
    return std::forward<Function>(f);
}

#define scope_exit_impl(fn, n) auto at_scope_exit##n = scope_exit_forwarder([&] { fn })
#define scope_exit_fwd(fn, n) scope_exit_impl(fn, n)
#define scope_exit(fn) scope_exit_fwd(fn, __COUNTER__)

#endif /* scope_exit_h */
