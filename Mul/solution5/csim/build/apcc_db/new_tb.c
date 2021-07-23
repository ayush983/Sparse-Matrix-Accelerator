/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void mul1(signed int (*llvm_cbe_A)[8], signed int (*llvm_cbe_B)[8], signed int (*llvm_cbe_C)[8], signed int (*llvm_cbe_sparse_new)[3]);
signed int main(void);


/* Global Variable Definitions and Initialization */
static signed int aesl_internal_main_OC_B[8][8] = { { 4u, 1u, 5u, 5u, 7u, 12u, 0u, 6u }, { 2u, 2u, 3u, 20u, 55u, 90u, 100u, 10u }, { 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u }, { 3u, 6u, 9u, 3u, 1u, 3u, 5u, 5u }, { 4u, 2u, 5u, 8u, 1u, 4u, 1u, 1u }, { 10u, 20u, 30u, 4u, 5u, 15u, 12u, 1u }, { 1u, 2u, 5u, 7u, 3u, 10u, 11u, 12u }, { 1u, 2u, 19u, 20u, 4u, 3u, 2u, 1u } };
static  char aesl_internal__OC_str[4] = "%d ";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void mul1(signed int (*llvm_cbe_A)[8], signed int (*llvm_cbe_B)[8], signed int (*llvm_cbe_C)[8], signed int (*llvm_cbe_sparse_new)[3]) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  signed int *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  signed int *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  signed int *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  signed int *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  signed int *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  signed int *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  signed int *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  signed int *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  signed int *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  signed int *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  signed int *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  signed int *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  signed int *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  signed int *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  signed int *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  signed int *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  signed int *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  signed int *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mul1\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__59;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__59:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%59, %%1  for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [3 x i32]* %%sparse_new, i64 %%2, i64 0, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__2 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sparse_new' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__3 = (unsigned int )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [3 x i32]* %%sparse_new, i64 %%2, i64 1, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__4 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sparse_new' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__5 = (unsigned int )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [3 x i32]* %%sparse_new, i64 %%2, i64 2, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__6 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'sparse_new' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 4, !dbg !5 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__7 = (unsigned int )*llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sext i32 %%6 to i64, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__8 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%4 to i64, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__9 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 0, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__10 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* %%11, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__11 = (unsigned int )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul nsw i32 %%12, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__11&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 0, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__13 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%15, %%13, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_tmp__14&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* %%14, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_49_count);
  *llvm_cbe_tmp__13 = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 1, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__16 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__17 = (unsigned int )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul nsw i32 %%18, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(llvm_cbe_tmp__17&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 1, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__19 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__20 = (unsigned int )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%21, %%19, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__18&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* %%20, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_61_count);
  *llvm_cbe_tmp__19 = llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 2, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__22 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* %%23, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__23 = (unsigned int )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = mul nsw i32 %%24, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__23&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 2, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__25 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__26 = (unsigned int )*llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%27, %%25, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_tmp__26&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__24&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%26, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_73_count);
  *llvm_cbe_tmp__25 = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 3, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__28 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* %%29, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__29 = (unsigned int )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = mul nsw i32 %%30, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_tmp__29&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 3, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__31 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i32* %%32, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__32 = (unsigned int )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add nsw i32 %%33, %%31, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(llvm_cbe_tmp__32&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__30&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%34, i32* %%32, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_85_count);
  *llvm_cbe_tmp__31 = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__34 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%35, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__35 = (unsigned int )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = mul nsw i32 %%36, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_tmp__35&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__37 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i32* %%38, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__38 = (unsigned int )*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%39, %%37, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_tmp__38&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__36&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%40, i32* %%38, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_97_count);
  *llvm_cbe_tmp__37 = llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 5, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__40 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i32* %%41, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__41 = (unsigned int )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = mul nsw i32 %%42, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__42 = (unsigned int )((unsigned int )(llvm_cbe_tmp__41&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__42&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 5, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__43 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i32* %%44, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__44 = (unsigned int )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%45, %%43, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__42&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )5ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%46, i32* %%44, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_109_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 6, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__46 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i32* %%47, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__47 = (unsigned int )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = mul nsw i32 %%48, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(llvm_cbe_tmp__47&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__48&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 6, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__49 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i32* %%50, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__50 = (unsigned int )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = add nsw i32 %%51, %%49, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_tmp__50&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__48&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )6ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%52, i32* %%50, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_121_count);
  *llvm_cbe_tmp__49 = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds [8 x i32]* %%B, i64 %%9, i64 7, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__52 = (signed int *)(&llvm_cbe_B[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'B' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i32* %%53, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__53 = (unsigned int )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = mul nsw i32 %%54, %%8, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_tmp__53&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds [8 x i32]* %%C, i64 %%10, i64 7, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__55 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__9))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__9));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i32* %%56, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__56 = (unsigned int )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add nsw i32 %%57, %%55, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__54&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )7ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%58, i32* %%56, align 4, !dbg !4 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_133_count);
  *llvm_cbe_tmp__55 = llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add nsw i32 %%storemerge3, 1, !dbg !6 for 0x%I64xth hint within @mul1  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__58&4294967295ull)));
  if (((llvm_cbe_tmp__58&4294967295U) == (6u&4294967295U))) {
    goto llvm_cbe_tmp__60;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__58;   /* for PHI node */
    goto llvm_cbe_tmp__59;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__60:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mul1}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_A_count = 0;
  signed int llvm_cbe_A[8][8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_B_count = 0;
  signed int llvm_cbe_B[8][8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_C_count = 0;
  signed int llvm_cbe_C[8][8];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_sparse_new_count = 0;
  signed int llvm_cbe_sparse_new[6][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
   char *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  signed int *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  signed int *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  signed int *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  signed int *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  signed int *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  signed int *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
   char *llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
   char *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
   char *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
   char *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  signed int *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned int llvm_cbe_tmp__74;
  unsigned int llvm_cbe_tmp__74__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  signed int *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  signed int *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  signed int *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed int *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__83;
  unsigned int llvm_cbe_tmp__83__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  signed int *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  signed int (*llvm_cbe_tmp__86)[8];
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  signed int (*llvm_cbe_tmp__87)[8];
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  signed int (*llvm_cbe_tmp__88)[8];
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  signed int (*llvm_cbe_tmp__89)[3];
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned int llvm_cbe_storemerge15;
  unsigned int llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  signed int *llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  signed int *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  signed int *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  signed int *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  signed int *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned int llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  signed int *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned int llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned int llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  signed int *llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  signed int *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  unsigned int llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  unsigned long long llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  signed int *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  signed int *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  unsigned int llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  signed int *llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned int llvm_cbe_tmp__121;
  unsigned int llvm_cbe_tmp__121__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  signed int *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned int llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  unsigned long long llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  signed int *llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  signed int *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  signed int *llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  unsigned int llvm_cbe_tmp__129;
  unsigned int llvm_cbe_tmp__129__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  signed int *llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  unsigned long long llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  signed int *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  signed int *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  unsigned int llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  signed int *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  unsigned int llvm_cbe_tmp__137;
  unsigned int llvm_cbe_tmp__137__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  signed int *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned int llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned long long llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  signed int *llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  signed int *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  signed int *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned int llvm_cbe_tmp__145;
  unsigned int llvm_cbe_tmp__145__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  signed int *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  unsigned int llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  signed int *llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  signed int *llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  unsigned int llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  signed int *llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  unsigned int llvm_cbe_tmp__153;
  unsigned int llvm_cbe_tmp__153__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  signed int *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  unsigned int llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  unsigned long long llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  signed int *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  signed int *llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  unsigned int llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  signed int *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  unsigned int llvm_cbe_tmp__161;
  unsigned int llvm_cbe_tmp__161__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  signed int *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  unsigned int llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  unsigned long long llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  signed int *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  signed int *llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  unsigned int llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  signed int *llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned int llvm_cbe_tmp__169;
  unsigned int llvm_cbe_tmp__169__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  unsigned int llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast [8 x [8 x i32]]* %%A to i8*, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__61 = ( char *)(( char *)(&llvm_cbe_A));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 256 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_150_count);
  ( char *)memset(( char *)llvm_cbe_tmp__61, 0u, 256ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",256ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr [8 x [8 x i32]]* %%A, i64 0, i64 0, i64 1, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__63 = (signed int *)(&llvm_cbe_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 8 && "Write access out of array 'A' bound?");
  assert(((signed long long )1ull) < 8 && "Write access out of array 'A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 5, i32* %%3, align 4, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_152_count);
  *llvm_cbe_tmp__63 = 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 5u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr [8 x [8 x i32]]* %%A, i64 0, i64 1, i64 3, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__64 = (signed int *)(&llvm_cbe_A[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 8 && "Write access out of array 'A' bound?");
  assert(((signed long long )3ull) < 8 && "Write access out of array 'A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 4, i32* %%4, align 4, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_154_count);
  *llvm_cbe_tmp__64 = 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 4u);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr [8 x [8 x i32]]* %%A, i64 0, i64 2, i64 4, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__65 = (signed int *)(&llvm_cbe_A[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 8 && "Write access out of array 'A' bound?");
  assert(((signed long long )4ull) < 8 && "Write access out of array 'A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 7, i32* %%5, align 16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_156_count);
  *llvm_cbe_tmp__65 = 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 7u);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr [8 x [8 x i32]]* %%A, i64 0, i64 3, i64 0, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__66 = (signed int *)(&llvm_cbe_A[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 8 && "Write access out of array 'A' bound?");
  assert(((signed long long )0ull) < 8 && "Write access out of array 'A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 2, i32* %%6, align 16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_158_count);
  *llvm_cbe_tmp__66 = 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 2u);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr [8 x [8 x i32]]* %%A, i64 0, i64 4, i64 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__67 = (signed int *)(&llvm_cbe_A[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 8 && "Write access out of array 'A' bound?");
  assert(((signed long long )5ull) < 8 && "Write access out of array 'A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%7, align 4, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_160_count);
  *llvm_cbe_tmp__67 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr [8 x [8 x i32]]* %%A, i64 0, i64 7, i64 2, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__68 = (signed int *)(&llvm_cbe_A[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )7ull) < 8 && "Write access out of array 'A' bound?");
  assert(((signed long long )2ull) < 8 && "Write access out of array 'A' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 9, i32* %%8, align 8, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_162_count);
  *llvm_cbe_tmp__68 = 9u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 9u);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast [8 x [8 x i32]]* %%B to i8*, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__69 = ( char *)(( char *)(&llvm_cbe_B));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memcpy(i8* %%9, i8* bitcast ([8 x [8 x i32]]* @aesl_internal_main.B to i8*), i64 256 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__69, ( char *)(( char *)(&aesl_internal_main_OC_B)), 256ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",256ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__70);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast [8 x [8 x i32]]* %%C to i8*, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__71 = ( char *)(( char *)(&llvm_cbe_C));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i8* @memset(i8* %%11, i32 0, i64 256 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_168_count);
  ( char *)memset(( char *)llvm_cbe_tmp__71, 0u, 256ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",256ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__72);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr [8 x [8 x i32]]* %%C, i64 0, i64 7, i64 2, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__73 = (signed int *)(&llvm_cbe_C[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )7ull) < 8 && "Write access out of array 'C' bound?");
  assert(((signed long long )2ull) < 8 && "Write access out of array 'C' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 9, i32* %%13, align 8, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_170_count);
  *llvm_cbe_tmp__73 = 9u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 9u);
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__74__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%136, %%134  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__170);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi i32 [ 0, %%0 ], [ %%135, %%134  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__74 = (unsigned int )llvm_cbe_tmp__74__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__74);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__169);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%storemerge8 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__75 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__76 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i32* %%16, align 16, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__77 = (unsigned int )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
  if (((llvm_cbe_tmp__77&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
    goto llvm_cbe_tmp__171;
  } else {
    goto llvm_cbe_tmp__172;
  }

llvm_cbe_tmp__173:
if (AESL_DEBUG_TRACE)
printf("\n  %%135 = phi i32 [ %%132, %%128 ], [ %%124, %%123  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__169 = (unsigned int )llvm_cbe_tmp__169__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__169);
printf("\n = 0x%X",llvm_cbe_tmp__167);
printf("\n = 0x%X",llvm_cbe_tmp__161);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%136 = add nsw i32 %%storemerge8, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__170 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__170&4294967295ull)));
  if (((llvm_cbe_tmp__170&4294967295U) == (8u&4294967295U))) {
    goto llvm_cbe_tmp__174;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__170;   /* for PHI node */
    llvm_cbe_tmp__74__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__169;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

llvm_cbe_tmp__175:
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = phi i32 [ %%121, %%117 ], [ %%113, %%112  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_507_count);
  llvm_cbe_tmp__161 = (unsigned int )llvm_cbe_tmp__161__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__161);
printf("\n = 0x%X",llvm_cbe_tmp__159);
printf("\n = 0x%X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 7, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__162 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )7ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = load i32* %%125, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__163 = (unsigned int )*llvm_cbe_tmp__162;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__163);
  if (((llvm_cbe_tmp__163&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__169__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__161;   /* for PHI node */
    goto llvm_cbe_tmp__173;
  } else {
    goto llvm_cbe_tmp__176;
  }

llvm_cbe_tmp__177:
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = phi i32 [ %%110, %%106 ], [ %%102, %%101  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__153 = (unsigned int )llvm_cbe_tmp__153__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__153);
printf("\n = 0x%X",llvm_cbe_tmp__151);
printf("\n = 0x%X",llvm_cbe_tmp__145);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 6, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_490_count);
  llvm_cbe_tmp__154 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )6ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = load i32* %%114, align 8, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_491_count);
  llvm_cbe_tmp__155 = (unsigned int )*llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
  if (((llvm_cbe_tmp__155&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__161__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__153;   /* for PHI node */
    goto llvm_cbe_tmp__175;
  } else {
    goto llvm_cbe_tmp__178;
  }

llvm_cbe_tmp__179:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = phi i32 [ %%99, %%95 ], [ %%91, %%90  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__145 = (unsigned int )llvm_cbe_tmp__145__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__145);
printf("\n = 0x%X",llvm_cbe_tmp__143);
printf("\n = 0x%X",llvm_cbe_tmp__137);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 5, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_463_count);
  llvm_cbe_tmp__146 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )5ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load i32* %%103, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_464_count);
  llvm_cbe_tmp__147 = (unsigned int )*llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
  if (((llvm_cbe_tmp__147&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__153__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__145;   /* for PHI node */
    goto llvm_cbe_tmp__177;
  } else {
    goto llvm_cbe_tmp__180;
  }

llvm_cbe_tmp__181:
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = phi i32 [ %%88, %%84 ], [ %%80, %%79  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_426_count);
  llvm_cbe_tmp__137 = (unsigned int )llvm_cbe_tmp__137__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__137);
printf("\n = 0x%X",llvm_cbe_tmp__135);
printf("\n = 0x%X",llvm_cbe_tmp__129);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__138 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )4ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = load i32* %%92, align 16, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__139 = (unsigned int )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
  if (((llvm_cbe_tmp__139&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__145__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__137;   /* for PHI node */
    goto llvm_cbe_tmp__179;
  } else {
    goto llvm_cbe_tmp__182;
  }

llvm_cbe_tmp__183:
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = phi i32 [ %%77, %%73 ], [ %%69, %%68  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__129 = (unsigned int )llvm_cbe_tmp__129__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__129);
printf("\n = 0x%X",llvm_cbe_tmp__127);
printf("\n = 0x%X",llvm_cbe_tmp__121);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 3, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_409_count);
  llvm_cbe_tmp__130 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = load i32* %%81, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__131 = (unsigned int )*llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__131);
  if (((llvm_cbe_tmp__131&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__137__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__129;   /* for PHI node */
    goto llvm_cbe_tmp__181;
  } else {
    goto llvm_cbe_tmp__184;
  }

llvm_cbe_tmp__185:
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = phi i32 [ %%66, %%62 ], [ %%26, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__121 = (unsigned int )llvm_cbe_tmp__121__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__121);
printf("\n = 0x%X",llvm_cbe_tmp__119);
printf("\n = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__122 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i32* %%70, align 8, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__123 = (unsigned int )*llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
  if (((llvm_cbe_tmp__123&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__121;   /* for PHI node */
    goto llvm_cbe_tmp__183;
  } else {
    goto llvm_cbe_tmp__186;
  }

llvm_cbe_tmp__171:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = phi i32 [ %%23, %%19 ], [ %%14, %%.preheader6  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__83 = (unsigned int )llvm_cbe_tmp__83__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__83);
printf("\n = 0x%X",llvm_cbe_tmp__81);
printf("\n = 0x%X",llvm_cbe_tmp__74);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 %%15, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__84 = (signed int *)(&llvm_cbe_A[(((signed long long )llvm_cbe_tmp__75))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__75));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__75) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'A' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%27, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__85 = (unsigned int )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
  if (((llvm_cbe_tmp__85&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__121__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__83;   /* for PHI node */
    goto llvm_cbe_tmp__185;
  } else {
    goto llvm_cbe_tmp__187;
  }

llvm_cbe_tmp__172:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%14 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__78 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%20, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__79 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__78))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__78));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__78) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%21, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_202_count);
  *llvm_cbe_tmp__79 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%20, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__80 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__78))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__78));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__78) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%22, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_204_count);
  *llvm_cbe_tmp__80 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%14, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(llvm_cbe_tmp__74&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__81&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%20, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__82 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__78))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__78));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__78) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%17, i32* %%24, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_211_count);
  *llvm_cbe_tmp__82 = llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
  llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__81;   /* for PHI node */
  goto llvm_cbe_tmp__171;

llvm_cbe_tmp__187:
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = sext i32 %%26 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__116 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%63, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__117 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__116))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__116));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__116) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%64, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_361_count);
  *llvm_cbe_tmp__117 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%63, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__118 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__116))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__116));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__116) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%65, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_363_count);
  *llvm_cbe_tmp__118 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add nsw i32 %%26, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__119 = (unsigned int )((unsigned int )(llvm_cbe_tmp__83&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__119&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%63, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__120 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__116))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__116));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__116) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%67, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_370_count);
  *llvm_cbe_tmp__120 = llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
  llvm_cbe_tmp__121__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__119;   /* for PHI node */
  goto llvm_cbe_tmp__185;

llvm_cbe_tmp__186:
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = sext i32 %%69 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_386_count);
  llvm_cbe_tmp__124 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%74, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_387_count);
  llvm_cbe_tmp__125 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__124))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__124));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__124) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%75, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_388_count);
  *llvm_cbe_tmp__125 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%74, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__126 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__124))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__124));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__124) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 2, i32* %%76, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_390_count);
  *llvm_cbe_tmp__126 = 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 2u);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add nsw i32 %%69, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__127 = (unsigned int )((unsigned int )(llvm_cbe_tmp__121&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__127&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%74, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_396_count);
  llvm_cbe_tmp__128 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__124))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__124));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__124) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%71, i32* %%78, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_397_count);
  *llvm_cbe_tmp__128 = llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
  llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__127;   /* for PHI node */
  goto llvm_cbe_tmp__183;

llvm_cbe_tmp__184:
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = sext i32 %%80 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_413_count);
  llvm_cbe_tmp__132 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%85, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_414_count);
  llvm_cbe_tmp__133 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__132))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__132));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__132) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%86, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_415_count);
  *llvm_cbe_tmp__133 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%85, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__134 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__132))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__132));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__132) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 3, i32* %%87, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_417_count);
  *llvm_cbe_tmp__134 = 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 3u);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = add nsw i32 %%80, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__135 = (unsigned int )((unsigned int )(llvm_cbe_tmp__129&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__135&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%85, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__136 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__132))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__132));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__132) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%82, i32* %%89, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_424_count);
  *llvm_cbe_tmp__136 = llvm_cbe_tmp__131;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__131);
  llvm_cbe_tmp__137__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__135;   /* for PHI node */
  goto llvm_cbe_tmp__181;

llvm_cbe_tmp__182:
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = sext i32 %%91 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__140 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%96, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_441_count);
  llvm_cbe_tmp__141 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__140))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__140));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__140) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%97, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_442_count);
  *llvm_cbe_tmp__141 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%96, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__142 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__140))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__140));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__140) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 4, i32* %%98, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_444_count);
  *llvm_cbe_tmp__142 = 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 4u);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = add nsw i32 %%91, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_445_count);
  llvm_cbe_tmp__143 = (unsigned int )((unsigned int )(llvm_cbe_tmp__137&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__143&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%96, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__144 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__140))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__140));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__140) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%93, i32* %%100, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_451_count);
  *llvm_cbe_tmp__144 = llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
  llvm_cbe_tmp__145__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__143;   /* for PHI node */
  goto llvm_cbe_tmp__179;

llvm_cbe_tmp__180:
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = sext i32 %%102 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_467_count);
  llvm_cbe_tmp__148 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%107, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__149 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__148))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__148));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__148) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%108, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_469_count);
  *llvm_cbe_tmp__149 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%107, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_470_count);
  llvm_cbe_tmp__150 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__148))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__148));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__148) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 5, i32* %%109, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_471_count);
  *llvm_cbe_tmp__150 = 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 5u);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = add nsw i32 %%102, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_472_count);
  llvm_cbe_tmp__151 = (unsigned int )((unsigned int )(llvm_cbe_tmp__145&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__151&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%107, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_477_count);
  llvm_cbe_tmp__152 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__148))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__148));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__148) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%104, i32* %%111, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_478_count);
  *llvm_cbe_tmp__152 = llvm_cbe_tmp__147;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
  llvm_cbe_tmp__153__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__151;   /* for PHI node */
  goto llvm_cbe_tmp__177;

llvm_cbe_tmp__178:
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = sext i32 %%113 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__156 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__156);
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%118, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_495_count);
  llvm_cbe_tmp__157 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__156))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__156));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__156) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%119, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_496_count);
  *llvm_cbe_tmp__157 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%118, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_497_count);
  llvm_cbe_tmp__158 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__156))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__156));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__156) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 6, i32* %%120, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_498_count);
  *llvm_cbe_tmp__158 = 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 6u);
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = add nsw i32 %%113, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_499_count);
  llvm_cbe_tmp__159 = (unsigned int )((unsigned int )(llvm_cbe_tmp__153&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__159&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%118, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__160 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__156))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__156));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__156) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%115, i32* %%122, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_505_count);
  *llvm_cbe_tmp__160 = llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
  llvm_cbe_tmp__161__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__159;   /* for PHI node */
  goto llvm_cbe_tmp__175;

llvm_cbe_tmp__176:
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = sext i32 %%124 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__164 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%130 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%129, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_522_count);
  llvm_cbe_tmp__165 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__164))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__164));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__164) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%storemerge8, i32* %%130, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_523_count);
  *llvm_cbe_tmp__165 = llvm_cbe_storemerge8;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge8 = 0x%X\n", llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n  %%131 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%129, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_524_count);
  llvm_cbe_tmp__166 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__164))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__164));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__164) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 7, i32* %%131, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_525_count);
  *llvm_cbe_tmp__166 = 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 7u);
if (AESL_DEBUG_TRACE)
printf("\n  %%132 = add nsw i32 %%124, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__167 = (unsigned int )((unsigned int )(llvm_cbe_tmp__161&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__167&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%133 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 %%129, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__168 = (signed int *)(&llvm_cbe_sparse_new[(((signed long long )llvm_cbe_tmp__164))
#ifdef AESL_BC_SIM
 % 6
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__164));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__164) < 6 && "Write access out of array 'sparse_new' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'sparse_new' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%126, i32* %%133, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_532_count);
  *llvm_cbe_tmp__168 = llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__163);
  llvm_cbe_tmp__169__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__167;   /* for PHI node */
  goto llvm_cbe_tmp__173;

  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__174:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [8 x [8 x i32]]* %%A, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__86 = (signed int (*)[8])(&llvm_cbe_A[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [8 x [8 x i32]]* %%B, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__87 = (signed int (*)[8])(&llvm_cbe_B[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__88 = (signed int (*)[8])(&llvm_cbe_C[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [6 x [3 x i32]]* %%sparse_new, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__89 = (signed int (*)[3])(&llvm_cbe_sparse_new[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @mul1([8 x i32]* %%31, [8 x i32]* %%32, [8 x i32]* %%33, [3 x i32]* %%34), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_231_count);
  mul1(llvm_cbe_tmp__86, llvm_cbe_tmp__87, llvm_cbe_tmp__88, llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i32 [ 0, %%30 ], [ %%60, %%.preheader  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned int )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%X",llvm_cbe_storemerge15);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__115);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sext i32 %%storemerge15 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__90 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge15);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__91 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i32* %%36, align 16, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__92 = (unsigned int )*llvm_cbe_tmp__91;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%37) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_253_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__92);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__93);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__94 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%39, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__95 = (unsigned int )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%40) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_265_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__95);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__96);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 2, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__97 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i32* %%42, align 8, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__98 = (unsigned int )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%43) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_277_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__98);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__99);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 3, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__100 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i32* %%45, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__101 = (unsigned int )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%46) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_289_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__101);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__102);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__103 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )4ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i32* %%48, align 16, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__104 = (unsigned int )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%49) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_301_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__104);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__105);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 5, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_311_count);
  llvm_cbe_tmp__106 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )5ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i32* %%51, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__107 = (unsigned int )*llvm_cbe_tmp__106;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%52) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_313_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__107);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__108);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 6, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__109 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )6ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i32* %%54, align 8, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__110 = (unsigned int )*llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%55) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_325_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__110);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__111);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds [8 x [8 x i32]]* %%C, i64 0, i64 %%35, i64 7, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__112 = (signed int *)(&llvm_cbe_C[(((signed long long )llvm_cbe_tmp__90))
#ifdef AESL_BC_SIM
 % 8
#endif
][(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__90));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__90) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )7ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'C' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load i32* %%57, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_336_count);
  llvm_cbe_tmp__113 = (unsigned int )*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%58) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_337_count);
  printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__113);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__114);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = call i32 @putchar(i32 10) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_putchar_count);
  putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add nsw i32 %%storemerge15, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__115 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__115&4294967295ull)));
  if (((llvm_cbe_tmp__115&4294967295U) == (8u&4294967295U))) {
    goto llvm_cbe_tmp__188;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__115;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__188:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

