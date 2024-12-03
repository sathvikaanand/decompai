
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

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
  (*(code *)PTR___assert_fail_00103fd0)();
  return;
}


void processEntry entry(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fd8)
            (FUN_00101200,param_2,&stack0x00000008,0,0,param_1,auStack_8);
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


undefined8 FUN_00101169(float param_1,long param_2,int param_3)

{
  int local_10;
  int local_c;
  
  local_10 = 0;
  do {
    local_c = local_10;
    if (param_3 <= local_10) {
      return 0;
    }
    while (local_c = local_c + 1, local_c < param_3) {
      if ((float)(DAT_001020d0 &
                 (uint)(*(float *)(param_2 + (long)local_10 * 4) -
                       *(float *)(param_2 + (long)local_c * 4))) < param_1) {
        return 1;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}


undefined8 FUN_00101200(void)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = DAT_001020e0;
  local_24 = DAT_001020e4;
  local_20 = DAT_001020e8;
  local_1c = DAT_001020ec;
  local_18 = DAT_001020f0;
  local_14 = DAT_001020f4;
  iVar1 = FUN_00101169(DAT_001020f8,&local_28,6);
  if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(a, 6, 0.3) == 1","paper_example.c",0x14,"main");
  }
  iVar1 = FUN_00101169(DAT_001020fc,&local_28,6);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(a, 6, 0.05) == 0","paper_example.c",0x15,"main");
  }
  local_88 = DAT_001020e0;
  local_84 = DAT_001020e4;
  local_80 = DAT_00102100;
  local_7c = DAT_001020ec;
  local_78 = DAT_001020f0;
  iVar1 = FUN_00101169(DAT_00102104,&local_88,5);
  if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(b, 5, 0.95) == 1","paper_example.c",0x18,"main");
  }
  iVar1 = FUN_00101169(DAT_00102108,&local_88,5);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(b, 5, 0.8) == 0","paper_example.c",0x19,"main");
  }
  local_68 = DAT_001020e0;
  local_64 = DAT_001020e4;
  local_60 = DAT_0010210c;
  local_5c = DAT_001020ec;
  local_58 = DAT_001020f0;
  iVar1 = FUN_00101169(DAT_001020e4,&local_68,5);
  if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(c, 5, 2.0) == 1","paper_example.c",0x1c,"main");
  }
  local_48 = DAT_00102110;
  local_44 = DAT_001020f4;
  local_40 = DAT_00102114;
  local_3c = DAT_00102118;
  local_38 = DAT_0010211c;
  iVar1 = FUN_00101169(DAT_001020e0,&local_48,5);
  if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(d, 5, 1.0) == 1","paper_example.c",0x1f,"main");
  }
  iVar1 = FUN_00101169(DAT_00102120,&local_48,5);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("func0(d, 5, 0.5) == 0","paper_example.c",0x20,"main");
  }
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

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

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

