### Indirect

```c
#define DISPATCH()                                      \
        do {                                            \
            instruction_t inst = code[machineState.ip]; \
            goto *dispatch[inst];                       \
        } while (0)
```

```asm
# rdi: start address of code
# rsi: IP
# esi (result): instruction
movzx  esi,BYTE PTR [rdi+rsi*1]

# rsp: start address of dispatch table
# rsi: instruction (1 byte) (times 8 because pointer is 8 bytes)
jmp    QWORD PTR [rsp+rsi*8+0x10]
```

### Direct

```c
#define DISPATCH()                                  \
        do {                                        \
            goto *predecoded_code[machineState.ip]; \
        } while (0)
```

```asm
# r10: predecoded_code
# rax: IP
jmp    QWORD PTR [r10+rax*8]
```
