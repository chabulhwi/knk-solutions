find . \( -name '*.c' -o -name '*.h' \) \
    ! \( -path "./chapter16/*" \( \
    -name 'exercise02d.c' -o \
    -name 'exercise03d.c' -o \
    -name 'exercise04c.c' -o \
    -name 'exercise04d.c' -o \
    -name 'exercise08b.h' -o \
    -name 'exercise10*.c' -o \
    -name 'exercise14b.c' \) \) \
    ! \( -path "./chapter17/*" \( \
    -name 'exercise06.c' -o \
    -name 'exercise07.c' -o \
    -name 'exercise11.c' -o \
    -name 'exercise12.c' -o \
    -name 'exercise13.c' -o \
    -name 'exercise14.c' -o \
    -name 'exercise19.c' -o \
    -path "./chapter17/project04/line.c" \) \) \
    -exec indent \
    -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce \
    -cli0 -d0 -di1 -nfc1 -i8 -ip0 -l80 -lp -npcs -nprs -npsl -sai \
    -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il0 {} +
