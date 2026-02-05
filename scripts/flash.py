#! /usr/bin/env python

import subprocess
from pathlib import Path

import chariot_utils

recipes = ["source/ember", "source/init", "custom/image"]
options = ["--option", "logging=fb"]
chariot_utils.build(recipes, options)

image_path = Path(chariot_utils.path("custom/image", options)) / "ember.img"
usb_path = "/dev/sda"


cmd = [
    "sudo",
    "dd",
    f"if={image_path}",
    f"of={usb_path}",
    "bs=4M",
    "status=progress",
    "conv=fdatasync",
]

try:
    print("\nFlashing...\n")
    subprocess.run(cmd, check=True)
    print("\nFlash complete!")
except subprocess.CalledProcessError as e:
    print(f"Error during flashing: {e}")
