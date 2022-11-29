### Show main_loop function

```shell
objdump -d --disassemble="main_loop" -M intel cmake-build-release/direct_threaded
```

### Show jmp instructions in binary and 5 previous instructions

```shell
objdump -d --disassemble="main_loop" -M intel cmake-build-release/direct_threaded | grep -B 5 jmp
```

### Compare main_loop function between binaries

```shell
diff --color=always -y <(objdump -d cmake-build-release/indirect_threaded -M intel --disassemble="main_loop"  --no-show-raw-insn --no-addresses) <(objdump -d cmake-build-release/direct_threaded -M intel --disassemble="main_loop"  --no-show-raw-insn --no-addresses) | less -R
```
