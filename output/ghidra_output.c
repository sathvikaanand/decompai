
int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd0;
  if (PTR___gmon_start___00103fd0 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd0)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104008)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __isoc99_scanf(void)

{
  (*_DAT_00104010)();
  return;
}


undefined8 main(void)

{
  long in_FS_OFFSET;
  uint local_18;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Enter the first number: ");
  __isoc99_scanf(&DAT_0010201d,&local_18);
  printf("Enter the second number: ");
  __isoc99_scanf(&DAT_0010201d,&local_14);
  printf("The sum of %d and %d is: %d\n",(ulong)local_18,(ulong)local_14,
         (ulong)(local_18 + local_14));
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc0)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101133) */
/* WARNING: Removing unreachable block (ram,0x0010113f) */

void FUN_00101120(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101174) */
/* WARNING: Removing unreachable block (ram,0x00101180) */

void FUN_00101150(void)

{
  return;
}


void _FINI_0(void)

{
  if (__TMC_END__ == '\0') {
    if (PTR___cxa_finalize_00103fe0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fe0)(__dso_handle);
    }
    FUN_00101120();
    __TMC_END__ = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101150();
  return;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __isoc99_scanf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __isoc99_scanf@GLIBC_2.7 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}

