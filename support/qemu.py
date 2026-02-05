#! /usr/bin/env python

import subprocess
import sys

sys.dont_write_bytecode = True
import chariot_utils

chariot_recipes = ["source/ember", "source/init", "custom/image"]

qemu_args = [
    "-accel",
    "tcg",
    "-machine",
    "q35",
    "-cpu",
    "qemu64",
    "-smp",
    "cores=1",
    "-m",
    "1G",
    "-M",
    "smm=off",
    "-d",
    "int,fpu",
    "-D",
    "log.txt",
    "-monitor",
    "stdio",
    "-debugcon",
    "file:/dev/stdout",
    "-S",
    "-s",
    "-no-reboot",
    "-no-shutdown",
    "-display",
    "none",
    "-drive",
    f"format=raw,file={chariot_utils.path('custom/image')}/ember.img",
]


chariot_utils.build(chariot_recipes)

subprocess.run(["alacritty", "msg", "config", "font.size=10"])

try:
    subprocess.run(["qemu-ovmf-x86-64"] + qemu_args, check=True)
except KeyboardInterrupt:
    pass

subprocess.run(["alacritty", "msg", "config", "font.size=13"])
