local c = require("lang_c")

local c_sources = sources(fab.glob("**/*.c"))

local flags = {
    "-std=gnu2x",
    "-O0",
    "-g",

    "-Wall ",
    "-Wextra",
    "-Wvla",
    "-Wshadow",
    "-Wno-unused-variable",
    "-Wno-unused-function",
    "-Wno-unused-parameter"
}

local cc = c.get_gcc("x86_64-midnatt-gcc")
assert(cc ~= nil, "x86_64-midnatt-gcc not found")

local init = cc:compile("init", c_sources, flags)

return {
    install = {
        ["/usr/bin/init"] = init
    }
}
