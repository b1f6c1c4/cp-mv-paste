#!/bin/sh

usage() {
    cat - <<EOF
Usage:
    cp <file>
    cp -- <files> ...

    All other calling forms will be forwarded to /usr/bin/cp.
EOF
}

LST=~/.cp-mv-paste

if [ "$#" -eq 0 ]; then
    usage
    exit 1
fi

if [ "$#" -eq 1 ]; then
    if [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
        usage
        exit 0
    fi
    if [ "$1" = "--" ]; then
        exit 0
    fi
fi

if [ "$#" -gt 1 ]; then
    if [ ! "$1" = "--" ]; then
        exec /usr/bin/cp "$@"
    fi
    shift
fi

while [ "$#" -gt 0 ]; do
    mkdir -p "$LST"
    if [ -d "$1" ]; then
        echo "warning: you copied a directory $1." >&2
    fi
    printf '%s\0' "$PWD/$1" >>"$LST/pending-cp"
    shift
done
