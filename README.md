# cp-mv-paste

> Windows-like file copy/paste utility for bash/zsh/etc.

```bash
$ cd /src/dir
$ cp foo
$ mv bar
$ cd /dst
$ pst ./dir
cp -R /src/dir/foo /dst/dir
mv    /src/dir/bar /dst/dir
$ ls
foo     bar
```

## Install
```bash
git clone --depth=1 https://github.com/b1f6c1c4/cp-mv-paste
```

And then either:

1. Use shell alias
2. Add to PATH
3. `ln -s` to somewhere in PATH

## Usage
```
{cp,mv} <file>
{cp,mv} -- <files> ...

All other calling forms will be forwarded to /usr/bin/{cp,mv}.
```

## Limitation
- It doesn't support copy/move across ssh sessions.
- The file list is persistent after reboot.
- If you forget to `pst --abort`, you may accidentally copy/move more files than you need.
