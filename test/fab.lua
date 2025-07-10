local c_sources = sources(fab.glob("**/*.c"))

local c_flags = {
    "-I" .. "/chariot/sysroot/usr/include", -- TODO: Janky af.

    "-std=gnu2x",
    "-static -O0",
    "-g",

    "-Wall ",
    "-Wextra",
    "-Wvla",
    "-Wshadow",
    "-Wno-unused-variable",
    "-Wno-unused-function",
    "-Wno-unused-parameter"
}

local c_compiler = fab.find_executable("x86_64-midnatt-gcc")
if c_compiler == nil then
    error("x86_64-midnatt-gcc not found")
end

local rule = fab.rule({
    name = "compile-c",
    description = "compiling c program @OUT@",
    command = { c_compiler, "@ARGS@", "-o", "@OUT@", "@IN@" },
    compdb = true
})

local test_elf = rule:build("test", c_sources, { args = table.join(c_flags, " ") })

test_elf:install("bin/test")
