set -xe

CC="clang"

RENGE_CFLAGS="-Isrc"
RENGE_SOURCES=(
    "./src/renge/core/memory.c"
    "./src/renge/core/console.c"
    "./src/renge/core/string.c"
    "./src/renge/external/stb/stb_sprintf.c"
)

CFLAGS="-Wall -Wextra ${RENGE_CFLAGS}"

$CC $CFLAGS -o application.exe ./src/main.c "${RENGE_SOURCES[@]}"
