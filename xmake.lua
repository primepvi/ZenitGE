add_rules("mode.debug", "mode.release")
add_requires("glfw", "glad")

target("shade")
set_kind("binary")
add_files("src/*.cpp")
add_packages("glfw", "glad")
