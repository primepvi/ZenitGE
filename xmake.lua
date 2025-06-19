add_rules("mode.debug", "mode.release", "module")
add_requires("glfw", "glad")

target("zenit")
set_kind("binary")
add_files("src/*.cpp")
add_includedirs("include")
add_packages("glfw", "glad")

rule("module")
on_config(function(target)
    target:set("rundir", os.projectdir())
end)
