#!/usr/bin/env bash
set -ex

CLANG="${CLANG:-clang-18}"
CLANGXX="${CLANG/clang/clang++}"

if ! [ -d deps/musl/release ]; then
  cd deps/musl
  CLANG=$CLANG ./ckb/build.sh
  cd ../..
fi

if ! [ -f deps/builtins/build/libcompiler-rt.a ]; then
  cd deps/builtins
  make CC=$CLANG \
    LD=${CLANG/clang/ld.lld} \
    OBJCOPY=${CLANG/clang/llvm-objcopy} \
    AR=${CLANG/clang/llvm-ar} \
    RANLIB=${CLANG/clang/llvm-ranlib}
  cd ../..
fi

if ! [ -d deps/libcxx/release ]; then
  cd deps/libcxx
  CLANG=$CLANG ./build.sh
  cd ../..
fi

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

$CLANGXX --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -D_GNU_SOURCE \
  -nostdinc --sysroot deps/musl/release \
  -isystem deps/libcxx/release/include/c++/v1 \
  -isystem deps/musl/release/include \
  -Ldeps/libcxx/release/lib \
  -Ldeps/musl/release/lib \
  -Ldeps/builtins/build -lcompiler-rt \
  cpp_cout_test.cpp -o cpp_cout_test_ckb \
  -fdata-sections -ffunction-sections -Wl,--gc-sections
