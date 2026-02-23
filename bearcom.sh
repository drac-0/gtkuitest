#!/usr/bin/env bash
bear -- gcc $1 $(pkg-config --cflags --libs gtk4) -o a
./a
