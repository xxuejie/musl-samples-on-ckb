#!/usr/bin/env bash
set -ex

CLANG="${CLANG:-clang-18}"
CLANGXX="${CLANG/clang/clang++}"
LD="${CLANG/clang/ld.lld}"

if ! [ -d deps/musl/release ]; then
  cd deps/musl
  CLANG=$CLANG ./ckb/build.sh
  cd ../..
fi

if ! [ -f deps/builtins/build/libcompiler-rt.a ]; then
  cd deps/builtins
  BUILTIN_CFLAGS="--target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs -mabi=lp64"
  BUILTIN_CFLAGS+=" -nostdinc -I ../musl/release/include"
  BUILTIN_CFLAGS+=" -Os"
  BUILTIN_CFLAGS+=" -fdata-sections -ffunction-sections -fno-builtin -fvisibility=hidden -fomit-frame-pointer"
  BUILTIN_CFLAGS+=" -I compiler-rt/lib/builtins"
  BUILTIN_CFLAGS+=" -DVISIBILITY_HIDDEN -DCOMPILER_RT_HAS_FLOAT16"
  make CC=$CLANG \
    LD="$LD" \
    OBJCOPY=${CLANG/clang/llvm-objcopy} \
    AR=${CLANG/clang/llvm-ar} \
    RANLIB=${CLANG/clang/llvm-ranlib} \
    CFLAGS="$BUILTIN_CFLAGS"
  cd ../..
fi

if ! [ -d deps/libcxx/release ]; then
  cd deps/libcxx
  CLANG=$CLANG ./build.sh
  cd ../..
fi

$CLANG --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -nostdinc \
  -isystem deps/musl/release/include \
  -c blake2b_test.c -o blake2b_test.o \
  -fdata-sections -ffunction-sections
$LD blake2b_test.o -o blake2b_test_ckb \
  --gc-sections \
  --nostdlib --sysroot deps/musl/release \
  -Ldeps/musl/release/lib -Ldeps/builtins/build \
  -lc -lgcc -lcompiler-rt

$CLANG --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -nostdinc \
  -isystem deps/musl/release/include \
  -c malloc_test.c -o malloc_test.o \
  -fdata-sections -ffunction-sections
$LD malloc_test.o -o malloc_test_ckb \
  --gc-sections \
  --nostdlib --sysroot deps/musl/release \
  -Ldeps/musl/release/lib -Ldeps/builtins/build \
  -lc -lgcc -lcompiler-rt

$CLANG --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -nostdinc \
  -isystem deps/musl/release/include \
  -I deps/ckb \
  -c double_test.c -o double_test.o \
  -fdata-sections -ffunction-sections
$LD double_test.o -o double_test_ckb \
  --gc-sections \
  --nostdlib --sysroot deps/musl/release \
  -Ldeps/musl/release/lib -Ldeps/builtins/build \
  -lc -lgcc -lcompiler-rt

$CLANGXX --target=riscv64 -march=rv64imc_zba_zbb_zbc_zbs \
  -g -O3 \
  -D_GNU_SOURCE \
  -nostdinc \
  -isystem deps/libcxx/release/include/c++/v1 \
  -isystem deps/musl/release/include \
  -c cpp_cout_test.cpp -o cpp_cout_test.o \
  -fdata-sections -ffunction-sections
$LD cpp_cout_test.o -o cpp_cout_test_ckb \
  --gc-sections \
  --nostdlib --sysroot deps/musl/release \
  -Ldeps/musl/release/lib -Ldeps/builtins/build \
  -lc -lgcc -lcompiler-rt \
  -Ldeps/libcxx/release/lib \
  -lc++ -lc++abi -lunwind
