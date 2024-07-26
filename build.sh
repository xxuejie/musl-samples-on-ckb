#!/bin/bash
set -ex

CLANG="${CLANG:-clang-18}"

cd deps/musl
CLANG=$CLANG ./ckb/build.sh
cd ../..

cd deps/builtins
make CC=$CLANG \
  LD=${CLANG/clang/ld.lld} \
  OBJCOPY=${CLANG/clang/llvm-objcopy} \
  AR=${CLANG/clang/llvm-ar} \
  RANLIB=${CLANG/clang/llvm-ranlib}
cd ../..

$CLANG --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -nostdinc --sysroot deps/musl/release -isystem deps/musl/release/include -Ldeps/musl/release/lib \
  -Ldeps/builtins/build -lcompiler-rt \
  blake2b_test.c -o blake2b_test_ckb \
  -fdata-sections -ffunction-sections -Wl,--gc-sections

$CLANG --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -nostdinc --sysroot deps/musl/release -isystem deps/musl/release/include -Ldeps/musl/release/lib \
  -Ldeps/builtins/build -lcompiler-rt \
  malloc_test.c -o malloc_test_ckb \
  -fdata-sections -ffunction-sections -Wl,--gc-sections

$CLANG --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -nostdinc --sysroot deps/musl/release -isystem deps/musl/release/include -Ldeps/musl/release/lib \
  -Ldeps/builtins/build -lcompiler-rt \
  double_test.c -o double_test_ckb \
  -I deps/ckb \
  -fdata-sections -ffunction-sections -Wl,--gc-sections
