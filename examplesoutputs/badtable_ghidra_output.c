
void FUN_100003934(void)

{
  _printf("\n\nTimeout expired!\n");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


ulong FUN_100003958(void)

{
  ulong uVar1;
  char acStack_428 [1024];
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  _fgets(acStack_428,0x400,*(FILE **)PTR____stdinp_100004018);
  uVar1 = _strtol(acStack_428,(char **)0x0,0);
  if (*(long *)PTR____stack_chk_guard_100004010 != local_28) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar1 & 0xffffffff;
}


int FUN_1000039ec(void)

{
  char local_28 [16];
  long local_18;
  
  local_18 = *(long *)PTR____stack_chk_guard_100004010;
  _fgets(local_28,0x10,*(FILE **)PTR____stdinp_100004018);
  if (*(long *)PTR____stack_chk_guard_100004010 != local_18) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return (int)local_28[0];
}


undefined4 entry(void)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ulong uVar7;
  int local_103c;
  undefined4 local_102c;
  undefined4 auStack_1028 [1024];
  long local_28;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  puVar2 = PTR____stdoutp_100004020;
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  if (DAT_100008008 != 0) {
    _signal(0xe);
    _alarm(DAT_100008008);
  }
  _printf("This service allows you to store integers in a table for future use.\n");
  _printf("Commands: Store (s), Read (r), Dump (d), Quit (q)\n");
  for (local_103c = 0; local_103c < 0x400; local_103c = local_103c + 1) {
    auStack_1028[local_103c] = 0;
  }
LAB_100003b3c:
  do {
    do {
      _printf("Command: ");
      iVar3 = _fflush(*(FILE **)puVar2);
      uVar7 = FUN_1000039ec(iVar3);
      cVar1 = (char)uVar7;
      if (cVar1 == -1) {
        local_102c = 1;
LAB_100003d9c:
        if (*(long *)PTR____stack_chk_guard_100004010 == local_28) {
          return local_102c;
        }
                    /* WARNING: Subroutine does not return */
        ___stack_chk_fail(uVar7);
      }
    } while (cVar1 == '\n');
    if (cVar1 != 'd') {
      if (cVar1 == 'q') {
        uVar6 = _printf("Quitting...\n");
        uVar7 = (ulong)uVar6;
        local_102c = 0;
        goto LAB_100003d9c;
      }
      if (cVar1 == 'r') {
        _printf("Index: ");
        iVar3 = _fflush(*(FILE **)puVar2);
        FUN_100003958(iVar3);
        _printf("Value: %08d (0x%08x)\n");
      }
      else if (cVar1 == 's') {
        _printf("Index: ");
        iVar3 = _fflush(*(FILE **)puVar2);
        iVar3 = FUN_100003958(iVar3);
        _printf("Value: ");
        iVar4 = _fflush(*(FILE **)puVar2);
        uVar5 = FUN_100003958(iVar4);
        _printf(
               "Updating table value at index %04d with %08d (0x%08x): previous value was %08d (0x%08x)\n"
               );
        auStack_1028[iVar3] = uVar5;
      }
      else {
        _printf("Unknown command %c\n");
      }
      goto LAB_100003b3c;
    }
    for (local_103c = 0; local_103c < 0x400; local_103c = local_103c + 1) {
      _printf("%04d: %08d (0x%08x)\n");
    }
  } while( true );
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003df4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004030)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004040)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004048)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004050)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long _strtol(char *param_1,char **param_2,int param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)PTR__strtol_100004058)(param_1,param_2,param_3);
  return lVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

