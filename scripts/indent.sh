find . -name "*.c" -exec indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 \
     -ncdb -ce -ut -cli0 -d0 -di1 -nfc1 -i8 -ip0 -l80 -lp -npcs -nprs -npsl \
     -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il1 {} +
