
void _DT_INIT(void)

{
  if (PTR___gmon_start___00103fe8 != (undefined *)0x0) {
    (*(code *)PTR___gmon_start___00103fe8)();
  }
  return;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103fc0)();
  return;
}


void FUN_00101050(void)

{
  (*(code *)PTR___cxa_finalize_00103ff8)();
  return;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00103fc8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00103fd0)();
  return iVar1;
}


void processEntry entry(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fd8)
            (FUN_0010121c,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x001010c3) */
/* WARNING: Removing unreachable block (ram,0x001010cf) */

void FUN_001010b0(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x00101104) */
/* WARNING: Removing unreachable block (ram,0x00101110) */

void FUN_001010e0(void)

{
  return;
}


void _FINI_0(void)

{
  if (DAT_00104010 == '\0') {
    if (PTR___cxa_finalize_00103ff8 != (undefined *)0x0) {
      FUN_00101050(PTR_LOOP_00104008);
    }
    FUN_001010b0();
    DAT_00104010 = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_001010e0();
  return;
}


void FUN_00101169(ulong param_1)

{
  ulong uVar1;
  int local_1c;
  ulong local_18;
  
  local_18 = (param_1 ^ 0xdeadbeefcafebabe) * 0x1337;
  for (local_1c = 0; local_1c < 5; local_1c = local_1c + 1) {
    local_18 = local_18 ^ local_18 >> ((byte)local_1c + (char)param_1 & 7);
    uVar1 = local_18 + 0xabcdef;
    if (((long)(1 << ((byte)local_1c & 0x1f)) & uVar1) == 0) {
      local_18 = local_18 + 0xdeadbeefcbaa88ad;
    }
    else {
      local_18 = uVar1 ^ 0xdeadbeefcafebabe;
    }
  }
  printf("Obfuscated result: %llx\n",local_18);
  return;
}


undefined8 FUN_0010121c(undefined8 param_1,undefined8 param_2)

{
  long in_FS_OFFSET;
  uint local_24;
  ulong local_20;
  char local_15 [5];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  builtin_strncpy(local_15,"Z\x1f;,\x1d",5);
  local_20 = 0;
  for (local_24 = 0; local_24 < 5; local_24 = local_24 + 1) {
    local_20 = (long)(int)(local_24 * 0x42 ^ (int)local_15[(int)local_24]) | local_20 << 8;
  }
  FUN_00101169(local_20,param_2,local_20);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


void _DT_FINI(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
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
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
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
  halt_baddata();
}

