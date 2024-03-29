// Run-time library interface                                  -*- C++ -*-
//
// This header defines the interface of the run-time library. It is not actually
// used anywhere because the compiler pass inserts calls to the library
// functions at the level of LLVM bitcode, but it serves as documentation of the
// intended interface.
//
// Whoever uses this file has to define the type "SymExpr" first; we use it to
// keep this header independent of the back-end implementation.

// This file is part of SymCC.
//
// SymCC is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// SymCC is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// SymCC. If not, see <https://www.gnu.org/licenses/>.

#ifndef RUNTIMECOMMON_H
#define RUNTIMECOMMON_H

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else
#include <stdint.h>
#endif

/*
 * Initialization
 */
void _sym_initialize(void);
void _sym_pre_initialize_qemu(void);
void _sym_initialize_qemu(void);

/*
 * Finalization
 */
void _sym_finalize(void);

/*
 * Construction of simple values
 */
SymExpr _sym_build_integer(uint64_t value, uint8_t bits);
SymExpr _sym_build_integer128(uint64_t high, uint64_t low);
SymExpr _sym_build_value_from_memory(uint8_t *addr, size_t length);
SymExpr _sym_build_float(double value, int is_double);
SymExpr _sym_build_null_pointer(void);
SymExpr _sym_build_true(void);
SymExpr _sym_build_false(void);
SymExpr _sym_build_bool(bool value);

/*
 * Arithmetic and shifts
 */
SymExpr _sym_build_neg(SymExpr expr);
SymExpr _sym_build_add(SymExpr a, SymExpr b);
SymExpr _sym_build_sub(SymExpr a, SymExpr b);
SymExpr _sym_build_mul(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_div(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_div(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_rem(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_rem(SymExpr a, SymExpr b);
SymExpr _sym_build_shift_left(SymExpr a, SymExpr b);
SymExpr _sym_build_logical_shift_right(SymExpr a, SymExpr b);
SymExpr _sym_build_arithmetic_shift_right(SymExpr a, SymExpr b);

SymExpr _sym_build_fp_add(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_sub(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_mul(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_div(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_rem(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_abs(SymExpr a);

/*
 * Boolean operations
 */
SymExpr _sym_build_not(SymExpr expr);
SymExpr _sym_build_signed_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_not_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_bool_and(SymExpr a, SymExpr b);
SymExpr _sym_build_and(SymExpr a, SymExpr b);
SymExpr _sym_build_bool_or(SymExpr a, SymExpr b);
SymExpr _sym_build_or(SymExpr a, SymExpr b);
SymExpr _sym_build_bool_xor(SymExpr a, SymExpr b);
SymExpr _sym_build_xor(SymExpr a, SymExpr b);

SymExpr _sym_build_float_ordered_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_not_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_not_equal(SymExpr a, SymExpr b);

/*
 * Casts
 */
SymExpr _sym_build_sext(SymExpr expr, uint8_t bits);
SymExpr _sym_build_zext(SymExpr expr, uint8_t bits);
SymExpr _sym_build_trunc(SymExpr expr, uint8_t bits);
SymExpr _sym_build_bswap(SymExpr expr);
SymExpr _sym_build_int_to_float(SymExpr value, int is_double, int is_signed);
SymExpr _sym_build_float_to_float(SymExpr expr, int to_double);
SymExpr _sym_build_bits_to_float(SymExpr expr, int to_double);
SymExpr _sym_build_float_to_bits(SymExpr expr);
SymExpr _sym_build_float_to_signed_integer(SymExpr expr, uint8_t bits);
SymExpr _sym_build_float_to_unsigned_integer(SymExpr expr, uint8_t bits);
SymExpr _sym_build_bool_to_bits(SymExpr expr, uint8_t bits);
SymExpr _sym_build_bool_to_sign_bits(SymExpr expr, uint8_t bits);

/*
 * Bit-array helpers
 */
SymExpr _sym_concat_helper(SymExpr a, SymExpr b);
SymExpr _sym_extract_helper(SymExpr expr, size_t first_bit, size_t last_bit);
size_t _sym_bits_helper(SymExpr expr);

/*
 * If-Then-Else
 */
SymExpr _sym_build_ite(SymExpr cond, SymExpr a, SymExpr b);

/*
 * Other bit vector operations
 */
SymExpr _sym_build_extract(SymExpr expr, uint64_t offset, uint64_t length,
                            bool little_endian);
SymExpr _sym_build_insert(SymExpr target, SymExpr to_insert, uint64_t offset,
                            bool little_endian);

/*
 * Function-call helpers
 */
void _sym_set_parameter_expression(uint8_t index, SymExpr expr);
void _sym_set_int_parameter_expression(uint8_t index, SymExpr expr, bool is_int);
SymExpr _sym_get_parameter_expression(uint8_t index);
SymExpr _sym_get_parameter_expression_with_truncate(uint8_t index, uint8_t size);
bool _sym_is_int_parameter(uint8_t index);
uint8_t _sym_get_args_count(void);
void _sym_set_args_count(uint8_t index);
void _sym_set_return_expression(SymExpr expr);
SymExpr _sym_get_return_expression(void);
SymExpr _sym_get_return_expression_with_truncate(uint8_t size);

/*
 * Constraint handling
 */
void _sym_push_path_constraint(SymExpr constraint, int taken,
                               uintptr_t site_id);
SymExpr _sym_get_input_byte(size_t offset);

/*
 * Memory management
 */
SymExpr _sym_read_memory(SymExpr addrExpr, uint8_t *addr, size_t length, uint8_t little_endian);
void _sym_write_memory(SymExpr addrExpr, uint8_t *addr, size_t length, SymExpr expr,
                       uint8_t little_endian, uint64_t value);
void _sym_concretize_memory(uint8_t *addr, size_t length);

/*
 * Models
 */
void _sym_memcpy(uint8_t *dest, const uint8_t *src, size_t length);
void _sym_memset(uint8_t *memory, SymExpr value, size_t length);
void _sym_memmove(uint8_t *dest, const uint8_t *src, size_t length);
void _sym_libc_memset(uint8_t *s, int c, size_t n);
void _sym_libc_memcpy(void *dest, const void *src, size_t n);
void _sym_libc_memmove(void *dest, const void *src, size_t n);

/*
 * Call-stack tracing
 */
uintptr_t _sym_get_call_site(void);
void _sym_update_call(uintptr_t site_id);
void _sym_notify_call(uintptr_t site_id);
void _sym_notify_ret(uintptr_t site_id);
void _sym_notify_basic_block(uintptr_t site_id);
uintptr_t _sym_get_basic_block_id(void);

/*
 * Debugging
 */
const char *_sym_expr_to_string(SymExpr expr); // statically allocated
void _sym_check_consistency(SymExpr expr, uint64_t expected_value, uint64_t addr);
void _sym_print_stack(void);

/*
 * Hybrid mode
 */
void _sym_analysis_mode(int mode);
int _sym_is_concrete_mode_enabled(void);
int _sym_set_concrete_mode(int v);
int _sym_is_emulation_mode_enabled(void);
int _sym_set_emulation_mode(int v);

/*
 * Indirect call handling
 */
uint64_t _sym_wrap_indirect_call_int(uint64_t target);
void _sym_indirect_call_set_arg_int(uint8_t index, uint64_t value, int8_t size);
void _sym_indirect_call_set_arg_count(uint8_t count);
uint64_t _sym_indirect_call_get_arg_int(uint8_t index);
void _sym_wrap_indirect_call_set_trumpoline(uint64_t target);
void _sym_check_indirect_call_target(uint64_t target);

/*
 * Variadic functions
 */
void _sym_va_list_start(uint64_t* ap);

typedef enum {
    UNKNOWN,
    SAT,
    UNSAT
} feasibility_result_t;
feasibility_result_t _sym_feasible(SymExpr expr);

/*
 * Garbage collection
 */
void _sym_register_expression_region(SymExpr *start, size_t length);
void _sym_collect_garbage(void);

void _sym_switch_fs_to_native(void);
void _sym_switch_fs_to_emulation(void);
void _sym_add_exec_map(uint64_t start, uint64_t end, char* name);

#ifdef __cplusplus
}
#endif

#endif
