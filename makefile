all: plugin_loader test_plugin

run: plugin_loader test_plugin
	bin/plugin_loader bin/test_plugin.dylib non-existent-plugin-path

plugin_loader: src/plugin_loader.cpp src/plugin_interface.h \
	src/scope_exit.h src/dynamic_lib.h src/dynamic_lib.cpp \
	src/dynamic_lib_impl_ld.h
	g++ src/plugin_loader.cpp src/dynamic_lib.cpp -std=c++11 -o bin/plugin_loader

test_plugin: src/test_plugin.cpp src/plugin_interface.h
	g++ -shared src/test_plugin.cpp -std=c++11 -o bin/test_plugin.dylib

clean:
	rm -rf bin/*
