### Show jmp instructions in binary

```shell
objdump -d --disassemble="main_loop" -M intel cmake-build-release/direct_threaded | grep jmp
```
