rm -rf build
rm -rf log

cmake -B build -S .
cmake --build build -- -j$(nproc)

unset ASAN_OPTIONS

ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-alloc-dealloc-mismatch-1"                                 build/alloc-dealloc-mismatch-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-allocation-size-too-big-1"                                build/allocation-size-too-big-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-calloc-overflow-1"                                        build/calloc-overflow-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-container-overflow-1"                                     build/container-overflow-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-double-free-1"                                            build/double-free-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-double-free-2"                                            build/double-free-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-dynamic-stack-buffer-overflow-1"                          build/dynamic-stack-buffer-overflow-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-dynamic-stack-buffer-overflow-2"                          build/dynamic-stack-buffer-overflow-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-dynamic-stack-buffer-overflow-3"                          build/dynamic-stack-buffer-overflow-3
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-buffer-overflow-1"                                   build/heap-buffer-overflow-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-buffer-overflow-2"                                   build/heap-buffer-overflow-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-buffer-overflow-3"                                   build/heap-buffer-overflow-3
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-use-after-free-1"                                    build/heap-use-after-free-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-use-after-free-2"                                    build/heap-use-after-free-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-use-after-free-3"                                    build/heap-use-after-free-3
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-heap-use-after-free-4"                                    build/heap-use-after-free-4
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-invalid-allocation-alignment-1"                           build/invalid-allocation-alignment-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-memcpy-param-overlap-1"                                   build/memcpy-param-overlap-1
ASAN_OPTIONS="halt_on_error=0:detect_leaks=1:log_path=log/ASAN-memory-leak-1"                             build/memory-leak-1
ASAN_OPTIONS="halt_on_error=0:detect_leaks=1:log_path=log/ASAN-memory-leak-2"                             build/memory-leak-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-new-delete-type-mismatch-1"                               build/new-delete-type-mismatch-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-buffer-overflow-1"                                  build/stack-buffer-overflow-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-buffer-overflow-2"                                  build/stack-buffer-overflow-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-buffer-underflow-1"                                 build/stack-buffer-underflow-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-buffer-underflow-2"                                 build/stack-buffer-underflow-2
ASAN_OPTIONS="halt_on_error=0:detect_stack_use_after_return=1:log_path=log/ASAN-stack-use-after-return-1" build/stack-use-after-return-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-use-after-scope-1"                                  build/stack-use-after-scope-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-use-after-scope-2"                                  build/stack-use-after-scope-2
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-use-after-scope-3"                                  build/stack-use-after-scope-3
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-stack-use-after-scope-4"                                  build/stack-use-after-scope-4
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-strncat-param-overlap-1"                                  build/strncat-param-overlap-1
ASAN_OPTIONS="halt_on_error=0:log_path=log/ASAN-use-after-poison-1"                                       build/use-after-poison-1

