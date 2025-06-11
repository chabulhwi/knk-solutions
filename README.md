# knk-solutions

This is the repository for my solutions to the exercises in ["C Programming: A
Modern Approach," second edition][c] by [K. N. King][knk]. You are free to reuse
the content under the terms of [Mozilla Public License Version 2.0](./LICENSE).

I wrote the source code in the [Linux kernel coding style][linux].

## Shell scripts

The shell scripts are in the `scripts` directory.

### `aspell.sh`

Check the spelling of each Markdown document and C source code.

### `indent.sh`

Format the C source code according to the Linux style.

The manpage of the `indent` command says that the style is equivalent to the
following settings:

```
-nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4
-cli0 -d0 -di1 -nfc1 -i8 -ip0 -l80 -lp -npcs -nprs -npsl -sai
-saf -saw -ncs -nsc -sob -nfca -cp33 -ss -ts8 -il0
```

When a statement is broken across two lines, the second line is indented by a
number of additional spaces specified by the `-ci` option. Note that I removed
the `-ci4` option because I want to indent the second line by a tab instead.

The default style of indentation is to use tabs, which is specified by the `-ut`
option. Since this option is the default, I don't have to explicitly specify it.

I changed the offset at which a label (except case labels) will be positioned
from one to zero.

## Contributing

If you've found errors in my solutions and want to fix them, please send an
email to <~chabulhwi/public-inbox@lists.sr.ht>. It's my [public inbox][inbox]
showing patches, questions, and discussions for any of my projects that don't
have their own mailing list.

[c]: http://knking.com/books/c2/index.html
[knk]: http://knking.com/index.html
[linux]: https://www.kernel.org/doc/html/latest/process/coding-style.html
[inbox]: https://lists.sr.ht/~chabulhwi/public-inbox
